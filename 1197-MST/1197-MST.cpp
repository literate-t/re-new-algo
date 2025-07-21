#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertex[10001]{};
int edge[100001]{};

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

class UnionFind
{
public:
    UnionFind(int n)
    {
        // node가 1부터 시작
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // 노드의 루트 트리를 찾는다
    // 같은 루트라면 같은 집합
    // 최초의 각 노드의 루트를 자신을 지정했기 때문에
    // 순차적으로 가중치가 작은 값부터 시작하면, 처음에 설정될 루트가
    // 앞으로 구성할 하나의 새 집합의 루트가 된다
    // main에서의 첫 루프에서 해당 노드 트리의 rank가 1이 되면
    // 이보다 커지는 rank는 발생하지 않는다
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        // 같은 집합이면 사이클 발생
        if (px == py)
            return false;
        // 랭크가 큰 쪽(트리 최대 높이가 큰쪽) 하위에 작은 랭크의 노드 트리를 붙이는 이유는
        // 2라는 새 노드 트리를 추가할 때,
        // 3 -> {4}가 3 -> {2, 4}가 되면 높이가 유지되지만(parent[2] = 3)
        // 반대로 하면(parent[3] = 2) 2 -> 3 -> 4가 되어 뎁스가 추가된다        
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        // 뎁스가 같은 경우에는 경유하는 노드 트리가 하나 생기는 것이므로 ++
        else
        {
            parent[py] = px;
            ++rank[px];
        }

        return true;
    }

private:
    vector<int> parent, rank;
};

int main()
{
    int V, E;
    cin >> V >> E;
    UnionFind uf(V);
    vector<Edge> edges;
    edges.reserve(E);
    for (int i = 1; i <= E; ++i)
    {
        int u, v, e;
        cin >> u >> v >> e;
        edges.push_back(Edge{ u, v, e });
    }

    sort(edges.begin(), edges.end());

    int edge_used = 0;
    int total_weight = 0;
    for (auto& edge : edges)
    {
        if (uf.unite(edge.u, edge.v))
        {
            ++edge_used;
            total_weight += edge.weight;
        }

        if (edge_used == V - 1)
            break;
    }

    cout << total_weight << "\n";
}
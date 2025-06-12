#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int p1, p2;

vector<int> parents;
bool visited[101];
queue<pair<int, int>> q;

int main()
{
    cin >> N;
    cin >> p1 >> p2;
    cin >> M;

    parents.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int parent, child;
        cin >> parent >> child;

        parents[child] = parent;
    }

    q.push({ p1, 0 });

    while (q.empty() == false)
    {
        auto [person, degree] = q.front();
        q.pop();

        if (person == p2)
        {
            cout << degree;
            return 0;
        }        

        int parent = parents[person];
        if (parent && visited[parent] == false)
        {            
            visited[parent] = true;
            q.push({ parent, degree + 1 });
        }
        
        for (int i = 1; i <= N; ++i)
        {
            if (parents[i] == person && visited[i] == false)
            {
                visited[i] = true;
                q.push({ i, degree + 1 });
            }
        }
    }

    cout << -1;
}


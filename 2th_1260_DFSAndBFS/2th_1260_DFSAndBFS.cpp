#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool nodes[1001][1001]{};
bool visited[1001]{};
queue<int> q;
int N, M, V;

void dfs(int start);
void bfs(int start);

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		nodes[s][e] = true;
		nodes[e][s] = true;
	}
	dfs(V);
	cout << endl;
	memset(visited, 0, sizeof visited);
	bfs(V);
}

void dfs(int start)
{
	visited[start] = true;
	cout << start << " ";
	for (int i = 1; i <= N; ++i)
		if (nodes[start][i] == true && visited[i] == false)
			dfs(i);
}

void bfs(int start)
{
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int next = q.front();
		q.pop();
		cout << next << " ";
		for (int i = 1; i <= N; ++i)
			if (nodes[next][i] && visited[i] == false)
			{
				visited[i] = true;
				q.push(i);
			}
	}
}
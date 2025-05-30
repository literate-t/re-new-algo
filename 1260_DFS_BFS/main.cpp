#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start);
void bfs();
queue<int> q;
bool map[1001][1001] = { false };
bool dfs_visited[1001] = { false };
bool bfs_visited[1001] = { false };
int N, M, start;

// 1260¹ø
int main()
{
	cin >> N >> M >> start;

	for (int i = 0; i < M; ++i)
	{
		int v, u;
		cin >> v >> u;

		map[v][u] = true;
		map[u][v] = true;
	}

	bfs(start);
	cout << endl;

	q.push(start);
	bfs();
}

void bfs(int start)
{
	if (dfs_visited[start]) return;

	dfs_visited[start] = true;

	cout << start << " ";

	for (int i = 1; i <= N; ++i)
		if (map[start][i] && dfs_visited[i] == false)
			bfs(i);
}

void bfs()
{
	while (!q.empty())
	{
		int start = q.front();
		q.pop();

		bfs_visited[start] = true;
		cout << start << " ";

		for (int i = 1; i <= N; ++i)
		{
			if (bfs_visited[i]) continue;

			if (map[start][i] && bfs_visited[i] == false)
			{
				q.push(i);
				bfs_visited[i] = true;
			}
		}
	}
}

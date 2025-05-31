#include <iostream>
#include <vector>
using namespace std;

int N;
int M;

bool map[101][101];
bool visited[101];
int result_count = -1;

void dfs(int node);

int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		map[u][v] = true;
		map[v][u] = true;
	}

	dfs(1);

	cout << result_count << endl;
}

void dfs(int node)
{
	if (visited[node]) return;

	++result_count;
	visited[node] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (map[node][i] && visited[i] == false)
		{
			dfs(i);
		}		
	}
}

#include <iostream>
using namespace std;

bool nodes[1001][1001]{};
bool visited[1001]{};
int N, M, V;

void dfs(int start);

int main()
{
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		nodes[s][e] = true;
		nodes[e][s] = true;
	}

	dfs(V);
}

void dfs(int start)
{
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= N; ++i)
		if (nodes[start][i] == true && visited[i] == false)
			dfs(i);
}
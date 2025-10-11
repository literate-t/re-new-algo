#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
void dfs(int row, int col);

constexpr int MaxN = 25;
int map[MaxN][MaxN]{};
bool visited[MaxN][MaxN]{};

int N;
int complex_count = 0;

int c_dir[] = { 0, -1, 0, 1 };
int r_dir[] = { -1, 0, 1, 0 };

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;

		for (int j = 0; j < N; ++j)
			map[i][j] = line[j] - '0';
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] && visited[i][j] == false)
			{
				dfs(i, j);
				pq.push(complex_count);
				complex_count = 0;
			}
		}
	}

	cout << pq.size() << '\n';
	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
}

void dfs(int row, int col)
{
	visited[row][col] = true;
	++complex_count;

	for (int i = 0; i < 4; ++i)
	{
		int next_r = row + r_dir[i];
		int next_h = col + c_dir[i];

		if (next_r < 0 || next_r >= N || next_h < 0 || next_h >= N)
			continue;

		if (map[next_r][next_h] && visited[next_r][next_h] == false)
		{
			dfs(next_r, next_h);
		}
	}
}

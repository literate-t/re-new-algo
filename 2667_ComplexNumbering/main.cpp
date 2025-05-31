#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
bool map[25 + 2][25 + 2];
bool visited[25 + 2][25 + 2];
int N;
int adj_dir_row[] = { 1, 0, -1, 0 };
int adj_dir_col[] = { 0, 1, 0, -1 };

void answer();
void dfs(int row, int col);

int house_count = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < N; ++j)
			map[i][j] = line[j] - '0';
	}

	answer();

	cout << pq.size() << endl;
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

void answer()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] && visited[i][j] == false)
			{
				dfs(i, j);
				pq.push(house_count);
				house_count = 0;
			}
		}
	}
}

void dfs(int row, int col)
{
	if (visited[row][col]) return;

	++house_count;

	visited[row][col] = true;

	for (int i = 0; i < 4; ++i)
	{
		int next_row = row + adj_dir_row[i];
		int next_col = col + adj_dir_col[i];

		if (map[next_row][next_col] && false == visited[next_row][next_col])
			dfs(next_row, next_col);
	}
}
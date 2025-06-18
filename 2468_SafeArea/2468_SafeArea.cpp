#include <iostream>
#include <array>
using namespace std;

array<array<int, 100>, 100> map;
array<array<bool, 100>, 100> visited;

int N;

void dfs(int row, int col, int height);
void init_visited();

int adj_row[] = { 1, 0, -1, 0 };
int adj_col[] = { 0, 1, 0, -1 };

int main()
{	
	for (int i = 0; i < 100; ++i)
		map[i].fill(0);

	cin >> N;
	int max_height = -1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int height;
			cin >> height;
			map[i][j] = height;

			if (height > max_height)
				max_height = height;
		}

	int max = -1;
	for (int height = 0; height <= max_height; ++height)			
	{
		int count = 0;
		init_visited();

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == false && map[i][j] > height)
				{
					++count;
					dfs(i, j, height);
				}
			}
		}		
		
		if (max < count)
			max = count;		
	}

	cout << max << endl;
}

void dfs(int row, int col, int height)
{
	visited[row][col] = true;

	for (int i = 0; i < 4; ++i)
	{
		int next_row = row + adj_row[i];
		int next_col = col + adj_col[i];

		if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N)
			continue;
			
		if (false == visited[next_row][next_col] && map[next_row][next_col] > height)
			dfs(next_row, next_col, height);
	}
}

void init_visited()
{
	for (int i = 0; i < 100; ++i)
		visited[i].fill(false);
}
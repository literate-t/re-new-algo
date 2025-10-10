#include <iostream>
#include <queue>
using namespace std;

int map[102][102]{};
bool visited[102][102]{};
queue<pair<pair<int, int>, int>> q;

int N, M;

constexpr int h_dir[] = {-1, 0, 1, 0};
constexpr int w_dir[] = {0, -1, 0, 1};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		string line;
		cin >> line;
		for (int j = 1; j <= M; ++j)
			map[i][j] = line[j - 1] - '0';

	}

	q.push({ { 1, 1 }, 1 });
	visited[1][1] = true;

	while (!q.empty())
	{
		auto& [position, c] = q.front();
		auto& [w, h] = position;
		q.pop();

		if (w == N && h == M)
		{
			cout << c << "\n";
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int next_w = w + w_dir[i];
			int next_h = h + h_dir[i];

			if (next_w < 1 || next_w > N || next_h < 1 || next_h > M) continue;

			if (map[next_w][next_h] == 1 && visited[next_w][next_h] == false)
			{
				visited[next_w][next_h] = true;
				q.push({ { next_w, next_h }, c + 1 });
			}
		}
	}
}

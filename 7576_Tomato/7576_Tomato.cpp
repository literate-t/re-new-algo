#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
int map[1000][1000]{};
int adjacent_m[] = { 0, 1, 0, -1 };
int adjacent_n[] = { 1, 0, -1, 0 };
std::queue<std::pair<std::pair<int, int>, int>> q;
int M, N;
int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int t;
			scanf("%d", &t);
			map[i][j] = t;
			if (t == 1)
				q.push({ {i, j}, 0});
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		auto [pos, count] = q.front(); q.pop();
		auto [n, m] = pos;

		for (int i = 0; i < 4; ++i)
		{
			int next_m = m + adjacent_m[i];
			int next_n = n + adjacent_n[i];
			if (next_m < 0 || next_m >= M || next_n < 0 || next_n >= N)
				continue;

			if (map[next_n][next_m] == 0)
			{
				map[next_n][next_m] = 1;
				q.push({ {next_n, next_m}, count + 1 });
			}
		}
		answer = count;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
	
	if (answer == 0)
		printf("0\n");
	else
		printf("%d\n", answer);
}

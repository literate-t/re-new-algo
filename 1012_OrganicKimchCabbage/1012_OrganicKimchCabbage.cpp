#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int adjacent_m[] = { 0, 1, 0, -1 };
int adjacent_n[] = { 1, 0, -1, 0 };
int T, M, N, K;

//int main()
//{
//	scanf("%d", &T);
//
//	while (T--)
//	{
//		int answer = 0;
//		scanf("%d%d%d", &M, &N, &K);
//		vector<vector<bool>> map(M, vector<bool>(N, false));
//		vector<vector<bool>> visited(M, vector<bool>(N, false));
//		queue<pair<int, int>> q;
//		while (K--)
//		{
//			int m, n;
//			scanf("%d%d", &m, &n);
//			map[m][n] = true;
//		}
//
//		for (int i = 0; i < M; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				if (visited[i][j] == false && map[i][j])
//				{
//					++answer;
//					q.push({ i, j });
//					visited[i][j] = true;
//					while (!q.empty())
//					{
//						auto [m, n] = q.front();
//						q.pop();
//						for (int k = 0; k < 4; ++k)
//						{
//							int next_m = m + adjacent_m[k];
//							int next_n = n + adjacent_n[k];
//
//							if (next_m < 0 || next_m >= M || next_n < 0 || next_n >= N)
//								continue;
//
//							if (map[next_m][next_n] && visited[next_m][next_n] == false)
//							{
//								visited[next_m][next_n] = true;
//								q.push({ next_m, next_n });
//							}
//						}
//					}
//				}
//			}
//		}
//		printf("%d\n", answer);
//	}
//}

bool map[50][50]{};
bool visited[50][50]{};

void dfs(int m, int n);

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int answer = 0;
        memset(map, 0, sizeof(bool) * 50 * 50);
        memset(visited, 0, sizeof(bool) * 50 * 50);

        scanf("%d%d%d", &M, &N, &K);
        while (K--)
        {
            int m, n;
            scanf("%d%d", &m, &n);
            map[m][n] = true;
        }

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == false && map[i][j])
                {
                    dfs(i, j);
                    ++answer;
                }
            }
        }
        printf("%d\n", answer);
    }    
}

void dfs(int m, int n)
{
    visited[m][n] = true;

    for (int i = 0; i < 4; ++i)
    {
        int next_m = m + adjacent_m[i];
        int next_n = n + adjacent_n[i];

        if (next_m < 0 || next_m >= M || next_n < 0 || next_n >= N)
            continue;

        if (map[next_m][next_n] && visited[next_m][next_n] == false)
            dfs(next_m, next_n);
    }
}

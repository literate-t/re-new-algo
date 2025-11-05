#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <array>
#include <algorithm>

//int main()
//{
//	std::array<int, 3> curr, prev;
//	int N;
//	scanf("%d", &N);
//
//	int r, g, b;
//	scanf("%d %d %d", &r, &g, &b);
//	prev[0] = r;
//	prev[1] = g;
//	prev[2] = b;
//
//	// r: 0, g: 1, b: 2
//	for (int i = 1; i < N; ++i)
//	{
//		scanf("%d %d %d", &r, &g, &b);
//		
//		curr[0] = r + std::min(prev[1], prev[2]);
//		curr[1] = g + std::min(prev[0], prev[2]);
//		curr[2] = b + std::min(prev[0], prev[1]);
//
//		prev = curr;
//	}
//
//	printf("%d", std::min({prev[0], prev[1], prev[2]}));
//}

int main()
{
	int dp[1001][3]{};
	int cost[3]{};
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);
		dp[i][0] = cost[0] + std::min({ dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = cost[1] + std::min({ dp[i - 1][0], dp[i - 1][2] });
		dp[i][2] = cost[2] + std::min({ dp[i - 1][0], dp[i - 1][1] });
	}

	printf("%d", std::min({ dp[N][0], dp[N][1], dp[N][2]}));
}

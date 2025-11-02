#include <iostream>
#include <vector>

void fibonacci(int n, std::vector<std::pair<int, int>>& dp);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<std::pair<int, int>> dp(41, { 0,0 });
	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	dp[2] = { 1, 1 };

	int T, N;
	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		fibonacci(N, dp);
		printf("%d %d\n", dp[N].first, dp[N].second);
	}
}

void fibonacci(int n, std::vector<std::pair<int, int>>& dp)
{
	for (int i = 3; i <= n; ++i)
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
}

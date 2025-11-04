#include <iostream>
using namespace std;

int main()
{
	int N;
	int dp[300]{};
	int step[300]{};

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &step[i]);

	dp[0] = step[0];
	dp[1] = step[0] + step[1];
	dp[2] = step[2] + max(step[0], step[1]);

	for (int i = 3; i < N; ++i)
	{
		dp[i] = step[i] + max(dp[i - 3] + step[i - 1], dp[i - 2]);
	}

	printf("%d\n", dp[N - 1]);
}

/*
* dp[i] = step[i] + max(dp[i - 3] + step[i - 1], dp[i - 2])
*/

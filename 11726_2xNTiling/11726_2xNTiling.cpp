#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[1001]{};

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int N;
    cin >> N;

    for (int i = 4; i <= N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[N] << '\n';
}
/*
* dp[0] = 0
* dp[1] = 1
* dp[2] = 2
* dp[3] = 3                                                                 
* 
* dp[n]: 2xn 크기의 직사각형을 1x2, 2x1로 채우는 방법의 수
* 타일 조합은 맨 오른쪽에 1개가 세워지거나, 2개가 포개진 경우로 나뉜다
* dp[n] = dp[n-1] + dp[n-2]
*/
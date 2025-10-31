#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int dp[11]{};

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 10; ++i)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1] ;

    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
}
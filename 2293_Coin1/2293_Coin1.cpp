#include <iostream>
using namespace std;

int coins[101]{};
int dp[10001]{};

int main()
{
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        int coin = coins[i];
        for (int j = coin; j <= k; ++j)
        {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[k] << '\n';
}

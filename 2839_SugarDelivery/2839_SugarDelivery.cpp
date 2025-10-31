#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 2e9;
    vector<int> dp(5001, INF);

    // N은 주어진 설탕 무게
    // dp[i] => ikg을 위한 최소 봉지 개수 => min(dp[i], dp[i - w] + 1(w: {3, 5})
    int N;
    cin >> N;

    dp[0] = 0;
    int weights[] = { 3, 5 };

    for (int i = 1; i <= N; ++i)
    {
        for (int w : weights)
        {
            int prev_weight = i - w;
            if (prev_weight >= 0 && dp[prev_weight] != INF)
                dp[i] = min(dp[i], dp[prev_weight] + 1);
        }
    }

    cout << (dp[N] != INF ? dp[N] : -1) << '\n';
}

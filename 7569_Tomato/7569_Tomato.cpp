#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int M, N, H;

//           N*H    M
int tomatoes[10000][100] = {};
bool visited[10000][100] = {};
int adjacent_m[] = {0, 1, 0, -1};
int adjacent_n[] = {1, 0, -1, 0};
int adjacent_h[] = { 1, -1 };

queue<pair<pair<int, int>, int>> q;
set<int> answers;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    bool all_ripen = true;
    for (int i = 0; i < N * H; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int tomato;
            cin >> tomato;
            tomatoes[i][j] = tomato;
            
            if (tomato == 1)
            {
                visited[i][j] = true;
                q.push({ {i, j}, 0 });
            }
            else if (tomato == 0)
                all_ripen = false;
        }
    }

    if (q.empty())
    {
        cout << -1 << endl;
        return 0;
    }

    if (all_ripen)
    {
        cout << 0 << endl;
        return 0;
    }

    while (q.empty() == false)
    {
        auto [pos, day] = q.front();
        auto [n, m] = pos;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {

            int next_n = n + adjacent_n[i];
            int next_m = m + adjacent_m[i];

            int current_h = n / N;
            int next_h = next_n / N;
            if (next_n < 0 || current_h != next_h || next_n >= N * H || next_m < 0 || next_m >= M)
                continue;

            if (visited[next_n][next_m] == false && tomatoes[next_n][next_m] == 0)
            {
                tomatoes[next_n][next_m] = 1;
                visited[next_n][next_m] = true;
                q.push({ {next_n, next_m}, day + 1 });
                answers.insert(day + 1);
            }
        }

        for (int i = 0; i < 2; ++i)
        {
            int next_h = n + adjacent_h[i] * N;
            if (next_h < 0 || next_h >= N * H) continue;

            if (visited[next_h][m] == false && tomatoes[next_h][m] == 0)
            {
                tomatoes[next_h][m] = 1;
                visited[next_h][m] = true;
                q.push({ {next_h, m}, day + 1 });
                answers.insert(day + 1);
            }
        }        
    }

    for (int i = 0; i < N * H; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomatoes[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int answer = -1;

    for (int item : answers)
    {
        if (answer < item)
            answer = item;
    }

    cout << answer << endl;
}

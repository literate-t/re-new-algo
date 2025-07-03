#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[300][300]{};
bool visited[300][300]{};

int adjacent_row[] = {1, 0, -1, 0};
int adjacent_col[] = {0, 1, 0, -1};

int N, M;
void dfs(int row, int col);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    int count = 0;
    int loop_count = 0;
    while (true)
    {
        count = 0;
        memset(visited, 0, sizeof(visited));
        bool has_dfs = false;

        for (int row = 1; row < N; ++row)
        {
            for (int col = 1; col < M; ++col)
            {                
                if (map[row][col] != 0 && visited[row][col] == false)
                {
                    has_dfs = true;
                    dfs(row, col);
                    ++count;
                }                
            }
        }
        
        if (count >= 2)
        {
            cout << loop_count << endl;
            return 0;
        }

        if (has_dfs == false)
        {
            cout << 0 << endl;
            return 0;
        }

        ++loop_count;
    }
}

void dfs(int row, int col)
{
    visited[row][col] = true;

    vector<pair<int, int>> adjacents;

    for (int i = 0; i < 4; ++i)
    {
        int next_row = row + adjacent_row[i];
        int next_col = col + adjacent_col[i];

        if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M)
            continue;

        if (map[row][col] != 0 && map[next_row][next_col] == 0 && visited[next_row][next_col] == false)
        {
            int value = map[row][col];
            map[row][col] = max(--value, 0);
        }

        if (map[next_row][next_col] != 0 && visited[next_row][next_col] == false)
            adjacents.push_back({ next_row, next_col });
    }

    for (int i = 0; i < 4; ++i)
    {
        int next_row = row + adjacent_row[i];
        int next_col = col + adjacent_col[i];

        if (next_row < 0 || next_col < 0 || next_row >= N || next_col >= M)
            continue;

        if (map[next_row][next_col] != 0 && visited[next_row][next_col] == false)
            dfs(next_row, next_col);
    }
}

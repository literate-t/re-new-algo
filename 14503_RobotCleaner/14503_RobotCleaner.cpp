#include <iostream>
using namespace std;
using Pair = pair<int, int>;
Pair dirs[] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
int map[50][50]{};
int N, M, start_r, start_c, dir;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;    
    cin >> start_r >> start_c >> dir;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    int current_r = start_r;
    int current_c = start_c;
    int answer = 1;
    while (true)
    {
        map[current_r][current_c] = -1;
        bool can_clear = false;
        for (int i = 0; i < 4; ++i)
        {
            if (map[current_r + dirs[i].first][current_c + dirs[i].second] == 0)
            {
                can_clear = true;
                break;
            }
        }
        if (can_clear)
        {
            int new_dir = (dir + 3) % 4;
            int next_r = current_r + dirs[new_dir].first;
            int next_c = current_c + dirs[new_dir].second;
            if (map[next_r][next_c] == 0)
            {
                current_r = next_r;
                current_c = next_c;
                ++answer;
            }
            dir = new_dir;
        }
        else
        {
            Pair nd = dirs[(dir + 2) % 4];
            int next_r = current_r + nd.first;
            int next_c = current_c + nd.second;
            if (map[next_r][next_c] == 1)
                break;
            else
            {
                current_r = next_r;
                current_c = next_c;                
            }
        }
    }
    cout << answer << endl;
}
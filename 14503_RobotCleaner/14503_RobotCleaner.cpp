#include <iostream>
#include <queue>
using namespace std;

using Pair = pair<int, int>;

int adjacent_r[]{1, 0, -1, 0};
int adjacent_c[]{0, 1, 0, -1};
Pair dirs[] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };

enum {north, east, south, west};

int map[50][50]{};
bool visited[50][50]{};
queue<pair<Pair, int>> q;

int N, M;
int start_r, start_c, dir;
Pair operator+(const Pair& a, const Pair& b);

int main()
{
    int dir;
    cin >> N >> M;    
    cin >> start_r >> start_c >> dir;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    int current_r = start_r;
    int current_c = start_c;
    int answer = 0;
    while (true)
    {
        ++answer;

        map[current_r][current_c] = -1;
        bool can_clear = false;
        for (int i = 0; i < 4; ++i)
        {
            int next_r = current_r + adjacent_r[i];
            int next_c = current_c + adjacent_c[i];

            if (map[current_r][current_c] == 0)
            {
                can_clear = true;
                break;
            }
        }

        if (can_clear)
        {
            int new_dir = (dir + 3) % 4;
            Pair nd = dirs[new_dir];
            int next_r = current_r + nd.first;
            int next_c = current_c + nd.second;

            if (map[next_r][next_c] == 0)
            {
                current_r = next_r;
                current_c = next_c;
                dir = new_dir;
            }
        }
        else
        {
            int reverse_dir = (dir + 2) % 4;
            Pair nd = dirs[reverse_dir];
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

Pair operator+(const Pair& a, const Pair& b)
{
    return Pair(a.first + b.first, a.second + b.second);
}
#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>> q;
//queue<pair<int, int>> q;
int N, M;
int map[102][102];
bool visited[102][102];
int dist[102][102];
int dir_n[] = { 1, 0, -1, 0 };
int dir_m[] = { 0, 1, 0, -1 };

void bfs(int n, int m);

int main()
{
	cin >> N >> M;

	for (int n = 1; n <= N; ++n)
	{
		string line;
		cin >> line;
		for (int m = 1; m <= M; ++m)
		{
			int number = line[m - 1] - '0';
			map[n][m] = number;
		}
	}

	//dist[1][1] = 1;
	bfs(1, 1);
}

void bfs(int n, int m)
{
	q.push({ { n, m }, 1 });

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();		

		auto [current_n, current_m] = node.first;
		int current_count = node.second;		
		visited[current_n][current_m] = true;

		if (current_n == N && current_m == M)
		{
			cout << current_count;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int next_dir_n = dir_n[i] + current_n;
			int next_dir_m = dir_m[i] + current_m;

			if (map[next_dir_n][next_dir_m] && false == visited[next_dir_n][next_dir_m])
			{
				visited[next_dir_n][next_dir_m] = true;
				q.push({ { next_dir_n, next_dir_m }, current_count + 1 });
			}
		}
	}
}

// queue�� pair�� ���� �ʰ� �Ÿ��� ������ �迭�� �����ϴ� �� �޸𸮸� ���� ����(40KB) �� �Ա� ������ 
// ���� �����Ͱ� �и��Ǵ� ������ ����
//void bfs(int n, int m)
//{
//	q.push({ n, m });
//
//	while (!q.empty())
//	{
//		auto node = q.front();
//		q.pop();
//
//		auto [current_n, current_m] = node;
//		int current_count = dist[current_n][current_m];
//		visited[current_n][current_m] = true;
//
//		if (current_n == N && current_m == M)
//		{
//			cout << current_count;
//			return;
//		}
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int next_dir_n = dir_n[i] + current_n;
//			int next_dir_m = dir_m[i] + current_m;
//
//			if (map[next_dir_n][next_dir_m] && false == visited[next_dir_n][next_dir_m])
//			{
//				visited[next_dir_n][next_dir_m] = true;
//				q.push({ next_dir_n, next_dir_m });
//				dist[next_dir_n][next_dir_m] = dist[current_n][current_m] + 1;
//			}
//		}
//	}
//}

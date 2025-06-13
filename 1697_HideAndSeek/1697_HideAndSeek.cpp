#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 정답
// 배열을 사용하면 좋은 이유가 별도의 visited 배열을 안 둬도 된다.
int N, K;
const int MAX_SIZE = 200000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	vector<int> seconds(MAX_SIZE + 1, -1);
	queue<int> q;

	seconds[N] = 0;
	q.push(N);

	int answer = 0;
	while (q.empty() == false)
	{
		int current = q.front();
		q.pop();

		if (current == K)
		{
			answer = seconds[K];
			break;
		}

		for (int next : {current - 1, current + 1, current * 2})
		{
			if (next < 0 || next > MAX_SIZE + 1 || seconds[next] != -1) continue;

			seconds[next] = seconds[current] + 1;
			q.push(next);
		}
	}

	cout << answer << endl;
}

// 틀렸다
// BFS 방식을 나름대로 모사해보려고 한 건데 pos++만 하니까 8 14 경우 정답을 못 구한다
// 남겨놓음
//int N, K;
//int seconds[200002] = {};
//void set_value_by_condition(int pos, int second)
//{
//	seconds[pos] = seconds[pos] > second ? second : seconds[pos];
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> K;
//
//	if (N > K)
//	{
//		cout << N - K << endl;
//		return 0;
//	}
//	
//	seconds[N] = 0;
//	int pos = N;
//	int answer = 0;
//
//	while (true)
//	{
//		int current_second = seconds[pos];
//		if (pos == K)
//		{
//			answer = current_second;
//			break;
//		}
//
//		int next_pos = pos * 2;
//		int next_second = current_second + 1;
//		seconds[next_pos] = next_second;
//
//		{
//			int next = next_pos + 1;
//			if (seconds[next] != 0)
//				set_value_by_condition(next, next_second + 1);
//			else
//				seconds[next] = next_second + 1;
//
//			next = next_pos - 1;
//			if (next >= 0)
//			{
//				if (seconds[next] != 0)
//					set_value_by_condition(next, next_second + 1);
//				else
//					seconds[next] = next_second + 1;
//			}
//		}
//
//		next_pos = pos + 1;
//		if (seconds[next_pos] != 0)
//			set_value_by_condition(next_pos, next_second);
//		else
//			seconds[next_pos] = next_second;
//
//		next_pos = pos - 1;
//		if (next_pos >= 0)
//		{
//			if (seconds[next_pos] != 0)
//				set_value_by_condition(next_pos, next_second);
//			else
//				seconds[next_pos] = next_second;
//		}
//
//		++pos;
//	}
//
//	cout << answer << endl;
//}

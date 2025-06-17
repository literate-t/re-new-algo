#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 정답
// 배열을 사용하면 좋은 이유가 별도의 visited 배열을 안 둬도 된다.
int N, K;
const int MAX_SIZE = 200000;
array<int, MAX_SIZE + 1> seconds;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	seconds.fill(-1);
	queue<int> q;

	cin >> N >> K;

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

	vector<int> path;
	path.reserve(answer);
	int index = K;

	path.push_back(index);
	--answer;
	while (answer >= 0)
	{
		if ((index % 2 == 0) && index / 2 >=0 && seconds[index / 2] == answer)
		{			
			path.push_back(index / 2);
			index = index / 2;
		}
		else if((index - 1) >= 0 && seconds[index - 1] == answer)
		{
			path.push_back(index - 1);
			index = index - 1;
		}
		else if (seconds[index + 1] == answer)
		{
			path.push_back(index + 1);
			index = index + 1;
		}

		--answer;
	}

	reverse(path.begin(), path.end());

	for (int item : path)
		cout << item << " ";
}
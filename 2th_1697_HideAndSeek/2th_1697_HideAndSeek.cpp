#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int N, K;
constexpr int kMax = 100001;
int position[kMax]{};
queue<int> q;
int main()
{
	scanf("%d%d", &N, &K);
	q.push(N);

	while (!q.empty())
	{
		auto n = q.front(); q.pop();
		if (n == K)
		{
			printf("%d\n", position[n]);
			return 0;
		}

		// initializer
		for (int next : {n - 1, n + 1, n * 2})
		{
			if (next < 0 || next >= kMax || position[next] != 0)
				continue;

			q.push(next);
			position[next] = position[n] + 1;
		}

		//if (n >= 1 && position[n - 1] == 0)
		//{
		//	q.push(n - 1);
		//	position[n - 1] = position[n] + 1;
		//}
		//if (n + 1 <= 100000 && position[n + 1] == 0)
		//{
		//	q.push(n + 1);
		//	position[n + 1] = position[n] + 1;
		//}
		//if (n * 2 <= 100000 && position[n * 2] == 0)
		//{
		//	q.push(n * 2);
		//	position[n * 2] = position[n] + 1;
		//}
	}
}

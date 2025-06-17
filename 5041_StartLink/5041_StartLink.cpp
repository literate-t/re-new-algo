#include <iostream>
#include <array>
#include <queue>
using namespace std;

int F, S, G, U, D;
const int MAX = 1000000;
array<int, MAX + 1> building;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	building.fill(-1);
	queue<int> q;

	cin >> F >> S >> G >> U >> D;

	building[S] = 0;

	q.push(S);

	while (q.empty() == false)
	{
		int current = q.front();
		q.pop();

		if (current == G)
		{
			cout << building[current] << endl;
			return 0;
		}

		for (int next : {current + U, current - D})
		{
			if (next < 1 || next > F || building[next] != -1)
				continue;

			building[next] = building[current] + 1;
			q.push(next);
		}
	}

	cout << "use the stairs" << endl;
}
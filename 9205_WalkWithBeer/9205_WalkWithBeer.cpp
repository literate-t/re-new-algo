#include <iostream>
#include <queue>
#include <array>
using namespace std;

using Pair = pair<int, int>;
int t, n;
vector<string> answers;
array<bool, 102> visited;
array<Pair, 102> positions;
queue<int> q;

inline int dist(Pair a, Pair b);
void dfs(int pos);

int main()
{
	answers.reserve(50);

	cin >> t;

	while (t--)
	{
		visited.fill(false);

		cin >> n;

		for (int i = 0; i < n + 2; ++i)
		{
			Pair pos;
			cin >> pos.first;
			cin >> pos.second;

			positions[i] = pos;
		}

		dfs(0);

		if (visited[n + 1])
			answers.push_back("happy\n");
		else
			answers.push_back("sad\n");
	}

	for (auto& result : answers)
		cout << result;
}

void dfs(int current)
{
	visited[current] = true;

	for (int to = 1; to < n + 2; ++to)
	{
		if (visited[to] == false && dist(positions[current], positions[to]) <= 1000)
			dfs(to);
	}
}

// bfs
//int main()
//{
//	// test case count
//	cin >> t;
//
//	for (int test = 0; test < t; ++test)
//	{
//		Pair start;
//		Pair rock;
//
//		// conv count
//		cin >> n;
//
//		// start
//		cin >> start.first;
//		cin >> start.second;
//
//		vector<bool> visited(n + 2, false);
//		vector<Pair> positions(n + 2);
//		queue<int> q;
//
//		// set start
//		positions[0] = start;
//
//		// stroe
//		for (int i = 1; i <= n; ++i)
//		{
//			Pair store;
//			cin >> store.first;
//			cin >> store.second;
//
//			positions[i] = store;
//		}
//		cin >> rock.first;
//		cin >> rock.second;
//
//		// set rock
//		positions[n + 1] = rock;
//
//		q.push(0);
//		while (q.empty() == false)
//		{
//			int current = q.front(); q.pop();
//			visited[current] = true;
//
//			for (int to = 0; to < n + 2; ++to)
//			{
//				if (false == visited[to] && dist(positions[current], positions[to]) <= 1000)
//				{
//					q.push(to);
//					visited[to] = true;
//				}
//			}
//		}
//
//		if (visited[n + 1])
//			answer[test] = "happy\n";
//		else
//			answer[test] = "sad\n";
//	}
//
//	for (auto& result : answer)
//		cout << result;
//}

int dist(Pair a, Pair b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

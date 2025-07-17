#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void build(vector<int>& arr, vector<int>& tree, int node, int start, int end);
void update(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int diff);
int query(vector<int>& tree, vector<int>& lazy, int node, int N, int rest, int start, int end, int left, int right);
void propagate(vector<int>& tree, vector<int>& lazy, int node, int start, int end);

int main()
{
	int N, M, size;
	cin >> N >> M;
	size = N * N;

	int h = static_cast<int>(log2(size));
	int tree_size = 1 << (h + 1);

	vector<int> arr(size, 0);
	vector<int> tree(tree_size, 0);
	vector<int> lazy(tree_size, 0);

	for (int i = 0; i < size; ++i)
		cin >> arr[i];

	build(arr, tree, 1, 0, size - 1);

	while (M--)
	{
		int command;
		cin >> command;

		if (command == 0)
		{
			int x, y, val;
			cin >> x >> y >> val;
			int index = (x - 1) * N + (y - 1);
			int diff = arr[index] - val;

			update(tree, lazy, 1, 0, size - 1, x - 1, y - 1, diff);
		}
		else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int left = (x1 - 1) * N + (y1 - 1);
			int right = (x2 - 1) * N + (y2 - 1);

			cout << query(tree, lazy, 1, N, left % N, 0, size - 1, left, right) << '\n';
		}
	}
}

void build(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(arr, tree, node * 2, start, mid);
	build(arr, tree, node * 2 + 1, mid + 1, end);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int diff)
{
	propagate(tree, lazy, node, start, end);

	if (right < start || end < left)
		return;

	// full cover
	if (left <= start && end <= right)
	{
		lazy[node] += diff;
		propagate(tree, lazy, node, start, end);
		return;
	}

	int mid = (end + start) / 2;
	update(tree, lazy, node * 2, start, mid, left, right, diff);
	update(tree, lazy, node * 2, mid + 1, end, left, right, diff);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>& tree, vector<int>& lazy, int node, int N, int rest, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 0;

	propagate(tree, lazy, node, start, end);

	// full cover
	if (left <= start && end <= right)
	{
		if ()
		{
			return tree[node];
		}
	}

	int mid = (end + start) / 2;
	int l_sum = query(tree, lazy, node * 2, N, rest, start, mid, left, right);
	int r_sum = query(tree, lazy, node * 2 + 1, N, rest, mid + 1, end, left, right);

	return l_sum + r_sum;
}

void propagate(vector<int>& tree, vector<int>& lazy, int node, int start, int end)
{
	if (lazy[node] == 0)
		return;

	tree[node] += lazy[node] * (end - start + 1);

	if (start == end)
	{
		lazy[node] = 0;
		return;
	}

	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];

	lazy[node] = 0;
}

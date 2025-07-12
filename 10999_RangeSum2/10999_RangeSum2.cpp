#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void build(vector<int64_t>& arr, vector<int64_t>& tree, int node, int arr_start, int arr_end);
int64_t query(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int arr_start, int arr_end, int left, int right);
void update(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int arr_start, int arr_end, int left, int right, int64_t diff);
void propagate(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int start, int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int64_t> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<int64_t> tree(tree_size);
    vector<int64_t> lazy(tree_size, 0);

    // tree 초기화
    build(arr, tree, 1, 0, N - 1);

    int command;
    int count = M + K;
    while (count--)
    {
        cin >> command;
        // update
        if (command == 1)
        {
            int b, c;
            int64_t d;
            cin >> b >> c >> d;
            update(tree, lazy, 1, 0, N - 1, b - 1, c - 1, d);
        }
        // range sum
        else
        {
            int b, c;
            cin >> b >> c;
            cout << query(tree, lazy, 1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}

void build(vector<int64_t>& arr, vector<int64_t>& tree, int node, int arr_start, int arr_end)
{
    if (arr_start == arr_end)
    {
        tree[node] = arr[arr_start];
        return;
    }

    int mid = (arr_start + arr_end) / 2;
    build(arr, tree, node * 2, arr_start, mid);
    build(arr, tree, node * 2 + 1, mid + 1, arr_end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int64_t query(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int arr_start, int arr_end, int left, int right)
{
    if (right < arr_start || arr_end < left)
        return 0;    

    propagate(tree, lazy, node, arr_start, arr_end);

    if (left <= arr_start && arr_end <= right)
        return tree[node];

    int mid = (arr_start + arr_end) / 2;
    int64_t l_sum = query(tree, lazy, node * 2, arr_start, mid, left, right);
    int64_t r_sum = query(tree, lazy, node * 2 + 1, mid + 1, arr_end, left, right);

    return l_sum + r_sum;
}

void update(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int arr_start, int arr_end, int left, int right, int64_t diff)
{
    propagate(tree, lazy, node, arr_start, arr_end);

    if (right < arr_start || arr_end < left)
        return;

    if (left <= arr_start && arr_end <= right)
    {
        lazy[node] += diff;
        propagate(tree, lazy, node, arr_start, arr_end);
        return;
    }

    int mid = (arr_start + arr_end) / 2;
    update(tree, lazy, node * 2, arr_start, mid, left, right, diff);
    update(tree, lazy, node * 2 + 1, mid + 1, arr_end, left, right, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void propagate(vector<int64_t>& tree, vector<int64_t>& lazy, int node, int start, int end)
{
    if (lazy[node] == 0)
        return;

    tree[node] += (end - start + 1) * lazy[node];

    if (start == end)
    {
        lazy[node] = 0;
        return;
    }

    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];

    lazy[node] = 0;
}

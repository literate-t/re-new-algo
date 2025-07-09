#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;

void init(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t arr_start, int64_t arr_end);
int64_t query(vector<int64_t>& tree, int64_t node, int64_t arr_start, int64_t arr_end, int64_t left, int64_t right);
void update(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t index, int64_t val);
void update(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t index, int64_t arr_start, int64_t arr_end, int64_t val);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<int64_t> arr(N);
    for (int64_t i = 0; i < N; ++i)
        cin >> arr[i];

    int64_t h = ceil(log2(N));
    // -1을 안 하는 이유는 노드 번호를 1부터 시작해야 자식 노드 계산하기가 편함
    int tree_size = 1 << (h + 1);
    vector<int64_t> tree(tree_size);

    int64_t count = M + K;
    vector<int64_t> answers;
    answers.reserve(K);
    init(arr, tree, 1, 0, N - 1);

    while (count--)
    {
        int64_t command, b, c;
        cin >> command >> b >> c;

        if (command == 1)
        {
            update(arr, tree, 1, b - 1, c);
        }
        else if (command == 2)
        {
            int64_t sum = query(tree, 1, 0, N - 1, b - 1, c - 1);   
            answers.push_back(sum);
        }
    }
    for (int64_t answer : answers)
        cout << answer << '\n';
}

void init(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t arr_start, int64_t arr_end)
{
    if (arr_start == arr_end)
    {
        tree[node] = arr[arr_start];
        return;
    }

    init(arr, tree, node * 2, arr_start, (arr_start + arr_end) / 2);
    init(arr, tree, node * 2 + 1, (arr_start + arr_end) / 2 + 1, arr_end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int64_t query(vector<int64_t>& tree, int64_t node, int64_t arr_start, int64_t arr_end, int64_t left, int64_t right)
{
    if (arr_end < left || arr_start > right)
        return 0;
    if (left <= arr_start && arr_end <= right)
        return tree[node];

    int64_t l = query(tree, node * 2, arr_start, (arr_start + arr_end) / 2, left, right);
    int64_t r = query(tree, node * 2 + 1, (arr_start + arr_end) / 2 + 1, arr_end, left, right);

    return l + r;
}

void update(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t index, int64_t val)
{
    update(arr, tree, node, index, 0, N - 1, val);
}

void update(vector<int64_t>& arr, vector<int64_t>& tree, int64_t node, int64_t index, int64_t arr_start, int64_t arr_end, int64_t val)
{
    if (index < arr_start || arr_end < index)
        return;

    if (arr_start == arr_end)
    {
        arr[index] = val;
        tree[node] = val;
        return;
    }

    update(arr, tree, node * 2, index, arr_start, (arr_start + arr_end) / 2, val);
    update(arr, tree, node * 2 + 1, index, (arr_start + arr_end) / 2 + 1, arr_end, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

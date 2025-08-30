#include <bits/stdc++.h>
using namespace std;

struct Node {
    int first, first_cnt;
    int second, second_cnt;
    
    Node() : first(0), first_cnt(0), second(0), second_cnt(0) {}
    Node(int val, int cnt) : first(val), first_cnt(cnt), second(0), second_cnt(0) {}
};

vector<int> arr;
vector<Node> tree;

Node merge(const Node& left, const Node& right) {
    // Create a list of all distinct values from both nodes
    vector<int> values = {left.first, left.second, right.first, right.second};
    sort(values.begin(), values.end(), greater<int>());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    if (values.empty() || values[0] == 0) {
        return Node();
    }
    
    Node result;
    result.first = values[0];
    
    // Count frequencies
    if (left.first == result.first) result.first_cnt += left.first_cnt;
    if (left.second == result.first) result.first_cnt += left.second_cnt;
    if (right.first == result.first) result.first_cnt += right.first_cnt;
    if (right.second == result.first) result.first_cnt += right.second_cnt;
    
    if (values.size() > 1) {
        result.second = values[1];
        if (left.first == result.second) result.second_cnt += left.first_cnt;
        if (left.second == result.second) result.second_cnt += left.second_cnt;
        if (right.first == result.second) result.second_cnt += right.first_cnt;
        if (right.second == result.second) result.second_cnt += right.second_cnt;
    }
    
    return result;
}

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = Node(arr[l], 1);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        tree[idx] = Node(val, 1);
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * idx + 1, l, mid, pos, val);
    } else {
        update(2 * idx + 2, mid + 1, r, pos, val);
    }

    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return Node();
    }
    if (ql <= l && r <= qr) {
        return tree[idx];
    }
    
    int mid = (l + r) / 2;
    Node left_res = query(2 * idx + 1, l, mid, ql, qr);
    Node right_res = query(2 * idx + 2, mid + 1, r, ql, qr);

    return merge(left_res, right_res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    tree.resize(4 * n);
    build(0, 0, n - 1);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            update(0, 0, n - 1, p - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            Node res = query(0, 0, n - 1, l - 1, r - 1);
            cout << res.second_cnt << '\n';
        }
    }
    
    return 0;
}
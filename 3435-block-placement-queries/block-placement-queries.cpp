#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Node {
        int leftmost;   
        int rightmost;  
        int max_gap;    
        Node() : leftmost(-1), rightmost(-1), max_gap(0) {}
        Node(int l, int r, int mg) : leftmost(l), rightmost(r), max_gap(mg) {}
    };

    vector<Node> tree;
    int n;  

    Node merge(const Node& a, const Node& b) {

        if (a.leftmost == -1) return b;
        if (b.leftmost == -1) return a;
        Node res;
        res.leftmost = a.leftmost;
        res.rightmost = b.rightmost;
        res.max_gap = max(a.max_gap, b.max_gap);
        res.max_gap = max(res.max_gap, b.leftmost - a.rightmost);
        return res;
    }


    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            tree[idx] = Node(pos, pos, 0);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx * 2, l, mid, pos);
        else update(idx * 2 + 1, mid + 1, r, pos);
        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(idx * 2, l, mid, ql, qr);
        if (ql > mid) return query(idx * 2 + 1, mid + 1, r, ql, qr);
        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        int max_x = 0;
        for (auto& q : queries) {
            if (q[0] == 1) max_x = max(max_x, q[1]);
            else max_x = max(max_x, q[1]);   
        }
        n = max_x + 1;   
        tree.assign(4 * n, Node()); 

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, n - 1, q[1]);
            } else {
                int x = q[1], sz = q[2];
                Node res = query(1, 0, n - 1, 0, x);
                int max_gap;
                if (res.leftmost == -1) {
                    max_gap = x;
                } else {
                    max_gap = max(res.leftmost - 0, res.max_gap);
                    max_gap = max(max_gap, x - res.rightmost);
                }
                ans.push_back(max_gap >= sz);
            }
        }
        return ans;
    }
};
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char pref_char;
    char suff_char;
};

class Solution {
private:
    vector<Node> tree;

    // Combines left and right children while keeping range order strictly intact
    Node merge(const Node& left, const Node& right, int len_L, int len_R) {
        Node res;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        // Base max length
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        // Prefix length calculation
        if (left.pref_len == len_L && left.suff_char == right.pref_char) {
            res.pref_len = len_L + right.pref_len;
        } else {
            res.pref_len = left.pref_len;
        }

        // Suffix length calculation
        if (right.suff_len == len_R && left.suff_char == right.pref_char) {
            res.suff_len = len_R + left.suff_len;
        } else {
            res.suff_len = right.suff_len;
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        // Build segment tree on initial string
        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};
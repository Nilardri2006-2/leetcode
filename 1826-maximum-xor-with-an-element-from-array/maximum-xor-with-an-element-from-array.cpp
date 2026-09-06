class Node {
public:
    Node* links[2];

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

    bool containsKey(int bit) { return links[bit] != NULL; }

    void put(int bit, Node* node) { links[bit] = node; }

    Node* get(int bit) { return links[bit]; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(int num) {

        Node* node = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {

        Node* node = root;

        int maxi = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit)) {

                maxi = maxi | (1 << i);

                node = node->get(1 - bit);
            }

            else {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> offline;

        for (int i = 0; i < queries.size(); i++) {

            offline.push_back({
                queries[i][1], // mi
                queries[i][0], // xi
                i              // original index
            });
        }

        sort(offline.begin(), offline.end());

        vector<int> ans(queries.size());

        Trie trie;

        int i = 0;

        for (auto& q : offline) {

            int mi = q[0];
            int xi = q[1];
            int idx = q[2];

            while (i < nums.size() && nums[i] <= mi) {

                trie.insert(nums[i]);

                i++;
            }

            if (i == 0) {
                ans[idx] = -1;
            }

            else {
                ans[idx] = trie.getMax(xi);
            }
        }

        return ans;
    }
};
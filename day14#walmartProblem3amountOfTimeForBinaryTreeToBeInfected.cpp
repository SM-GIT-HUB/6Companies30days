/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* &root, TreeNode* &main, unordered_map<int, TreeNode*>& parent, int &start)
    {
        if (root == nullptr) {
            return;
        }

        if (root->val == start) {
            main = root;
        }

        if (root->left)
        {
            parent[root->left->val] = root;
            preOrder(root->left, main, parent, start);
        }

        if (root->right)
        {
            parent[root->right->val] = root;
            preOrder(root->right, main, parent, start);
        }
    }

    int getTime(TreeNode* &main, unordered_map<int, TreeNode*>& parent)
    {
        unordered_map<int, bool> visited;
        queue<TreeNode*> store;

        visited[main->val] = true;
        store.push(main);
        store.push(nullptr);

        int mins = 0;

        while (!store.empty())
        {
            TreeNode* top = store.front();
            store.pop();

            if (!top)
            {
                if (store.empty()) {
                    break;
                }
                else
                {
                    mins++;
                    store.push(nullptr);
                    continue;
                }
            }

            if (parent[top->val] && !visited[parent[top->val]->val])
            {
                visited[parent[top->val]->val] = true;
                store.push(parent[top->val]);
            }

            if (top->left && !visited[top->left->val])
            {
                visited[top->left->val] = true;
                store.push(top->left);
            }

            if (top->right && !visited[top->right->val])
            {
                visited[top->right->val] = true;
                store.push(top->right);
            }
        }

        return mins;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* main = nullptr;
        unordered_map<int, TreeNode*> parent;

        preOrder(root, main, parent, start);

        int time = getTime(main, parent);

        return time;
    }
};

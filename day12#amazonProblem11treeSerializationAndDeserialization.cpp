/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();

            if (!top)
            {
                ans += "N,";
                continue;
            }

            ans += to_string(top->val) + ",";

            q.push(top->left);
            q.push(top->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N,") {
            return nullptr;
        }

        int index = 0;
        int n = data.size();

        string value = "";

        while (data[index] != ',')
        {
            value += data[index++];
        }

        index++;
        
        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty() && index < n)
        {
            if (data[index] == ',')
            {
                index++;
                continue;
            }

            string a = "";
            string b = "";

            while (index < n && data[index] != ',')
            {
                a += data[index++];
            }

            index++;

            while (index < n && data[index] != ',')
            {
                b += data[index++];
            }

            index++;

            TreeNode* curr = q.front();
            q.pop();

            if (!curr) {
                continue;
            }

            if (a != "N" && a.size())
            {
                int val = stoi(a);
                curr->left = new TreeNode(val);
                q.push(curr->left);
            }

            if (b != "N" && b.size())
            {
                int val = stoi(b);
                curr->right = new TreeNode(val);
                q.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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
    class obj {
    public:
        int sum;
        int isBst;
        int maxi;
        int mini;

        obj(int s, int i, int mx, int mn): sum(s), isBst(i), maxi(mx), mini(mn) {}
    };

    obj* getSum(TreeNode* &root, int &ans)
    {
        if (root == nullptr) {
            return new obj(0, 1, INT_MIN, INT_MAX);
        }

        obj* left = getSum(root->left, ans);
        obj* right = getSum(root->right, ans);

        if (!left->isBst || !right->isBst || !(root->val > left->maxi && root->val < right->mini)) {
            return new obj(0, 0, 0, 0);
        }

        int sum = left->sum + right->sum + root->val;
        int mini = min(root->val, min(left->mini, right->mini));
        int maxi = max(root->val, max(left->maxi, right->maxi));

        if (sum > ans) {
            ans = sum;
        }

        return new obj(sum, 1, maxi, mini);
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;

        getSum(root, ans);

        return ans;
    }
};

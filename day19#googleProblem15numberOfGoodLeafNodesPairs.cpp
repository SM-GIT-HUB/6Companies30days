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
    int getAns(TreeNode* &root, int &distance, vector<int>& depths)
    {
        int pairs = 0;
        int left = depths.size();
        int right = left;
        int after = right;

        if (root->left)
        {
            pairs += getAns(root->left, distance, depths);
            right = depths.size();
        }

        if (root->right) {
            pairs += getAns(root->right, distance, depths);
        }
            
        after = depths.size();

        if (after == left) {
            depths.push_back(1);
        }
        else
        {
            if ( (right > left) && (after > right) )
            {
                for (int i = left; i < right; i++)
                {
                    if (depths[i] < distance)
                    {
                        for (int j = right; j < after; j++)
                        {
                            if ((depths[i] + depths[j]) <= distance) {
                                pairs++;
                            }
                        }
                    }
                }
            }

            for (int i = left; i < after; i++)
            {
                depths[i]++;
            }
        }

        return pairs;
    }

    int countPairs(TreeNode* root, int distance) {
        vector<int> depths;

        int ans = getAns(root, distance, depths);

        return ans;
    }
};

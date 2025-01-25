class Solution {
public:
    class Trie {
    public:
        unordered_map<int, Trie*> children;
    };

    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        Trie* root = new Trie();

        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            Trie* curr = root;
            int count = 0;

            for (int j = i; j < n; j++)
            {
                if (nums[j] % p == 0) {
                    count++;
                }

                if (count > k) {
                    break;
                }

                if (curr->children[nums[j]] == nullptr)
                {
                    curr->children[nums[j]] = new Trie();
                    ans++;
                }

                curr = curr->children[nums[j]];
            }
        }

        return ans;
    }
};

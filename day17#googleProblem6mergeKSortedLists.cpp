/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class comp {
    public:
        bool operator()(ListNode* &a, ListNode* &b)
        {
            return (a->val > b->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        priority_queue<ListNode*, vector<ListNode*>, comp> q;

        for (auto &l : lists)
        {
            if (l) {
                q.push(l);
            }
        }

        while (!q.empty())
        {
            ListNode* curr = q.top();
            q.pop();

            temp->next = curr;
            temp = temp->next;

            if (curr->next) {
                q.push(curr->next);
            }
        }

        return ans->next;
    }
};

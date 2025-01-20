class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;

        for (int x : nums)
        {
            if (q.size() < k) {
                q.push(x);
            }
            else
            {
                if (x > q.top())
                {
                    q.pop();
                    q.push(x);
                }
            }
        }
    }
    
    int add(int val) {
        if (q.size() < size) {
            q.push(val);
        }
        else if (val > q.top())
        {
            q.pop();
            q.push(val);
        }

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class DataStream {
public:
    int k;
    int count;
    int val;

    DataStream(int value, int k) {
        this->val = value;
        this->count = 0;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == val) {
            count++;
        }
        else
            count = 0;
        
        return (count >= k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

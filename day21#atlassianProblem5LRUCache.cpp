class LRUCache {
    class obj {
    public:
        int key;
        int value;
        obj* prev;
        obj* next;

        obj(int k, int s)
        {
            key = k;
            value = s;
            prev = nullptr;
            next = nullptr;
        }
    };

public:
    unordered_map<int, obj*> mapp;
    obj* head;
    obj* tail;
    int size;
    int maxSize;

    LRUCache(int capacity) {
        size = 0;
        maxSize = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (mapp[key])
        {
            obj* curr = mapp[key];

            if (curr == head) {
                return curr->value;
            }
            
            if (curr->prev && curr->next)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            else if (curr->prev)
            {
                curr->prev->next = nullptr;
                tail = curr->prev;
            }

            curr->next = head;
            head->prev = curr;
            curr->prev = nullptr;
            
            head = curr;

            return curr->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (mapp[key])
        {
            mapp[key]->value = value;
            obj* curr = mapp[key];

            if (curr == head) {
                return;
            }
            
            if (curr->prev && curr->next)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            else if (curr->prev)
            {
                tail = curr->prev;
                curr->prev->next = nullptr;
            }

            curr->next = head;
            head->prev = curr;
            curr->prev = nullptr;
            
            head = curr;
        }
        else
        {
            obj* newHead = new obj(key, value);
            mapp[key] = newHead;

            if (size < maxSize)
            {
                if (head)
                {
                    head->prev = newHead;
                    newHead->next = head;
                }
                else
                    tail = newHead;
                    
                head = newHead;
                this->size++;
            }
            else
            {
                mapp.erase(tail->key);

                if (head != tail)
                {
                    tail = tail->prev;
                    tail->next->prev = nullptr;
                    tail->next = nullptr;
                    
                    head->prev = newHead;
                    newHead->next = head;
                }
                else
                    tail = newHead;
                
                head = newHead;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

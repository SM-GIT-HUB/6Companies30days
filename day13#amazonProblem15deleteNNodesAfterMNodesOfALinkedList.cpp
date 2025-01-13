class Solution {
  public:
    Node* getNodes(Node* &root, int n, int m)
    {
        if (root == nullptr) {
            return root;
        }
        
        int skip = m;
        int del = n;
        
        Node* curr = root;
        
        while (--skip && curr)
        {
            curr = curr->next;
        }
        
        if (!curr) {
            return root;
        }
        
        Node* temp = curr->next;
        
        while (del-- && temp)
        {
            temp = temp->next;
        }
        
        curr->next = getNodes(temp, n, m);
        
        return root;
    }
  
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if (m == 0) {
            return nullptr;
        }
        
        head = getNodes(head, n, m);
        
        return head;
    }
};

class Solution{
    class trienode {
    public:
        char data;
        bool isTerminal;
        trienode* children[26];
        
        trienode(char data)
        {
            this->data = data;
            this->isTerminal = false;
            
            for (int i = 0; i < 26; i++)
            {
                this->children[i] = nullptr;
            }
        }
    };
    
    class Trie {
    
    trienode* root = nullptr;
    
    public:
        
        Trie()
        {
            root = new trienode('\0');
        }
        
        void insertInto(trienode* &root, string word)
        {
            if (word.size() == 0)
            {
                root->isTerminal = true;
                return;
            }
            
            int index = word[0] - 'a';
            trienode* child = nullptr;
            
            if (root->children[index]) {
                child = root->children[index];
            }
            else
            {
                child = new trienode(word[0]);
                root->children[index] = child;
            }
            
            insertInto(child, word.substr(1));
        }
        
        void insert(string word)
        {
            insertInto(root, word);
        }
        
        void searchInto(trienode* &root, vector<string>& output, string x)
        {
            if (root->isTerminal)
            {
                output.push_back(x);
            }
            
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i])
                {
                    x += i + 'a';
                    searchInto(root->children[i], output, x);
                    x.pop_back();
                }
            }
        }
        
        void search(string &word, vector<vector<string> >& ans)
        {
            string x = "";
            trienode* curr = root;
            bool flag = false;
            
            for (char &y : word)
            {
                x += y;
                
                int index = y - 'a';
                trienode* child = curr->children[index];
                
                if (!flag) {
                    flag = child? flag : true;
                }
                
                if (!flag)
                {
                    vector<string> output;
                    
                    searchInto(child, output, x);
                    ans.push_back(output);
                    
                    curr = child;
                }
                else
                    ans.push_back({"0"});
            }
        }
    };
    
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* main = new Trie();
        
        for (int i = 0; i < n; i++)
        {
            main->insert(contact[i]);
        }
        
        vector<vector<string> > ans;
        
        main->search(s, ans);
        
        return ans;
    }
};

class WordDictionary {
    class trienode {
    public:
        char data;
        bool isTerminal;
        trienode* children[26];

        trienode(char data)
        {
            this->data = data;
            this->isTerminal = false;

            for (auto &x : children)
            {
                x = nullptr;
            }
        }
    };

    class Trie {
    public:
        trienode* root = nullptr;

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

        bool searchInto(trienode* &root, string word)
        {
            if (word.size() == 0)
            {
                if (root->isTerminal == true) {
                    return true;
                }
                else
                    return false;
            }

            if (word[0] == '.')
            {
                bool ans = false;

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    int index = ch - 'a';

                    if (root->children[index]) {
                        ans = searchInto(root->children[index], word.substr(1));
                    }

                    if (ans == true) {
                        return ans;
                    }
                }

                return ans;
            }
            else
            {
                int index = word[0] - 'a';

                bool ans = false;

                if (root->children[index]) {
                    ans = searchInto(root->children[index], word.substr(1));
                }

                return ans;
            }
        }

        bool search(string word)
        {
            bool ans = searchInto(root, word);
            return ans;
        }
    };

public:
    Trie* main = nullptr;
    WordDictionary() {
        main = new Trie();
    }
    
    void addWord(string word) {
        main->insert(word);
    }
    
    bool search(string word) {
        bool ans = main->search(word);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

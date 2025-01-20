class ThroneInheritance {
public:
    class obj {
    public:
        string name;
        bool isAlive;
        vector<obj*> children;

        obj(string name)
        {
            this->name = name;
            this->isAlive = true;
        }
    };

    obj* king = nullptr;
    unordered_map<string, obj*> mapp;

    ThroneInheritance(string kingName) {
        king = new obj(kingName);
        mapp[kingName] = king;
    }
    
    void birth(string parentName, string childName) {
        obj* child = new obj(childName);
        mapp[parentName]->children.push_back(child);
        mapp[childName] = child;
    }
    
    void death(string name) {
        mapp[name]->isAlive = false;
    }

    void inheritDfs(obj* &root, vector<string>& ans)
    {
        if (root == nullptr) {
            return;
        }

        if (root->isAlive == true) {
            ans.push_back(root->name);
        }

        for (auto &x : root->children)
        {
            inheritDfs(x, ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        inheritDfs(king, ans);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

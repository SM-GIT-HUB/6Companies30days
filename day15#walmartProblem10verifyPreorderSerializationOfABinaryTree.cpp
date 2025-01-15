class Solution {
public:
    pair<string, int> form(int index, string &str)
    {
        string a = "";

        while (index < str.size() && str[index] != ',')
        {
            a += str[index++];
        }

        return {a, index + 1};
    }

    bool isValidSerialization(string preorder) {
        stack<string> s;

        pair<string, int> curr = form(0, preorder);
        s.push(curr.first);
        
        int index = curr.second;
        int pop = 0;

        while (!s.empty())
        {
            string t = s.top();

            if(t == "#")
            {
                pop++;
                s.pop();
                continue;
            }
            else if (pop == 2)
            {
                s.pop();
                pop--;
                continue;
            }

            if (index >= preorder.size()) {
                break;
            }

            curr = form(index, preorder);

            s.push(curr.first);
            index = curr.second;
        }

        if (index < preorder.size() || (index > preorder.size() && !s.empty())) {
            return false;
        }

        return true;
    }
};

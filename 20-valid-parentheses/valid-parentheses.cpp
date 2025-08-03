class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> s_; 
        for (char c : s) 
        {
            if (c == '(' || c == '{' || c == '[') s_.push(c);
            else 
            {
                if (s_.empty()) return false;
                char t = s_.top(); s_.pop();
                if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) 
                {
                    return false;
                }
            }
        }
        return s_.empty();
    }
};

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        stack<char> st;
        for (char c : s) 
        {
            if (c == '(') // push "(" into stack
            {
                st.push(c);
            } 
            else if (c == ')') // pop ")" from stack
            {
                st.pop();
            }
            
            ans = max(ans, (int)st.size()); 
        }
        
        return ans;
    }
};
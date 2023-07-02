class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string s = "";
        helper (n, n, s,res);
        return res;
    }

    void helper (int open, int closed, string& current, vector<string>& res){
        
        if (open == 0 && closed == 0) res.push_back (current);
        else if (open < 0 || closed < 0) return;
        else if (closed < open) return;

        current.push_back ('(');
        helper (open - 1, closed, current, res);
        current.pop_back ();

        current.push_back (')');
        helper (open, closed - 1, current, res);
        current.pop_back ();

        return;
    }
};

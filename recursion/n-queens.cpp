class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> res;
        vector<int> row;
        helper (row, 0, n, res);
        return board_generator (res, n);
    }

    void helper (vector<int>& row, int idx, int n, vector<vector<int>>& res){
        
        if (idx == n) {
            res.push_back (row); 
            return;
        }

        for (int i = 0; i < n; i++){
            if (!check_col_safe (row, i, idx)) continue;
            if (!check_diagonal_safe (row, i, idx)) continue;
            row.push_back (i);
            helper (row, idx+1, n, res);
            row.pop_back();
        }
        return;
    }

    bool check_col_safe (vector<int>& row, int num, int idx){
        
        for (int j = idx-1; j >= 0; j--){
            if (row[j] == num) return false;
        }
        return true;
    }

    bool check_diagonal_safe (vector<int>& row, int num, int idx){
        
        int count = 1;
        for (int j = idx-1; j >= 0; j--){
            if (num == row[j]-count || num == row[j]+count) return false;
            ++count;
        }
        return true;
    }

    vector<vector<string>> board_generator (vector<vector<int>>& conf, int n){
        
        vector<vector<string>> res;

        for (vector<int>& v: conf){
            vector<string> board;
            for (int& i: v){
                string row = "";
                for (int j = 0; j < n; j++) row += i == j ? 'Q' : '.';
                board.push_back (row);
            }
            res.push_back (board);
        }
        return res;
    }
};

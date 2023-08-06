class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9),cols(9),box(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    int num = board[i][j] - '0';
                    
                    if (row[i].count(num) || cols[j].count(num) || box[(i/3)*3 + (j/3)].count(num)) {
                        return false;
                    }

                    cols[j].insert(num);
                    row[i].insert(num);
                    box[(i/3)*3 + (j/3)].insert(num);
                }
            }
        }
        return true;
    }
};
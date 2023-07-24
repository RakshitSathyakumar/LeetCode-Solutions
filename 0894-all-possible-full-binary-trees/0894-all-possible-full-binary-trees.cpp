/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int n){
        if(n == 1){
            TreeNode* base = new TreeNode(0);
            return {base};
        }
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> Left,Right;
            Left = solve(i);
            Right=solve(n-i-1);
            for(auto l:Left){
                for(auto r:Right){
                    ans.push_back(new TreeNode(0,l,r));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0){
            return {};
        }
        return solve(n);
    }
};
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
    void inorder(TreeNode* &root,queue<int> &q){
        if(!root) return;
        inorder(root->left,q);
        q.push(root->val);
        inorder(root->right,q);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> q1,q2;
        inorder(root1,q1);
        inorder(root2,q2);
        vector<int> ans;
        while(q1.size() || q2.size()){
            if(!q1.size()){
                ans.push_back(q2.front());
                q2.pop();
            }else if(!q2.size()){
                ans.push_back(q1.front());
                q1.pop();
            }else if(q1.front() > q2.front()){
                ans.push_back(q2.front());
                q2.pop();
            }else{
                ans.push_back(q1.front());
                q1.pop();
            }
        }
        return ans;
    }   
};
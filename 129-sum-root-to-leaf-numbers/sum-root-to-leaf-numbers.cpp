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
void solve(TreeNode* &root,vector<vector<int>> &ans,vector<int>temp){
    if(root==NULL){
        return ;
    }
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
    ans.push_back(temp);
    return;
    }
    //left call
    solve(root->left,ans,temp);
    //right call
    solve(root->right,ans,temp);
}
    int sumNumbers(TreeNode* root) {

      vector<vector<int>>ans;
      vector<int>temp;
      solve(root,ans,temp);
      vector<int>finalans;

    int finalSum = 0;

    for (int i = 0; i < ans.size(); i++) {
        int sum = 0;
        for (int j = 0; j < ans[i].size(); j++) {
            sum = sum * 10 + ans[i][j];
        }
        finalSum += sum;
    }

    return finalSum;
        
    }
};
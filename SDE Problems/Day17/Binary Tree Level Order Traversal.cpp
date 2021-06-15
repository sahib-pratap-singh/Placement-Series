//Naive approach
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    void order(TreeNode* root, vector<int> &v,int k){
        if(root==NULL){
            return;
        }
        if(k==0){
            v.push_back(root->val);
            return;
        }
        order(root->left,v,k-1);
        order(root->right,v,k-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=height(root);
        vector<int> v;
        vector<vector<int>> ans;
        for(int i=0;i<h;i++){
            order(root,v,i);
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};

//Best approach BFS

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
    void order(TreeNode* root,vector<int> &v,vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!(q.empty())){
            TreeNode* front = q.front();
            if(front == NULL){
                ans.push_back(v);
                v.clear();
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                v.push_back(front->val);
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> v;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        order(root,v,ans);
        return ans;
    }
};
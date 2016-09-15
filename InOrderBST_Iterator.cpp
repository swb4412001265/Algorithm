/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode *> S;
        TreeNode *current = root;
        bool flag = false;
        while(!flag){
            if(current != NULL){
                S.push(current);
                current = current->left;
            }
            else if(S.empty()){
                flag = true;
            }
            else {
                current = S.top();
                S.pop();
                result.push_back(current->val);
                current = current->right;
            }
        }
        return result;
    }
};
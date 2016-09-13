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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode *> S;
        if (root == NULL) {
            return result;
        }
        S.push(root);
        while (!S.empty()) {
            //can not use S.pop() directly since system will give error since void stack which is different as JAVA
            TreeNode *temp = S.top();
            S.pop();
            result.push_back(temp->val);
            if (temp->right != NULL) {
                S.push(temp->right);
            }
            //since stack is LIFO style, so need to put left last
            if (temp->left != NULL) {
                S.push(temp->left);
            }
        }
        return result;
    }
};

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


//////////////////////////////////////////////////////////////
//Binary Tree Postorder Traversal 
///////////////////
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> myStack;
        
        TreeNode *current = root, *lastVisited = NULL;
        while (current != NULL || !myStack.empty()) {
            while (current != NULL) {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top(); 
            if (current->right == NULL || current->right == lastVisited) {
                myStack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
        return result;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: A Tree
    @return: Preorder in ArrayList which contains node values.
    """
    def preorderTraversal(self, root):
        # write your code here
        if not root:
            return []
        stack = []
        stack.append(root)
        res = []
        while len(stack) != 0:
            tmp = stack.pop()
            res.append(tmp.val)
            if tmp.right != None:
                stack.append(tmp.right)
            if tmp.left != None:
                stack.append(tmp.left)
        return res

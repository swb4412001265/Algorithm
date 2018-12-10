
474. Lowest Common Ancestor II
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7

/////////////////////////////////////////////////////////////////////////////
/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    vector<ParentTreeNode*> traverse(ParentTreeNode *root){
        vector<ParentTreeNode*> result;
        while(root != NULL){
        result.push_back(root);
        root = root->parent;
        }
        return result;
    }
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        // Write your code here
        vector<ParentTreeNode*> tempA;
        vector<ParentTreeNode*> tempB;
        tempA = traverse(A);
        tempB = traverse(B);
        int indexA = tempA.size() - 1;
        int indexB = tempB.size() - 1;
        ParentTreeNode *temp = NULL;
        while(indexA >= 0 && indexB >= 0){
            if(tempA[indexA] != tempB[indexB]){
                break;
            }
            temp = tempA[indexA];
            indexA--;
            indexB--;
        }
        return temp;
    }
};


////////////////////////////////////python//////////////////////////
"""
Definition of ParentTreeNode:
class ParentTreeNode:
    def __init__(self, val):
        self.val = val
        self.parent, self.left, self.right = None, None, None
"""


class Solution:
    """
    @param: root: The root of the tree
    @param: A: node in the tree
    @param: B: node in the tree
    @return: The lowest common ancestor of A and B
    """
    def lowestCommonAncestorII(self, root, A, B):
        # write your code here
        if root == None:
            return None
        tmp = []    
        while A is not root:
            tmp.append(A)
            A = A.parent
            
        while B is not root:
            if B in tmp:
                return B
            B = B.parent
        return root

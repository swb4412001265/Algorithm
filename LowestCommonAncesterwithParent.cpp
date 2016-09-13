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
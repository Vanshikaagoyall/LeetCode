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
    TreeNode* min1=NULL;
    TreeNode* min2=NULL;
    void traversal(TreeNode* node){
        if (node == NULL){
            return;
        }

        traversal(node->left);

        if (min1 == NULL || node->val < min1->val){
            min2 = min1;
            min1 = node;
        }else if((min2 == NULL || node->val < min2->val) && node->val != min1->val){
            min2 = node;
        }

        traversal(node->right);

    }

    int findSecondMinimumValue(TreeNode* root) {
        traversal(root);

        if(min2==NULL){
            return -1;
        }else{
            return min2->val;
        }



    }
};
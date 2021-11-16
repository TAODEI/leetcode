#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }
    targetSum -= root->val;

    if (!root->left && !root->right && !targetSum) {
        return true;
    }

    // if (targetSum) {
        if (hasPathSum(root->left, targetSum)) {
            return true;
        } else {
            return hasPathSum(root->right, targetSum);
        }
    // }
}
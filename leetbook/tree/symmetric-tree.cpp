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

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return compare(root->left, root->right);
}

bool compare(TreeNode* left, TreeNode* right) {
    if (!left && !right) { // 都为NULL
        return true;
    } else if (!left || !right) { // 仅1个NULL
        return false;
    }
    
    if (left->val == right->val) { // left 本身没问题, 就往左下
        if (compare(left->left, right->right)) { // left往左下没问题, 就往右下
            return compare(left->right, right->left); // left往右下没问题, 就返回true
        }
    }
    return false;
}
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

int maxDepth(TreeNode* root) {
    // 后序 自底向上
    if (!root) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

int ans;
void maxDepth(TreeNode* root, int dep) {
    // 前序 自顶向下
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        if (dep > ans) {
            ans = dep;
        }
    }
    maxDepth(root->left, dep+1);
    maxDepth(root->right, dep+1);
}
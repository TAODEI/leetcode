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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    if(root == nullptr) {
        return ans;
    }
    que.push(root);

    while(!que.empty()){
        int len = que.size();
        for (int i = 0; i < len; i++) {
            auto ele = que.front();
            ans.back().push_back(ele->val);
            que.pop();
            if (ele->left != NULL) {
                que.push(ele->left);
            }
            if (ele->right != NULL) {
                que.push(ele->right);
            }
        }
    }
    return ans;
}
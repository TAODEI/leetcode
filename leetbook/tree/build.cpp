#include <vector>
#include <iostream>
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

// 此为参考力扣的方法
TreeNode *dfs(vector<int>& inorder, vector<int>& postorder,int head1,int tail1, int head2,int tail2){
    if(head2>tail2)return nullptr;
    
    int val=postorder[tail2];
    TreeNode *root= new TreeNode(val);
    if(head2==tail2)return root;

    int mid=0;  //拆分点mid的位置是相对的，因为h1!=h2
    while(inorder[head1+mid]!=val)mid++;

    root->left=dfs(inorder, postorder, head1, head1+mid-1, head2, head2+mid-1);
    root->right=dfs(inorder, postorder, head1+mid+1, tail1, head2+mid, tail2-1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.empty() || inorder.empty()) {
        return nullptr;
    }
    int len = inorder.size();
    // return dfs(inorder,postorder,0,len-1,0,len-1); // 此为参考力扣的方法, 下面为自己方法, 但最后一个测试点超时
    vector<int> leftOrder;
    vector<int> rightOrder;
    // for (int i = 0; i < postorder.size(); i++) {
    //     for (int j = 0; j < inorder.size(); j++) {
    //         if (inorder.at(j) == postorder.back()) {
    //             for (int k = j+1; k < inorder.size(); k++) {
    //                 rightOrder.push_back(inorder.at(k)); // 分给rightOrder
    //             }
    //             goto LABEL;
    //         } else {
    //             leftOrder.push_back(inorder.at(j)); // 分给leftOrder
    //         }
    //     }
    //     if (postorder.empty()) {
    //         return nullptr;
    //     }
    //     postorder.pop_back();
    //     leftOrder.clear();
    // }
    // LABEL:


    int index;
    for (index = 0; ; index++) {
        if (inorder.at(index) == postorder.back()) {
            for (int i = index+1; i < inorder.size(); i++) {
                rightOrder.push_back(inorder.at(i)); // 分给rightOrder
            }
            break;
        } else {
            leftOrder.push_back(inorder.at(index)); // 分给leftOrder
        }
        if (index == inorder.size()-1) { // 此次在inorder里未找到相等的, 找postorder里的下一个
            if (postorder.empty()) {
                return nullptr;
            }
            postorder.pop_back();
            leftOrder.clear();
            index = -1;
        }
    }

    auto root = new TreeNode(postorder.back());

    postorder.pop_back();

    vector<int> new1Post(postorder);
    root->left = buildTree(leftOrder, new1Post);
    vector<int> new2Post(postorder);
    root->right = buildTree(rightOrder, new2Post);
    return root;
}



// 下面为令本地run起来的主函数
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    ret.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);

    ret.insert(ret.end(), left.begin(), left.end()); // 向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据

    vector<int> right = preorderTraversal(root->right);
    
    ret.insert(ret.end(), right.begin(), right.end());
    return ret;
}

int main() {
    vector<int> inorder, postorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);
    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(7);
    postorder.push_back(20);
    postorder.push_back(3);

    auto root = buildTree(inorder, postorder);
    auto res = preorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res.at(i) << " ";
    }
}

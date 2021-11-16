#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



Node* connect(Node* root) {
    queue<Node*> que;
    if(root == nullptr) {
        return root;
    }
    que.push(root);

    while(!que.empty()){
        int len = que.size();
        for (int i = 0; i < len; i++) {
            auto ele = que.front();
            que.pop();
            if (que.empty()) {
                ele->next = que.front();
            }
            if (ele->left) {
                que.push(ele->left);
                que.push(ele->right);
            }
            // if (ele->right) {
            //     que.push(ele->right);
            // }
        }
    }
    return root;
}

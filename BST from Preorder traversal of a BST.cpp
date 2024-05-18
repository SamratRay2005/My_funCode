// You have been given an array/list 'PREORDER' representing the preorder traversal of a BST with 'N' nodes. All the elements in the given array have distinct values.

// Your task is to construct a binary search tree that matches the given preorder traversal.

// A binary search tree (BST) is a binary tree data structure that has the following properties:

// • The left subtree of a node contains only nodes with data less than the node’s data.
// • The right subtree of a node contains only nodes with data greater than the node’s data.
// • Both the left and right subtrees must also be binary search trees.
// Note:
// It is guaranteed that a BST can be always constructed from the given preorder traversal. Hence, the answer will always exist.



//CODE
#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

// using the preorder fact root --> root's left --> roots right
BinaryTreeNode<int>* solve(int &i , int max , int min , vector<int> &preorder)
{
    if (i>=preorder.size())
    {
        return NULL;
    }
    if (preorder[i]>max || preorder[i]<min)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(i,root->data , min , preorder);
    root->right = solve(i,max, root->data , preorder);
    return root;
}
// using range to determine the position


BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(i,max,min,preorder);
}


//............................................................................................................................................................



// Alternative method(From Inorder)
BinaryTreeNode<int>* solve(vector<int> &inorder , vector<int> &preorder , int f , int l, int &i)
{
    if (i>=preorder.size())
    {
        return NULL;
    }
    if (!(inorder[f]<=preorder[i] && inorder[l]>=preorder[i]))
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    int p = lower_bound((inorder.begin()+f) , (inorder.begin() + l) , root->data) - (inorder.begin()+f);
    p += f;
    // cout << f << l << " " << i << " " << p << " " << root->data << endl;
    root->left = solve(inorder,preorder,f,p-1,i);
    root->right = solve(inorder,preorder,p+1,l,i);
    return root;

}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin() , inorder.end());
    int i = 0;
    int l = preorder.size()-1;
    return solve(inorder,preorder,0, l, i);
}

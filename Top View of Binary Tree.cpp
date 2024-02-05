// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

class Solution
{
    public:
    map<int,map<int,vector<int>>> m;
    
    void trv(Node* root,int x,int y)
    {
        if (root==NULL)
        {
            return;
        }
        m[x][y].push_back(root->data);
        trv(root->left,x-1,y+1);
        trv(root->right,x+1,y+1);
    }
   
    
    
    vector<int> topView(Node *root)
    {
        vector<int> v;
        trv(root,0,0);
        for (auto i:m)
        {
            bool flag = true;
            for (auto j:i.second)
            {
               if (flag == false)
               {
                   break;
               }
               flag = false;
               v.push_back(j.second[0]);
            }
        }
        
        return v;
    }

};

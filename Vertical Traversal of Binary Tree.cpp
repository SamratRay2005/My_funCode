// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
// only the main functions


// The dataStructure is important to note
// for two integer to be maped with some numbers we can use this data structure
// map sort the data automatically with accordance with the first element
    map<int,map<int,vector<int>>> m;
    int c = 0;
    void tr(Node* root, int x, int y)
    {
        if (root==NULL)
        {
            return;
        }

        m[x][y].push_back(root->data);

        tr(root->left,x-1,y+1);
        tr(root->right,x+1,y+1);
    }
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        tr(root,0,0);
        vector<int> v;
        for (auto i:m)
        {
            for (auto j:i.second)
            {
                int n = (j.second).size();
                for (int y = 0 ;y<n ;y++)
                {
                    v.push_back(j.second[y]);
                }
            }
        }
        return v;
    }

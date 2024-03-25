// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.
// You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.
//{ Driver Code Starts
//Initial Template for C++

// see the data structurs used
class Solution {
  public:
  map<Node*,Node*> m;
  map<Node*,bool> v;
  void levelordertraversal(Node* root)
{
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp == NULL)
		{
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
				
			if (temp -> left)
			{
				q.push(temp->left);
				m[temp->left] = temp;
			}
			if (temp -> right)
			{
				q.push(temp->right);
				m[temp->right] = temp;
			}
		}
	}

}
Node* find(Node* root,int t)
{
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==t)
    {
        return root;
    }
    if (find(root->left,t)!=NULL)
    {
        return find(root->left,t);
    }
    if (find(root->right,t)!=NULL)
    {
    return find(root->right,t);
    }
    return NULL;
}
int ans = INT_MIN;
void trv(Node* r,int y)
{
    if (r==NULL)
    {
        ans = max(ans,y-1);
        return;
    }
    if (v[r])
    {
        return;
    }
    v[r] = true;
    trv(m[r],y+1);
    trv(r->right,y+1);
    trv(r->left,y+1);
}
    int minTime(Node* root, int target) 
    {
        levelordertraversal(root);
        Node* p = find(root,target);
        trv(p,0);
        return ans;
        
    }
};

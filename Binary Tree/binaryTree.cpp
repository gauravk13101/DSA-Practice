#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode *left, *right;

    TreeNode(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

TreeNode* buildTree(TreeNode* root) 
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new TreeNode(data);

    if(data == -1) return NULL;

    cout<<"Enter the data on the left of the "<< data <<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data on the right of the "<< data <<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL)  // previous level has been traversed
        {
            cout<<endl;
            if(!q.empty()) q.push(NULL);  // queue still has some child nodes
        }
        else
        {
            cout << temp -> data << " ";
            if(temp ->left) q.push(temp ->left);  //pushing the left element in the queue

            if(temp ->right) q.push(temp ->right);  //pushing the right element in the queue
        }

    }
}


    // L N R
void inorder(TreeNode* root)
{
    if(root == NULL) return;

    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}


    // N L R
void preorder(TreeNode* root)
{
    if(root == NULL) return;

    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

    // L R N
void postorder(TreeNode* root)
{
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}


int main()
{

    TreeNode* root = NULL;
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal is: ";
    inorder(root);

    cout<<endl<<"Preorder Traversal is: ";
    preorder(root);

    cout<<endl<<"Postorder Traversal is: ";
    postorder(root);
}
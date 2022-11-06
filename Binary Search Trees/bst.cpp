#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* minValue(Node *&root)
{
    Node *temp = root;
    while (temp->left)
        temp = temp->left;

    return temp;
}

Node* maxValue(Node *&root)
{
    Node *temp = root;
    while (temp->right)
        temp = temp->right;

    return temp;
}
Node *insertIntoBST(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
        root->right = insertIntoBST(root->right, d);

    else
        root->left = insertIntoBST(root->left, d);

    return root;
}

Node* deleteFromBST(Node* root, int val)
{
    //base case
    if(root == NULL) return root;

    if(root -> data == val)
    {
        //0 child
        if(root -> left == NULL && root -> right == NULL) 
        {
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        //right child
        if(root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        //2 child
        if(root -> left != NULL && root -> right != NULL)
        {
            int min = minValue(root -> right) -> data;
            root -> data = min;
            root -> right = deleteFromBST(root -> right, min);
            return root;
        }
    }

    else if(root -> data > val)
    {
        //finding in left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else
    {
        //finding in right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) // previous level has been traversed
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL); // queue still has some child nodes
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left); // pushing the left element in the queue

            if (temp->right)
                q.push(temp->right); // pushing the right element in the queue
        }
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data into BST:" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    // 10 8 21 7 27 5 4 3 -1

    cout << "Min Value is " << minValue(root)->data << endl;
    cout << "Max Value is " << maxValue(root)->data << endl;

    //DELETION
    root = deleteFromBST(root, 10);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    // 10 8 21 7 27 5 4 3 -1

    cout << "Min Value is " << minValue(root)->data << endl;
    cout << "Max Value is " << maxValue(root)->data << endl;
}
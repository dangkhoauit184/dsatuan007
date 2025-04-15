#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
Node *findMin(Node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = nullptr;
    int arr[] = {3, 5, 2, 20, 11, 30, 9, 18, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    cout << "Cay BST ban dau (inorder): ";
    inorder(root);
    cout << endl;
    root = deleteNode(root, 5);
    cout << "Cay sau khi xoa node 5 (inorder): ";
    inorder(root);
    cout << endl;
    cout << "Node 20 van ton tai trong cay.\n";
    return 0;
}

#include <iostream>
#include <string>
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
void LNR(Node *root)
{
    if (root == nullptr)
        return;
    LNR(root->left);
    cout << root->data << " ";
    LNR(root->right);
}
void LRN(Node *root)
{
    if (root == nullptr)
        return;
    LRN(root->left);
    LRN(root->right);
    cout << root->data << " ";
}
void NLR(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}
void NRL(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    NRL(root->right);
    NRL(root->left);
}
void RNL(Node *root)
{
    if (root == nullptr)
        return;
    RNL(root->right);
    cout << root->data << " ";
    RNL(root->left);
}
void RLN(Node *root)
{
    if (root == nullptr)
        return;
    RLN(root->right);
    RLN(root->left);
    cout << root->data << " ";
}
Node *search(Node *root, int x)
{
    if (root == nullptr || root->data == x)
        return root;
    if (x < root->data)
        return search(root->left, x);
    return search(root->right, x);
}
Node *findParent(Node *root, Node *child)
{
    if (root == nullptr || root->left == child || root->right == child)
        return root;
    if (child->data < root->data)
        return findParent(root->left, child);
    return findParent(root->right, child);
}
bool areSiblings(Node *root, int val1, int val2)
{
    Node *node1 = search(root, val1);
    Node *node2 = search(root, val2);
    if (node1 == nullptr || node2 == nullptr)
        return false;
    Node *parent1 = findParent(root, node1);
    Node *parent2 = findParent(root, node2);
    return parent1 == parent2 && parent1 != nullptr;
}
int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeaves(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int countOneChild(Node *root)
{
    if (root == nullptr)
        return 0;
    if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
        return 1 + countOneChild(root->left) + countOneChild(root->right);
    return countOneChild(root->left) + countOneChild(root->right);
}
int countTwoChildren(Node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left != nullptr && root->right != nullptr)
        return 1 + countTwoChildren(root->left) + countTwoChildren(root->right);
    return countTwoChildren(root->left) + countTwoChildren(root->right);
}
int countEvenNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return (root->data % 2 == 0 ? 1 : 0) + countEvenNodes(root->left) + countEvenNodes(root->right);
}
int countOddNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return (root->data % 2 != 0 ? 1 : 0) + countOddNodes(root->left) + countOddNodes(root->right);
}
int sumNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int sumOneChild(Node *root)
{
    if (root == nullptr)
        return 0;
    if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
        return root->data + sumOneChild(root->left) + sumOneChild(root->right);
    return sumOneChild(root->left) + sumOneChild(root->right);
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int sumOneChildPrime(Node *root)
{
    if (root == nullptr)
        return 0;
    if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
        return (isPrime(root->data) ? root->data : 0) + sumOneChildPrime(root->left) + sumOneChildPrime(root->right);
    return sumOneChildPrime(root->left) + sumOneChildPrime(root->right);
}
int height(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool areIdentical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
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
        Node *temp = search(root->right, root->data + 1);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
    root = deleteNode(root, 5);
    cout << "LNR: ";
    LNR(root);
    cout << endl;
    cout << "LRN: ";
    LRN(root);
    cout << endl;
    cout << "NLR: ";
    NLR(root);
    cout << endl;
    cout << "NRL: ";
    NRL(root);
    cout << endl;
    cout << "RNL: ";
    RNL(root);
    cout << endl;
    cout << "RLN: ";
    RLN(root);
    cout << endl;
    int X = 20;
    cout << "Tim node co khoa bang " << X << ": ";
    Node *found = search(root, X);
    cout << (found ? "Co" : "Khong") << endl;
    int val1 = 11, val2 = 30;
    cout << "Kiem tra " << val1 << " va " << val2 << " co phai anh em: ";
    cout << (areSiblings(root, val1, val2) ? "Co" : "Khong") << endl;
    cout << "Tong so nut: " << countNodes(root) << endl;
    cout << "So nut la: " << countLeaves(root) << endl;
    cout << "So nut co 1 con: " << countOneChild(root) << endl;
    cout << "So nut co 2 con: " << countTwoChildren(root) << endl;
    cout << "So nut chan: " << countEvenNodes(root) << endl;
    cout << "So nut le: " << countOddNodes(root) << endl;
    cout << "Tong cac nut: " << sumNodes(root) << endl;
    cout << "Tong cac nut co 1 con: " << sumOneChild(root) << endl;
    cout << "Tong cac nut co 1 con va la so nguyen to: " << sumOneChildPrime(root) << endl;
    int h = height(root);
    cout << "Chieu cao cay: " << (h > 0 ? to_string(h) : "Khong co") << endl;
    Node *root2 = nullptr;
    int arr2[] = {3, 2, 9, 4, 20, 11, 30, 18};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < m; i++)
    {
        root2 = insert(root2, arr2[i]);
    }
    cout << "Hai cay co giong nhau: " << (areIdentical(root, root2) ? "Co" : "Khong") << endl;
    return 0;
}

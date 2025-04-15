#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string engWord;
    string vietMeaning;
    Node *left;
    Node *right;
    Node(string eng, string viet) : engWord(eng), vietMeaning(viet), left(nullptr), right(nullptr) {}
};
Node *insert(Node *root, string eng, string viet)
{
    if (root == nullptr)
        return new Node(eng, viet);
    if (eng < root->engWord)
        root->left = insert(root->left, eng, viet);
    else if (eng > root->engWord)
        root->right = insert(root->right, eng, viet);
    return root;
}
Node *search(Node *root, string eng)
{
    if (root == nullptr || root->engWord == eng)
        return root;
    if (eng < root->engWord)
        return search(root->left, eng);
    return search(root->right, eng);
}
void updateMeaning(Node *root, string eng, string newViet)
{
    Node *node = search(root, eng);
    if (node != nullptr)
        node->vietMeaning = newViet;
}
void displayInorder(Node *root)
{
    if (root == nullptr)
        return;
    displayInorder(root->left);
    cout << root->engWord << ": " << root->vietMeaning << endl;
    displayInorder(root->right);
}
int main()
{
    Node *root = nullptr;
    int choice;
    string engWord, vietMeaning;

    do
    {
        cout << "\nTu dien Anh-Viet\n";
        cout << "1. Them tu\n";
        cout << "2. Tra cuu tu\n";
        cout << "3. Sua nghia cua tu\n";
        cout << "4. Hien thi tu dien\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Nhap tu tieng Anh: ";
            getline(cin, engWord);
            cout << "Nhap nghia tieng Viet: ";
            getline(cin, vietMeaning);
            root = insert(root, engWord, vietMeaning);
            cout << "Da them tu thanh cong!\n";
            break;
        }
        case 2:
        {
            cout << "Nhap tu tieng Anh can tra cuu: ";
            getline(cin, engWord);
            Node *found = search(root, engWord);
            if (found != nullptr)
            {
                cout << found->engWord << ": " << found->vietMeaning << endl;
            }
            else
            {
                cout << "Tu khong ton tai trong tu dien!\n";
            }
            break;
        }
        case 3:
        {
            cout << "Nhap tu tieng Anh can sua nghia: ";
            getline(cin, engWord);
            Node *found = search(root, engWord);
            if (found != nullptr)
            {
                cout << "Nghia hien tai: " << found->vietMeaning << endl;
                cout << "Nhap nghia moi (tieng Viet): ";
                getline(cin, vietMeaning);
                updateMeaning(root, engWord, vietMeaning);
                cout << "Da sua nghia thanh cong!\n";
            }
            else
            {
                cout << "Tu khong ton tai trong tu dien!\n";
            }
            break;
        }
        case 4:
        {
            if (root == nullptr)
            {
                cout << "Tu dien dang trong!\n";
            }
            else
            {
                cout << "Noi dung tu dien:\n";
                displayInorder(root);
            }
            break;
        }
        case 5:
        {
            cout << "Tam biet!\n";
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!\n";
        }
        }
    } while (choice != 5);
    return 0;
}

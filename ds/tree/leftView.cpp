#include <iostream>
using namespace std;

class btree
{
    public:
    int data;
    btree *left, *right;
    static int maxLevel;

    btree(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    void leftView(int curLevel)
    {
        if (!this)
        {
            return;
        }
        if (maxLevel < curLevel)
        {
            cout << data << endl;
            maxLevel = curLevel;
        }
        left->leftView(curLevel + 1);
        right->leftView(curLevel + 1);
    }
};
int btree::maxLevel = 0;

int main()
{
    btree *root = new btree(12);
    root->left = new btree(10);
    root->right = new btree(30);
    root->right->left = new btree(25);
    root->right->right = new btree(40);

    root->leftView(1);

    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;
template<typename ItemType>
struct BinaryTreeNode {
    ItemType data;
    BinaryTreeNode<ItemType> *parent;
    BinaryTreeNode<ItemType> *leftChild;
    BinaryTreeNode<ItemType> *rightChild;
};

template<class ItemType>
class BinaryTree {
private:
    BinaryTreeNode<ItemType> *root;
    int numberOfNodes;
public:
    BinaryTree();
    bool isEmpty();
    ItemType getRootData();
    void setRootData(const ItemType& newData);
    int getNumberSize() const;
    void addIntegerNode(const ItemType& newEntry);
    void addStringNode(const ItemType& newEntry);

};
//Part One: Tree Implementation
template<class ItemType>
BinaryTree<ItemType>::BinaryTree() {
    BinaryTreeNode<ItemType> *root;
    root->parent=NULL;
    root->leftChild=NULL;
    root->rightChild=NULL;
}
template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() {
    if(numberOfNodes==0)
    {
        return true;
    }
    else
        return false;
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getRootData() {
    ItemType x;
    root->data=x;
    return x;
}
template<class ItemType>
void BinaryTree<ItemType>::setRootData(const ItemType& newData) {
    root->data=newData;
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberSize() const {
    return numberOfNodes;
}
template<class ItemType>
void BinaryTree<ItemType>::addIntegerNode(const ItemType& newEntry) {
    BinaryTreeNode<ItemType> *tmp = new BinaryTreeNode<ItemType>;
    BinaryTreeNode<ItemType> *newNode = new BinaryTreeNode<ItemType>;
    BinaryTreeNode<ItemType> *parent;
    newNode->data=newEntry;
    tmp=root;
    parent=NULL;
    while(tmp!=NULL)
    {
        parent=tmp->parent;
        if(newNode->data < tmp->data)
        {
            tmp=tmp->leftChild;
        }
        else
            tmp=tmp->rightChild;
    }
    if(tmp->parent==NULL)
    {
        root = tmp;
    }
    else if(tmp->data < root->data)
    {
        root->leftChild = tmp;
        tmp->parent = root;
    }
    else
    {
        root->rightChild= tmp;
        tmp->parent = root;
    }
}
template<class ItemType>
void BinaryTree<ItemType>::addStringNode(const ItemType& newEntry) {
    BinaryTreeNode<ItemType> *tmp = new BinaryTreeNode<ItemType>;
    BinaryTreeNode<ItemType> *newNode = new BinaryTreeNode<ItemType>;
    BinaryTreeNode<ItemType> *parent;
    newNode->data=newEntry;
    tmp=root;
    parent=NULL;
    while(tmp!=NULL)
    {
        parent=tmp->parent;
        if(newNode->data < tmp->data)
        {
            tmp=tmp->leftChild;
        }
        else
            tmp=tmp->rightChild;
    }
    if(tmp->parent==NULL)
    {
        root = tmp;
    }
    else if(tmp->data < root->data)
    {
        root->leftChild = tmp;
        tmp->parent = root;
    }
    else
    {
        root->rightChild= tmp;
        tmp->parent = root;
    }
}
int main()
{
ifstream IntegerTree;
IntegerTree.open("random_integer.txt");
//BinaryTree BT = new BinaryTree;

//system("pwd");
if(IntegerTree.is_open())
{
    string line;
    while(getline(IntegerTree, line))
    {
        cout<<line<<endl;
    }
}

ifstream StringTree;
StringTree.open("random_string.txt");
if(StringTree.is_open())
{
    string line;
    while(getline(StringTree, line))
    {
        cout<<line<<endl;
    }
}

    return 0;
}

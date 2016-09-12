#include <iostream>
#include <fstream>

using namespace std;

int totalCost = 0;

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
    void traverseAndPrintInOrder(BinaryTreeNode<ItemType> *root);                     //Problem 1
    void traverseAndPrintPreOrder(BinaryTreeNode<ItemType> *root);                    //Problem 2
    void traverseAndPrintPostOrder(BinaryTreeNode<ItemType> *root);                   //Problem 3
    BinaryTreeNode<ItemType> *getNode(BinaryTreeNode<ItemType>, ItemType target);     //Problem 4
};

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
            tmp=tmp->leftChild; totalCost++;
        }
        else
            tmp=tmp->rightChild; totalCost++;
    }
    if(tmp->parent==NULL)
    {
        root = tmp;totalCost++;
    }
    else if(tmp->data < root->data)
    {
        root->leftChild = tmp; totalCost++;
        tmp->parent = root; totalCost++;
    }
    else
    {
        root->rightChild= tmp;totalCost++;
        tmp->parent = root;totalCost++;
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
        parent=tmp->parent;totalCost++;
        if(newNode->data < tmp->data)
        {
            tmp=tmp->leftChild;totalCost++;
        }
        else
            tmp=tmp->rightChild;totalCost++;
    }
    if(tmp->parent==NULL)
    {
        root = tmp;totalCost++;
    }
    else if(tmp->data < root->data)
    {
        root->leftChild = tmp;totalCost++;
        tmp->parent = root;totalCost++;
    }
    else
    {
        root->rightChild= tmp;totalCost++;
        tmp->parent = root;totalCost++;
    }
}
//IMPLEMENTAIION for Traverse methods
template<class ItemType>
void BinaryTree<ItemType>::traverseAndPrintInOrder(BinaryTreeNode<ItemType> *root) {
    if(root == NULL) return;totalCost++;
    traverseAndPrintInOrder(root->leftChild);
    cout<<root->data<<endl;totalCost++;
    traverseAndPrintInOrder(root->rightChild);
}

template<class ItemType>
void BinaryTree<ItemType>::traverseAndPrintPreOrder(BinaryTreeNode<ItemType> *root) {
    if(root == NULL) return;totalCost++;
    cout<<root->data<<endl;totalCost++;
    traverseAndPrintPreOrder(root->leftChild);
    traverseAndPrintPreOrder(root->rightChild);
}

template<class ItemType>
void BinaryTree<ItemType>::traverseAndPrintPostOrder(BinaryTreeNode<ItemType> *root) {
    if(root == NULL) return;totalCost++;
    traverseAndPrintPostOrder(root->leftChild);
    traverseAndPrintPostOrder(root->rightChild);
    cout<<root->data<<endl;totalCost++;
}

template<class ItemType>
BinaryTreeNode<ItemType> *getNode(ItemType target) {
    BinaryTreeNode<ItemType> *tmp = new BinaryTreeNode<ItemType>;
    if(tmp!=NULL) //maybe create a new BinaryTreeNode?
    {
        if(tmp->data == target)
        {
            return tmp;totalCost++;
        }
        else if(tmp->data > target)
            {
                return getNode(tmp->leftChild, target);totalCost++;
            }
        else
            return getNode(tmp->rightChild, target);totalCost++;
    }
    else
        return NULL;totalCost++;
}



int main()
{
BinaryTree<string> BT;
BinaryTreeNode<string> *root = new BinaryTreeNode<string>;
ifstream ColorTree;
ColorTree.open("random_colors.txt");
if(ColorTree.is_open())
{
    string line;
    while(getline(ColorTree, line))
    {
        //BT.addStringNode(line);
        //BT.traverseAndPrintPreOrder(root);
        cout<<line<<endl;

    }
}
    cout<<"Number of Costs: "<<totalCost<<endl;
    return 0;
}

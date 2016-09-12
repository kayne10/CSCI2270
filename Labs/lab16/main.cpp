//Troy Kayne
//Lab 16
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
    void traverseAndPrintInOrder(BinaryTreeNode<ItemType> *root);
    void traverseAndPrintPreOrder(BinaryTreeNode<ItemType> *root);
    void traverseAndPrintPostOrder(BinaryTreeNode<ItemType> *root);
    BinaryTreeNode<ItemType> *getNode(BinaryTreeNode<ItemType>, ItemType target);
    BinaryTreeNode<ItemType> *findMax(int &totalCost);
    BinaryTreeNode<ItemType> *findMaxHead(BinaryTreeNode *head, int &totalCost);
    BinaryTreeNode<ItemType> *findMin(int &totalCost);
    BinaryTreeNode<ItemType> *findMindHead(BinaryTreeNode *head, int &totalCost);
    int findHeight(int &totalCost);
    int findHeightHead(BinaryTreeNode<ItemType> *head);
    void deleteNode(BinaryTreeNode<ItemType> *target, int &totalCost);
    BinaryTreeNode<ItemType> *getSuccessor(string data);
    BinaryTreeNode<ItemType> *getPredecessor(string data);

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
template<class ItemType>
BinaryTreeNode<ItemType> *findMax(int &totalCost) {
    findMaxHead(BinaryTreeNode<ItemType>* head, int &totalCost) totalCost++;
    {
        BinaryTreeNode *current = head; totalCost++;
        while(current->rightChild != NULL)
        {
            current= current->rightChild; totalCost++;
        }
        return current;totalCost++;totalCost++;
    } //or return values here?
}
template<class ItemType>
BinaryTreeNode<ItemType> *findMin(int &totalCost) {
    findMinHead(BinaryTreeNode* head, int &totalCost) totalCost++;
    {
        BinaryTreeNode *current = head;totalCost++;
        while(current->leftChild != NULL)
        {
            current= current->leftChild;totalCost++;
        }
        return current;totalCost++;totalCost++;
    }//or return values here?
}
template<class ItemType>
int BinaryTree<ItemType>::findHeight(int &totalCost) {
    int findHeightHead(BinaryTreeNode<ItemType> *head) totalCost++; {
        if(head == NULL)
        {
            return -1;totalCost++;
        }
        int leftHeight = findHeightHead(head->leftChild);totalCost++;totalCost++;
        int rightHeight = findHeightHead(head->rightChild);totalCost++;totalCost++;
        if(leftHeight > rightHeight)
        {
            leftHeight++;totalCost++;
            return leftHeight;totalCost++;totalCost++;
        }
        else
        {
            rightHeight++;totalCost++;
            return leftHeight;totalCost++;totalCost++;
        }
    }
}

template<class ItemType>
void BinaryTree<ItemType>::deleteNode(BinaryTreeNode<ItemType> *target, int &totalCost) {
    if(target==NULL) return;
    else
    {
        //No Child
        if(target->leftChild==NULL && target->rightChild==NULL)
        {
            if(target->parent->leftChild==target){
                target->parent->leftChild == NULL;
            }
            else {
                target->parent->rightChild == NULL;
            }
            delete target;
            target = NULL;
        }
        //One Child (rightside)
        else if(target->leftChild==NULL)
        {
            BinaryTreeNode<ItemType> *targetChild = target->rightChild;
            if(target->parent->leftChild==target)
            {
                target->parent->leftChild = target;
            }
            else
                target->parent->rightChild = target;
            targetChild->parent = target->parent;
            delete target;
            target = NULL;
        }
        //One Child(leftside)
        else if(target->rightChild==NULL)
        {
            BinaryTreeNode<ItemType> *targetChild = target->leftChild;
            if(target->parent->leftChild==target)
            {
                target->parent->leftChild = target;
            }
            else
                target->parent->rightChild = target;
            targetChild->parent = target->parent;
            delete target;
            target = NULL;
        }
        //case 3 two children
        else
        {
            BinaryTreeNode<ItemType> *rightMin = findMin(target->rightChild);
            target->data = rightMin->data;
            deleteNode(rightMin, totalCost);
        }
        return;
    }
}
template<class ItemType>
BinaryTreeNode<ItemType> *getSuccessor(string data) {
    BinaryTreeNode<ItemType> *target;
    target->data = data;
    getSuccessor(target);
    BinaryTreeNode<ItemType> *current;
    current = getNode(target);
    if(current == NULL)
    {
        return NULL;
    }
    if(current->rightChild !=NULL)
    {
        return findMin(current->rightChild);
    }
    else
    {
        BinaryTreeNode<ItemType> *successor = NULL;
        BinaryTreeNode<ItemType> *ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->leftChild;
            }
            else
                ancestor = ancestor->rightChild;
        }
        return successor;
    }
}
template<class ItemType>
BinaryTreeNode<ItemType> *getPredecessor(string data) {
    BinaryTreeNode<ItemType> *target;
    target->data = data;
    getPredecessor(target);
    BinaryTreeNode<ItemType> *current;
    current = getNode(target);
    if(current==NULL) return NULL;
    if(current->leftChild != NULL)
    {
        return findMax(current->leftChild);
    }
    else{
        BinaryTreeNode<ItemType> *successor = NULL;
        BinaryTreeNode<ItemType> *ancestor = root;
        while(ancestor != current)
        {
            if(current->data > ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->rightChild;
            }
            else
                ancestor = ancestor->leftChild;
        }
        return successor;
    }
}

template<class ItemType>
void testfindMax() {
    BinaryTree BT;
    cout<<"Find Max: "<<endl;
    int costMax = 0;
    BinaryTreeNode<string> *max = BT.findMax(costMax);
    cout<<"Cost of findMax(): "<<costMax<<endl;
    cout<<"Expected max: yellow"<<endl<<"Actual max: "<<max->data<<endl<<endl;
}
template<class ItemType>
void testfindMin() {
    BinaryTree BT;
    cout<<"Find Min: "<<endl;
    int costMin = 0;
    BinaryTreeNode<string> *min = BT.findMin(costMin);
    cout<<"Cost of findMin(): "<<costMin<<endl;
    cout<<"Expected min: black"<<endl<<"Actual min: "<<min->data<<endl<<endl;
}
template<class ItemType>
void testfindHeight() {
    BinaryTree BT;
    cout<<"Find Height: "<<endl;
    int costHeight = 0;
    int h = BT.findHeight(costHeight);
    cout<<"Cost of findHeight(): "<<costHeight<<endl;
    cout<<"Expected Height: 4"<<endl<<"Actual Height: "<<h<<endl<<endl;
}
template<class ItemType>
void testdeleteNode() {
    BinaryTree BT;
    cout<<"DeleteNode: "<<endl;
    int costDelete = 0;
    BinaryTreeNode<string> *targetDeleteNode = BT.getNode("red",totalCost);
    BT.deleteNode(targetDeleteNode, costDelete);
    cout<<"Actual Cost of deleteNode(): "<<costDelete<<endl;
    cout<<"Expected output: \npurple cyan yellow blue green white black brown orange grey"<<endl<<endl;
    BinaryTree<ItemType>.traverseAndPrintInOrder();
}
template<class ItemType>
void testGetSuccessor() {
    BinaryTree BT;
    cout<<"Get Successor: "<<endl;
    int costSuccessor = 0;
    BinaryTreeNode<string> *successor = BT.getSuccessor("green", costSuccessor);
    cout<<"Cost of getSuccessor(): "<<costSuccessor<<endl;
    cout<<"Expected successor: grey"<<endl<<"Actual Successor: "<<successor->data<<endl<<endl;
}
template<class ItemType>
void testGetPredecessor() {
    BinaryTree BT;
    cout<<"Get Predecessor: "<<endl;
    BinaryTreeNode<string> *predecessor = BT.getPredecessor("green");
    cout<<"Expected Predecessor: cyan"<<endl<<"Actual Predecessor: "<<predecessor->data<<endl<<endl;
}

int main()
{
BinaryTree<string> BT;
ifstream ColorTree;
ColorTree.open("random_colors.txt");
if(ColorTree.is_open())
{
    string line;
    while(getline(ColorTree, line))
    {
        testfindMin();
        testfindMax();
        testfindHeight();
        testdeleteNode();
        testGetSuccessor();
        testGetPredecessor();
        cout<<line<<endl;
    }
}
    return 0;
}


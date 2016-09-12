#include <iostream>

using namespace std;

/* ******************************************************** */
/*			Declarations and implementations of 			*/
/*			the SingleNode and DoubleNode classes			*/
/* ******************************************************** */
// Do not change these classes.
class SingleNode {
private:
	string value;
public:
    SingleNode *nextNode;
	SingleNode() { nextNode = NULL; };
	SingleNode(string s) { value = s; nextNode = NULL; };
	string getValue() { return value; }
	SingleNode* getNextNode() { return nextNode; }
	void setNextNode(SingleNode *newNode) { nextNode = newNode; }
};
class DoubleNode {
private:
	string value;
	DoubleNode *previousNode;
public:
    DoubleNode *nextNode;
	DoubleNode() { nextNode = previousNode = NULL; };
	DoubleNode(string s) { value = s; nextNode = previousNode = NULL; };
	string getValue() { return value; }
	DoubleNode* getNextNode() { return nextNode; }
	DoubleNode* getPreviousNode() { return previousNode; }
	void setNextNode(DoubleNode *newNode) { nextNode = newNode; }
	void setPreviousNode(DoubleNode *newNode) { previousNode = newNode; }
};


/* ******************************************** */
/*			The SingleLinkedList class			*/
/* ******************************************** */
// Declarations
class SingleLinkedList {
private:
	SingleNode *head;
	SingleNode *tail;
	int totalNodes;
public:
	SingleLinkedList();
	~SingleLinkedList();
	void traverseAndPrint();
	void addNode(string data);
	bool deleteNode(string data);
};

// Implementations
// constructor
SingleLinkedList::SingleLinkedList() {
	head = new SingleNode();
	tail = new SingleNode();
	totalNodes = 0;
}
// destructor
SingleLinkedList::~SingleLinkedList() {
	SingleNode* current = head;
	while( current != 0 ) {
		SingleNode* next = current->getNextNode();
		delete current;
		current = next;
	}
	head = 0;
}
/* ----------------------------------------   Begin: your code	------------------------------------- */
void SingleLinkedList::traverseAndPrint(){
    cout<<"Single Linked List: ";
    SingleNode *tempNode;
    tempNode = head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
        {
            cout<<tempNode<<endl;
            tempNode++;
        }
    cout<<endl;
}
void SingleLinkedList::addNode(string data){
    SingleNode *newNode= new SingleNode;
    if(head->nextNode==NULL)
    {
        head->nextNode= newNode;
        tail->nextNode= newNode;
    }
    else{
        tail->nextNode->nextNode = newNode;
        tail->nextNode=newNode;
    }
}
bool SingleLinkedList::deleteNode(string data){
    SingleNode *current = head->nextNode;
    SingleNode *previous = NULL;
    while(current != NULL)
    {
        if(current->getValue()==data)
        {
            if(previous==NULL)
            {
                head->nextNode= current->nextNode;
            }
            else {
                head->nextNode= previous->nextNode;
            }
            delete current;
            return true;
        }
        previous=current;
        current =current->nextNode;
    }
	return false;
}
/* ----------------------------------------   End: your code	------------------------------------- */





/* ******************************************** */
/*			The DoubleLinkedList class			*/
/* ******************************************** */
// Declarations
class DoubleLinkedList {
private:
	DoubleNode *head;
	DoubleNode *tail;
	int totalNodes;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void traverseAndPrintForward();
	void traverseAndPrintBackward();
	void addNode(string data);
	bool deleteNode(string data);
};
// Implementations
// constructor
DoubleLinkedList::DoubleLinkedList() {
	head = new DoubleNode();
	tail = new DoubleNode();
	totalNodes = 0;
}
// destructor
DoubleLinkedList::~DoubleLinkedList() {
	DoubleNode* current = head;
	while( current != 0 ) {
		DoubleNode* next = current->getNextNode();
		delete current;
		current = next;
	}
	head = 0;
}
/* ----------------------------------------   Begin: your code	------------------------------------- */
void DoubleLinkedList::traverseAndPrintForward() {
    cout<<"Double Linked List: ";
    DoubleNode *tempNode;
    tempNode = head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
    {
        cout<<tempNode<<endl;
        tempNode++;
    }
    cout<<endl;
}
void DoubleLinkedList::traverseAndPrintBackward() {
    cout<<"Double Linked List: ";
    DoubleNode *tempNode;
    tempNode = tail->getNextNode();
    while(tempNode->getNextNode()!=NULL)
    {
        cout<<tempNode<<endl;
        tempNode++;
    }
    cout<<endl;
}
void DoubleLinkedList::addNode(string data) {
    DoubleNode *newNode = new DoubleNode;
    if(head->nextNode==NULL)
    {
        head->nextNode= newNode;
        tail->nextNode= newNode;
    }
    else{
        tail->nextNode->nextNode = newNode;
        tail->nextNode=newNode;
    }
}
bool DoubleLinkedList::deleteNode(string data) {
    DoubleNode *current = head->nextNode;
    DoubleNode *previous = NULL;
    while(current != NULL)
    {
        if(current->getValue()==data)
        {
            if(previous==NULL)
            {
                head->nextNode= current->nextNode;
            }
            else {
                head->nextNode= previous->nextNode;
            }
            delete current;
            return true;
        }
        previous=current;
        current =current->nextNode;
    }
	return false;
}
/* ----------------------------------------   End: your code	------------------------------------- */


void testSingleLinkedList() {
	SingleLinkedList sll;
	sll.addNode("a");
	sll.addNode("b");
	sll.addNode("c");
	sll.addNode("d");
	cout << "Add values [a, b, c, d] to the linked list" << endl;
	sll.traverseAndPrint();
	cout << "Should print 'a b c d'" << endl;
	cout << endl;

	sll.deleteNode("c");
	cout << "Remove the value 'c' from the linked list" << endl;
	sll.traverseAndPrint();
	cout << "Should print 'a b d'" << endl;
	cout << endl;

	sll.deleteNode("a");
	cout << "Remove the value 'a' from the linked list" << endl;
	sll.traverseAndPrint();
	cout << "Should print 'b d'" << endl;
	cout << endl;
}

void testDoubleLinkedList() {
	DoubleLinkedList dll;
	dll.addNode("z");
	dll.addNode("y");
	dll.addNode("x");
	dll.addNode("w");
	cout << "Add values [z, y, x, w] to the linked list" << endl;
	cout << endl;

	dll.traverseAndPrintForward();
	cout << "Should print 'z y x w'" << endl;
	cout << endl;

	dll.traverseAndPrintBackward();
	cout << "Should print 'w x y z'" << endl;
	cout << endl;

	dll.deleteNode("y");
	cout << "Remove the value 'y' from the linked list" << endl;
	dll.traverseAndPrintForward();
	cout << "Should print 'z x w'" << endl;
	cout << endl;

	dll.deleteNode("z");
	cout << "Remove the value 'z' from the linked list" << endl;
	dll.traverseAndPrintForward();
	cout << "Should print 'x w'" << endl;
	cout << endl;
}


int main()
{
	testSingleLinkedList();
	testDoubleLinkedList();

    return 0;
}

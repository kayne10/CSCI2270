#include <iostream>

using namespace std;



class CNode {
private:
    string name;
    CNode *next;
    CNode *previous;
public:
    CNode(string value) {name = value; next=previous=NULL; }
    ~CNode() {}
    void setNext( CNode *n) {next = n; }
    void setPrevious( CNode *n) {previous = n; }
    CNode* getNext() {return next;}
    CNode* getPrevious() {return previous;}
};

CNode::CNode(string value) {
name=value;
next=previous=NULL;
}

CNode::~CNode() {
}
CNode::setNext(CNode *n) {
n= new CNode;
n->next=n->next;
}

class DoubleLinkedList {
private:
	CNode *head;
	CNode *tail;
	int totalNodes;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void traverseAndPrintForward();
	void traverseAndPrintBackward();
	void addNode(string data);
	bool deleteNode(string data);

}


DoubleLinkedList::DoubleLinkedList() {
	head = new CNode();
	tail = new CNode();
	totalNodes = 0;
}
int main()
{
   string userInput;
   DoubleLinkedList dll;
   while(userInput!="no") {
    cout<<"Do you want to add a city?"<<endl;
    if(userInput=="yes") {
        cout<<"What is the name of the city?"<endl;
        cin>>dll.addNode()
    }
    else
        return 0;
   }
    return 0;
}


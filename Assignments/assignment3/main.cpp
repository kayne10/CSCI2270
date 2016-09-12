#include <iostream>

using namespace std;

//Single Node
struct SingleNode
{
    string value;
    SingleNode *nextNode;
public:
    SingleNode()
    {
        nextNode = NULL;
    };
    SingleNode(string s)
    {
        value = s;
        nextNode = NULL;
    };
    string getValue()
    {
        return value;
    }
    SingleNode* getNextNode()
    {
        return nextNode;
    }
    void setNextNode(SingleNode *newNode)
    {
        nextNode = newNode;
    }
};
//Double Node
class DoubleNode
{
private:
    string value;
    DoubleNode *nextNode;
    DoubleNode *previousNode;
public:
    DoubleNode()
    {
        nextNode = previousNode = NULL;
    };
    DoubleNode(string s)
    {
        value = s;
        nextNode = previousNode = NULL;
    };
    string getValue()
    {
        return value;
    }
    DoubleNode* getNextNode()
    {
        return nextNode;
    }
    DoubleNode* getPreviousNode()
    {
        return previousNode;
    }
    void setNextNode(DoubleNode *newNode)
    {
        nextNode = newNode;
    }
    void setPreviousNode(DoubleNode *newNode)
    {
        previousNode = newNode;
    }
};

//Single Linked List Stack
class SingleLinkedListStack
{
private:
    SingleNode *head;
    SingleNode *tail;
    int totalNodes;
public:
    SingleLinkedListStack();
    ~SingleLinkedListStack();
    bool isEmpty();
    void push(string value);
    string pop();
    void traverseandPrint();
};
//Single Linked List Stack Implementation
SingleLinkedListStack::SingleLinkedListStack()
{
    head = new SingleNode();
    tail = new SingleNode();
    totalNodes = 0;
}
SingleLinkedListStack::~SingleLinkedListStack()
{
    SingleNode* current = head;
    while( current != 0 )
    {
        SingleNode* next = current->getNextNode();
        delete current;
        current = next;
    }
    head = 0;
}
bool SingleLinkedListStack::isEmpty() {
    SingleNode* top = head;
    if(top->getNextNode()==NULL)
    {
        return true;
    }
    else
        return false;
}
void SingleLinkedListStack::traverseandPrint()
{
    SingleNode* tempNode= head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
    {
        cout<<tempNode->getValue()<<endl;
        tempNode++;
    }
    cout<<endl;
}
void SingleLinkedListStack::push(string data)
{
    SingleNode *newNode= new SingleNode;
    if(!isEmpty())
    {

        if(head->getNextNode()==NULL)
        {

            head->getNextNode()== newNode;
            tail->getNextNode()== newNode;
            newNode->getValue()= data;
        }
        else
        {
            tail->getNextNode()->getNextNode() == newNode;
            tail->getNextNode()==newNode;
            newNode->getValue()=data;
        }
    }
}
string SingleLinkedListStack::pop()
{
    SingleNode *current = head->getNextNode();
    SingleNode *previous = NULL;
    while(current != NULL)
    {
            if(previous==NULL)
            {
                head->getNextNode()== current->getNextNode();
            }
            else
            {
                previous->getNextNode()== current->getNextNode();
                return current;
            }
        delete current;
        previous=current;
        current =current->getNextNode();
    }
}


//Doubly Linked List Stack
class DoublyLinkedListStack {
private:
	DoubleNode *head;
	DoubleNode *tail;
	int totalNodes;
public:
	DoublyLinkedListStack();
	~DoublyLinkedListStack();
	bool isEmpty();
    void push(string value);
    string pop();
    void traverseandPrint();data);
};
//Doubly Linked List Stack Implementation
DoublyLinkedListStack::DoublyLinkedListStack() {
	head = new DoubleNode();
	tail = new DoubleNode();
	totalNodes = 0;
}
DoublyLinkedListStack::~DoublyLinkedListStack() {
	DoubleNode* current = head;
	while( current != 0 ) {
		DoubleNode* next = current->getNextNode();
		next->getPreviousNode() == current;
		delete current;
		current = next;
		next->getPreviousNode() == NULL;
	}
	head = 0;
}
bool SingleLinkedListStack::isEmpty() {
    DoubleNode* top = head;
    if(top->getNextNode()==NULL && top->getPreviousNode()==NULL)
    {
        return true;
    }
    else
        return false;
}
void DoublyLinkedListStack::traverseandPrint() {
    DoubleNode *tempNode;
    tempNode = head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
    {
        cout<<tempNode->getValue()<<endl;
        tempNode++;
    }
    cout<<endl;
}

void DoublyLinkedListStack::push(string data) {
    DoubleNode *newNode= new DoubleNode;
    if(!isEmpty())
    {

        if(head->getNextNode()==NULL)
        {

            head->getNextNode()== newNode;
            tail->getNextNode()== newNode;
            newNode->getValue()= data;
            newNode->getPreviousNode()=head;

        }
        else
        {
            tail->getNextNode()->getNextNode() == newNode;
            tail->getNextNode()==newNode;
            newNode->getValue()=data;
            newNode->getPreviousNode()= tail;
        }
    }
}
string DoublyLinkedListStack::pop() {
    DoubleNode *current = head->getNextNode();
    current->getPreviousNode()=head;
    DoubleNode *previous = NULL;
    while(current != NULL)
        {
            if(previous==NULL)
            {
                head->getNextNode()== current->getNextNode();
                current->getPreviousNode()=head;
            }
            else {
                head->getNextNode()== previous->getNextNode();
            }
            return current;
            delete current;
        }
    previous=current;
    current =current->getNextNode();
    current->getPreviousNode()= previous;
}
//Stack Array
class arrayStack {
private:
    int max_stack =40;
    string *items;
    int top;
public:
    arrayStack();
    ~arrayStack();
    bool isEmpty();
    void push(int a);
    string pop();
    void traverseandPrint();
};
//Stack Array Implementation
arrayStack::arrayStack() {
}

arrayStack::~arrayStack() {}
bool arrayStack::isEmpty() {
    if(top==0)
    {
        return true;
    }
    else
        return false;
}
void arrayStack::push(int a) {
    if(!isEmpty()) {
    items[top]=a;
    top++;
    }
}

string arrayStack::pop() {
    if(top==0) {
        cout<<"underflow error"<<endl;
    }
    else {
       top--;
    }
    return items[top];
}

void arrayStack::traverseandPrint() {
    while(top!=0)
    {
        cout<<items[top]<<endl;
        top--;
    }
}

//Queue Single Linked List
class SingleLinkedListQueue
{
private:
    SingleNode *head;
    SingleNode *tail;
public:
    SingleLinkedListQueue() {head=tail=NULL;}
    void enqueue(string e) {
    SingleNode *tmp = new SingleNode;
    tmp->getValue()=e;
    tmp->getNextNode()=NULL;
    if(tail != NULL){
        tail->getNextNode()=tmp;
        tail = tmp;
    }
    else {
        tail = tmp;
        head = tmp;
    }
    }
    int dequeue() {
    SingleNode *tmp;
    if(head!= NULL){
        tmp = head;
        head = head->getNextNode();
        string tmp_value = tmp->getValue();
        delete tmp;
        return tmp_value;
    }
    else {
        cout<<"Queue is empty, cannot dequeue another item"<<endl;
    }
    }
};


//Doubly Linked List Queue
class DoublyLinkedListQueue {
private:
	DoubleNode *head;
	DoubleNode *tail;
public:
	DoublyLinkedListQueue() {head=tail=NULL;}
    void enqueue(string e) {
    DoubleNode *tmp = new DoubleNode;
    tmp->getValue()=e;
    tmp->getNextNode()=NULL;
    tmp->getPreviousNode()=NULL;
    if(tail != NULL){
        tail->getNextNode()=tmp;
        tail = tmp;
        tmp->getPreviousNode()=tail;
    }
    else {
        tail = tmp;
        head = tmp;
    }
    }
    string dequeue() {
    DoubleNode *tmp;
    if(head!= NULL){
        tmp = head;
        head = head->getNextNode();
        string tmp_value = tmp->getValue();
        head = head->getPreviousNode();
        delete tmp;
        return tmp_value;
    }
    else {
        cout<<"Queue is empty, cannot dequeue another item"<<endl;
    }
    }
};

//Queue Array
class arrayQueue {
private:
    static const int max_queue =40;
    string *items;
    int head;
    int tail;
    int itemCount;
public:
    arrayQueue(); {head = tail = itemCount = 0;
    items = new string[max_queue];}
    void enqueue(string e) {
    if(itemCount<max_queue){
        items[tail]=e;
        itemCount++;
        if(tail==(max_queue - 1))
            tail = 0;
            else
                tail++;
    }
    else
        cout<<"Queue is full, cannot enqueue another item"<<endl;
    }
    string dequeue() {
    if(itemCount>0) {
        string x = items[head];
        itemCount--;
        if(head==max_queue)
            head = 0;
        else
            head++;
        return x;
    }
    else
        cout<<"Queue is empty, cannot dequeue another item"<<endl;
    }
};


int main()
{
    SingleLinkedListStack slls;
    arrayQueue aQ;
    SingleLinkedListQueue sllq;
    string userChoice, userString;
    int stackChoice, queueChoice;
    cout<<"Do you want to create a Stack or Queue?"<<endl;
    cin>>userChoice;
    while(userChoice=="Stack")
    {
        cout<<"1. PUSH(Enter string for insertion into stack)"<<endl;
        cout<<"2. POP(Display string and delete it from stack)"<<endl;
        cout<<"3. PRINT STACK"<<endl;
        cout<<"4. Exit program"<<endl;
        cin>>stackChoice>>endl;
        if(stackChoice==1)
        {
            cout<<"What string would you like to add to the stack?"<<endl;
            cin>>userString;
            cout<<endl;
            slls.push(userString);
        }
        else if(stackChoice==2)
        {
            cout<<"Enter the string you want to display?"<<endl;
            cin>>userString;
            cout<<endl;
            slls.pop(userString);
        }
        else if(stackChoice==3)
        {
            cout<<"stack looks like: "<< slls.traverseandPrint()<<endl;
        }
        else if(stackChoice==4)
        {
            cout<<"Good-bye"<<endl;
        }
    }
    while(userChoice=="Queue")
    {
        cout<<"1. ENQUEUE(Enter string for insertion into queue)"<<endl;
        cout<<"2. DEQUEUE(Display string and delete it from queue)"<<endl;
        cout<<"3. PRINT QUEUE"<<endl;
        cout<<"4. Exit program"<<endl;
        cin>>queueChoice>>endl;
        if(queueChoice==1)
        {
            cout<<"What string would you like to add to the queue?"<<endl;
            cin>>userString;
            cout<<endl;
            aQ.enqueue(userString);
        }
        else if(queueChoice==2)
        {
            cout<< aQ.dequeue() <<endl;
        }
        else if(queueChoice==3)
        {
            for(int i=itemCount; i--)
                cout<<sllq.dequeue()<<endl;
        }
        else if(queueChoice==4)
        {
            cout<<"Good-bye"<<endl;
        }
    }
    return 0;
}

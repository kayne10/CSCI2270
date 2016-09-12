#include <iostream>

using namespace std;

struct doubleNode {
    int ID;
    string name;
    doubleNode* next;
    doubleNode* previous;
};

int main()
{
    string studentName;
    int IDnumber;
    string userDecision;
    doubleNode* head= NULL;
    doubleNode* cur = new doubleNode;
    cout<<"Do you want to add a new student?"<<endl;
    cin>>userDecision;
    while(userDecision == "yes")
    {
         cout<<"What is the student's name?: "<<endl;
         cin>>studentName;
         cout<<"And what is that student's id number?"<<endl;
         cin>>IDnumber;
         doubleNode* tempNode = new doubleNode;
         tempNode->name = studentName;
         tempNode->ID = IDnumber;
         tempNode->next = NULL;
         tempNode->previous = NULL;
         if(head==NULL){
            head = tempNode;
            cur = head;
         }
         else {
            tempNode->previous=cur;
            cur->next= tempNode;
            cur=tempNode;
         }

         cout<<"Do you want to add a new student?"<<endl;
         cin>>userDecision;
    }
    cur = head;
    while(cur!=NULL) {
        cout<< cur->name<<": "<<cur->ID <<endl;
        cur=cur->next;
    }
    return 0;
}

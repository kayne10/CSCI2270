#include <iostream>

using namespace std;

struct pnNode {
    int number;
    int areaCode;
    pnNode *next;
    pnNode *previous;
};




int main()
{
    string userInput;
    int phoneNumber;
    int areaCode;

    pnNode *head;
    pnNode *tail;
    head->next=new pnNode;
    head->previous=NULL;
    tail->next=NULL;
    tail->previous=new pnNode;

    cout<<"Do you want to add a new phone number?"<<endl;
    cin>>userInput;
    while(userInput=="yes")
    {
        cout<<"First, enter the area code"<<endl;
        cin>>areaCode;


    }


    return 0;
}

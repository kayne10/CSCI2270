#include <iostream>

using namespace std;

struct Node {
    int areaCode;
    int number;
    int duplicate;
    Node *left;
    Node *right;
};

void addPhoneNumber(int areaCode, int number) {
    Node *tmp = new Node;
    areaCode = tmp->areaCode;
    number = tmp->number;
    tmp->left = NULL;
    tmp->right = NULL;
}
void sortPhoneNumber(Node *root) {
    if(root->left != NULL)
    {
        sortPhoneNumber(root->left);
    }
    if(root->right != NULL)
    {
        sortPhoneNumber(root->right);
    }
}


int main()
{
    string userDecision;
    int userAreaCode;
    int userPhoneNumber;
    cout<<"Would you like to add a phone number? "<<"Enter yes or no."<<endl;
    cin>>userDecision;
    while(userDecision == "yes")
    {
        Node *root = new Node;
        root = NULL;

        //Prompting user to add Area Code and rest of Phone Number
        cout<<"Start by entering the Area Code: "<<endl;
        cin>>userAreaCode;
        cout<<"Now enter the remaining digits for the new phone number: "<<endl;
        cin>>userPhoneNumber;

        //adding Node
        addPhoneNumber(userAreaCode, userPhoneNumber); {
            Node *tmp = new Node;
            Node *parent = NULL;
            userAreaCode = parent->areaCode;
            while(tmp !=NULL)
            {
                parent = tmp;
                if(parent->areaCode < tmp->areaCode)
                {
                    tmp = tmp->left;
                }
                else
                    tmp = tmp->right;
            }
        }

        //Sort by AreaCode
        sortPhoneNumber(root);


        //Prompting user to add another phone number
        cout<<"Would you like to add another phone number?"<<endl;
        cin>>userDecision;
    }
    return 0;
}

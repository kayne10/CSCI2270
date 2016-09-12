#include <iostream>

using namespace std;

class Node {
public:
    string city;
    int dup;
    Node *left;
    Node *right;
    Node *parent;
    Node(string c, int d, Node *l, Node *r, Node *p) {city = c; dup = d; left = l;right = r; parent = p;}
};


void addCity(string city) {
    Node *tmp = new Node;
    city = tmp->city;
    Node *leftChild = new Node;
    Node *rightChild = new Node;
    leftChild = tmp->left;
    rightChild = tmp->right;
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
    string userCity;
    cout<<"Would you like to add a City? "<<"Enter yes or no."<<endl;
    cin>>userDecision;
    while(userDecision == "yes")
    {
        Node *root = new Node;
        root = NULL;

        //Prompting user to add Area Code and rest of Phone Number
        cout<<"What is the name of the city?"<<endl;
        cin>>userCity;

        //adding Node
        addCity(userCity); {
            Node *tmp = new Node;
            Node *parent = NULL;
            userCity = parent->city;
            while(tmp !=NULL)
            {
                parent = tmp;
                if(parent->city < tmp->city)
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

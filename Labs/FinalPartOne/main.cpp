#include <iostream>

using namespace std;

int totalCost = 0;
struct Node {
    string firstName;
    string lastName;
    Node *left;
    Node *right;
    int duplicate;
};

Node *mirror(Node *root) {
    Node *tmp = new Node; totalCost++;
    tmp = root;totalCost++;
    while(tmp->firstName != NULL && tmp->lastName != NULL)
    {
        if(tmp->right != NULL && tmp->right != NULL)
        {
            tmp->right = tmp->left;totalCost++;
            tmp->left = tmp->right;totalCost++;
        }
        else if(tmp->left ==NULL)
        {
            tmp->left = tmp->right;totalCost++;
        }
        else if(tmp->right ==NULL)
        {
            tmp->right = tmp->left;totalCost++;
        }
    }
}

int main()
{
    void addStudent(string firstName, string lastName);
    string userDecision;
    string userFirstName;
    string userLastName;
    cout<<"Would you like to add a student? "<<"Enter yes or no."<<endl;
    cin>>userDecision;
    while(userDecision == "yes")
    {
        cout<<"What is the student's first name?"<<endl;
        cin>>userFirstName;
        cout<<"And last name?"<<endl;
        cin>>userLastName;
        addStudent(userFirstName, userLastName); {
            Node *tmp = new Node;
            Node *parent = NULL;
            while(tmp != NULL) {
                parent = tmp;
                if(parent->lastName < tmp->lastName)
                {
                    tmp = tmp->left;
                }
                else
                    tmp = tmp->right;
            }
        }
    }
    Node *mirror(root);
    cout<<"the cost efficiency of mirror(): "<<totalCost<<endl;
    return 0;
}
//PART 3
// Yes there is a relationship, because when the  size of the tree
// differs, so does the cost efficiency of mirror(). The cost efficiency
// and size of the tree have a direct correlation relationship.
//When the size goes up or down, same with the cost efficiency.

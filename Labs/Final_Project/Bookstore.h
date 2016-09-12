#ifndef BOOKSTORE_H_INCLUDED
#define BOOKSTORE_H_INCLUDED
#include "book.h"
#include <iostream>
using namespace std;

class Bookstore {
public:
    Bookstore();
    virtual ~Bookstore();
    void printInventory(BookNode *root);
    void printBargainBook(int price);
    void printOnSale();
    void addBook(string title, string firstName, string lastName, string genre, int price, int quantity_in_stock, int ISBN_number);
    void sellBook(int ISBN_number);
    void findBook(int ISBN_number);
private:
    BookNode *root;
    int numberOfNodes;
};

Bookstore::Bookstore() {
    root = NULL;
}

Bookstore::~Bookstore() {}

void Bookstore::addBook(string title, string firstName, string lastName, string genre, int price, int quantity_in_stock, int ISBN_number) {
    BookNode *tmp = new BookNode;
    BookNode *current = new BookNode;
    current->title= title;
    current->firstName = firstName;
    current->lastName = lastName;
    current->genre = genre;
    current->price = price;
    current->quantity_in_stock = quantity_in_stock;
    current->ISBN_number = ISBN_number;
    tmp = root;
    BookNode *parent = new BookNode;
    parent = NULL;
    while(tmp!=NULL)
    {
        parent = tmp;
        if(current->lastName < tmp->lastName)
        {
            tmp = tmp->leftChild;
        }
        else
            tmp = tmp->rightChild;
    }
    current->parent = parent;
    if(parent == NULL)
    {
        root = current;
    }
    else if(current->lastName < parent->lastName)
        parent->leftChild = current;
    else
        parent->rightChild = current;
}
void Bookstore::findBook(int ISBN_number) {
    BookNode *tmp = new BookNode;
    while(tmp!=NULL)
    {
        if(tmp->ISBN_number < ISBN_number)
        {
            tmp = tmp->leftChild;
        }
        else if(tmp->ISBN_number < ISBN_number)
        {
            tmp = tmp->rightChild;
        }
        else
            return node
    }
    return NULL;
}

void Bookstore::sellBook(int ISBN_number) {
    BookNode *target = new BookNode;
    if(target == NULL) return;
    else
    {
        if(target->leftChild == NULL && target->rightChild == NULL)
        {
            if(target->parent!=NULL)
            {
                if(target->parent->leftChild != NULL && target->parent->leftChild == target)
                    target->parent->leftChild = targetChild;
                else
                    target->parent->rightChild = targetChild;
		    }
		    else
                root = targetChild;
            delete target;
            target = NULL;
        }
        else if(target->leftChild==NULL)
        {
            BookNode *targetChild = target->rightChild;
            if(target->parent!=NULL)
            {
                if(target->parent->leftChild != NULL && target->parent->leftChild == target)
                    target->parent->leftChild = targetChild;
                else
                    target->parent->rightChild = targetChild;
            }
            else
                root = targetChild;
            delete target;
            target = NULL;
        }
        else if(target->rightChild == NULL)
        {
            BookNode *targetChild = target->leftChild;
            if(target->parent != NULL) {
                if(target->parent->leftChild != NULL && target->parent->leftChild == target)
                    target->parent->leftChild = targetChild;
                else
                    target->parent->rightChild = targetChild;
		    }
		    else
                root = targetChild;
            targetChild->parent = target->parent;
            delete target;
            target = NULL;
        }
    }
    target->getQuantityInStock() = target->quantity_in_stock = quantity_in_stock--;
}

void Bookstore::printInventory(BookNode *root) {
    if(root == NULL) return;
    printInventory(root->leftChild);
    cout<<root->title<<" by: "<<root->firstName<<" "<<root->lastName<<endl;
    printInventory(root->rightChild);
}


#endif // BOOKSTORE_H_INCLUDED

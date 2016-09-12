#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <iostream>

using namespace std;


class BookNode {
private:
    string title;
    string lastName;
    string firstName;
    string genre;
    int price;
    int quantity_in_stock;
    int ISBN_number;
    BookNode *parent;
    BookNode *leftChild;
    BookNode *rightChild;
public:
    BookNode();
    string getTitle();
    string getAuthor();
    void setAuthor(string firstName, string lastName);
    void setPrice(int price);
    int getPrice();
    int getQuantityInStock();
    void setQuantityInStock(int quantity_in_stock);
    int getISBN();
    void setISBN(int ISBN_number);
    bool onSale();
};

BookNode::BookNode() {}
string BookNode::getTitle() {
    return title;
}
void BookNode::setAuthor(string firstName,string lastName) {
    BookNode *author = new BookNode;
    firstName = author->firstName;
    lastName = author->lastName;
}

string BookNode::getAuthor() {
    return setAuthor();
}

void BookNode::setPrice(int price) {
    BookNode *current = new BookNode;
    price = current->price;
}

int BookNode::getPrice() {
    return setPrice();
}

void BookNode::setQuantityInStock(int quantity_in_stock) {
    BookNode *current = new BookNode;
    quantity_in_stock = current->quantity_in_stock;
}

int BookNode::getQuantityInStock() {
    return setQuantityInStock;
}

void BookNode::setISBN(int ISBN_number) {
    BookNode *current = new BookNode;
    ISBN_number = current->ISBN_number;
}

int BookNode::getISBN();{
    return setISBN();
}
bool BookNode::onSale() {
    if(quantity_in_stock != 0) return true;
    else
        return false;
}

#endif // book_H_INCLUDED

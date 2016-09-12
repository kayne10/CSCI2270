#include <iostream>
#include <stdexcept>

using namespace std;
/*class ViolatedExcep: public logic_error                  //Part 2
{
public:
     ViolatedExcep(const string& message ""):
         logic_error("Violated Exception: " + message) {};
};

ViolatedExcep::ViolatedExcep(const string& message ""):
    logic_error("Violated Exception: " + message)
{
}
*/
class Stack1 {
private:
    int max_stack =3;
    int *items;
    int top;
public:
    Stack1();
    bool isEmpty();
    void push(int a);
    int pop();
    int peek();
    //int peek2();                //Part 2
    void traverseandPrint();
};

Stack1::Stack1() {

}

bool Stack1::isEmpty() {
    if(top==0)
    {
        return true;
    }
    else
        return false;
}
void Stack1::push(int a) {
    if(!isEmpty()) {
    items[top]=a;  //switch?
    top++;
    }
}

int Stack1::pop() {
    if(top==0) {
        cout<<"underflow error"<<endl;
    }
    else {
       top--;
    }
    return items[top];
}
int Stack1::peek() {
    return items[top];
}
void Stack1::traverseandPrint() {
    while(top!=0)
    {
        cout<<items[top]<<endl;
        top--;
    }
}
/*int Stack1::peek2() const throw(ViolatedExcep) {   //Part 2 continued
    top=top-1;
    if(isEmpty())
    {
        throw ViolatedExcep("peek2() called with empty stack.");
    }
    return items[top];
}
*/
//Part 3
class Stack2 {
private:
    int max_stack =3;
    int *items;
    int top;
public:
    Stack2();
    bool isEmpty();
    void push(int a);
    int pop();
    int peek();
    void traverseandPrint();
};

Stack2::Stack2() {
}

bool Stack2::isEmpty() {
    if(top==0)
    {
        return true;
    }
    else
        return false;
}
void Stack2::push(int a) {
    if(!isEmpty()) {
    items[top]=a;
    top++;
    }
}

int Stack2::pop() {
    if(top==0) {
        cout<<"underflow error"<<endl;
    }
    else {
       top--;
    }
    return items[top];
}
int Stack2::peek() {
    return items[top];
}
void Stack2::traverseandPrint() {
    while(top!=0)
    {
        cout<<items[top]<<endl;
        top--;
    }
}

int main()
{
    Stack1 s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.traverseandPrint();
    s1.push(4);
    s1.traverseandPrint();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.peek();    //maybe delete cout<<
    s1.pop();
    //cout<<s1.peek2();
    if(s1.isEmpty())
    {
        cout<<"S1 is empty";
    }

    Stack2 s2;
    s2.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);
    s2.traverseandPrint();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.peek();
    s2.pop();
    if(s2.isEmpty())
    {
        cout<<"S2 is empty";
    }
    return 0;
}

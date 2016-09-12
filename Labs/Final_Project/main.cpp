#include <iostream>
#include <fstream>
#include "Book.h"
#include "Bookstore.h"

using namespace std;

int main()
{
    Bookstore *BS;
    ifstream infile_smallList;
    string line_smallList;
    int line_sl;

    infile_smallList.open("small_order");
    if(infile_smallList.is_open()) {
        while(getline(infile_smallList, line_ints)) {
            line_sl = atoi(line_smallList.c_str());
            BS.addBook(line_sl);
        }
        infile_ints.close();
    }
    return 0;
}

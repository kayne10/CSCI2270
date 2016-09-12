#include <iostream>
#include "ship.h"

using namespace std;

void operation(int k)
{
    int x, y;
    cout << "Guess x" << endl;
    cin >> x;
    cout << endl;
    cout << "guess y" << endl;
    cin >> y;
    ship.shipGuess(x,y);
    k++;
}

int main()
{
    ship g;
    int k = 0;
    while(!g.allShips())
    {
        operation(k);
    }
    cout << "Congrats you win !" << endl;
    cout << "It took you " << k << " guesses" << endl;
}

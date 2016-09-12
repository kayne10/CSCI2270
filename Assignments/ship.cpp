#include "ship.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

ship::ship()
{
    bship lists[5];
    for(int i = 0; i < 5; i++)
    {
        bship *newShip = new bship;
        newShip.sunk = false;
        newShip.x = rand() % 10 +1;
        newShip.y = rand() % 10 + 1;
        lists[i] = newShip;

    }
}

void ship::shipGuess(int x, int y)
{
    for(int i = 0; i < 5; i++)
    {
        if(lists[i].x == x && lists[i].y == y)
        {
            lists[i].sunk = true;
            cout << "Nice Ship " << i << " has been sunk" << endl;
        }
        else
        {
            cout << "MISS!!" << endl;
        }
    }
}

bool ship::allShips()
{
    bool shipsStatus = false;
    int k = 0;
    for(int i =0 ; i < 5; i ++)
    {
        if(lists[i].sunk == true)
        {
            k++;
        }
    }
    if(k == 5)
    {
        shipsStatus = true;
    }
    return shipsStatus;
}


ship::~ship()
{
    //dtor
}

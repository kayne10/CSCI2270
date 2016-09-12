//Troy Kayne
//Assignment 1
//BattleShip!

#ifndef SHIP_H
#define SHIP_H
struct bship;
{
    int x;
    int y;
    bool sunk;
};

class ship
{
    public:
        ship();
        bool ship::allShips();
        void ship::shipGuess(int x, int y);
        virtual ~ship();
    protected:
    private:
        bship lists[];
};

#endif // SHIP_H

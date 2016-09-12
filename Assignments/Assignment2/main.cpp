#include <iostream>

using namespace std;

//Single Node
class MagicItem {
private:
	string value;
	MagicItem *nextNode;
public:
	MagicItem() { nextNode = NULL; };
	MagicItem(string s) { value = s; nextNode = NULL; };
	string getValue() { return value; }
	MagicItem* getNextNode() { return nextNode; }
	void setNextNode(MagicItem *newNode) { nextNode = newNode; }
};
//Double Node
class Potion {
private:
	string value;
	Potion *nextNode;
	Potion *previousNode;
public:
	Potion() { nextNode = previousNode = NULL; };
	Potion(string s) { value = s; nextNode = previousNode = NULL; };
	string getValue() { return value; }
	Potion* getNextNode() { return nextNode; }
	Potion* getPreviousNode() { return previousNode; }
	void setNextNode(Potion *newNode) { nextNode = newNode; }
	void setPreviousNode(Potion *newNode) { previousNode = newNode; }
};

//Single Linked List Pocket
class PocketOfMagic {
private:
	MagicItem *head;
	MagicItem *tail;
	int totalNodes;
public:
	PocketOfMagic();
	~PocketOfMagic();
	void revealItems();
	void addItem(string data);
	bool deleteItem(string data);
};

PocketOfMagic::PocketOfMagic() {
	head = new MagicItem();
	tail = new MagicItem();
	totalNodes = 0;
}
PocketOfMagic::~PocketOfMagic() {
	MagicItem* current = head;
	while( current != 0 ) {
		MagicItem* next = current->getNextNode();
		delete current;
		current = next;
	}
	head = 0;
}
void PocketOfMagic::revealItems(){
    cout<<"Inside the Pocket of Magic: ";
    MagicItem* tempNode= head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
        {
            cout<<tempNode<<endl;
            tempNode++;
        }
    cout<<endl;
}
void PocketOfMagic::addItem(string data){
    MagicItem *newNode= new MagicItem;
    if(head->getNextNode()==NULL)
    {
        head->getNextNode()== newNode;
        tail->getNextNode()== newNode;
    }
    else{
        tail->getNextNode()->getNextNode() == newNode;
        tail->getNextNode()==newNode;
    }
}
bool PocketOfMagic::deleteItem(string data){
    MagicItem *current = head->getNextNode();
    MagicItem *previous = NULL;
    while(current != NULL)
    {
        if(current->getValue()==data)
        {
            if(previous==NULL)
            {
                head->getNextNode()== current->getNextNode();
            }
            else {
                previous->getNextNode()== current->getNextNode();
            }
            delete current;
            return true;
        }
        previous=current;
        current =current->getNextNode();
    }
	return false;
}


//Double Linked List
class PocketOfPotions {
private:
	Potion *head;
	Potion *tail;
	int totalNodes;
public:
	PocketOfPotions();
	~PocketOfPotions();
	void revealItems();
	void addItem(string data);
	bool deleteItem(string data);
};
PocketOfPotions::PocketOfPotions() {
	head = new Potion();
	tail = new Potion();
	totalNodes = 0;
}
PocketOfPotions::~PocketOfPotions() {
	Potion* current = head;
	while( current != 0 ) {
		Potion* next = current->getNextNode();
		delete current;
		current = next;
	}
	head = 0;
}

void PocketOfPotions::revealItems() {
    cout<<"Inside the Pocket of Potions: ";
    Potion *tempNode;
    tempNode = head->getNextNode();
    while(tempNode->getNextNode()!=NULL)
    {
        cout<<tempNode<<endl;
        tempNode++;
    }
    cout<<endl;
}
void PocketOfPotions::addItem(string data) {
    Potion *newNode = new Potion;
    if(head->getNextNode()==NULL)
    {
        tail->getNextNode()== newNode;
    }
    else{
        tail->getNextNode()->getNextNode() == newNode;
        tail->getNextNode()==newNode;
    }
}
bool PocketOfPotions::deleteItem(string data) {
    Potion *current = head->getNextNode();
    Potion *previous = NULL;
    while(current != NULL)
    {
        if(current->getValue()==data)
        {
            if(previous==NULL)
            {
                head->getNextNode()== current->getNextNode();
            }
            else {
                head->getNextNode()== previous->getNextNode();
            }
            delete current;
            return true;
        }
        previous=current;
        current =current->getNextNode();
    }
	return false;
}

//Dynamically Allocated Array
class PocketOfGoods
{
private:
    string goods[40];
    int itemCount;
    static const int maxItems=40;
public:
    PocketOfGoods();
    bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
    void showItem();
};
PocketOfGoods::PocketOfGoods()
{
}
bool PocketOfGoods::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}

	return hasRoomToAdd;
}
bool PocketOfGoods::remove(const ItemType& newEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}

	return canRemoveItem;
}
void PocketOfGoods::showItem() {
for(i=0;i<size;i++) {
    cout<<goods[i]<<endl;
}
}

void testingPocketofMagic() {
	int decision;
	PocketOfMagic pom;

	cout<<"What do you choose to do?"<<endl;
	cout<<endl;
	cout<<"1. Keep item (add item to pocket)"<<endl;
	cout<<"2. Dismiss item (remove item from pocket)"<<endl;
	cout<<"3. Reveal all items in pocket"<<endl;
	cout<<"4. Retreat (Go back to main menu)"<<endl;
	cin>> decision;
	if(decision==1)
    {
        string item;
        cout<<"What would you like to add in Pocket of Magic?"<<endl;
        cin>> item;
        cout<<item<<" is added to Pocket of Magic!"<<endl;
        pom.addItem(item);
    }
	else if(decision==2)
    {
        string item;
        cout<<"What would you like to take from Pocket of Magic?"<<endl;
        cin>> item;
        cout<<item<<" is removed from Pocket of Magic!"<<endl;
        pom.deleteItem(item);
    }
    else if(decision==3)
    {
        pom.revealItems();
    }
    else {
        //go back to main menu
    }
}

void testingPocketofPotions()
{
    int decision;
    PocketOfPotions pop;

    cout<<"What do you choose to do?"<<endl;
    cout<<endl;
    cout<<"1. Keep item (add item to pocket)"<<endl;
	cout<<"2. Dismiss item (remove item from pocket)"<<endl;
	cout<<"3. Reveal all items in pocket"<<endl;
	cout<<"4. Retreat (Go back to main menu)"<<endl;
	cin>> decision;
	if(decision==1)
    {
        string item;
        cout<<"What would you like to add in Pocket of Potions?"<<endl;
        cin>> item;
        cout<<item<<" is added to Pocket of Potions!"<<endl;
        pop.addItem(item);
    }
	else if(decision==2)
    {
        string item;
        cout<<"What would you like to take from Pocket of Potions?"<<endl;
        cin>> item;
        cout<<item<<" is removed from Pocket of Potions!"<<endl;
        pop.deleteItem(item);
    }
    else if(decision==3)
    {
        pop.revealItems();
    }
    else {
        //go back to main menu
    }
}
/*
void testingPocketofGoods() {
int decision;
    PocketOfGoods pog;

    cout<<"What do you choose to do?"<<endl;
    cout<<endl;
    cout<<"1. Keep item (add item to pocket)"<<endl;
	cout<<"2. Dismiss item (remove item from pocket)"<<endl;
	cout<<"3. Reveal all items in pocket"<<endl;
	cout<<"4. Retreat (Go back to main menu)"<<endl;
	cin>> decision;
	if(decision==1)
    {
        string item;
        cout<<"What would you like to add in Pocket of Potions?"<<endl;
        cin>> item;
        cout<<item<<" is added to Pocket of Potions!"<<endl;
        pog.add(item);
    }
	else if(decision==2)
    {
        string item;
        cout<<"What would you like to take from Pocket of Potions?"<<endl;
        cin>> item;
        cout<<item<<" is removed from Pocket of Potions!"<<endl;
        pog.remove(item);
    }
    else if(decision==3)
    {
        pog.showItem();
    }
    else {
        //go back to main menu
    }
}
*/
int main()
{
int pocketChoice;
int i;
cout<<"Welcome Adventurer to the game of holding. You will need to be careful on your journey."<<endl;
cout<<endl;
cout<<"Which pocket do you want to access?"<<endl;
cout<<"1. Pocket of Magic"<<endl;
cout<<"2. Pocket of Potions"<<endl;
cout<<"3. Pocket of Goods"<<endl;
cout<<"4. Exit Game"<<endl;
cin>> pocketChoice;
while(pocketChoice!=4) {
    if(pocketChoice==1) {
        testingPocketofMagic();
    }
    else if(pocketChoice==2) {
        testingPocketofPotions();
    }
    else {
        //testingPocketofGoods();
    }
}
cout<<"Good Luck on your travels adventurer!"<<endl;
    return 0;
}

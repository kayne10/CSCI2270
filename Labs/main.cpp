#include <iostream>
#include "BagInterface.h"

using namespace std;
#include <cstddef>

typedef int ItemType;


/* **************************************************************** */
/*					DECLERATION OF ARRAYBAG CLASS					*/
/* **************************************************************** */
template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 20; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items
	int maxItems;                          // Max capacity of the bag

   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain
   // the target.
   int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	bool remove2(const ItemType& anEntry);
	bool removeAll(const ItemType& anEntry);
	bool doubleAndPopulate(int n);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;

	bool remove2(const ItemType& anEntry);
	bool removeAll(const ItemType& anEntry);
	bool doubleAndPopulate(int n);

}; // end ArrayBag




/* ******************************************************************** */
/*					IMPLEMENTATION OF ARRAYBAG CLASS					*/
/* ******************************************************************** */
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if

      curIndex++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;

   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      }
      else
      {
         searchIndex++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf


/* code */
template<class ItemType>
bool remove2(const ItemType& anEntry) {
	return true;
}

template<class ItemType>
bool removeAll(const ItemType& anEntry) {
	return true;
}

template<class ItemType>
bool doubleAndPopulate(int n) {
	return true;
}







/* ************************************************ */
/*					TEST FUNCTIONS					*/
/* ************************************************ */

void displayBag(ArrayBag<ItemType>& bag) {
	cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
	vector<int> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	for (int i = 0; i < numberOfEntries; i++) {
		cout << bagItems[i] << " ";
	}
	cout << endl << endl;
}


void bagTesterIni(ArrayBag<ItemType> bag) {
	cout << "---------- Initial testing of the Array-Based Bag ----------" << endl;
	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
	displayBag(bag);

	int items[] = {1, 2, 3, 4, 5, 1};
	cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++) {
		bag.add(items[i]);
	}
	displayBag(bag);

	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;
	cout << "Try to add another entry: add(3) returns " << bag.add(3) << endl;
	cout << endl;
}

// tester function for the first homework problem
void bagTesterProblem1(ArrayBag<ItemType> bag) {
	cout << "---------- Testing of Problem 1 ----------" << endl;
	displayBag(bag);

	int items[] = {10, 20, 30, 40, 50};
	cout << "Add 5 items to the bag: " << endl;
	for (int i = 0; i < 5; i++) {
		bag.add(items[i]);
	}
	displayBag(bag);

	cout << "remove2(30): returns " << bag.remove2(30) << "; should be 1 (true)" << endl;
	cout << "new bag looks like: ";
	displayBag(bag);
	cout << "; should look like [10, 20, 40, 50]" << endl;
	cout << endl;
}

// tester function for the second homework problem
void bagTesterProblem2(ArrayBag<ItemType> bag) {
	cout << "---------- Testing of Problem 2 ----------" << endl;
	displayBag(bag);

	int items[] = {10, 20, 20, 30, 40, 20, 50};
	cout << "Add 7 items to the bag: " << endl;
	for (int i = 0; i < 7; i++) {
		bag.add(items[i]);
	}
	displayBag(bag);

	cout << "removeAll(20): returns " << bag.removeAll(30) << "; should be 1 (true)" << endl;
	cout << "new bag looks like: ";
	displayBag(bag);
	cout << "; should look like [10, 30, 40, 50]" << endl;
	cout << endl;
}

// tester function for the third homework problem
void bagTesterProblem3(ArrayBag<ItemType> bag) {
	cout << "---------- Testing of Problem 3 ----------" << endl;
	displayBag(bag);

	int items[] = {4, 2, 5};
	cout << "Add 3 items to the bag: " << endl;
	for (int i = 0; i < 3; i++) {
		bag.add(items[i]);
	}
	displayBag(bag);

	cout << "doubleAndPopulate(2): returns " << bag.doubleAndPopulate(2) << "; should be 1 (true)" << endl;
	cout << "new bag looks like: ";
	displayBag(bag);
	cout << "; should look like [4, 2, 5, 8, 4, 10, 8, 4, 10, 16, 8, 20]" << endl;
	cout << endl;
}



/* ************************************************ */
/*					MAIN FUNCTION					*/
/* ************************************************ */

int main()
{
	ArrayBag<ItemType> bag;

	// test the initial bag
	// this function should work when you first download this code
	bagTesterIni(bag);

	// test your problem 1
	bagTesterProblem1(bag);

	// test your problem 2
	bagTesterProblem2(bag);

	// test your problem 3
	bagTesterProblem3(bag);

	return 0;
}

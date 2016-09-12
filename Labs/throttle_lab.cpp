#include <iostream>

using namespace std;

class Throttle{
	private:
	   int position;
	   int static const position_max = 10;
	   int static const position_min=0;
	public:
	   Throttle();
	   Throttle(int pos);
		Throttle(const Throttle& t);
	   ~Throttle();
	      void shutoff();
	      void shift(int amount);
	      int getPosition();
	   double flow();
	   bool is_on();
	   bool isAboveHalfway();
	   bool operator<(const Throttle& t);
	   bool operator>(const Throttle& t);
	   void operator = (const Throttle& t);
   };


Throttle::Throttle()
{
	position = 0;
}

Throttle::Throttle(int pos) {
	position = pos;
}

Throttle::Throttle(const Throttle& t) {
	position = t.position;
}

Throttle::~Throttle() {
	position = 0;
}

void Throttle::shutoff() {
	position = 0;
}

void Throttle::shift(int amount) {
	position += amount;
	if(position > 10)
	   position = 10;
	if(position < 0)
	   position = 0;
}

int Throttle::getPosition(){
	return position;
}

double Throttle::flow() {
	return ( (double)position / position_max);
}

bool Throttle::is_on() {
	return (position > 1);
}

bool Throttle::isAboveHalfway() {
	return (flow() > .5);
}

bool Throttle::operator <(const Throttle& t) {
	return (position < t.position);
}

bool Throttle::operator >(const Throttle& t) {
	return (position > t.position);
}

void Throttle::operator =(const Throttle& t) {
	position = t.position;
}



int main()
{
	Throttle t1;
	cout<< t1.flow();
	t1.shift(6);

	Throttle t2(4);
	t2.shift(3);
	cout<< t2.flow();

	t1= t2;
	cout<<t1.flow()<<t2.flow();
	t1.shift(-20);
	t2.shift(2);
	cout<< t1.flow()<<t2.flow();

	if(t2.isAboveHalfway())
	   cout<< "t2 is above halfway. ";
	if(t1<t2)
	   cout<< "t1 has less flow than t2. ";
	t1.shift(10);
	if(t1>t2)
	   cout<<"t2 has less flow than t1. ";


	return 0;
}


#include <iostream>
using namespace std;

class halfadder
{
public:
	int in1;
	int in2;
	int out;
	int carryout1;

	void setin1(int w)
	{
		in1 = w;
	}

	void setin2(int h)
	{
		in2 = h;
	}

	int thecarryout(void)
	{
		return in1 & in2;
	}

	int thesum(void)
	{
		return in1 ^ in2;
	}
};

class fulladder : public halfadder
{
public:
	int carryin;
	int sum;
	int carryout;

	fulladder()
	{
		in1 = thesum();
		in2 = thecarryout();
	}

	int setcarryin(int a)
	{
		carryin = a;
	}

	int thecarryout1(void)
	{
		return (in1 & in2) | thesum(); 
	}

	int thesum1(void)
	{
		return thesum() ^ carryin;
	}
};

int main(void)
{
	class fulladder halfaddertemp;

	int index2 = 0;
	int index3 = 0;
	int index4 = 0;

	index2 = 2;
	index3 = 2;
	index4 = 2;

	while(index2 < 0 || index2 > 1)
	{
		cout << "Enter 0 or 1: ";
		cin >> index2;
	}

	while(index3 < 0 || index3 > 1)
	{
		cout << "Enter 0 or 1: ";
		cin >> index3;
	}

	while(index4 < 0 || index4 > 1)
	{
		cout << "Enter 0 or 1: ";
		cin >> index4;
	}

	halfaddertemp.setin1(index2);
	halfaddertemp.setin2(index3);
	halfaddertemp.setcarryin(index4);
	cout << "The sum is " << halfaddertemp.thesum1() << endl;
	cout << "The carryout is " << halfaddertemp.thecarryout1() << endl;

	cout << endl;

	return 0;
}


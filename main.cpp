#include <iostream>
using namespace std;

class halfadder
{
public:
	void setin1(int w)
	{
		in1 = w;
	}

	void setin2(int h)
	{
		in2 = h;
	}

	int getin1(void)
	{
		return in1;
	}

	int getin2(void)
	{
		return in2;
	}

protected:
	friend class fulladder;
	int thecarryout(void)
	{
		return in1 & in2;
	}

	int thesum(void)
	{
		return in1 ^ in2;
	}

private:
	int in1;
	int in2;
};

class fulladder : public halfadder
{
public:
	fulladder()
	{
		in1 = thesum();
		in2 = thecarryout();
	}

	void setcarryin(int a)
	{
		carryin = a;
	}

	int getcarryin(void)
	{
		return carryin;
	}

	int thecarryout1(void)
	{
		return (in1 & in2) | thesum(); 
	}

	int thesum1(void)
	{
		return thesum() ^ carryin;
	}

private:
	int carryin;
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
		cout << "Enter 0 or 1 for in1: ";
		cin >> index2;
	}

	while(index3 < 0 || index3 > 1)
	{
		cout << "Enter 0 or 1 for in2: ";
		cin >> index3;
	}

	while(index4 < 0 || index4 > 1)
	{
		cout << "Enter 0 or 1 for carryin: ";
		cin >> index4;
	}

	halfaddertemp.setin1(index2);
	halfaddertemp.setin2(index3);
	halfaddertemp.setcarryin(index4);
	cout << "The sum is " << halfaddertemp.thesum1() << endl;
	cout << "The carryout is " << halfaddertemp.thecarryout1() << endl;

	cout << "The in1 is " << halfaddertemp.getin1() << endl;
	cout << "The in2 is " << halfaddertemp.getin2() << endl;
	cout << "The carryin is " << halfaddertemp.getcarryin() << endl;
	
	cout << endl;

	return 0;
}


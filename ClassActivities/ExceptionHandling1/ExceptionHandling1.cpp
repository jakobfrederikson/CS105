// testing function with throw capability

#include <iostream>
using namespace std;

void a(int i)throw(int, char, double)
{
	if (i == 0)
		throw i;
	if (i == 1)
		throw 'a';
	if (i == 2)
		throw 55.33;
}

int main()
{
	cout << "Start!\n";
	try
	{
		a(1);
	}
	catch (int i)
	{
		cout << "Caught an int = " << i << "\n";
	}
	catch (char j)
	{
		cout << "Caught a char = " << j << "\n";
	}
	catch (double c)
	{
		cout << "Caught a double = " << c << "\n";
	}
	cout << "End!\n";
	return 0;
}


#include <iostream>
//#include <string> //<-- also seems to work without string
#include <sstream>
//#include <istream> //<-- Do I need to include istream? seems to work without it

using namespace std;

int GetValue(int& ValueValidated);
void PrintRow(int iNumOne, int iNumTwo, int iNumThree, int iNumFour, int iNumFive);

int main()
{
	int iNumOne, iNumTwo, iNumThree, iNumFour, iNumFive;
	int ValueValidated;
	
	iNumOne = GetValue(ValueValidated);
	iNumTwo = GetValue(ValueValidated);
	iNumThree = GetValue(ValueValidated);
	iNumFour = GetValue(ValueValidated);
	iNumFive = GetValue(ValueValidated);

	PrintRow(iNumOne, iNumTwo, iNumThree, iNumFour, iNumFive);

	cout << endl;

	exit(0);
}

int GetValue(int& ValueValidated)
{
	string Value;
	string CleanValue;
	int InputLength;
	int i = 0;
	char PositionCheck;
	stringstream ss;
	bool Loopy = true;


	while (Loopy == true)
	{
		cout << "Enter a number between 0 and 10 (inclusive): ";
		getline(cin, Value);
		InputLength = (Value.length());

		if (InputLength > 0)
		{
			while (i < (InputLength))
			{
				PositionCheck = Value.at(i);
				if (isdigit(PositionCheck))
				{
					CleanValue = CleanValue + PositionCheck;
					++i;
				}
				else
				{
					cout << "Invalid Value. Try again." << endl;
					cin.clear();
					Value = "";
					i = 0;
					PositionCheck = 0;
					CleanValue = "";
					break;
				}
			}
			if (i == InputLength)
			{
				ss << CleanValue;
				ss >> ValueValidated;

				if ((ValueValidated < 0) || (ValueValidated > 10))
				{
					cout << "Invalid Value. Try again." << endl;

					i = 0;
					cin.clear();
					ss.clear();
					ss.str("");
					Value = "";
					CleanValue = "";
					InputLength = 0;
					PositionCheck = 0;
					ValueValidated = 0;
				}
				else
				{ 
					return ValueValidated;
					
				}
			}
		}
		else
		{
			cout << "Invalid Value. Try again." << endl;

			i = 0;
			cin.clear();
			ss.clear();
			ss.str("");
			Value = "";
			CleanValue = "";
			InputLength = 0;
			PositionCheck = 0;
			ValueValidated = 0;
		}
	}	//need to use the clearing lines here somewhere to get rid of IDE 'control path' wanrning?
return (0);
}

void PrintRow(int iNumOne, int iNumTwo, int iNumThree, int iNumFour, int iNumFive)
{
	for (int x = iNumOne; 0 < x; x--)	//	for (int y = 0; y < 1; y++) {the following 'for's go inside of here} if i want it to loop more than once
	{
		cout << "*";
	}
	cout << endl; 

	for (int x = iNumTwo; 0 < x; x--)
	{
		cout << "*";
	}
	cout << endl;

	for (int x = iNumThree; 0 < x; x--)
	{
		cout << "*" ;
	}
	cout << endl;

	for (int x = iNumFour; 0 < x; x--)
	{
		cout << "*";
	}
	cout << endl;

	for (int x = iNumFive; 0 < x; x--)
	{
		cout << "*";
	}
}
	

	

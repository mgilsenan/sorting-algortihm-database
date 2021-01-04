#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* This program is written by Maryam Gilsenan.
The program begins, by opening the file of employees.dat. The function Sort_ID is called to sort the file contents by employee number.
The second function Sort_LN is called to sort contents alphabetically by employee's last name. All requirements mentioned in the readme have been met successfully.
*/

namespace {
	//The operator () has been overloaded to add additional functionalities that can compare 2 string to return sorted employees last name and number. 
	
	struct ID_cmp {
		bool operator()(const string& str1, const string& str2)
		{
			return (str1.substr(0, str1.find_first_of(',')) < str2.substr(0, str2.find_first_of(','))); //Range of comparison starts at position 0 to position before first ',' indicating the employee's number.
		}
	};

	struct LN_cmp {
		bool operator()(const string& str3, const string& str4)
		{
			int found1, found2;
			for (int i = 0; i < str3.size(); i++)
			{
				if (str3[i] == ' ')  //if statement used to check for spaces in the file.
				{
					found1 = i + 1; //value "found1" is used to indicate beginning position of the employees last name.
				}
			}
			for (int i = 0; i < str4.size(); i++)
			{
				if (str4[i] == ' ')
				{
					found2 = i + 1;  
				}
			}
			return (str3.substr(found1) < str4.substr(found2)); //Range of comparison starts at first position of employees last name till the end of the string (line).
		}
	};
}

void Sort_ID(std::ifstream& arg1)
{
	vector<string> IDs;
	string line;
	if (arg1) { //Verify the file opens (evaluating to true), else output error message.
		while (getline(arg1, line)) 
		{
			if (line[0] == '#') { //check for # to ignore comments
			}
			else {
				IDs.push_back(line); //else, employees information get stored into vector<string> ID.
			}
		}
		sort(IDs.begin(), IDs.end(), ID_cmp());
		for (vector<string>::iterator it1 = IDs.begin(); it1 != IDs.end(); ++it1)
		{
			cout << *it1 << '\n'; //output is extracted from vector<string> ID
		}
	}
	else {
		cout << "Failure to open file." << endl;
	}
}

void Sort_LN(std::ifstream& arg2)
{
	vector<string> LNames;
	string line;
	if (arg2) //Verify the file opens (evaluating to true), else output error message.
	{
		while (getline(arg2, line))
		{
			if (line[0] == '#') { //check for # to ignore comments
			}
			else {
				LNames.push_back(line); //else, employees information get stored into vector<string> LNames
			}
		}
		sort(LNames.begin(), LNames.end(), LN_cmp());
		for (vector<string>::iterator it2 = LNames.begin(); it2 != LNames.end(); ++it2)
		{
			cout << *it2 << '\n'; //output is extracted from vector<string> LNames
		}
	}
	else {
		cout << "Failure to open file." << endl;
	}
}


int main()
{
	ifstream infile1("employees.dat");
	ifstream infile2("employees.dat");
	cout << "Processing by employee number..." << endl;
	Sort_ID(infile1);
	cout << endl;
	cout << "Processing by last (family) Name..." << endl;
	Sort_LN(infile2);
	cout << endl;
	infile1.close();
	infile2.close();
	return 0;
}
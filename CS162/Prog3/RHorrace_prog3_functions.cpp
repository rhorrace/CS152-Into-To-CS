#include "RHorrace_prog3.h"

//Horrace, Robert CS162
/*
   This program is designed to implement the functions named in the .h file
   The functions will prompt the user for information.
   The functions will also store the info into an external data file.
 */

void insert_data(char name[], int & age, char height[], int & weight, char talent[], char availability[])
{
	cout << "Enter name(ex. John Doe):";
	cin.get(name,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter age(ex. 21):";
	cin >> age;
	cin.ignore(100,'\n');
	cout << "Enter height(ex. 5'2):";
	cin.get(height,HGT,'\n');
	cin.ignore(100,'\n');
	cout << "Enter weight in pounds(ex. 153):";
	cin >> weight;
	cin.ignore(100,'\n');
	cout << "Enter talent(s) (ex. sing, dance):";
	cin.get(talent,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter availability(ex. evenings only):";
	cin.get(availability,SIZE,'\n');
	cin.ignore(100,'\n');
}
void write_file(char nm[], int & yr, char hght[], int & wght, char tlnt[], char avlblty[])
{
	ofstream fout;
	fout.open("talent.txt",ios::app);
	if(fout)
	{
		fout << nm << ":" << yr << ":" << hght << ":" << wght << ":" << tlnt << ":" << avlblty << endl;
	}
	fout.close();
	fout.clear();
}
//void read_file(char nm[], int & yr, char hght[], int & wght, char tlnt[], char avlblty[])
//{
//}
void display(person & prsn)
{
	cout << prsn.name << endl;
	cout << prsn.age << endl;
	cout << prsn.height << endl;
	cout << prsn.weight << endl;
	cout << prsn.talent << endl;
	cout << prsn.availability << endl;
}

#include "RHorrace_prog3.h"

//Horrace, Robert CS162
/*
   This program is designed to call functions.
   The program will be calling functions in order
   to insert a person's data into a file.
   It will also read in the file.
 */

int main()
{
	person prsn[SIZE];
	int a = 0;
	char temp[SIZE];
	char response;
	ifstream fin;
	fin.open("talent.txt");
	if(fin)
	{
		if(!fin.eof())
		{
			while(fin.peek() != -1)
			{
				fin.get(prsn[a].name,SIZE,':');
				fin.ignore(100, ':');
				fin >> prsn[a].age;
				fin.ignore(100, ':');
				fin.get(prsn[a].height,HGT,':');
				fin.ignore(100, ':');
				fin >> prsn[a].weight;
				fin.ignore(100, ':');
				fin.get(prsn[a].talent,SIZE,':');
				fin.ignore(100, ':');
				fin.get(prsn[a].availability,SIZE,'\n');
				fin.ignore(100, '\n');
				++a;
			}
		}

	}
	do{
		cout << "Add an applicant to the list?(Y/N):";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
	{
		do{
			insert_data(prsn[a].name,prsn[a].age,prsn[a].height,prsn[a].weight,prsn[a].talent,prsn[a].availability);
			write_file(prsn[a].name,prsn[a].age,prsn[a].height,prsn[a].weight,prsn[a].talent,prsn[a].availability);
			do{
				cout << "Another applicant(Y/N):";
				cin >> response;
				cin.ignore(100,'\n');
				response = toupper(response);
			}while(response != 'Y' && response != 'N');
			if(response == 'Y')
				++a;
		}while(response == 'Y');
	}
	do{
	cout << "Search by talent?(Y/N):";
	cin >> response;
	cin.ignore(100,'\n');
	response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
	{
		cout << "enter talent:";
		cin.get(temp,SIZE,'\n');
		cin.ignore(100,'\n');
		for(int i = 0; i < a; ++i)
		{
			if(strcmp(temp,prsn[i].talent) == 0)
			{
				display(prsn[i]);
			}
		}
	}
	do{
		cout << "Display all?(Y/N):";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
	{
		for(int j = 0; j <= a; ++j)
		{
			display(prsn[j]);
		}
	}
	return 0;
}

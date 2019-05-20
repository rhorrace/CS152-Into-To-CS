#include <iostream>
#include <cctype>
#include <cstring>

//Horrace, Robert CS162

/*
   This program is designed to creat a password.
   The program will then test how strong the password.
   This program will be operated using prototypes.
 */

using namespace std;

const int SIZE = 41;//size limit for most arrays
const int YEAR = 5;//for the birthyear array
void insert_info(char last[],char pet[],char birth[], char & num);//inserts info
int testlength(char code[]);//tests the length of the password
int testchar(char code[]);//tests for an uppercase letter and if beginning starts with letter
int testnum(char code[]);//tests for a number
int testsym(char code[]);//tests for a symbol
int testspace(char code[]);//test for spaces and tabs
int error(int & a, int & b, int & c, int & d);//displays errors if any
int teststrength(char code[], char nm[], char anml[], char birth[], char num);//tests for any info in password
int strengtherror(int & strngth, int & sz);//displays any errors in strength + size
void display(char code[]);//displays password
int main()
{
	char name[SIZE];//last name
	char animal[SIZE];//pet name
	char birthday[YEAR];//birthyear
	char favorite;//favorite number
	char password[SIZE];//passowrd
	int size = 0;//return for testlength
	int letter = 0;//return for testchar
	int number = 0;//return for testnum
	int symbol = 0;//return for testsym
	int space = 0;//return for testspace
	int check = 0;//return for error
	int loop = 0;//for the password attempts
	int strength = 0;//return for teststrength
	int choice = 0;//return for strengtherror
	cout << "Welcome to the password generator" << endl;//Welcomes user
	cout << "Please enter a password and the generator " << endl;
	cout << "will determine the strength of your password." << endl;
	insert_info(name,animal,birthday,favorite);//inserts info
	do{
		do{
			cout << "Enter your password(less than 40 characters):";
			cin.get(password,SIZE,'\n');//enters password into variable
			cin.ignore(100,'\n');
			size = testlength(password);//calls testlength function
			letter = testchar(password);//calls testchar function
			number = testnum(password);//calls testnum function
			symbol = testsym(password);//calls testsym function
			space = testspace(password);//calls testspace function
			check = error(letter,number,symbol,space);//calls error function
			++loop;//adds one to loop variable
		}while(check >= 1 && loop < 5);//loops if check is greater or equal to 1 and loop is less than 5
		strength = teststrength(password,name,animal,birthday,favorite);//calls teststrength function
		choice = strengtherror(strength, size);//calls strengtherror function
	}while(choice == 1);//loops if choice is 1
	display(password);//calls display function
	cout << "Farewell." << endl << endl << endl;//bids user farewell
}
void insert_info(char last[],char pet[],char birth[], char & num)//inserts user's info
{
	cout << "Insert your last name:";
	cin.get(last,SIZE,'\n');//for last name
	cin.ignore(100,'\n');
	cout << "Insert pet/former pet name:";
	cin.get(pet,SIZE,'\n');//for pet name
	cin.ignore(100,'\n');
	cout << "Insert birth year(ex. 1999):";
	cin.get(birth,YEAR,'\n');//for birthyear
	cin.ignore(100, '\n');
	do{
		cout << "Insert favorite number(0-9):";
		cin >> num;//for favorite number
		cin.ignore(100,'\n');
	}while(!isdigit(num));//loops if num isn't a number
}
int testlength(char code[])//test the length of password
{
	if(strlen(code) < 10)
	{
		return 0;//returns 0 if code is less than 10 characters
	}
	if(strlen(code) >= 10 && strlen(code) < 20)
	{
		return 1;//returns 1 if code is between 10 and 20 characters
	}
	if(strlen(code) >= 20 && strlen(code) < 30)
	{
		return 2;//returns 2 if code is between 20 and 30 characters
	}
	if(strlen(code) >= 30 && strlen(code) <= 40)
	{
		return 3;//returns 3 if code is between 30 and 40 characters
	}
}
int testchar(char code[])//tests for a uppercase char and if first index is a char
{
	int temp = 0;//temp variable
	int a = strlen(code);//for for loop
	if(!isalpha(code[0]))
	{
		return temp;//returns temp(0) if first index isn't a letter
	}
	else if(isalpha(code[0]))
	{
		for(int i = 0; i < a; ++i)
		{	
			if(isupper(code[i]))
			{
				temp = 1;//temp is 1 if the index is an uppercase letter
			}
		}
	}
	return temp;//returns temp(0 or 1) depending on for loop
}
int testnum(char code[])//tests for at least one number
{
	int temp = 0;//temp variable
	int a = strlen(code);//for for loop
	for(int i = 0; i < a; ++i)
	{
		if(isdigit(code[i]))
		{
			temp = 1;//temp is 1 if index is a number
		}
	}
	return temp;//returns temp(0 or 1) depending if there is/isn't a number
}
int testsym(char code[])//tests for at least one symbol
{	
	int temp = 0;//temp variable
	int a = strlen(code);//for for loop
	for(int i = 0; i < a; ++i)
	{
		if(ispunct(code[i]) && !isspace(code[i]))
		{
			temp = 1;//temp is 1 if index is a symbol(nonalphanumeric)
		}
	}
	return temp;//returns temp(0 or 1) depending on for loop
}
int testspace(char code[])//tests for any spaces
{
	int temp = 0;//temp variable
	int a = strlen(code);//for for loop
	for(int i = 0; i < a; ++i)
	{
		if(isspace(code[i]))
		{
			temp = 1;//if index is a space, temp is 1
		}
	}
	return temp;//returns temp(0 or 1) depending on for loop
}
int error(int & a, int & b, int & c, int & d)//displays errors if any
{
	if(a == 0 || b == 0 || c == 0 || d == 1)
	{
		cout << "Error" << endl;

		if(a == 0)//if there are no uppercase letters and/or first index isn't a letter
		{
			cout << "Password must start with a letter and password" << endl;
			cout << "must have at least one uppercased letter." << endl;
		}
		if(b == 0)//if there isn't any number
		{
			cout << "Password must have at least one number." << endl;
		}
		if(c == 0)//if there isn't a symbol
		{
			cout << "Password must have at least one symbol." << endl;
		}
		if(d == 1)//if there is a tab or space
		{
			cout << "Password can't have any spaces or tabs." << endl;
		}
		return 1;//returns 1 if there are errors
	}
	else
	{
		return 0;//returns 0 if there aren't any errors
	}
}
int teststrength(char code[], char nm[], char anml[], char birth[], char num)//tests the strength of password
{
	int temp = 0;//temp variable
	int cnt = strlen(anml);//variable for length of pet name
	int brth = strlen(birth);//variable for length of birthyear
	int count = strlen(code);//variable for length of passwod
	int a = 0;//for counting letters of pet name
	if(code[0] == nm[0])
	{
		cout << "First letter of last name appears at the beginning." << endl;
		cout << "Suggest a different password." << endl;
		++temp;//adds one to temp if first character is the same as the first letter of the last name
	}
	for(int i = 0; i < count; ++i)
	{
		if(code[i] == anml[a])
		{
			++a;
		}
		if(a == cnt)
		{
			cout << "Letters of pet name show up contiguously." << endl;
			cout << "Suggest a different password." << endl;
			++temp;//adds one to temp if pet name shows up in password
			i = count;
		}
	}

	for(int j = 0; j < cnt; ++j)
	{
		if(code[j] == birth[0] && code[j+1] == birth[1] && code[j+2] == birth[2] && code[j+3] == birth[3] || code[j] == birth[2] && code[j+1] == birth[3])
		{
			cout << "Birthyear appears in the password." << endl;
			cout << "Suggest a different password." << endl;
			++temp;//adds one to temp if whole birth year is in password or last two digits of birthyear is in password
			j = cnt;
		}
	}
	for(int k = 0; k < cnt; ++k)
	{
		if(code[k] == num)
		{
			k = cnt;
			cout << "Favorite number appears in the password." << endl;
			cout << "Suggest a different password" << endl;
			++temp;//adds one to temp if favorite number shows up in password
		}
	}
	return temp;//returns value of temp(0/1/2/3/4)
}
int strengtherror(int & strngth, int & sz)//displays error for strength od password
{
	char temp;
	if(strngth >= 2)//if strength value is over two(higher the number, the weaker)
	{
		cout << "Your password is too weak." << endl;
		cout << "I suggest a different password." << endl;
	}
	if(sz <= 1)//if password is too short
	{
		cout << "Your password is weak by length." << endl;
		cout << "I suggest a longer password." << endl;
	}
	if(strngth < 2 && sz > 1)//if password is just fine
	{
		return 0;
	}
	if(strngth >= 2 || sz <= 1)//if length or strength is too weak
	{
		do{
			cout << "Change your password?(Y/N):";
			cin >> temp;
			temp = toupper(temp);
		}while(temp != 'N' && temp != 'Y');
		if(temp == 'N')
			return 0;//returns 0 if user says no
		if(temp == 'Y')
			return 1;//returns 1 if user says yes
	}
}
void display(char code[])//displays password
{
	char temp;
	do{
		cout << "Display password?(Y/N):";
		cin >> temp;
		temp = toupper(temp);
	}while(temp != 'N' && temp != 'Y');
	if(temp == 'Y')
	{
		cout << endl << code << endl;//displays password if user says yes
	}


}

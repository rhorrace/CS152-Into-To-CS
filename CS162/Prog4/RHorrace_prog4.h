#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100;
class activity//class for a single activity
{
	public:
		activity();//activity constructor
		~activity();//activity destructor
		void insert(char act[],char des[], char loc[], float dis, char sug[]);//inserts into activity variables
		void check_dis(float dist);//checks distance
		void display();//displays variables
	private:
		char * actvty;//activity name pointer
		char * dscrptn;//activity description pointer
		char * lctn;//activity location pointer
		float  dstnce;//distance in miles
		char * sggstns;//activity suggestions pointer
};
class activities//class for list of activities
{
	public:
		activities();//activities constructor
		~activities();//activities destructor
		int set_list(int & set);//sets the length of the list of activities
		int insert(char act[],char des[], char loc[], float dis, char sug[], int & set);//inserts data into one activity at a time
		void check_dis(float dist);//checks distance for all entered activities
		void display();//displays all entered activities
	private:
		activity * actvties;//activity pointer
		int amnt;//amount of activities
};

int amount(activities & actvties);//sets amount of activities

int insert(activities & actvties, int & sz);//inserts data for the activities

void check_dis(activities & actvties);//checks for activities within range

void display(activities & actvties);//displays all activities


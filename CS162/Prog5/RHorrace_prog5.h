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
		int check_act(char act[]);
		void check_dis(float dist);//checks distance
		void display();//displays variables
	private:
		char * actvty;//activity name pointer
		char * dscrptn;//activity description pointer
		char * lctn;//activity location pointer
		float  dstnce;//distance in miles
		char * sggstns;//activity suggestions pointer
};
struct node
{
	activity data;
	node * next;
	
};
class activities//class for list of activities
{
	public:
		activities();//activities constructor
		~activities();//activities destructor
		int insert(char act[],char des[], char loc[], float dis, char sug[]);//insert wrapper function
		int insert(node *& head,char act[],char des[], char loc[], float dis, char sug[]);//inserts into activity variables recursively
		int check_dis(float dis);//check_dis wrapper function
		int check_dis(node * head, float dis);//checks each node for an activity within a certain mileage
		int count();//count wrapper function
		int count(node * head);//counts all nodes
		int display_all();//display_all wrapper function
		int display_all(node * head);//displays all nodes
	private:
		node * head;//activity node pointer
};

int insert(activities & actvties);//inserts data for the activities

void check_dis(activities & actvties);//checks for activities within range

void display(activities & actvties);//displays all activities


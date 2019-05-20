#include "RHorrace_prog4.h"

activity::activity()//activity constructor
{
	actvty = NULL;
	dscrptn = NULL;
	lctn = NULL;
	dstnce = 0;
	sggstns = NULL;
}
activity::~activity()//activity destructor
{
	if(actvty)//if not NULL
	{
		delete [] actvty;
		actvty = NULL;
	}
	if(dscrptn)//if not NULL
	{
		delete [] dscrptn;
		dscrptn = NULL;
	}
	if(lctn)//if not NULL
	{
		delete [] lctn;
		lctn = NULL;
	}
	if(dstnce != 0)//if not zero
	{

		dstnce = 0;
	}
	if(sggstns)//if not NULL
	{
		delete [] sggstns;
		sggstns = NULL;
	}
}

void activity::insert(char act[], char des[], char loc[], float dis, char sug[])//insert into activity variables
{
	actvty = new char[strlen(act) + 1];//initializes actvty
	strcpy(actvty,act);//copies into actvty variable
	dscrptn = new char[strlen(des) + 1];//initializes dscrptn
	strcpy(dscrptn,des);//copies into dscrptn variable
	lctn = new char[strlen(loc) + 1];//initializes lctn
	strcpy(lctn,loc);//copies into lctn variable
	dstnce = dis;//dstnce becomes dis value
	sggstns = new char[strlen(sug) + 1];//initializes sggstns variable
	strcpy(sggstns,sug);//copies into sggstns variable
}

void activity::check_dis(float dist)//checks distance
{
	if(dstnce <= dist)//if the activity's distance is less than or equal to the requested distance
	{
		//Display the activity
		cout << endl;
		display();
		cout << endl;
	}
}

void activity::display()//displays variables
{
	cout << endl;
	cout << "Activity: " << actvty << endl;
	cout << "Description: " << dscrptn << endl;
	cout << "Location: " << lctn << endl;
	cout << "Distance(in miles): " <<dstnce << endl;
	cout << "Suggestions: " << sggstns << endl;
	cout << endl;
}

activities::activities()//activities constructor
{
	actvties = NULL;
	amnt = 0;
}

activities::~activities()//activities destructor
{
	if(actvties)//if not NULL
	{
		delete [] actvties;
		actvties = NULL;
	}
	if(amnt != 0)//if not zero
		amnt = 0;
}

int activities::set_list(int & set)//sets the length of the list of activities
{
	if(set > 0)//if it is greater than zero
	{
		actvties = new activity[set];//sets the list into an array of activities
		return 1;
	}
	else if(set < 0)//if it is less than 0
	{
		cout << "The amount can't be less than 0." << endl;
		return -1;
	}
	else return 0;//if zero
}

int activities::insert(char act[],char des[], char loc[], float dis, char sug[], int & set)//inserts data into one activity at a time
{
	if(amnt < set && set != 0)//if the list isn't full
	{
		actvties[amnt].insert(act,des,loc,dis,sug);//inserts variable
		amnt += 1;
		if(amnt < set)//if list isn't full yet
			return 0;
		else if(amnt == set)//if list is full
			return 1;
	}
	else if(amnt == set)//if list is already full
		return 1;
}

void activities::check_dis(float dist)//checks distance for all entered activities
{
	for(int i = 0; i<amnt; ++i)
	{
		actvties[i].check_dis(dist);//checks distance for each activity
	}
}

void activities::display()//displays all entered activities
{
	cout << "There are " << amnt << " activities." << endl << endl;//displays how many activities there are
	for(int i = 0; i < amnt; ++i)
	{
		actvties[i].display();//displays activity one at a time
	}
}

int amount(activities & actvties)//sets amount of activities
{
	int temp = 0;
	do{
		cout << "How many activities do you want to put in the list? Warning, the list will be fixed with this number:";
		cin >> temp;
		cin.ignore(100,'\n');
	}while(actvties.set_list(temp) == -1);//calls set_list function in activities class
	return temp;//returns the amount value
}

int insert(activities & actvties, int & sz)//inserts data into activities class
{
	char act[SIZE];//activity variable
	char des[SIZE];//description variable
	char loc[SIZE];//location variable
	float dis = 0;//distance variable
	char sug[SIZE]; //suggestion variable
	cout << "Enter name of activity:";
	cin.get(act,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter description of activity:";
	cin.get(des,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter location of activity:";
	cin.get(loc,SIZE,'\n');
	cout << "Enter distance(in miles):";
	cin >> dis;
	cin.ignore(100,'\n');
	cout << "Enter suggestions:";
	cin.get(sug,SIZE,'\n');
	cin.ignore(100,'\n');
	return actvties.insert(act,des,loc,dis,sug,sz);//calls insert function from activities class and returns 0 or 1	
}

void check_dis(activities & actvties)//checks distance from user
{
	char response;//response variable, Y or N
	float temp = 0;
	do{
		cout << "Do you want to find an activity near you?(Y/N):";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response == 'N' && response == 'Y');
	if(response == 'Y')//if yes
	{
		do{
			cout << "Enter maximum distance you are willing to travel(in miles):";
			cin >> temp;
			cin.ignore(100,'\n');
		}while(temp < 0);
		actvties.check_dis(temp);//calls check_dis function from activities class
	}
	if(response == 'N')//if no
		return;
}

void display(activities & actvties)//displays activities
{
	char response;//response variable, Y or N
	do{
		cout << "Display all activities?(Y/N):";
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'N' && response != 'Y');
	if(response == 'Y')
	{
		actvties.display();//calls display function from activities class
	}
}

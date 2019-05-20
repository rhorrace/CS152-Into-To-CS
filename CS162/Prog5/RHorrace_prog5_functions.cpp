#include "RHorrace_prog5.h"

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

int activity::check_act(char act[])//checks name of activity
{
	if(strcmp(actvty,act) > 0) return 1;//if act is less thn actvty
	if(strcmp(actvty,act) < 0) return -1;//if act is greater than actvty
	if(strcmp(actvty,act) == 0) return 0;//if they're the same
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
	head = NULL;
}

activities::~activities()//activities destructor
{
	if(head)//if not NULL
	{
		node * current = head;
		while(current -> next)
		{
			current = current -> next;
			delete head;
			head = current;
		}
		delete head;
		head = NULL;
	}
}

int activities::insert(char act[],char des[],char loc[],float dis, char sug[])//insert wrapper function
{
	return insert(head,act,des,loc,dis,sug);//calls insert function
}

int activities::insert(node *& head,char act[],char des[],char loc[],float dis, char sug[])//recursively inserts data into a node
{
	if(!head)//if NULL
	{
		head = new node;
		head -> data.insert(act,des,loc,dis,sug);//inserts data
		head -> next = NULL;
		return 1;
	}
	if(head)//if head exists
	{
		if(head -> data.check_act(act) == 1)//if new data is less than head
		{
			node * temp = new node;//temp node
			temp -> data.insert(act,des,loc,dis,sug);//inserts data
			temp -> next = head;//becomes node before head
			head = temp;//head becomes before node
			return 1;
		}
		if(head -> data.check_act(act) == -1 || head -> data.check_act(act) == 0)//if the same or greater
			return insert(head -> next,act,des,loc,dis,sug);//go to next node
	}
}

int activities::check_dis(float dis)//check_dis wrapper function
{
	return check_dis(head,dis);//calls check_dis function
}

int activities::check_dis(node * head, float dis)//checks distance recurisvely
{
	if(!head) return 0;//if NULL
	head->data.check_dis(dis);//checks distance
	return check_dis(head -> next, dis);//go to next node
}

int activities::count()//count wrapper
{
	return count(head);//calls count function
}

int activities::count(node * head)//displays all node recursively
{
	if(!head) return 0;//if NULL
	if(!head -> next) return 1;//if only one node
	return count(head-> next) + 1;//if more than one node
}

int activities::display_all()//display_all wrapper function
{
	return display_all(head);//calls display_all function
}

int activities::display_all(node * head)//displays all nodes recursively
{
	if(!head) return 0;//if NULL
	head -> data.display();//displays
	if(!head -> next) return 1;//if only one node
	return display_all(head -> next);//recursively go to next node
}

int insert(activities & actvties)//inserts data into activities class
{
	int insrt = 0;
	char act[SIZE];//activity variable
	char des[SIZE];//description variable
	char loc[SIZE];//location variable
	float dis = 0;//distance variable
	char sug[SIZE]; //suggestion variable
	char temp;
	do{
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
		insrt = actvties.insert(act,des,loc,dis,sug);//calls insert function from activities class and returns 0 or 1
		do{
			cout << "Enter another activity?(Y/N):";
			cin >> temp;
			cin.ignore(100,'\n');
			temp = toupper(temp);
		}while(temp != 'Y' && temp != 'N');
	}while(temp == 'Y');
	return 1;
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
		int count = actvties.count();//counts nodes in list
		cout << "There is/are " << count << " activity/activities to do.";
		actvties.display_all();//calls display function from activities class
	}
}

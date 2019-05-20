#include "RHorrace_prog4.h"

//Horrace,Robert CS162
/*
   This program is designed for the main function.
   This program will acces the .h file so the user
   can access the functions in order to insert an
   activity or activities.
 */
int main()
{
	activities my_activities;//activities object
	cout << "Welcome." << endl << endl;
	int size = amount(my_activities);//size of activities list
	int nsrt = 0;//for insert function
	if(size != 0)//if size is not 0
	{
		do{
			nsrt = insert(my_activities, size);//call insert function
		}while(nsrt == 0);

		check_dis(my_activities);//check distance function
		display(my_activities);//display function
	}
	cout << endl << endl << "Farewell" << endl;//bids user farewell
	return 0;
}

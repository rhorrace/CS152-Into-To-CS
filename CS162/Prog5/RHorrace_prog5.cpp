#include "RHorrace_prog5.h"

//Horrace,Robert CS162
/*
   This program is designed for the main function.
   This program will acces the .h file so the user
   can access the functions in order to insert an
   activity or activities.
 */
int main()
{
	int nsrt = 0;
	activities my_activities;//activities object
	cout << "Welcome." << endl << endl;
		nsrt = insert(my_activities);//call insert function

		check_dis(my_activities);//check distance function
		display(my_activities);//display function
	cout << endl << endl << "Farewell" << endl;//bids user farewell
	return 0;
}

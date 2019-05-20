#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;
//Horrace, Robert
/*The purpose of this program is to
  ask the user what is the product of
  two random numbers from 1 - 50 and
  determine if the user's answer is
  right or wrong. If the user answers
  incorrectly 3 times in a row, the
  program will end.*/

int main()
{
	int num1 = 0;//first number
	int num2 = 0;//second number
	int actual = 0;//actual answer of the problem(s)
	int count = 0;//counts the question done
	int wrongrow;//counts consecutive wrong answers, resets if answer is correct
	int wrong;//counts amount of wrong answers
	int right;//counts amount of right answers
	int answer = 0;//user's answer
	char previous;//for previous correct answers
	char again;//for repeating the program if Y
	cout << "Welcome fellow user." << endl;//Welcomes the user
	cout << "I will ask you multiple multiplication" << endl;
	cout << "problems and you must answer them correctly." << endl;
	cout << "Please insert your answer after the problem appears." << endl;
	cout << "If you solve 3 problems in a row incorrectly," << endl;
	cout << "I will not give you any more problems." << endl;
	cout << "Let's begin and good luck." << endl;
	do{
		wrong = 0;
		right = 0;
		wrongrow = 0;
		srand(time(0));
		previous = 'N';
		while(wrongrow < 3)
		{
			num1 = rand() % 50 + 1;//first number is a random number
			num2 = rand() % 50 + 1;//second number is a random number
			actual = num1 * num2;//correct answer
			cout << num1 << " * " << num2 << "=?" << endl;//displays problem
			cout << "Answer?:";//type in answer
			cin >> answer;
			if(answer == actual)//if the answer is correct
			{
				cout << "Correct" << endl << endl;
				right += 1;//adds one to amount correct
				previous = 'Y';//for next question,  previous answer was correct
				wrongrow -= wrongrow;//resets consecutive wrong counter
			}
			else if('Y' == previous && answer != actual && -5 <= actual - answer || 'Y' == previous && answer != actual && 5 >= actual - answer)//if previous answer was correct and answer is near the correct answer by 5
			{
				cout << "Close, please try again:";
				cin >> answer;
				if(answer == actual)//if answer is correct
				{
					cout << "Correct" << endl << endl;
					right += 1;//adds one to right counter
					previous = 'Y';//for next question, previous answer was correct
					wrongrow -= wrongrow;//resets consecutive wrong counter
				}
				if(answer != actual)//if answer isn't correct
				{
					cout << "Wrong" << endl << endl;
					wrong += 1;//adds 1 to wrong counter
					previous = 'N';//for next question, previous
					wrongrow += 1;//adds 1 to consecutive wrong counter
				}
			}
			else if( answer != actual)//if answer is wrong
			{
				cout << "Wrong" << endl << endl;
				wrong += 1;//adds 1 to wrong counter
				previous = 'N';//for next question, previous answer was wrong
				wrongrow += 1;//adds 1 to consecutive wrong counter
			}
		}
		cout << "I am sorry, you answered 3 problems incorrectly consecutively." << endl;
		cout << right << " problems have been answered correctly and" << endl;//amount of total right answers
		cout << wrong << " problems have been answered incorrectly." << endl;//amount of total wrong answers
		cout << "Run the program again?:";//asks if user wants to repeat the program
		cin >> again;
		again = toupper(again);//uppercases y or n(just in case)
	}while(again == 'Y');//repeats program if user says yes
	cout << "Farewell" << endl;//bids user farewell
	return 0;
}

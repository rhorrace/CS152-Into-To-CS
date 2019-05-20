#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//Horrace, Robert CS162
/*
This program is designed to store the function names and struct(s).
The struct will contain the data for an applicant.
The functions will deal with reading in the data for an applicant.
The functions will then write it into a file.
*/

using namespace std;

const int SIZE = 50;
const int HGT = 5;
struct person
{
	char name[SIZE];
	int age;
	char height[HGT];
	int weight;
	char talent[SIZE];
	char availability[SIZE];
};
void insert_data(char name[], int & age, char height[], int & weight, char talent[], char availability[]);
void write_file(char nm[], int & yr, char hght[], int & wght, char tlnt[], char avlblty[]);
//void read_file(char nm[], int & yr, char hght[], int & wght, char tlnt[], char avlblty[]);
void display(person & prsn);

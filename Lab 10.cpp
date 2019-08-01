// C++ Program			Lab 10.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Lab 10 
// Due Date:			04/14/2019

/*
  The purpose of this lab was to create a menu based program
  then allow the user to set the size of an array,
  fill the array with random numbers, print the array,
  sort from low to high or vice versa,
  then finally search the array.
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int s = 0;
int choice, temp, target, sq, bq, middle;
int value[100];

void printmenu()	//Function to print the menu
{
	cout << "(0) Exit" << endl;
	cout << "(1) Input array size" << endl;
	cout << "(2) Fill an array with random numbers from 1-100" << endl;
	cout << "(3) Print the array with position numbers" << endl;
	cout << "(4) Sort the array in ascending sequence" << endl;
	cout << "(5) Sort the array in descending sequence" << endl;
	cout << "(6) Sequential search of the array for a target" << endl;
	cout << "(7) Binary search of the array for a target" << endl;
	cout << "Type in a choice" << endl;

}

void arraysize()	//Function to get array size
{
	cout << "Type in the array size." << endl;
	cin >> s;

}

void fillarray()	//Function to fill array with random numbers
{
	//Random Number Seed
	rand();

	//Entering random numbers into the array
	for (int i = 0; i < s; i++)
	{
		value[i] = rand() % 100 + 1;
	}
}

void printarray()	//Function toprint the array
{
	for (int i = 0; i < s; ++i)
	{
		cout << i << "\t" << "-" << "\t" << value[i] << endl;
	}
}

void maxmin()	//Function to sort array from lowest to highest
{
	for (int k = 0; k < s; k++)
	{
		for (int j = k + 1; j < s; j++)
			if (value[k] > value[j])
			{
				temp = value[k];
				value[k] = value[j];
				value[j] = temp;
			}
	}
}

void descend()	//Function to sort attay from highest to lowest
{

	for (int i = 0; i < s; ++i)
	{
		int key = value[i];
		int position = i;
		while (position > 0 && value[position - 1] < key)
		{
			value[position] = value[position - 1];
			position--;
		}
		value[position] = key;
	}

}

int seqSearch(int target)	//Sequential search function
{
	for (int i = 0; i < s; i++)
	{
		if (value[i] == target)
		{
			return i; 	// found in position i
		}
	}
	return -1;

}

int binarySearch(int value[], int l, int r, int target)
{
	while (l <= r) 
	{
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (value[m] == target)
			return m;

		// If x greater, ignore left half 
		else if (value[m] < target)
			l = m + 1;

		// If x is smaller, ignore right half 
		else
			r = m - 1;
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}

void dispatch(int choice)	//Dispatch function that calls to all other functions
{
	int target;
	switch (choice)
	{
	case 0: exit;
		break;

	case 1: arraysize();
		break;

	case 2: fillarray();
		break;

	case 3: printarray();
		break;

	case 4: maxmin();
		break;

	case 5: descend();
		break;

	case 6:
		cout << endl;
		cout << "Type in  the value you want to search for." << endl;
		cin >> target;
		cout << endl;
		sq = seqSearch(target);
		if (sq == -1)
			cout << "Target not found" << endl;
		else
			cout << "Target found in position " << sq;
		break;

	case 7: 
		cout << endl;
		cout << "Type in  the value you want to search for." << endl;
		cin >> target;
		cout << endl;
		bq = binarySearch(value, 0, s - 1, target);
		if (bq == -1)
			cout << "Target not found" << endl;
		else
			cout << "Target found in position " << bq;
		break;
	}
}

int main()
{
	printmenu();
	cin >> choice;

	while (choice != 0)
	{
		cout << endl;
		dispatch(choice);
		printmenu();
		cout << endl;
		cin >> choice;
		cout << endl;
	}
	cout << "This prgram was coded by Hakeem Wilson." << endl;
	system("PAUSE");
	return 0;
}
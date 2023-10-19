// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

// lookup table
int lookup_table[MAX_SIZE];

// create the lookup table
// for an array of length n
void create_table(int n)
{
	// power and count variable
	int pow = 1;
	int co = 0;
	do {
		// multiply by 2
		pow <<= 1;

		// initialize the lookup table
		lookup_table[co] = (n + (pow >> 1)) / pow;
	} while (lookup_table[co++] != 0);
}

// binary search
int binary(int arr[], int v)
{
	// mid point of the array
	int index = lookup_table[0] - 1;

	// count
	int co = 0;

	while (lookup_table[co] != 0) {

		// if the value is found
		if (v == arr[index])
			return index;

		// if value is less than the mid value
		else if (v < arr[index])
			index -= lookup_table[++co];

		// if value is greater than the mid value
		else
			index += lookup_table[++co];
	}
return index;
}

// main function
int main()
{

	int arr[] = { 1, 3, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(int);

	// create the lookup table
	create_table(n);

	// print the position of the array
	cout << "Position of 3 in array = "
		<< binary(arr, 3) << endl;

	return 0;
}

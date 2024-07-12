// This program performs a linear search on a character array

// Last Modified Date: 5/1/2024

#include <iostream>
using namespace std;

int searchList(int[], int, int); // Function prototype

const int SIZE = 8;

int main()
{
    int nums[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
    int found;
    int num;
    const int SENTINEL = -999;  // Sentinel value to end the program

    cout << "Enter an integer to search for (enter -999 to quit):" << endl;

    while (true) {
        cin >> num;
        if (num == SENTINEL) {
            cout << "Exiting the program." << endl;
            break;
        }

        found = searchList(nums, SIZE, num);

        if (found == -1)
            cout << "The integer " << num << " was not found in the array." << endl;
        else
            cout << "The integer " << num << " is in the " << found + 1 << " position of the array." << endl;

        cout << "\nEnter another integer to search for (enter -999 to quit):" << endl;
    }

    return 0;
}

//*******************************************************************
//  searchList
//
//  task:         This searches an array for a particular value
//  data in:      List of values in an array, the number of
//                elements in the array, and the value searched for
//                in the array
//  data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************

int searchList(int List[], int numElems, int value)
{
    for (int count = 0; count < numElems; count++)
    {
        if (List[count] == value)
            return count;
    }

    return -1;  // if the value is not found, -1 is returned
}

// LAB 8.4 Student Generated Code Assignments

// Last Modified Date: 5/1/2024
#include <iostream>
#include <fstream>
#include <iomanip>  // For std::fixed and std::setprecision
#include <algorithm> // For std::fill
using namespace std;

const int MAX_SIZE = 50;

// Function prototypes
void bubbleSortArray(int[], int);
int binarySearch(int[], int, int);
double computeMean(int[], int);
void readDataFromFile(int&, int&, int[], string);
void outputResultsToFile(string, int[], int, int, int, double);

int main() {
    int size, searchValue, resultIndex;
    int array[MAX_SIZE] = {0}; // Initialize all to zero
    double mean;
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    // Read data from file
    readDataFromFile(size, searchValue, array, inputFile);

    // Sort the array
    bubbleSortArray(array, size);

    // Perform binary search
    resultIndex = binarySearch(array, size, searchValue);

    // Compute the mean of the array
    mean = computeMean(array, size);

    // Output results to file
    outputResultsToFile(outputFile, array, size, searchValue, resultIndex, mean);

    cout << "Processing complete. Results written to " << outputFile << "." << endl;

    return 0;
}

void bubbleSortArray(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
    }
}

int binarySearch(int array[], int size, int value) {
    int first = 0, last = size - 1, middle;
    while (first <= last) {
        middle = first + (last - first) / 2;
        if (array[middle] == value) {
            return middle;
        } else if (array[middle] < value) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }
    return -1;
}

double computeMean(int array[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

void readDataFromFile(int& size, int& searchValue, int array[], string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }
    inFile >> size;
    inFile >> searchValue;
    if (size > MAX_SIZE) {
        cerr << "Array size exceeds the maximum allowed limit." << endl;
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        if (!(inFile >> array[i])) {
            cerr << "Error reading element " << i << " from file." << endl;
            exit(1);
        }
    }
    inFile.close();
}

void outputResultsToFile(string filename, int array[], int size, int searchValue, int resultIndex, double mean) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }

    outFile << "Array Size: " << size << "\n";
    outFile << "Array As Entered: ";
    for (int i = 0; i < size; i++) {
        outFile << array[i] << " ";
    }
    outFile << "\nSorted Array: ";
    for (int i = 0; i < size; i++) {
        outFile << array[i] << " ";
    }
    outFile << "\nSearched Value: " << searchValue << "\n";
    outFile << "Index of Searched Value: " << (resultIndex != -1 ? to_string(resultIndex) : "Not found") << "\n";
    outFile << "Mean of the Dataset: " << fixed << setprecision(2) << mean << endl;

    outFile.close();
}

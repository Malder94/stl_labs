#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include "functions.cpp"

int main()
{
    vector <double> myDoubleVector;
    int vectorSize;

    cout << "Enter size of vector:" << endl;
    cin  >> vectorSize;

    VectorFill(myDoubleVector, vectorSize);

    cout << "\nUnsorted:" << endl;

    VectorOut(myDoubleVector);

    BubbleSort(myDoubleVector);

    cout << "\nSorted:" << endl;

    VectorOut(myDoubleVector);

    return 0;
}
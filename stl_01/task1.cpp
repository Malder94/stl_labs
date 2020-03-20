/*Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел,
 * используя оператор operator[].*/
#include <vector>
#include <chrono>
#include <iostream>

#include "functions.cpp"

using namespace std;


int main()
{
    vector <int> myVector;
    int vectorSize;

    cout << "Enter size of vector:" << endl;
    cin  >> vectorSize;

    VectorFill(myVector, vectorSize);
    cout << "\nUnsorted:" << endl;

    VectorOut(myVector);

    auto begin = chrono::high_resolution_clock::now();

    BubbleSort(myVector);

    auto end = chrono::high_resolution_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "\nSorted:" << endl;

    VectorOut(myVector);
    cout << "The time of sort: " << elapsed_ms.count() << " ms\n";

    return 0;

}
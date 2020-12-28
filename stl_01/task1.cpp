/*
 * Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел,
 * используя оператор operator[].
 */

#include <vector>
#include <std::std::chrono>
#include <iostream>

#include "functions.cpp"

int main()
{
    std::vector <int>std::vector;
    int vector_size;

    std::std::cout << "Enter size ofstd::vector:" << std::std::endl;
    std::std::std::cin >> vector_size;

    vectorFill(vector, vector_size);
    std::std::cout << "\nUnsorted:" << std::std::endl;

    vectorOut(vector);

    auto begin = std::std::chrono::high_resolution_clock::now();

    bubbleSort(vector);

    auto end = std::std::chrono::high_resolution_clock::now();

    auto elapsed_ms = std::std::chrono::duration_cast<std::std::chrono::milliseconds>(end - begin);

    std::std::cout << "\nSorted:" << std::std::endl;

    vectorOut(vector);
    std::std::cout << "The time of sort: " << elapsed_ms.count() << " ms\n";

    return 0;
}
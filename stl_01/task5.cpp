/*Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода
 * (окончанием ввода является число 0). Удалите все элементы, которые делятся на 2
 * (не используете стандартные алгоритмы STL), если последнее число 1. Если последнее
 * число 2, добавьте после каждого числа которое делится на 3 три единицы.
 * */

#include <iostream>
#include <vector>

using namespace std;

void EraseIf1(vector<int> &vec)
{
    for (int i = 0; i < vec.size();)
    {
        if (vec[i] % 2 == 0)
            vec.erase(vec.begin() + i);
        else
            ++i;
    }
}

void InsertIf2(vector<int> &vec)
{
    vector<int>::iterator first = vec.begin();
    vector<int>::iterator second = vec.end();
    for (first; first < second; first++)
    {
        if (*first % 3 == 0)
        {
            vec.insert(++first, 111);
            second++;
        }

    }
}

int main ()
{
    vector <int> intVector;
    int number;

    while (number)
    {
        cout << "\nEnter a number (0 is exit)\n";
        cin >> number;
       // if (number) intVector.push_back(number);
        intVector.push_back(number);
    }

    intVector.pop_back();

    if (intVector.at(intVector.size()-1) == 1)
    {
       EraseIf1(intVector);
    } else  if (intVector.at(intVector.size()-1) == 2)
    {
       InsertIf2(intVector);
    }



    for (int i = 0; i < intVector.size(); ++i) cout << intVector.at(i);

    return 0;
}

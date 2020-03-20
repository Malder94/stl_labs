//region Task
/* Разработать программу, которая, используя только стандартные алгоритмы и функторы,
 * умножает каждый элемент списка чисел с плавающей  точкой на число PI
 * */
//endregion Task

//region Include
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
//endregion Include

using namespace std;

void FillVector(vector <float>& v)
{
    int sign = 0;
    float newNumber = 0;

    srand(time(NULL));

    for (int i = 1000; i > 0; --i)
    {
        sign = rand() % 2;
        newNumber = (sign == 1) ? (float(rand())/float((RAND_MAX)) * 501.0 ) : (float(rand())/float((RAND_MAX)) * 501.0 ) * -1;
        v.push_back(newNumber);
    }
}

void PrintVector(const vector<float>& v)
{
    int i = 1;
    for (auto item : v) {
        cout << setw(8) << item << " ";
        if (i++ % 14 == 0)
            cout << endl;
    }
}

class MyFunctor
{
public:
    MyFunctor()  {}
    void operator()(float& x)
    {
        x *= 3.14;
    }
};

int main ()
{
    vector<float> floatVector;
    MyFunctor myFunctor;

    FillVector(floatVector);

    PrintVector(floatVector);

    //myFunctor = for_each(floatVector.begin(), floatVector.end(), myFunctor);
    for_each(floatVector.begin(), floatVector.end(), myFunctor);

    cout << "\nAfter multiplication on PI: \n ";

    PrintVector(floatVector);

    return 0;
}
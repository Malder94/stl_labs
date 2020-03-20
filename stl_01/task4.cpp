/*
 * Прочитайте во встроенный массив С содержимое текстового файла, скопируйте данные в вектор
 * одной строкой кода (без циклов и алгоритмов STL)
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main ()
{
    vector <string> stringVector;
    setlocale(LC_ALL, "RUS");
    string str;

    ifstream fInput ("../stl_01/text.txt");

    if (fInput.is_open())
    {
        stringstream ss;
        ss << fInput.rdbuf();
        str = ss.str();
    }
    fInput.close();

    stringVector.push_back(str);

    for (int i = 0; i < stringVector.size(); ++i) cout << stringVector.at(i);
    //for (const auto & i : stringVector) cout << i;


    return 0;
}

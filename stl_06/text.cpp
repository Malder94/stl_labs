//region Task
/*
 * Написать программу, которая выполняет следующие действия:
 *  a. Читает содержимое текстового файла
 *  b. Выделяет слова, словом считаются последовательность символов разделенных пробелами
 *     и/или знаками табуляции и/или символами новой строки
 *  c. Вывести список слов присутствующий в тексте без повторений (имеется в виду, что одно
 *     и то же слово может присутствовать в списке только один раз)
*/
//endregion Task

//region Include
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
//endregion Include

using namespace std;

void WordCount(const map<string, int>::value_type &vt)
{
    if (vt.second == 1)
        cout << vt.first << endl;
}

int main()
{
    ifstream fInput ("../stl_06/erunovskiy/input.txt");
    map<string, int> myMap;
    string str;

    while(!fInput.eof() && fInput >> str)
        ++myMap[str];
    for_each(++myMap.begin(), ++myMap.end(), WordCount);
}


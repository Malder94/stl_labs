#include <iostream>
#include <list>
#include <vector>
#include "queuewithpriority.h"

void fillList(list<int> &list, size_t length);
void printList(list<int> &list);
void printListSpec(list<int> &list);

int main()
{
  //  QueueWithPriority q = QueueWithPriority();
    list <int> myList;
    vector<int> listLengths = {0, 1, 2, 3, 4, 5, 7, 14};

    for (auto listLength : listLengths)
    {
        fillList(myList, static_cast<size_t>(listLength));

        if (myList.empty()) continue;
    }

    printList(myList);
    printListSpec(myList);




    return 0;
}

void fillList(list<int> &list, size_t length)
{
    while (length) {
        list.push_back(1 + rand() % 20);
        --length;
    }
}

void printList(list<int> &list)
{
    for (auto element : list) {
        cout << element << " ";
    }

    cout << endl;
}

void printListSpec(list<int> &list)
{
    for (auto element : list) {
        cout << element << " ";
    }

    cout << endl;
}
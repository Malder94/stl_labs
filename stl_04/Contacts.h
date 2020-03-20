#ifndef OOP_SEM4_CONTACTS_H
#define OOP_SEM4_CONTACTS_H

//region Include
#include <iostream>
#include <string>
#include <list>
//endregion Include

using namespace std;

class Contacts {
private:
    typedef list<Contacts>::iterator t_contactsit;
public:
    string name;
    string number;

    Contacts() { name = "Default"; number = "+7 (999) 999 99 99"; };
    Contacts (string _name, string _number);

    //Contacts (string _name, string _number);

    void FirstInit(list <Contacts>& contactsList);

    void PrintItem(Contacts& contact);

    void PrintMenu();

    void MoveIterator(t_contactsit& it, list<Contacts>& contactsList);

    void InsertItem(t_contactsit& it, list<Contacts>& contactsList);

    void EraseItem(t_contactsit& it, list<Contacts>& contactsList);

    void EditItem(t_contactsit& it);

    ~Contacts();


};


#endif //OOP_SEM4_CONTACTS_H

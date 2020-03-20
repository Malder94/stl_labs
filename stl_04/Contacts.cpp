#include "Contacts.h"
void Contacts::PrintItem(Contacts& contact) {
    cout << contact.name << " " << contact.number << endl;
}

Contacts::Contacts (string _name, string _number) {
    name = _name;
    number = _number;
}

void Contacts::FirstInit(list <Contacts>& contactsList)
{
    Contacts contact1 ("Alex", "89021378111");
    Contacts contact2 ( "Denis", "89214378222");
    Contacts contact3 ( "Nick",  "89021378333");

    contactsList = {contact1, contact2, contact3};
}

void Contacts::PrintMenu()
{
    cout << "\nMenu\n\n";

    cout << "1. Current\n";
    cout << "2. Move\n";
    cout << "3. Insert item...\n";
    cout << "4. Edit item\n";
    cout << "5. Erase\n";
    cout << "6. Print all items\n";
    cout << "7. Exit\n";

    cout << "Enter: ";
}

void Contacts::MoveIterator(t_contactsit& it, list<Contacts>& contactsList)
{
    int n = 1;
    bool goodN;
    auto first = contactsList.begin();
    auto last  = --contactsList.end();

    while (n != 0)
    {
        goodN = false;
        cout << "Enter n to move forward, or -n to move backward. 0 is exit:  ";
        cin >> n;

        if ((n > 0 && n <= distance(it, last)) || ((n < 0) && abs(n) <= distance(it, first)))
        {
            goodN = true;
        } else
        {
            cout << "Wrong n!\n";
        }

        if (goodN)
        {
            advance(it, n);
            cout << "Current item:\n";
            PrintItem(*it);
        }
    }
}

bool IsRightNumber(string& number)
{
    if (number.size() != 10)
    {
        cout << "Number should has 10 digits, for example \"1234567890\"\n";
        return false;
    }

    size_t found = number.find_first_not_of("1234567890");

    if (found != string::npos)
    {
        cout << "Only digits, please.\n";
        return false;
    }


    return true;

}

string EditNumber(string& number)
{
    return "+7 (" + number.substr(0,3) + ") " + number.substr(3,3)
        + " " + number.substr(6,2) + " " + number.substr(8,2);

}

void Contacts::InsertItem(t_contactsit& it, list<Contacts>& contactsList)
{
    short key;
    string rightNumber;

    while (key != 4)
    {
        Contacts newContact;
        cout << "1. Insert Item before current\n";
        cout << "2. Insert Item after current\n";
        cout << "3. Insert Item to the end\n";
        cout << "4. Exit\n";

        cin >> key;

        if (key != 4)
        {
            cout << "Enter name: ";
            cin >> newContact.name;

            cout << "Enter number: +7 ";
            cin >> rightNumber;

            while (!IsRightNumber(rightNumber))
            {
                cout << "Enter number: +7 ";
                cin >> rightNumber;
            }

            newContact.number = EditNumber(rightNumber);
        }



        switch (key)
        {
            case 1:
                contactsList.insert(it, newContact);
                break;
            case 2:
                contactsList.insert(++it, newContact);
                break;
            case 3:
                contactsList.push_back(newContact);
                break;
            default:
                cout << "Goodbye\n";
                exit;
        }

        cout << "New contact: ";
        PrintItem(newContact);
    }
}

void Contacts::EraseItem(t_contactsit& it, list<Contacts>& contactsList)
{
    if (contactsList.empty())
    {
        cout << "Nothing to erase";
    } else
    {
        string _name = it->name;
        contactsList.erase(it++);
        cout << "Contact \"" << _name << "\" is delete!\n";
    }
}

void Contacts::EditItem(t_contactsit& it)
{
    //Contacts newContact;
    cout << "Current item: \n";
    PrintItem(*it);

    cout << "New name: ";
    cin >> it->name;

    cout << "New number: ";
    cin >> it->name;

    cout << "Current item after edit: \n";
    PrintItem(*it);
}

Contacts::~Contacts(){};

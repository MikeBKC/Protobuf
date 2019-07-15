#include <iostream>
#include <string>
#include <fstream>
#include "add_person.pb.h"
using namespace std;

void List_Person(tutorial::Address address)
{
    int size = address.person_size();
    for(int i = 0;i < size;i++) 
    {
        cout << "Print "<< i+1 << " address info" << endl;
        tutorial::Person *person;
        person = address.mutable_person(i);
        cout << "Name:" << person->name() << endl;
        cout << "id:" << person->id() << endl;
        cout << "email:" << person->email() << endl;

        int phonenum = person->phone_size();
        for(int j = 0;j < phonenum;j++)
        {
            cout << "Print "<< j+1 << " person phone info" << endl;
            tutorial::Person::Phonenum phone;
            phone = person->phone(j);
            cout << "Num:" << phone.num() << endl;
            if(phone.type() == 0)
                cout << "Type: Mobile" << endl;
            else if(phone.type() == 1)
                cout << "Type: HOME" << endl;
            if(phone.type() == 2)
                cout << "Type: WORK" << endl;
        }
    }
}
int main(int argc,char *argv[])
{   
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    if(argc != 2){
        cout << "usage: add_person xx.dat" << endl;
        return -1;
    }



    tutorial::Address address;

    {
        // Read the existing address book.
        fstream input(argv[1], ios::in | ios::binary);
        if (!input) {
            cout << argv[1] << ": File not found.  Creating a new file." << endl;
        } else if (!address.ParseFromIstream(&input)) {
            cerr << "Failed to parse address." << endl;
            return -1;
        }
    }

    List_Person(address);

    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}

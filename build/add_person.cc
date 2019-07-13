#include <iostream>
#include <string>
#include <fstream>
#include "add_person.pb.h"
using namespace std;

void Add_Person(tutorial::Person *person)
{
    cout << "Enter name:";
    getline(cin,*person->mutable_name());

    cout << "Enter id:";
    int id;
    cin >> id;
    person->set_id(id);
    cin.ignore(256,'\n');

    string email;
    cout << "Enter email:";
    getline(cin,email);
    if(!email.empty()){
        person->set_email(email);
    }

    while(true){
        string num;
        cout << "Enter num:(or none to finish)";
        getline(cin,num);
        if(num.empty()){
            break;
        }
        
        tutorial::Person::Phonenum *phonenum;
        phonenum = person->add_phone();

        phonenum->set_num(num);

        cout << "Enter type: mobile|home|work" <<endl;
        string type;
        getline(cin,type);
        if(type == "mobile"){
            phonenum->set_type(tutorial::Person::MOBILE);
        }else if(type == "home"){
            phonenum->set_type(tutorial::Person::HOME);
        }else if(type == "work"){
            phonenum->set_type(tutorial::Person::WORK);
        }else{
            cout << "Enter error , using default" << endl;
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
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }

    Add_Person(address.add_person());

    {
        fstream output(argv[1], ios::out | ios::binary | ios::trunc);
        if(!address.SerializeToOstream(&output)){
            cout << "Write " << argv[1] << "error" <<endl;
            return -1;
        }
    }

    return 0;
}

#include "to_string.pb.h"

using namespace std;

int main(int argc,char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    string data;

    {
        tutorial::To_string to_string;
        to_string.set_name("Hello");
        to_string.add_num(1);
        to_string.add_num(5);
        to_string.add_num(9);
        to_string.SerializeToString(&data);
    }

    {
        tutorial::To_string pare_string;
        pare_string.ParseFromString(data);
        cout << "name:" << pare_string.name() << endl;
        cout << "size:" << pare_string.num_size() << endl;
        for(int i = 0;i < pare_string.num_size();i++)
        {
            cout << "num:" << pare_string.num(i) << endl;
        }
    }
    
    google::protobuf::ShutdownProtobufLibrary();    
    return 0;
}

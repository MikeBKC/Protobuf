#include <iostream>
#include <google/protobuf/map.h>
#include <google/protobuf/text_format.h>
#include "map.pb.h"

using namespace google::protobuf;

int main(int argc,char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::string data;
    Testmap tmap;
    Testmap rmap;
    tmap.mutable_data()->insert({1,"str1"});
    tmap.mutable_data()->insert(MapPair<int32,std::string>(2, "dong"));

    tmap.SerializeToString(&data);

    rmap.ParseFromString(data);

    auto map_it = rmap.data().begin();
    while(map_it != rmap.data().end()){
        std::cout << map_it->first << " " << map_it->second <<std::endl;
        map_it++;
    }

    //print like json data
    std::string strTest;
    TextFormat::PrintToString(rmap, &strTest);
    std::cout << strTest << std::endl;
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

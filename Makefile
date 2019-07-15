.PHONY: all
all: add_person list_person to_string
SRC = src
BUILD = build
person_protoc:
	protoc --proto_path=$(SRC)/ --cpp_out=$(BUILD)/ $(SRC)/add_person.proto	

string_protoc:
	protoc --proto_path=$(SRC)/ --cpp_out=$(BUILD)/ $(SRC)/to_string.proto

add_person:  person_protoc
	g++ -o $(BUILD)/$@ $(BUILD)/add_person.cc $(BUILD)/add_person.pb.cc -lprotobuf -lpthread -std=c++11

list_person: person_protoc
	g++ -o $(BUILD)/$@ $(BUILD)/list_person.cc $(BUILD)/add_person.pb.cc -lprotobuf -lpthread -std=c++11
	
to_string: string_protoc
	g++ -o $(BUILD)/$@ $(BUILD)/to_string.cc $(BUILD)/to_string.pb.cc -lprotobuf -lpthread -std=c++11

clean:
	rm build/add_person -rf

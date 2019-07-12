.PHONY: all
all:	add_person
SRC = src
BUILD = build
person_protoc:
	protoc --proto_path=$(SRC)/ --cpp_out=$(BUILD)/ $(SRC)/add_person.proto	

add_person:  person_protoc
	g++ -o $(BUILD)/$@ $(BUILD)/add_person.cc $(BUILD)/add_person.pb.cc -lprotobuf -lpthread -std=c++11
	
clean:
	rm build/add_person -rf

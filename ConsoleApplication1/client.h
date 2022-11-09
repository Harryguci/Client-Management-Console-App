#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class client {
private:
    int ID;
    string fullname;
    string phone;

public:
    client();
    client(int ID, string fullname, string phone);

    int getID();
    string getName();
    string getPhone();

    void setName(string newName);
    void setPhone(string newPhone);

    bool operator==(const client& B);
    bool operator!=(const client& B);
    
	friend ostream& operator<<(ostream& os, client A) {
		os << setw(30) << "Ma khach hang: ";
		os << setw(30) << A.ID << "\n";
		os << setw(30) << "Ho va ten: ";
		os << setw(30) << A.fullname << "\n";
		os << setw(30) << "SDT:"; 
		os << setw(30) << A.phone << endl;
		return os;
	}
};



client::client() {
	ID = 0;
	fullname = "";
	phone = "";
}
client::client(int ID, string fullname, string phone) {
	this->ID = ID;
	this->fullname = fullname;
	this->phone = phone;
}
int client::getID() {
	return this->ID;
}
string client::getName() {
	return this->fullname;
}
string client::getPhone() {
	return this->phone;
}
void client::setName(string newName) {
	this->fullname = newName;
}
void client::setPhone(string newPhone) {
	this->phone = newPhone;
}
bool client::operator==(const client& B) {
	return (this->fullname == B.fullname
		|| this->ID == B.ID
		|| this->phone == B.phone);
}

bool client::operator!=(const client& B) {
	return (!((this->fullname == B.fullname
		&& this->ID == B.ID
		&& this->phone == B.phone)));
}



#endif // !CLIENT_H_

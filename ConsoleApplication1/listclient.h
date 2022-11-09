#ifndef LIST_CLIENT_H_
#define LIST_CLIENT_H_

#include "dblist.h"
#include "client.h"
#include "../color-console/include/color.hpp"
//#include "../bprinter/include/bprinter/table_printer.h"

class ListClient : public dlist<client> {
private:
public:
	void display();
	client& EnterClient();
};



void ListClient::display() {
	if (this->empty()) {
		cout << hue::red << "! Khong tim thay khach hang nao.\n" << hue::reset;
		return;
	}

	int n = this->size();

	/*bprinter::TablePrinter tp(&std::cout);
	tp.AddColumn("TT", 5);
	tp.AddColumn("ID", 10);
	tp.AddColumn("Name", 30);
	tp.AddColumn("Phone", 10);

	tp.PrintHeader();

	int i = 1;

	iterator it = this->begin();
	for (it; it != this->end(); it++) {
		tp << i++ << it.getcurr()->getelem().getID() << it.getcurr()->getelem().getName() << it.getcurr()->getelem().getPhone() << "\n";
	}

	tp.PrintFooter();*/
}

client& ListClient::EnterClient() {
	int ID;
	string fullname, phone;

	cout << "\nNhap thong tin nhan vien:\n";
	cout << "- Ma khach hang: \t";
	cin >> ID;
	cout << "- Ho va ten: \t";
	fflush(stdin);
	getline(cin, fullname);
	cout << "- SDT: \t";
	cin >> phone;


	client newClient(ID, fullname, phone);

	this->push_back(newClient);
	return newClient;
}

#endif // !LIST_CLIENT_H_

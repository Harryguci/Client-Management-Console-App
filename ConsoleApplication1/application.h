#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <iostream>
#include "client.h"
#include "dblist.h"
#include "Node.h"
#include <string>
using namespace std;

class App {
private:
	// Nothing

public:
	//
	//	Handle Method:
	//

	void PrintMenu() {
		cout << "\n\n" << hue::green;
		cout << "\t\t-----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|              M E N U            | \n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t-----------------------------------\n\n" << hue::reset;

		string menulist[] = {
			"1. Them mot khach hang.",
			"2. Tim kiem khach hang.",
			"3. Hien thi danh sach khach hang."
		};
		int len = sizeof(menulist) / sizeof(string);
		for (int i = 0; i < len; i++) {
			cout << "\t\t" << menulist[i] << endl;
		}
	}

	void clrscr() {
		system("cls");
	}

	client EnterNewClient() {
		string phone, fullname;
		int ID;
		cout << "\n\nNhap thong tin khach hang:\n\n";
		cout << "- Ma khach hang: ";
		cin >> ID;
		cout << "- Ho va ten: ";
		//fflush(stdin);
		cin.ignore();
		getline(cin, fullname, '\n');

		cout << "- SDT: "; cin >> phone;

		client curr(ID, fullname, phone);
		return curr;
	}
	void display(dlist<client> List) {

		if (List.empty()) {
			cout << hue::red << "! Khong tim thay khach hang nao.\n" << hue::reset;
			return;
		}
		dlist<client>::iterator it = List.begin();
		cout << hue::yellow << setw(10) << "TT" << setw(20) << "Ma KH" << setw(30) << "Ho va Ten" << setw(20) << "SDT\n" << hue::reset;
		int i = 1;

		for (it; it != List.end(); it++) {
			cout << setw(10) << i++ << setw(20) << (*it).getID() << setw(30) << (*it).getName() << setw(20) << (*it).getPhone() << "\n";
		}
	}


	client findID(int ID, dlist<client> List) {
		for (auto& x : List) {
			if (x.getID() == ID) {
				return x;
			}
		}

		return client();
	}

	//
	// Options for USER :
	//
	void AddAClient(dlist<client>& List) {
		//L1.EnterClient();
		client newClient;
		bool check = true;

		do {
			newClient = EnterNewClient();
			bool check = (findID(newClient.getID(), List) == client());

			if (check)
				break;
			else
				cout << hue::red << "\nMa khach hang nay da ton tai.\n" << hue::reset;
		} while (1);

		List.push_back(newClient);
	}

	void FindAClient(dlist<client>& List) {
		// Tim kiem 1 khach hang
		int ID_temp;
		cout << "- Nhap ma khach hang can tim: "; cin >> ID_temp;

		client res = findID(ID_temp, List);

		if (res == client()) {
			cout << hue::red << "\nKhong tim thay khach hang nao !\n" << hue::reset;
		}
		else {
			cout << hue::yellow << "\nKet qua tim kiem\n" << hue::reset;
			cout << "\tMa khach hang: " << res.getID() << '\n';
			cout << "\tHo va ten: " << res.getName() << '\n';
			cout << "\tSDT: " << res.getPhone() << '\n';
		}
	}

	void PrintList(const dlist<client>& List) {
		cout << "\nDanh sach vua nhap la : \n";
		display(List);
	}
};


#endif // !APPLICATION_H_

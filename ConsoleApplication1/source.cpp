#include <iostream>
#include "../color-console/include/color.hpp"
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "client.h"
#include "dblist.h"
#include "listclient.h"
#include "application.h"
#include "Node.h"

using namespace std;

int main()
{
	bool is_quit = false;
	dlist<client> List1;
	App app;

	int status = 0;
	// 1. Nhap them 1 kh
	// 2. Tim kiem
	// 3. hien thi kh

	while (!is_quit) {
		
		app.clrscr(); // Xoa man hinh

		// Heading of the program
		cout << "\n\n\t\t\t" << hue::light_blue << "QUAN LY KHACH HANG" << hue::reset << "\n";

		app.PrintMenu(); // In menu len man hinh

		// User Nhap lua chon
		cout << hue::light_blue << "\t\t Nhap lua chon: " << hue::reset;
		cin >> status;

		// Xu ly lua chon
		switch (status)
		{
		case 1:
			app.AddAClient(List1);
			sort(List1);

			break;
		case 2: {
			cout << hue::aqua << "\nNhap ma khach hang can tim: " << hue::reset;
			int id;
			cin >> id;
			node<client>* temp = List1.binarySearch(client(id, "", ""));
			if (temp) {
				client res = (temp)->getelem();
				cout << hue::yellow << "\nKet qua tim kiem: \n" << hue::reset;
				cout << res;
			}
			else
				cout << "\nKhong tim thay khach hang nay\n";
		}
			  break;
		case 3:
			app.PrintList(List1);

		default:
			cout << hue::red << "\nBan da nhap sai dinh dang!\n" << hue::reset;
			break;
		}

		char temp;
		cout << hue::aqua << "Ban co muon tiep tuc ? (Y / N) : " << hue::reset;
		do {
			cin >> temp;
		} while (temp != 'Y' && temp != 'N');

		if (temp == 'N') {
			is_quit = true;
			cout << hue::red << setw(50) << "CHUONG TRINH SE DONG SAU 3s" << "\n" << hue::reset;
			Sleep(3000);
		}
	}

	system("pause");

	return 0;
}


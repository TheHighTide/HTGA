#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool adminMode = false;

bool CheckForAdminRights(bool logResult) {
	string adminFileName = "adminDataAdminRights.adminrights.hightide";
	string extraPath = "data/";
	ifstream adminFile(extraPath + adminFileName, ios::in);
	int password[] = { 'a', 'b', 'c', '1', '2', '3', '1', '2', '3', 'a', 'b', 'c' };
	int length = sizeof(password) / sizeof(password[0]);
	string convertedPassword;
	for (int i = 0; i < length; ++i) {
		convertedPassword += static_cast<char>(password[i]);
	}
	string enteredPassword;
	getline(adminFile, enteredPassword);
	if (enteredPassword == convertedPassword) {
		if (logResult) {
			cout << "You have admin rights!\n";
		}
		return true;
	}
	else {
		if (logResult) {
			cout << "You don't have admin rights!\n";
		}
		return false;
	}
}

int SetAdminMode(bool activated) {
	adminMode = activated;
	return 0;
}

bool IsAdminMode() {
	return adminMode;
}
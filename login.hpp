#pragma once
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "signup.hpp"

using namespace std;

void login() {
	string username = "";
	string password = "";
	string text = "";

	string value_delim = ":";

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	ifstream logins("logins.txt");
	while (getline (logins, text)) {
		string user = text.substr(0, text.find(value_delim));
		string pass = text.substr(text.find(value_delim) + 1);

		if (user == username) {
			if (pass == password) {
				cout << "Login successful.\n";
				return;
			}

			if (pass != password) {
				cout << "Incorrect password.\n";
				return;
			}
		}

		char reg_choice;
		cout << "User not found. Would you like to register? (Y or N)" << endl;
		cin >> reg_choice;
		reg_choice = toupper(reg_choice);
		
		if (reg_choice == 'Y') {
			sign_up();
			return;
		}
		if (reg_choice == 'N') 
			return;
	}
}

#endif
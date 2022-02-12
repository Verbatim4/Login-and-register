#pragma once
#ifndef LOGIN_H_
#define LOGIN_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "signup.hpp"
#include "admin.hpp"

using namespace std;

bool check_admin(string user, string pass) {
	string text = "";
	string admin_text = "";
	ifstream admins("admins.txt");
	while (getline(admins, admin_text))
	{
		if (user + ":" + pass == admin_text)
		{
			return true;
		}
		else {
			cout << text << endl;
		}
	}
	admins.close();
	return false;
}

bool check_login(string username, string password) {
	string text = "";
	string value_delim = ":";

	ifstream logins("logins.txt");
	while (getline (logins, text)) {
		string user = text.substr(0, text.find(value_delim));
		string pass = text.substr(text.find(value_delim) + 1);

		if (user == username) {
			if (pass == password) {
				cout << "Login successful.\n";
				// TODO: interface with someting useful
				return true;
			}

			cout << "Incorrect password.\n";
			return false;
		}
	}
	logins.close();
	cout << "User not found. " << endl;
	return false;
}

void login() {
	string username = "";
	string password = "";

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	if (!check_login(username, password))
		return;

	if (check_admin(username, password)) {
		char admin_panel_enter;
		cout << "Admin login successful.\n";
		cout << "Would you like to access the admin panel? (Y/N) \n";
		cin >> admin_panel_enter;

		if (toupper(admin_panel_enter) == 'Y') {
			admin_panel();
		}
		return;
	}

	char reg_choice;
	cout << "Would you like to register? (Y or N) " << endl;
	cin >> reg_choice;
	reg_choice = toupper(reg_choice);
	
	if (reg_choice == 'Y') {
		sign_up();
		return;
	}
	if (reg_choice == 'N') 
		return;
}

#endif

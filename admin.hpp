#pragma once
#ifndef ADMIN_H_
#define ADMIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "signup.hpp"

using namespace std;

void add_user() {
	string login = "";
	string password = "";

	cout << "Enter login: ";
	cin >> login;
	
	cout << "Enter password: ";
	cin >> password;

	if (!user_check(login))
			return;

	if (!pass_check(password))
		return;

	ifstream logins("logins.txt");
	string text;

	while (getline(logins, text)) {
		string user = text.substr(0, text.find(':'));

		if (user == login) {
			cout << "User already exists.\n";
			return;
		}
	}
	logins.close();
	
	ofstream logins_file("logins.txt", ios::app);
	logins_file << login << ":" << password << endl;
	logins_file.close();

	cout << "User added." << endl;
}

void delete_user() {
	string login = "";
	string text = "";
	string admin_text = "";

	ifstream logins("logins.txt");
	ifstream admins("admins.txt");

	ofstream logins_file("logins.txt", ios::out);
	ofstream admins_file("admins.txt", ios::out);

	cout << "Enter login: ";
	getline(cin, login);

	while (getline(logins, text))
	{
		while (getline(admins, admin_text))
		{
			string admin_user = admin_text.substr(0, admin_text.find(':'));
			if (text == admin_user)
			{
				cout << "You can't delete admin." << endl;
				return;
			}
		}
	}

	while (getline(logins, text))
	{
		if (text != login)
		{
			logins_file << text << endl;
		}
	}

	logins_file.close();
	logins.close();
	admins.close();
	cout << "User deleted." << endl;
}

void add_admin() {
	ofstream admins_file("admins.txt", ios::app);
	string login = "";
	string password = "";

	cout << "Enter login: ";
	getline(cin, login);
	cout << "Enter password: ";
	getline(cin, password);

	admins_file << login << endl;
	admins_file.close();

	cout << "Admin added." << endl;
}

void delete_admin() {
	string login = "";
	string text = "";
	string admin_text = "";

	ifstream logins("logins.txt");
	ifstream admins("admins.txt");

	ofstream logins_file("logins.txt", ios::out);
	ofstream admins_file("admins.txt", ios::out);

	cout << "Enter login: ";
	getline(cin, login);

	while (getline(admins, admin_text))
	{
		if (admin_text != login)
		{
			admins_file << admin_text << endl;
		}
	}

	admins_file.close();
	admins.close();
	cout << "Admin deleted." << endl;
}

void admin_panel() {
	string text = "";
	string admin_text = "";
	ifstream logins("logins.txt");
	ifstream admins("admins.txt");

	cout << "Admin panel" << endl;
	cout << "1. Add user" << endl;
	cout << "2. Delete user" << endl;
	cout << "3. Add admin" << endl;
	cout << "4. Delete admin" << endl;
	cout << "5. Exit" << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		add_user();
		break;
	case 2:
		delete_user();
		break;
	case 3:
		add_admin();
		break;
	case 4:
		delete_admin();
		break;
	case 5:
		return;

	default:
		cout << "Wrong choice" << endl;
		break;
	}
}

#endif

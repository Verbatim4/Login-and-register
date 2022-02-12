#pragma once
#ifndef SIGNUP_H_
#define SIGNUP_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

bool user_check(string username) {
	// TODO: make username check ban special chars
	if (username.find(',') != string::npos || username.find(' ') != string::npos)
	{
		cout << "No commas or spaces are allowed in a username.\b";
		return false;
	}

	return true;
}

bool pass_check(string password) {
	// TODO: make password check ban all special chars
	if (password.find(',') != string::npos || password.find(' ') != string::npos)
	{
		cout << "No commas or spaces are allowed in a password.\n";
		return false;
	}

	bool has_num = false;
	bool has_upper = false;

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i]))
		{
			has_num = true;
		}
		if (isupper(password[i]))
		{
			has_upper = true;
		}
	}

	if (!has_num || !has_upper)
	{
		cout << "Password need at least one number and uppercase letter.\n" << endl;
		return false;
	}

	if (password.length() <= 8) {
		cout << "Password must be at least 8 characters long.\n" << endl;
		return false;
	}

	return true;
}

bool user_exists(string username) {
	string text = "";
	ifstream logins("logins.txt");
	while (getline (logins, text)) {
		string user = text.substr(0, text.find(':'));

		if (user == username){
			return true;
		}
	}
	return false;
}

void enter_users(string file, string username, string password) {
	ofstream logins_enter(file, ios::app);
	logins_enter << username << ":" << password << endl;
	logins_enter.close();
	return;
}

void sign_up() {

	string username = "";
	string password = "";
	string verify = "";

	cout << "Enter a username: ";
	getline(cin, username);

	cout << "Enter a password: ";
	getline(cin, password);

	cout << "Verify your password: ";
	getline(cin, verify);


	if (!user_check(username))
		return;

	if (!pass_check(password))
		return;

	if (password != verify)
	{
		cout << "Passwords do not match.\n";
		return;
	}

	if (user_exists(username)) {
		cout << "Username already exists.\n";
		return;
	}

	enter_users("logins.txt", username, password);
	cout << "Sign up successful.\n";
}

#endif

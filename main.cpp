#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "login.hpp"
#include "signup.hpp"

using namespace std;

int main() 
{	
	char l_or_r;
	cout << "Do you want to Login(L) or Register(R)?";
	cin >> l_or_r;
	l_or_r = toupper(l_or_r);

	if (l_or_r == 'L')
		login();
	else if (l_or_r == 'R')
		sign_up();
	else
		cout << "Invalid input.\n";

	return 0;
}
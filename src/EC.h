#ifndef EC_H
#define EC_H

#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void Command_Prompt()
{
	char* name = getlogin();

	if (!name)
	{
		cout << "Error: Could not retrieve login information." << endl;
		exit(EXIT_FAILURE);
	}

	char login_name[256];
	int check = gethostname(login_name, 255);

	if (check == -1)
	{
		cout << "Error: Could not retrieve login information." << endl;
		exit(1);
	}

	cout << name << "@" << login_name << "$ ";
	//test
}


#endif

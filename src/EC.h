#ifndef EC_H
#define EC_H

#include <iostream>
#include <cstdlib>

#include <unistd.h>

using namespace std;

void prompt(){
	char* name = getlogin();

	if (name == NULL)
	{
		cout << "Error: Cannot get login info." << endl;
		exit(1);
	}	

	char hostname[256]; 

	int hostcheck = gethostname(hostname, 255);

	if(hostcheck == -1)
	{
		cout << "Error: Cannot get login info." << endl;
		exit(1);
	}
	cout << name << "@" << hostname << "$ ";

}

#endif
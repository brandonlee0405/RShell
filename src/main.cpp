/* 
#############
Neel Sethia
Brandon Lee
############# 
*/
   
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "rshell.h"
#include "execute.h"
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
	char hostName[512];
	//char loginName[512];
	char* loginName = getlogin();
	gethostname(hostName, 255);
	string userInput;
/*
	do
	{
		cout << loginName << "@" << hostName << "$ ";
		getline(cin, userInput);	
	} while (userInput.empty()); //continue for when else to keep loop running.
	//execution and parsing will be done below after rshell and command are
	//given further implementation
*/	
		cout << loginName << "@" << hostName << "$ ";
	Rshell r;
	r.parse();
	
	
	
	
	
/*	only for reference, not used code. 
void Command_Prompt()
{
	char* name = getlogin();
	if (!name)
	{
		cout << "Error: Could not retrieve login information." << endl;
		exit(1);
	}

	char login_name[256];
	int check = gethostname(login_name, 255);
	if (check == -1)
	{
		cout << "Error: Could not retrieve login information." << endl;
		exit(1);
	}

	cout << name << "@" << login_name << "$ ";
}

*/
	
	
	//bool check_exit = false;
	
	
	
	return 0;
}

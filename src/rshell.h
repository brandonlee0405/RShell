#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>

#include "command.h"
#include "EC.h"

using namespace std;

class Rshell 
{
    private:
    
    
    public: 
        void parse()
        {
            string cmd;
		
		// Executes the Extra Credit line
		Command_Prompt();
		
		char arr1[512];
		char arr2[512];
		
		// Gets the input of the user
		cin.getline(arr2,512);
		
		// Iterates through the input to locate if '#' exists
		for (unsigned i = 0; arr2[i] != NULL; ++i)
		{
			if (arr2[i] == '#')
			{
				strncpy(arr1, arr2, i);
				arr1[i] = NULL;
				break;
			}
			if (i == (strlen(arr2) - 1));
			{
				strncpy(arr1, arr2, (i + 1));
				arr1[i + 1] = NULL;
			}
		}
		
		vector<string> vector_separator;
		
		for (unsigned i = 0; i < 512; ++i)
		{
			if (arr1[i] == "|")
			{
				vector_separator.push_back("||");
				++i;
			}
			if (arr1[i] == "&")
			{
				vector_separator.push_back("&&");
				++i;
			}
			if (arr1[i] == ";")
			{
				vector_separator.push_back(";");
			}
		}
		
		
		// Using the strtok, split the user input into tokens and store it to a
		//new std::vector<T> ;
		vector<char *> vector_command;
		char *pointer;
		
		pointer = strtok(arr1, ";|&");
		while (pointer != NULL)
		{
		   vector_command.push_back(pointer);
		   pointer = strtok(NULL, ";|&");
		}
		
            
        }
        
    
};
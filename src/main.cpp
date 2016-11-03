/* 
#############
Neel Sethia
Brandon Lee
############# 
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "EC.h"
#include "execute.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool check_exit = false;

	do
	{
		prompt();

		char arr1[512]; 
		char arr2[512];
		
    	vector<vector<char *> > cmd_list;
    	vector<char *> temp_cmds;

		cin.getline(arr2,512);

		// Iterates through the input to locate if '#' exists
		for (unsigned i = 0; arr2[i] != '\0'; ++i)
		{
		    if (arr2[i] == '#')
		    {
			    strncpy(arr1, arr2, i);
			    arr1[i] = '\0';
			    break;
		    }
    		if (i == (strlen(arr2) - 1))
    		{
    			strncpy(arr1, arr2, (i + 1));
    			arr1[i + 1] = '\0';
    		}
    	}

    	vector<string> vector_separator;
    		
    	for (unsigned i = 0; i < 512; ++i)
    	{
    		if (arr1[i] == '|')
    		{
    			vector_separator.push_back("||");
    			++i;
    		}
    		if (arr1[i] == '&')
    		{
    			vector_separator.push_back("&&");
    			++i;
    		}
    		if (arr1[i] == ';')
    		{
    			vector_separator.push_back(";");
    		}
    	}
    		
    	// Using the strtok, split the user input into tokens and store it
    	// to a new vector;
    	vector<char *> vector_command;
    	char *pointer;
    	
    	pointer = strtok(arr1, "&|;");
    	while (pointer != NULL)
    	{
    	   vector_command.push_back(pointer);
    	   pointer = strtok(NULL, "&|;");
    	}
    		
    	// Gets rid of quotations when echoing user input
    	// i.e: echo "print" --> print (not "print")
    	for (unsigned i = 0; i < vector_command.size(); ++i)
    	{
    	    for (unsigned j = 0; vector_command.at(i)[j] != '\0'; ++j)
    	    {
    	        if (vector_command.at(i)[j] == '\"')
    	        {
    	            for (unsigned t = j; vector_command.at(i)[t] != '\0'; ++t)
    	            {
    	                vector_command.at(i)[t] = vector_command.at(i)[t + 1];
   		            }
   		        }
   		    }
   		}
    		
    		
    	// If needed, remove whitespace by using a for loop with an if statement
    	/*
    	    for (unsigned i = 0; i < vector_command.size(); ++i)
    	    {
    	        if (vector_command.at(i)[0] == ' ')
    	        {
    	            vector_command.at(i)++;
    	        }
    	    }
    	*/
    	
    	
    	char *pointer2;
    	for (unsigned i = 0; i < vector_command.size(); ++i)
    	{
    	    pointer2 = strtok(vector_command.at(i), " ");
    	    while (pointer2 != NULL)
    	    {
    	        temp_cmds.push_back(pointer2);
    	        pointer2 = strtok(NULL, " ");
    	    }
    	    cmd_list.push_back(temp_cmds);
    	    
    	    temp_cmds.clear();
    	}
    	Execute te;
    	te.isExecute(vector_separator, cmd_list, check_exit);

    	// Clears the vectors, arrays, pointers
    	for (unsigned i = 0; i < 512; ++i)
    	{
    	    arr1[i] = '\0';
    	    arr2[i] = '\0';
    	}
    	vector_command.clear();
    	vector_separator.clear();
    	pointer = NULL;
    	cmd_list.clear();
    	temp_cmds.clear();

	}while (!check_exit);
	
	return 0;
}



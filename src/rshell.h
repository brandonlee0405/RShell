#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <unistd.b>
//include boost libraries 



#include "command.h"
#include "EC.h"

using namespace std;

class Rshell 
{
    private:
    
        string cmd;
    
    public: 
    
        /*
        Function call to do everything
        
            isExecute(vector_separator, vector_command, ...);
        
        */
        
        
        // Constructor
        void rshell(string &c)
        {
            cmd = c;
        }
        // We will parse the input here
        void parse()
        {
            /* need to modify this and below code to our new main
               as we now retrieve userinput from the main and it is stored
               as cmd.
               */
            // below, specify which is which
            
            
		    char arr1[512]; 
		    char arr2[512];
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
    		                vector_command.at(i)[t] = vector_command.at(i)[k + 1];
    		            }
    		        }
    		    }
    		}
    		
    		
    		// If needed, remove whitespace by using a for loop with an if statement
    		/*
    		    for (unsigned i = 0; i < vector_command.size(); ++i)
    		    {
    		        if (vector_command.at(i)[0] == " ")
    		        {
    		            vector_command.at(i)++;
    		        }
    		    }
    		
    		*/
    		
    		vector<vector<char *> > cmd_list;
    		vector<char *> test_cmds;
    		
    		char *pointer2;
    		for (unsgined i = 0; i < vector_command.size(); ++i)
    		{
    		    pointer2 = strtok(vector_command.at(i), " ");
    		    while (pointer != NULL)
    		    {
    		        test_cmds.push_back(pointer2);
    		        pointer2 = strtok(NULL, " ");
    		    }
    		    cmd_list.push_back(test_cmds);
    		    
    		    test_cmds.clear();
    		}
    		
    		isExecute(vector_separator, cmd_list);
    		
    		
    		
    		// Clears the vectors, arrays, pointers
    		for (unsigned i = 0; i < 512; ++i)
    		{
    		    arr1[i] = '\0';
    		    arr2[i] = '\0';
    		}
    		vector_command.clear();
    		vector_separator.clear();
    		pointer = '\0';
        }
};
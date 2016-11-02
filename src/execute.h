#ifndef EXECUTE_H
#define EXECUTE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/stat.h> 


using namespace std;

class Execute
{
    
    private:
        
        
    public:
        //add in constructor after main execution
        int Execution()
        {
            /*  in here we will handle forking, execvp, and PID's 
                see manpages for these things as well as director checking
                etc.
            */ 
            
        }
    
    
        isExecute(vector<string> separator, vector<vector<char *> > command)
        {
            string exit = "exit";
            
            if (separator.size() == 1)
            {
                if (strcmp(command.at(0).at(0), exit.c_str()) == 0)
                {
                    // this needs to exit the terminal
                    
                    
                    return;
                }
            }
        }
};

#endif

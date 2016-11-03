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
#include <unistd.h>
#include <boost/algorithm/string.hpp>


using namespace std;



class Execute
{
    
    private:
        int counter; //counts processes to run
    public:
        //add in constructor and other functions after main execution
        char** execArgs(vector<char*>& vin)
		{
			char** tempArgv = &vin[0];	
			return tempArgv;
		}

        int Execution(vector<vector<char *> > cmd)
        {
            /*  in here we will handle forking, execvp, and PID's 
                see manpages for these things as well as directory checking, 
                perror, etc.
            */ 
            int negStat = -1;
          

            // TODO: this part
			vector<char *> temp;
			temp = cmd[0];			//gets the first row of commands
				
			char** arg[512];
			memset(arg, '\0', sizeof(arg)); 
			

            //TODO: check for exit then return a status value
			for (int i = 0; i < temp.size(); ++i)
			{
				if (temp.at(i) == "exit")
				{
					return negStat;
				}
			}
            
            //use all this later, need to run preliminary arguments
            pid_t pid; 
            pid_t waitid;
            int status;
            //char const* cmdexe = ("ls", "-a", NULL);
            
            // creates child
            pid = fork();
            // if pid < 0 then it's an error
            if (pid < 0)
            {
                perror("Error occurred!");
            }
            // pid == then child
            else if (pid == 0)
            {
				cout << "I am executing" << endl;
                if (execvp(arg[0], arg) < 0)
                {
                    cout << "-bash: " << arg[0] << " : command not found"
                    << endl;
                    //_exit() call exit here to kill the process if te execvp 
                    //does not work with inputted commands. 
                }
                _exit(0); //kills child processes and will return 0 as usual
            }
			waitpid(-1, &status, 0);
            
        }
		 
    
        void isExecute(vector<string> separator, vector<vector<char *> > command)
        {
            string exit = "exit";
            string clear = "clear";
            int temp_clear = 0;
            
            int command_size = command.size();
            int separator_size = separator.size();
            bool size_valid = true;
            
            if (separator.size() == 0)
            {
                if (command.size() == 1)
                {
                    // Checks if there is exit
                    if (strcmp(exit.c_str(), command.at(0).at(0)) == 0)
                    {
                        // this needs to exit the terminal
                        
                        
                        return;
                    }
                    
                    // Checks if there is clear
                    else if (strcmp(clear.c_str(), command.at(0).at(0)) == 0)
                    {
                        temp_clear = 1;
                    }
                }
            }
            
            if (command_size == 0)
            {
                if (separator_size != 0)
                {
                    cout << "Error: No commands preceeding connector" << endl;
                    size_valid = false;
                }
                else
                {
                    return;
                }
            }
           
		   /*
            if (command_size <= separator_size)
            {
                if (temp_clear != 1)
                {
                    cout << "Error" << endl;
                    return;
                }
            }
			*/
            if (size_valid)
            {
                Execution(command);
            }
            
        }
};

#endif

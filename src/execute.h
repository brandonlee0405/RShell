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
        
        char** execArgs(vector<char*>& vin, const int &ind)
        {
            //arg for use with execvp in execution
            char** arg;
            string temp;
            string holdArg = userInput.at(ind); //holds the userInput at 
            //whatever index is called
            vector<string> tempVec;
            /*  IMPORTANT!! VALIDATE IMPLEMENTATION
            //split the holdArg into tempVec here using the 
            //boost library 
            */ 
            boost::split(tempVec, holdArg, boost::is_any_of(" "));
            
            if (tempVec.at(0) == "echo")
            {
                //still need to convert this to c_string
                //this will only push back the first element but
                //will not take care of a string with multiple words
                //handle after the statement below
                //vin.push_back(tempVec.at(0).c_str());
                
                //from here we will handle any input after the first element 
                for (int i = 1; i < tempVec.size(); ++i)
                {
                    if (temp.empty())
                    {
                        temp = tempVec.at(i);
                    }
                    else
                    {
                        temp = temp + " " + tempVec.at(i);
                    }
                }
                //need to effectively convert this to c string as well
                //vin.push_back(temp.c_str());
            }
            //here we will take other commands for handling within
            //execution after storing them in vectors
            else
            {
                for (int i = 0; i < tempVec.size(); ++i)
                {
                    //need to convert this too
                    //vin.push_back(tempVec.at(i).c_str());
                }
            }
            vin.push_back(NULL);
            
            //assigns char** arg the first element of vin
            arg = &vin.at(0); 
            
            return arg;
            
            
        }
        int Execution()
        {
            /*  in here we will handle forking, execvp, and PID's 
                see manpages for these things as well as directory checking, 
                perror, etc.
            */ 
            int negStat = -1;
            vector <char*> charVec;
            
            //check for exit then return a status value
            if (userInput.at(getSize()).find("exit") != string::npos)
            {
                return negStat;
            }
            
            
            //use all this later, need to run preliminary arguments
            pid_t pid; 
            pid_t waitid;
            int status;
            char const* cmdexe = ("ls", "-a", NULL);
            
            // creates child
            pid = fork();
            // if pid < 0 then it's an error
            if (pid < 0);
            {
                perror("Error occurred!");
            }
            // pid == then child
            else if (pid == 0)
            {
                if (execvp(arg[0], arg) < 0)
                {
                    cout << "-bash: " << arg[0] << " : command not found"
                    << endl;
                    //_exit() call exit here to kill the process if te execvp 
                    //does not work with inputted commands. 
                }
                _exit(0); //kills child processes and will return 0 as usual
            }
            
        }
    
    
        isExecute(vector<string> separator, vector<vector<char *> > command)
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
            
            if (command_size <= separator_size)
            {
                if (temp_clear != 1)
                {
                    cout << "Error" << endl;
                    return;
                }
            }
            
            if (size_valid)
            {
                Execution(separator, );
            }
            
        }
};

#endif

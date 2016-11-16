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
//#include <boost/algorithm/string.hpp>

#include "isTest.h"

using namespace std;



class Execute
{
  public:

    void Execution(vector<string> separators, vector<vector<char *> > cmds, bool & exit_check, bool & check_previous, string previous, string exit1, string test, int flag_check, vector<int> & parenthesis)
    {
      for (unsigned i = 0; i < separators.size() + 1; ++i)
      {
      	char *temp_arr[512];
        memset(temp_arr, '\0', sizeof(temp_arr));

        if (separators.size() != 0)
        {
          if (i != 0)
          {
          	previous = separators.at(i - 1);
          }
        }

        if (check_previous)
      	{
        	if (previous == ";")
          {
      			for (unsigned hh = 0; hh < cmds.at(i).size(); ++hh)
          	{
          		temp_arr[hh] = const_cast<char *>(cmds.at(i).at(hh));
          	}
          	if (strcmp(temp_arr[0], exit1.c_str()) == 0)
          	{
          		exit_check = true;
          	  exit(0);
              return;
            }

            // ============= TEST ==============
            if (strcmp(temp_arr[0], test.c_str()) == 0)
            {
              Test icle;
              icle.isTest(temp_arr, check_previous);
            }
            // ==================================

            else
            {
      				pid_t PID = fork();
      				//pid_t PARENT;

      				if (PID < 0)
      				{
      					perror("Error Occurred\n");
      					exit(-1);
      				}
      				else if (PID == 0)
      				{
      					check_previous = true;
      					int run = execvp(temp_arr[0], temp_arr);
      					if (run < 0)
      					{
      						perror("Error Occurred\n");
      						check_previous = false;
      					}
      				}
            }

    			}

          else if (previous == "&&")
          {
            for (unsigned hh = 0; hh < cmds.at(i).size(); ++hh)
            {
              temp_arr[hh] = const_cast<char *>(cmds.at(i).at(hh));
            }
            if (strcmp(temp_arr[0], exit1.c_str()) == 0)
            {
              exit_check = true;
              return;
            }
            pid_t PID = fork();
            //pid_t PARENT;

            if (PID < 0)
            {
              perror("Error Occurred\n");
              exit(-1);
            }

            else if (PID == 0)
            {
              check_previous = true;
              int run = execvp(temp_arr[0], temp_arr);
              if (run < 0)
              {
                  perror("Error Occurred\n");
                  check_previous = false;
              }
            }

          }
          else if (previous == "||")
          {
            check_previous = false;
          }

        }
    		else
    		{
    			if (previous == ";")
    			{
    				for (unsigned hh = 0; hh < cmds.at(i).size(); ++hh)
    				{
    					temp_arr[hh] = const_cast<char *>(cmds.at(i).at(hh));
    				}
    				if (strcmp(temp_arr[0], exit1.c_str()) == 0)
    				{
    					exit_check = true;
    					return;
    				}

    				pid_t PID = fork();
    				//pid_t PARENT;

    				if (PID < 0)
    				{
    					perror("Error Occurred\n");
    					exit(-1);
    				}
    				else if (PID == 0)
    				{
    					check_previous = true;
    					int run = execvp(temp_arr[0], temp_arr);
    					if (run < 0)
    					{
    						perror("Error Occurred\n");
    						check_previous = false;
    					}
    				}
    			}

          else if (previous == "&&")
          {
              check_previous = false;
          }

          else if (previous == "||")
          {
            for (unsigned hh = 0; hh < cmds.at(i).size(); ++hh)
            {
              temp_arr[hh] = const_cast<char *>(cmds.at(i).at(hh));
            }
            if (strcmp(temp_arr[0], exit1.c_str()) == 0)
            {
              exit_check = true;
              return;
            }
            pid_t PID = fork();
            //pid_t PARENT;

            if (PID < 0)
            {
              perror("Error Occurred\n");
              exit(-1);
            }

            else if (PID == 0)
            {
              check_previous = true;
              int run = execvp(temp_arr[0], temp_arr);
              if (run < 0)
              {
                  perror("Error Occurred\n");
                  check_previous = false;
              }
            }
          }
        }
      }
    }
    void isExecute(vector<string> separators, vector<vector<char *> > cmds, bool & exit_check, int flag_check, vector<int> & parenthesis)
    {
    	string previous = ";";
    	string exit1 = "exit";
      string clear = "clear";
      string test = "test";
      bool check_previous = true;
      int temp_clear = 0;

      int command_size = cmds.size();
      int separator_size = separators.size();
      bool size_valid = true;

      if (separators.size() == 0)
      {
        if (cmds.size() == 1)
        {
          // Checks if there is exit
          if (strcmp(exit1.c_str(), cmds.at(0).at(0)) == 0)
          {
            // this needs to exit the terminal
            exit_check = true;
            exit(0);
          }

          // Checks if there is clear
          if (cmds.at(0).size() == 0)
          {
            return;
          }
          else if (strcmp(clear.c_str(), cmds.at(0).at(0)) == 0)
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
        Execution(separators, cmds, exit_check, check_previous, previous, exit1, test, flag_check, parenthesis);
      }
    }
};

#endif

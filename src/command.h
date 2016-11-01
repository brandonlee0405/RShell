#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

class Command
{
    
    private:
        
    public:
        void parse(char in[])
        {
            char in2[512];
            
            // Searches the input if there is a '#'
            for (unsigned i = 0; in[i] != NULL; ++i)
            {
                if (in[i] == '#')
                {
                    strncpy(in2, in, i);
                    in2[i] = NULL;
                    break;
                }
                if (i == (strlen(in) - 1))
                {
                    strncpy(in2, in, i + 1);
                    in[i + 1] = NULL;
                }
            }
        }
        
        
    private:
        //additional helper functions
        
    
    
};

#endif
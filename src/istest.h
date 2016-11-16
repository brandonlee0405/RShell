#ifndef __ISTEST_H__
#define __ISTEST_H__
#include "execute.h"

using namespace std;

class Test {
  public:
    void isTest(char* arr[512], bool &check_prev)
    {
        /* The purpose of this function is to use the test command along with
        various flags that may appear with any command entered in.
        We will use the S_ISREG and S_ISDIR macros along with stat()
        functionality to accomplish this further.
        */

        struct stat sb;
        bool isDir; //checks if directory
        bool isFile; //checks if it is a file
        string flag;
        flag = arr[1];
        //set flag to whatever is after the brackets; i.e -e, -d, -f

        //checks whether the flag is valid
        if (flag != "-e" || flag != "-f" || flag != "-d")
        {
          //if null, return default as "-e" flag
          if (arr[2] == '\0')
          {
            flag = "-e";
          }
          //return error if not
          else
          {
            cout << "Error. Did not use -e, -d, or -f" << endl;
            exit(1);
          }
        }

        //test cases to follow

        //check if flag is "-e"
        if (flag == "-e")
        {

          bool isDir = S_ISDIR(sb.st_mode);

          bool isFile = S_ISREG(sb.st_mode);

          if (isFile == true || isDir == true)
          {
            cout << "(True)" << endl;

            return;
          }
          else
          {
            cout << "(False)" << endl;

            return;
          }
        }

        //check if flag is "-d"
        if (flag == "-d")
        {

        }

    }
};


#endif

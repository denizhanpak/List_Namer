//Denizhan Pak
//Iterates through a directory and renames all files in a list
//Created: April 19, 2017
#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

class List_Namer{
    public:
        //Methods
        List_Namer(char* p, char* nn, char* cn);
        void traverse(DIR *directory);
        void renamer(struct dirent *file);
    protected:
        //Variables
        string path;
        string newName;
        string currentNum;
};

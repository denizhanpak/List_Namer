//Denizhan Pak
//Iterates through a directory and renames all files in a list
//Created: April 19, 2017

/* To Do add traversal for nested directories*/

#include <vector>
#include <string>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "List_Namer.h"

using namespace std;

//Constructor for class
List_Namer::List_Namer(char * p, char * nn, char * cn){
    DIR *directory;

    //Assignments
    path = p;
    path += "/";
    newName = nn;
    currentNum = cn;

    //Open Directory
    directory = opendir(p);
    if (directory == NULL) {
        fprintf(stderr, "Couldn't open %s", path.c_str());
        exit(1);
    }

    //Traverse
    traverse(directory);
}

//Traverses content of folder
void List_Namer::traverse(DIR *directory){
    int i;
    struct dirent *file;
    vector <char *> files;

    //Acquire files ignoring hidden files
    for(file = readdir(directory); file != NULL; file = readdir(directory)){
        if(file->d_name[0] != '.'){
            renamer(file);
            i = stoi(currentNum);
            i++;
            currentNum = to_string(i);
        }
    }
}

//Changes name of the files using original path
void List_Namer::renamer(struct dirent *file){
    string oldname, newname;

    //Save old name
    oldname = path;
    oldname += file->d_name;

    //Create new name
    newname = path + newName + currentNum + ".png";

    rename(oldname.c_str(), newname.c_str());
}

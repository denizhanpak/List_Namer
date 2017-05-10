//Denizhan Pak
//Iterates through a directory and renames all files in a list
//Created: April 19, 2017
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>

#include "List_Namer.h"

using namespace std;

int main(int argc, char **argv){
    struct stat buf;
    int exists;
    DIR *d;
    struct dirent *de;
    string name;

    //Usage error
    if(argc != 4){
        fprintf(stderr, "usage: list_namer [directory] [newname] [start_number]\n");
        exit(1);
    }

    new List_Namer(argv[1], argv[2], argv[3]);    
}

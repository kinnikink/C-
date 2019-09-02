//all imported libraries used for this program
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

using namespace std;

bool found = false;

static void getTimestamp(string directory_name, string file_name, const char * dname, const char* dirname);
static void findFile (const char * direct_name, string searchfile) {
    DIR * directory;
    directory = opendir (direct_name);//searches inside the current working directory
    struct dirent * dptr;
    const char * d_name;
    const char * file = searchfile.c_str();
    while ((dptr = readdir (directory)) != NULL) {//make sures the directory is not empty
        d_name = dptr->d_name;//pointer that points to the name of the directory
        if (!(dptr->d_type & DT_DIR)) {
            if(dptr->d_name == searchfile){
                found = true;
                string directory_name = direct_name;
                string file_name = d_name;
                getTimestamp(directory_name, file_name, d_name, direct_name);
            }//closes if statement on line 27
        }//closes if statement on line 26
        if (dptr->d_type & DT_DIR) {
            if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0){
                char path[256];
                snprintf (path, 256,"%s/%s", direct_name, d_name);
                findFile (path, file);
            }//closes if statement on line 35
        }//closes if statement on line 34
    }//closes while loop on line 24
    closedir (directory);
}//closes findFile function

//function to print the timestamp
static void getTimestamp(string directory_name, string file_name, const char* d_name, const char* dir_name){
    cout << endl << "Match Found for File: " << d_name << endl << endl;//
    struct tm *tm;
    
    //determines if a given dirent structure is a directory or a file
    struct stat statStruct;        string str = directory_name + "/" + file_name;
    stat(str.c_str(), &statStruct);
    tm = localtime(&statStruct.st_mtime);
    cout << endl << "Last Modified Date and Time: " << asctime(tm) << endl;//prints the last modified date and time
    
    tm = localtime(&statStruct.st_atime);
    cout << endl << "Last Access Date and Time: " << asctime(tm) << endl;//prints last access date and time of the file
    
    tm = localtime(&statStruct.st_ctime);
    cout << endl << "Last Changed Date and Time: " << asctime(tm) << endl;//prints the last changed date and time
    
    cout << endl << "Inode number of File: " << statStruct.st_ino << endl;//prints inode number
    
    cout << endl << "UID of File: " << statStruct.st_uid << endl;//prints the User ID
    
    cout << endl << "GID of File: " << statStruct.st_gid << endl;//prints the Group User ID
    
    
    cout << endl << endl << "Pathname for " << d_name << ": " << dir_name << "/" << d_name << endl << endl << endl;
}//closes get Timestamp function
int main (int argc, char * argv[]) {
    if(argc != 2){//if the user tries to search for more than 1 file
        cout << "You must enter exactly one argument, the file to search for." << endl;//error message
    }//closes if statement on line 72
    else{
        
        char getcurrentdir[256];
        findFile (getcwd(getcurrentdir, 255), argv[1]);
        if(found == false){//function if the directory does not exist
            cout << endl <<"File { " << argv[1] << " } not found" << endl << endl;//error message if user enters a file name that is not in the directory
        }//closes if statement on line 79
        return 0;
    }//closes else statement on line 75
}//closes main function


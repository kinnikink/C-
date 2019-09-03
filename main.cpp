#include <iostream>
#include "kinnikink_BST.h"
#include <sstream>
#include <fstream>
#include <string> //for converting strings to ints
#include <windows.h>
#include <dirent.h>

using namespace std;

int main(void) {
    BST leaf;
    int i = 0;
    ifstream user_file;
    string file_name;
    char begin_sequence;
    char command; //input char for what the user would like to do
    int Number_input = 0; //the number input for finding or deleting from the Binary Search Tree
    string holder; //holds the conversion for when we read nunbers from the file
    int number_from_file; //where the converted numbers are stored
    int number_of_lines = 0;
    cout << "Welcome to Binary Tree Maker 2500!" << endl;
    cout << "Please enter \"b\" to begin!" << endl;
    cin >> begin_sequence;
    while (begin_sequence != 'b') {
        cout << "Invalid input. Please enter \"b\" to begin!" << endl;
        cin >> begin_sequence;
    }
    if (begin_sequence == 'b') {
        cout << "Valid input. Welcome!" << endl;
    }
    cout << "---------------------------------------------" << endl;
    cout << "|\"d\" to delete from the Tree                |" << endl;
    cout << "|\"f\" to find an entry within the Tree       |" << endl;
    cout << "|\"h\" to show the options menu               |" << endl;
    cout << "|\"i\" to import a file into the program      |" << endl;
    cout << "|\"p\" to print all data in the Binary Tree   |" << endl;
    cout << "|\"q\" to quit the program                    |" << endl;
    cout << "|\"r\" to find the range between 2 values      |" << endl;
    cout << "|\"s\" to show all available files            |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
    while (begin_sequence == 'b') {
        cout << "What would you like to do?" << endl;
        cin >> command; //asking the user for what they would like to do
            if (command == 'i' || command == 'I') { //for importing numbers.txt into the program. This must be the first command if they plan to interact with the Tree
                cout << "Please enter the name of the file:\t";
                cin >> file_name;
                user_file.open(file_name.c_str()); //opens the user-defined file
                if(user_file.is_open()) {
                    cout << "File Found!\n";
                    while (getline(user_file,holder)) {
                       number_of_lines++;
                    }
                    user_file.close(); //closes the file
                    user_file.open(file_name.c_str());
                    for (i=0;i<=number_of_lines;i++) { //this whole for loop converts the numbers found within the file from strings to ints.
                          getline(user_file,holder);
                          stringstream ss_converter(holder);
                          ss_converter >> number_from_file;
                          leaf.add(number_from_file); //the number is then added
                    }
                }
                else { //if the user did not input the correct file name
                    cout << "\nError: File was not found.\n";
                    cout << "\"" << file_name << "\" does not exist.\n";
                }
            }
            if (command == 'd' || command == 'D') { //if the user wants to delete a number from the tree
                cout << "Please enter the number you would like to delete:   ";
                cin >> Number_input; //user inputs the number they wish to delete
                leaf.del(leaf.head,Number_input);

            }
            if (command == 'h' || command == 'H') { //this command re-displays the command menu
                cout << "---------------------------------------------" << endl;
                cout << "|\"d\" to delete from the Tree                |" << endl;
                cout << "|\"f\" to find an entry within the Tree       |" << endl;
                cout << "|\"h\" to show the options menu               |" << endl;
                cout << "|\"i\" to import a file into the program      |" << endl;
                cout << "|\"p\" to print all data in the Binary Tree   |" << endl;
                cout << "|\"q\" to quit the program                    |" << endl;
                cout << "|\"r\" to find the range between 2 values      |" << endl;
                cout << "|\"s\" to show all available files            |" << endl;
                cout << "---------------------------------------------" << endl;
            }
            if (command == 'p' || command == 'P') {/*EXTRA--CREDIT: prints the entire list in order and with the height at which each entry is found
                                                                      within the tree*/
                leaf.printTree(leaf.head);
                cout << endl;
            }
            if (command == 'q' || command == 'Q') { //quits the program
                cout << "We hope you enjoyed your experience with Binary Tree Maker 2500!" << endl; //exit message
                return 0; //program shuts down
            }
            if (command == 'f' || command == 'F') { //for finding a number within the tree
                    cout << "Please enter the value you would like to find:   ";
                    cin >> Number_input; //user inputs the value they wish to find
                    leaf.findVal(Number_input,leaf.head);
            }
            if (command == 'r' || command == 'R') {  //for finding a number between the min and the max
                cout << "Minimum Value:  ";
                int minimum_value;
                cin >> minimum_value;
                cout << "Maximum Value:  ";
                int maximum_value;
                cin >> maximum_value;
                cout << "Performing search...";
                leaf.findRange(minimum_value,maximum_value,leaf.head); //performs the search with the numbers input by the user
            }
            if (command == 's' || command == 'S') {
            string conversion;
            DIR *dpdf;
            struct dirent *epdf;
            dpdf = opendir("./");
                if (dpdf != NULL){
                    while (epdf = readdir(dpdf)){

                        stringstream ss_converter(epdf->d_name);
                        ss_converter >> conversion;
                        cout << conversion;
                        cout << endl;

                    }
                }
            closedir(dpdf);
            }

    }
}



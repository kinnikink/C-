#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
        string file_name;
        cout << "Enter quit to enter  program." << endl;
        cout << "Enter the name of file: ";
        cin >> file_name;
        string word;;
        int num;
        ifstream file;
        try{
            while(word.compare ("quit") != 0){
                try{
                    cout << "Enter a word: ";
                    cin >> word;
                    cout << "Enter an integer number: ";
                    cin >> num;
                    if(cin.fail()){
                        throw string ("Not a number");
                    }
                    file.open(file_name.c_str());
                    if(!file.is_open()){
                        throw file_name;
                    }
                    int line =1;;
                    string file_string;
                    int fileNum;
                    while(file >> file_string >> fileNum){
                        if(word == file_string && num == fileNum){
                            cout << "Match found on line: " << line << endl;
                            break;
                        }
                        line++;
                    }
                    if(file.eof()){
                        cout << "Match not found." << endl;
                    }
                    file.close();
                }
                catch(string not_a_number){
                    cout << "Not a number! " << "Program Exited" << endl;
                    return 0;
                }
            }
        }
        catch(string fileNotopened){
            cout << "Unable to open the file! " << "Program Exited" << endl;
            return 121;
            }
            }

#ifndef HOMEWORK2_STUDENTS_H_INCLUDED
#define HOMEWORK2_STUDENTS_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> //how i converted strings into other data types.

using namespace std;

class Students{
public:
    string f_name;
    string l_name;
    int stdnt_id;
    double gpa;
    int num_creds;

    // These can be used in main function.
    Students();
    ~Students();
    int getYear(string Year);
    bool honorStudent(string GPA);
    bool probation(string GPA);
    string getName(); //unused.
    int getId(string ID_NUM);
    double GPA_converter(string GPA);
    void setValues(string fn, string ln, int id, double g, int cred);
    void printFunctionHonor(double greatest_array[], int ID_array[], int honor_array[], int year_array[], string fnames_array[], string lnames_array[], int lines);
    void printFunctionHonorNotTop(double greatest_array[], int ID_array[], int honor_array[], int year_array[],string fnames_array[], string lnames_array[], int lines);

};


#endif // HOMEWORK2_STUDENTS_H_INCLUDED

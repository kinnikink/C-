#include "kinnikink_Students.h"

Students::Students() { //initializes variables
    f_name = "no";
    l_name = "no";
    stdnt_id = 0;
    gpa = 0.00;
    num_creds = 0;
}
Students::~Students() { //deconstructors variables after they're used and not needed anymore.
    f_name = "no";
    l_name = "no";
    stdnt_id = 0;
    gpa = 0.00;
    num_creds = 0;
}

int Students::getYear(string Year){ //converts string year into int year.
    int num_creds = 0;
    stringstream ss(Year);
    ss >> num_creds;
    return num_creds;
}
bool Students::honorStudent(string GPA){ //finds if a student is on the honor roll.
double GradePointAverage = 0;
stringstream ss(GPA);
ss >> GradePointAverage;
gpa = GradePointAverage;
    if (gpa >= 3.5) { // if a student's GPA is greater than 3.5 (on honor roll), return 1(true).
        return true;
    }
    else {
    return false;
    }
}
double Students::GPA_converter(string GPA) { //converts string GPA into double GPA
    double GradePointAverage = 0;
    stringstream ss(GPA);
    ss >> GradePointAverage;
    return GradePointAverage;
}
bool Students::probation(string GPA){ //finds if  student is on probation.
double GradePointAverage = 0;
stringstream ss(GPA);
ss >> GradePointAverage;
gpa = GradePointAverage;
    if (gpa < 2.5) { //if a student's GPA is less than 2.5(on probation)
        return true;
    }
    else {
        return false;
    }
}
string Students::getName(){ //unused

}
int Students::getId(string ID_NUM){ //converts string ID into int ID
    int ID = 0;
    stringstream ss(ID_NUM);
    ss >> ID;
    stdnt_id = ID;
    return stdnt_id;
}
void Students::setValues(string fn, string ln, int id, double g, int cred){ //Initializes the values for our elements (ID number, year, ect.)
    f_name = fn;
    l_name = ln;
    stdnt_id = id;
    gpa = g;
    num_creds = cred;
}


void Students::printFunctionHonor(double greatest_array[], int ID_array[], int honor_array[], int year_array[],string fnames_array[], string lnames_array[], int lines) { //output for when a student IS the highest GPA.
int i = 0; //primary counter.
    for (i=0;i<lines;i++) {
        if(honor_array[i] == 1 && greatest_array[i] > 0){
        cout <<fnames_array[i] << " " << lnames_array[i];
        cout << "\t\t";
        cout << ID_array[i] << "   ";
        cout << "\t    ";
                if (year_array[i] >= 0 && year_array[i] <= 29) {
                cout << "   Freshman";
                }
                if (year_array[i] >= 30 && year_array[i] <= 59) {
                cout << "   Sophomore";
                }
                if (year_array[i] >= 60 && year_array[i] <= 89) {
                cout << "   Junior";
                }
                if (year_array[i] >= 90) {
                cout << "   Senior";
                }
            cout << endl;
        }
    }
}

void Students::printFunctionHonorNotTop(double greatest_array[], int ID_array[], int honor_array[], int year_array[],string fnames_array[], string lnames_array[], int lines) { //output for when a student is NOT the highest GPA.
int i = 0;
    for (i=0;i<lines;i++) {
        if(honor_array[i] == 1 && greatest_array[i] == 0){
        cout <<fnames_array[i] << " " << lnames_array[i];
        cout << "\t\t";
        cout << ID_array[i] << "   ";
        cout << "\t    ";
                if (year_array[i] >= 0 && year_array[i] <= 29) {
                cout << "   Freshman";
                }
                if (year_array[i] >= 30 && year_array[i] <= 59) {
                cout << "   Sophomore";
                }
                if (year_array[i] >= 60 && year_array[i] <= 89) {
                cout << "   Junior";
                }
                if (year_array[i] >= 90) {
                cout << "   Senior";
                }
            cout << endl;
        }
    }
}

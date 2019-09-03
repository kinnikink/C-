#ifndef KINNIKINK_CUSTOMERS_H
#define KINNIKINK_CUSTOMERS_H
#include <iostream>
#include <string>
#include <time.h>    //included for time stamps
#include <windows.h> //included for time stamps
using namespace std;

class kinnikink_Customers{
    public:
        kinnikink_Customers();
       ~kinnikink_Customers();
       string name;         //customer's name
       string arrived;      // customer's arrival time
       int place;           //the customer's place within the linked list
       double time_waited;
       string getName();
       string getArrived();
       int getPlace(int position);
       void updatePlace(int p);
       void printTimeWaited(double time, int situation);
};

#endif // KINNIKINK_CUSTOMERS_H

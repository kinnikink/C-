#include "kinnikink_Customers.h"
#include "kinnikink_LinkedList.h"

kinnikink_Customers::kinnikink_Customers()
{

}

kinnikink_Customers::~kinnikink_Customers()
{

}

string kinnikink_Customers::getName() {
string Name;
cout << "Name: ";
cin >> Name; //asks user for a customer's name
name = name;
return Name;
}

string kinnikink_Customers::getArrived() {
string arrive;
cout << "time arrived: ";
cin >> arrive; //asks user what time the customer arrives
arrived = arrive;
return arrive;
}

int kinnikink_Customers::getPlace(int position) {
return position;
}

void kinnikink_Customers::updatePlace(int p) {
}

void kinnikink_Customers::printTimeWaited(double time, int situation) { //converts the time we got into a HOURS--MINUTES--SECONDS
    time_waited = time;
    int minutes = 0;
    int hours = 0;
    minutes = time_waited / 60;  // time in seconds converted to minutes
    hours = minutes / 60;        // minutes converted to hours
    int minutes_scaler = 0;
    int hours_scaler = 0;
        if(minutes >= 1) {
          minutes_scaler = minutes * 60;
          time_waited = time_waited - minutes_scaler; // can't have negative time intervals
        }
        if(hours >= 1) {
         hours_scaler = hours * 60;
         minutes = minutes - hours_scaler;
        }
    if (situation == 0) { //  if a customer has been deleted or helped
        cout << "This customer had to wait " << hours << " hours  " << minutes << " minutes " << time_waited << " seconds.\n";
    }
    if (situation == 1) { // if a customer was searched for
        cout << "This customer has had to wait " << hours << " hours  " << minutes << " minutes " << time_waited << " seconds  so far.\n";
    }
}

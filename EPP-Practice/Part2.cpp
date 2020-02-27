#include <iostream>
#include "Header2.h"


int main(){

Booking myticket;

    myticket.checkin("Tony", "Mandela", "First");
    myticket.checkin("Susan", "Lone", "Business");
    myticket.checkin("Jeffrey", "Ron", "First");
    myticket.checkin("Anthony", "Rhude", "Economy");
    myticket.checkin("Justin", "Drouin", "First");
    myticket.checkin("Don", "Goodie", "Business");
    myticket.checkin("Ashley", "Hann", "Business");
    myticket.checkin("Mark", "M.", "Economy");

    myticket.printorder();

/*
Tony Mandela (First)
Jeffrey Ron (First)
Justin Drouin (First)
Susan Lone (Business)
Don Goodie (Business)
Ashley Hann (Business)
Anthony Rhude (Economy)
Mark M. (Economy)
*/
}

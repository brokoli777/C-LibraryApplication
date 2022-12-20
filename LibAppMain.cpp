//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: LibApp module
Filename: LibAppMain.cpp
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

// Final Project Milestone 5
// LipApp Main
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include "LibApp.h"
#include "Date.h"
int main() {
   sdds::sdds_day = 10;//10
   sdds::sdds_mon = 8;//12
   sdds::sdds_year = 2022;//2021
   sdds::sdds_test = true;
   sdds::LibApp theApp("LibRecs.txt");
   theApp.run();
   return 0;
}
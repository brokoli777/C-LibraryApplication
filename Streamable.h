//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Streamable module
Filename: Streamable.h
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
using namespace std;
namespace sdds {
	class Streamable
	{
	public:
		virtual bool conIO(ios& io)const = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& istr) = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};

		
	};
	std::ostream& operator<<(std::ostream&, const Streamable&);
	std::istream& operator>>(std::istream&, Streamable&);
}
#endif 
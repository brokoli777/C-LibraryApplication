//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Book module
Filename: Book.h
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
#include "Lib.h"
namespace sdds {
	class Book: public Publication
	{
		char* authorName;
	public:
		Book();
		void setEmpty();
		Book& operator=(const Book& temp);
		Book(const Book& temp);

		char type()const;
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
		void set(int memberId = 0);
		operator bool() const;
		void pubDisplay(); 

		~Book();
	};

	
}
#endif
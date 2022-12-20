//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Publication module
Filename: Publication.h
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/


#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"
namespace sdds {


	class Publication: public Streamable
	{
		char* m_title;
		char m_shelfId[5];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		

		//ruleOfThree
		Publication& operator=(const Publication& temp);
		void setEmpty();
		Publication(const Publication& temp);


		//Modifiers:
		virtual void set(int member_id = 0);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//Queries:
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 

		const char* getTitle()const;
		virtual void pubDisplay();


		bool conIO(ios& io)const;
		ostream& write(ostream& os) const;
		istream& read(istream& istr);
		operator bool() const;

		~Publication();

	};
	std::ostream& operator<<(std::ostream&, const Streamable&);
    std::istream& operator>>(std::istream&, Streamable&);
}
#endif // !

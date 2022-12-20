//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Publication module
Filename: Publication.cpp
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
#include"Lib.h"
#include "Publication.h"
#include "Date.h"
using namespace sdds;
using namespace std;
namespace sdds {
	Publication::Publication()
	{
		m_title = nullptr;
		strcpy(m_shelfId, "\0");
		m_membership = 0;
		m_libRef = -1;
		resetDate();
		
	}
	void Publication::set(int member_id)
	{
		m_membership = member_id;
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date.setToToday();
	}

	char Publication::type()const
	{
		return 'P';
	}

	bool Publication::onLoan()const
	{
		if (m_membership != 0)
		{
			return true;
		}
		return false;
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		if (strstr(m_title, title) != nullptr)
		{
			return true;
		}
		return false;
	}

	Publication::operator const char* ()const
	{
		return m_title;
	}

	const char* Publication::getTitle()const
	{
		return m_title;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}

	bool Publication::conIO(ios& io)const 
	{
		if (&io == &cin || &io == &cout)
		{
			return true;
		}
		return false;
	}

	ostream& Publication::write(ostream& os) const
	{
		if (conIO(os))  
		{
			if (m_title != nullptr)
			{

				os << "| " << m_shelfId << " | ";
				if (m_title)
				{
					if (strlen(m_title) > SDDS_TITLE_WIDTH)
					{
						for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
						{
							os << m_title[i];
						};
					}
					else
					{
						os << std::setw(30) << std::setfill('.') << left << m_title ;
						
					}
				}
				os << " | ";
				if (onLoan())
				{
					os << m_membership;
				}
				else
				{
					os << " N/A ";
				}
				os << " | " << checkoutDate() << " |";
			}
			
		}
		else
		{
			os << type() << "\t" << getRef() << "\t" << m_shelfId <<"\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr)
	{
		istr.clear();
		delete[]  m_title;
		m_title = nullptr;
		setEmpty();
		char tempTitle[256]{};
		char tempShelfId[SDDS_SHELF_ID_LEN+2]{};
		int tempMembership{};
		int tempLibRef = -1;
		Date tempDate{};
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> tempShelfId;
			if (strlen(tempShelfId) > SDDS_SHELF_ID_LEN)
			{
				istr.setstate(ios::failbit);
				istr.ignore(2000, '\n');
			}
			cout << "Title: ";
			if (!istr.fail())
			{
				istr.ignore(2000, '\n');
				istr.getline(tempTitle, 255, '\n');
				
			}
			
			cout << "Date: ";
			if (!istr.fail())
			{
				tempDate.read(istr);
			}
		}
		else
		{

			istr >> tempLibRef;
			istr.ignore(2000, '\t');
			istr.getline(tempShelfId, SDDS_SHELF_ID_LEN + 2, '\t');
			istr.getline(tempTitle, 255, '\t');
			istr >> tempMembership;
			istr.ignore(2000, '\t');
			tempDate.read(istr);

		}
		
		if (tempDate.errCode() != 0 && !istr.fail())
		{
			istr.setstate(ios::failbit);
			
		}
		
		if (!istr.fail())
		{		
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelfId);
			set(tempMembership);
			setRef(tempLibRef);
			m_date = tempDate;	
		}

		return istr;
	}

	std::ostream& operator<<(std::ostream& os , const Streamable& S)
	{
		S.write(os);
		
		return os;
	}
	

	void Publication::setEmpty()
	{
		m_title = nullptr;
		strcpy(m_shelfId, "\0");
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}

	std::istream& operator>>(std::istream& istr, Streamable& S)
	{
		S.read(istr);
		return istr;
	}

	Publication::Publication(const Publication& temp)
	{
		setEmpty();
		*this = temp;
	}

	Publication& Publication::operator=(const Publication& temp)
	{

		if (this != &temp)
		{
			strcpy(m_shelfId, temp.m_shelfId);
			m_membership = temp.m_membership;
			m_libRef = temp.m_libRef;
			m_date = temp.m_date;
			

			if (temp.m_title != nullptr)
			{
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strlen(temp.m_title) + 1];
				strcpy(m_title, temp.m_title);
			}
		}
		return *this;
	}

	void Publication::pubDisplay()
	{
		cout << type() << "\t" << getRef() << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t";
		m_date.testOuput();
	}

	Publication::operator bool() const
	{
		if (m_title != nullptr && strcmp(m_shelfId, "\0") != 0)
		{
			return true;
		}
		return false;
	}


	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}
}

	
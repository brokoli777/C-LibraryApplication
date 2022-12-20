//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Book module
Filename: Book.cpp
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
#include <iomanip>
#include <cstring>
#include "Book.h"
namespace sdds {
	Book::Book():Publication()
	{
		setEmpty();
	}

	void Book::setEmpty()
	{
		authorName = nullptr;
	}

	Book& Book::operator=(const Book& temp)
	{
		Publication::operator =(temp);
		if (this != &temp)
		{
			if (temp.authorName != nullptr)
			{
				delete[] authorName;
				authorName = new char[strlen(temp.authorName) + 1];
				strcpy(authorName, temp.authorName);
			}
		}
		return *this;
	}

	Book::Book(const Book& temp)
	{
		setEmpty();
		*this = temp;
	}

	char Book::type()const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const
	{
		
		Publication::write(os);
		if (Publication::conIO(os))
		{
			
			if (authorName != nullptr)
			{
				os << " ";
				if (strlen(authorName) > SDDS_AUTHOR_WIDTH)
				{
					for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
					{
						os << authorName[i];
					};
				}
				else
				{
					
					os << std::setw(15) << std::setfill(' ') << left << authorName;
					
				}
				os << " |";
			}
			
		}
		else
		{
			os << "\t" << authorName;
		}
		return os;
	}

	istream& Book::read(istream& istr)
	{
		char tempName[256]{};
		Publication::read(istr);
		delete[] authorName;
		authorName = nullptr;
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.getline(tempName, 256, '\n');
		}
		else
		{
			istr.ignore();
			istr.get(tempName, 256);
		}
		if (!istr.fail())
		{
			delete[] authorName; 
			authorName = new char[strlen(tempName) + 1];
			strcpy(authorName, tempName);
		}

		return istr;
	}
	void Book::pubDisplay()
	{
		Publication::pubDisplay();
		cout << "\t" << authorName;
	}

	void Book::set(int memberId)
	{
		Publication::set(memberId);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		if (authorName != nullptr)
		{
			return Publication::operator bool();
		}
		return false;
	}

	Book::~Book()
	{
		delete[] authorName;
	}
	
}

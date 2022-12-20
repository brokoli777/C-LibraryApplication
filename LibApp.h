//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: LibApp module
Filename: LibApp.h
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__
#include <iostream>
#include"Publication.h"
#include "Menu.h"
#include "Book.h"
#include "PublicationSelector.h"
namespace sdds {
	class LibApp
	{
		bool m_changed{};
		Menu m_mainMenu;
		Menu m_exitMenu;

		char m_fileName[256]{};
		Publication* m_ptrArray[SDDS_LIBRARY_CAPACITY]{};
		int m_publicationCount{};
		int m_lastLibRefNum{};
		Menu m_menu;
	public:
		LibApp();
		LibApp(const char* tempFileName);
		void load();  
		void save();  
		int search(int searchType);  
		Publication* getPub(int libRef);
		void newPublication();
		void removePublication();
		bool confirm(const char* message);
		void checkOutPub();
		void returnPub();
		void run();
		~LibApp();
	};

}
#endif

//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Menu module
Filename: Menu.h
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem
	{
		char* title;
		MenuItem();
		MenuItem(const char* tempTitle);
		operator bool();
		operator const char* ();
		~MenuItem();
		std::ostream& display(std::ostream& os)const;
		friend class Menu;
	};
	class Menu
	{
	public:
		Menu();
		Menu(const char* tempTitle);
		MenuItem menuTitle;
		MenuItem* items[MAX_MENU_ITEMS];
		int pointerCount = 0;
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& display(std::ostream& os = std::cout)const;
		unsigned int run();
		unsigned int operator ~();

		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator [](int index)const;
		void setTitle(const char* tempTitle);

		Menu& operator<<(const char* menuitemContent);
		~Menu();
	};
	std::ostream& operator <<(std::ostream& os, const Menu& tempMenu);
}
#endif // !
//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: Menu module
Filename: Menu.cpp
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <limits>
#include "Menu.h"
using namespace sdds;
namespace sdds
{
	MenuItem::MenuItem()
	{
		title = nullptr;
	}

	MenuItem::MenuItem(const char* tempTitle)
	{
		title = new char[strlen(tempTitle) + 1];
		strcpy(title, tempTitle);
	}

	MenuItem::operator bool()
	{
		if (title != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::ostream& MenuItem::display(std::ostream& os)const
	{
		if (title != nullptr)
		{
			os << title;
		}
		return os;
	}

	MenuItem::operator const char* ()
	{
		return title;
	}

	MenuItem::~MenuItem()
	{
		delete[] title;
	}

	//FOR MENU =================
	Menu::Menu()
	{
		menuTitle.title = nullptr;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
	}

	Menu::Menu(const char* tempTitle)
	{

		menuTitle.title = new char[strlen(tempTitle) + 1];
		strcpy(menuTitle.title, tempTitle);
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
	}

	std::ostream& Menu::displayTitle(std::ostream& os)const
	{
		if (menuTitle.title != nullptr)
		{
			os << menuTitle.title;
		}
		return os;
	}

	std::ostream& Menu::display(std::ostream& os)const
	{
		displayTitle(os);
		os << std::endl;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			if (items[i] != nullptr)
			{
				os << " " << i + 1 << "- ";
				items[i]->display(os);
				os << std::endl;
			}
		}
		os << " 0- Exit\n> ";
		return os;
	}
	unsigned int Menu::run()
	{
		int userInput, temp;
		display(std::cout);


		while (!(std::cin >> temp) || temp < 0 || temp >= pointerCount + 1)
		{
			std::cout << "Invalid Selection, try again: ";
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}

		userInput = temp;


		return userInput;
	}

	unsigned int Menu::operator ~()
	{
		int userInput = run();
		return userInput;
	}


	Menu::operator int() const
	{
		return pointerCount;
	}

	Menu::operator unsigned int() const
	{
		return pointerCount;
	}

	Menu::operator bool() const
	{
		if (pointerCount >= 1)
		{
			return true;
		}
		return false;
	}


	std::ostream& operator <<(std::ostream& os, const Menu& tempMenu)
	{
		tempMenu.displayTitle();
		return os;
	}

	const char* Menu::operator [](int index)const
	{
		int modulus = index % pointerCount;
		if (index >= 0 && (unsigned int)index < MAX_MENU_ITEMS)
		{
			return items[index]->title;
		}
		else
		{
			return items[modulus]->title;
		}
	}

	void Menu::setTitle(const char* tempTitle)
	{
		menuTitle.title = new char[strlen(tempTitle) + 1];
		strcpy(menuTitle.title, tempTitle);
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		if ((unsigned int)pointerCount < MAX_MENU_ITEMS)
		{
			MenuItem* temp = new MenuItem(menuitemContent);
			items[pointerCount] = temp;
			pointerCount++;
		}
		return *this;
	}

	Menu::~Menu()
	{
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete items[i];
		}
	}
}
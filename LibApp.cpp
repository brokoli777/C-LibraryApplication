//Full Name : Bregwin Paul Jogi
//Student ID# : 156619215
//Email : bjogi1@myseneca.ca
//Date: 05/08/2022

/* Citation and Sources...
Final Project Milestone 5
Module: LibApp module
Filename: LibApp.cpp
Version 1.0
Author:	Bregwin Jogi
-----------------------------------------------------------
Revision History
Date      Reason
2022/08/06  Preliminary Release
2022/08/06  Added membership ID checking
2022/08/06  modified output file reading after exiting program
-----------------------------------------------------------
I have done all the coding by myself and only copied the codeS
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "LibApp.h"
using namespace std;
namespace sdds {
	LibApp::LibApp()
	{
        m_publicationCount = 0;
        m_menu << "Book" << "Publication";
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
        {
            m_ptrArray[i] = nullptr;
        }
        m_lastLibRefNum = 0;

        m_changed = false;
        m_mainMenu.setTitle("Seneca Library Application");
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
	}

    LibApp::LibApp(const char* tempFileName)
    {
        

        strcpy(m_fileName, tempFileName);
        m_menu.setTitle("Choose the type of publication:");
        m_publicationCount = 0;
        m_menu << "Book" << "Publication";
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
        {
            m_ptrArray[i] = nullptr;
        }
        m_lastLibRefNum = 0;

        m_changed = false;
        m_mainMenu.setTitle("Seneca Library Application");
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

	void LibApp::load()
	{
		std::cout << "Loading Data\n";

        ifstream infile(m_fileName);
        
        char type{};
        int i;
        for (i = 0; infile; i++) {
            infile >> type;
            infile.ignore();
            if (infile) {
                
                if (type == 'P')
                {
                    m_ptrArray[i] = new Publication;
                    
                }
                else if (type == 'B')
                {
                    
                    m_ptrArray[i] = new Book;
                }
                if (m_ptrArray[i]) {
                    infile >> *m_ptrArray[i];
                    
                    m_lastLibRefNum = m_ptrArray[i]->getRef();
                    m_publicationCount++;
                    
                }
            }
        }
	}

    void LibApp::save()
    {
        std::cout << "Saving Data\n";
        ofstream outfile(m_fileName);
        for (int i = 0; i < m_publicationCount; i++)
        {
            if (m_ptrArray[i]->getRef() != 0)
            {
                outfile << *m_ptrArray[i] << endl;
            }
            
        }
        
    }

    int LibApp::search(int searchType)
    {
        int publicationType{};
        char userInputTitle[256]{};
        char searchPubType{};
        PublicationSelector searchMenu("Select one of the following found matches:");

        publicationType = m_menu.run();
        if (publicationType == 1)
        {
            searchPubType = 'B';
        }
        else if (publicationType == 2)
        {
            searchPubType = 'P';
        }
        else
        {
            cout << "Aborted!" << endl;
        }


        if (!cin.fail() && (publicationType == 1 || publicationType == 2))
        {
            cout << "Publication Title: ";
            
            cin.ignore(2000, '\n');
            cin.getline(userInputTitle, 256);

            



            if (searchType == 1)
            {
                for (int i = 0; i < m_publicationCount; i++)
                {
                    if (m_ptrArray[i] != nullptr && *m_ptrArray[i] == userInputTitle && searchPubType == m_ptrArray[i]->type())
                    {
                        searchMenu << *m_ptrArray[i];
                    }
                }
            }
            else if (searchType == 2)
            {
                for (int i = 0; i < m_publicationCount; i++)
                {
                    if (m_ptrArray[i] != nullptr && *m_ptrArray[i] == userInputTitle && m_ptrArray[i]->onLoan() == true && searchPubType == m_ptrArray[i]->type())
                    {
                        searchMenu << *m_ptrArray[i];
                    }
                }
            }
            else if (searchType == 3)
            {
                for (int i = 0; i < m_publicationCount; i++)
                {
                    
                    if (m_ptrArray[i] != nullptr && *m_ptrArray[i] == userInputTitle && m_ptrArray[i]->onLoan() == false && searchPubType == m_ptrArray[i]->type())
                    {
                        searchMenu << *m_ptrArray[i];
                    }
                }
            }
            else
            {
                cout << "error - not supposed to be shown" << endl;
            }

        }
        else
        {
            cout << "search function- cin failed or publication type";
        }

        if (searchMenu)
        {

            searchMenu.sort();

            int searchMenuReturn = searchMenu.run();
            if (searchMenuReturn == 0)
            {
                cout << "Aborted!" << endl;
                return -1;
            }
            else
            {
                return searchMenuReturn;
            }
        }
        else
        {
            
            cout << "No matches found!";
        }
    
        return -1;
        
    }

    Publication* LibApp::getPub(int libRef)
    {
        for (int i = 0; i < m_publicationCount; i++)
        {
            if (m_ptrArray[i]->getRef() == libRef)
            {
                return m_ptrArray[i];
            }
        }
        return m_ptrArray[0]; 
    }

    void LibApp::newPublication()
    {
        int userPubType{};
        if (m_publicationCount >= SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!\n" ;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            userPubType = m_menu.run();
            if (userPubType == 1)
            {
                
                Book tempBook;

                if (!tempBook.read(cin))
                {
                    cout << "Aborted!" << endl;
                    cin.ignore(2000, '\n');
                    cin.clear();
                }
                else
                {
                    
                    if (confirm("Add this publication to the library?"))
                    {
                        if (tempBook.getTitle() != nullptr)
                        {
                            tempBook.setRef(m_lastLibRefNum + 1);
                            m_lastLibRefNum++;
                            m_ptrArray[m_publicationCount] = new Book(tempBook);
                            m_publicationCount++;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                        }
                        

                    }
                    else
                    {
                        cout << "Aborted!" << endl;
                    }
                }
            }
            else if (userPubType == 2)
            {
                
                Publication tempPublication;

                if (!tempPublication.read(cin))
                {
                    cout << "Aborted!" << endl;
                    cin.ignore(2000, '\n');
                    cin.clear();
                }
                else
                {
                    
                    if (confirm("Add this publication to the library?"))
                    {
                        if (tempPublication.getTitle() != nullptr)
                        {
                            tempPublication.setRef(m_lastLibRefNum + 1);
                            m_lastLibRefNum++;
                            m_ptrArray[m_publicationCount] = new Publication(tempPublication);
                            m_publicationCount++;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                        }


                    }
                    else
                    {
                        cout << "Aborted!" << endl;
                    }
                }

            }
            else
            {
                cout << "Aborted!" << endl;
            }
            
        }


    }

    bool LibApp::confirm(const char* message)
    {
        Menu tempMenu(message);
        tempMenu << "Yes";
        if (tempMenu.run() == 1)
        {
            return true;
        }
        return false;
    }



    void LibApp::removePublication()
    {
        int tempPubIndex{};
        cout << "Removing publication from the library" << endl;
        int tempLibRef = search(1);

        if (tempLibRef != -1) //added -1 check
        {
            for (int i = 0; i < m_publicationCount; i++)
            {
                if (m_ptrArray[i]->getRef() == tempLibRef)
                {
                    cout << *m_ptrArray[i];
                    tempPubIndex = i;
                }
            }
            cout << "\n";

            if (confirm("Remove this publication from the library?"))
            {
                m_ptrArray[tempPubIndex]->setRef(0);
                m_changed = true;
                std::cout << "Publication removed\n";
            }
        }

    }

    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int tempLibRef = search(3);
        int tempMembId;
        int tempDigitLength = 0;
        int tempDigit;
        

        if (tempLibRef != -1)
        {
            for (int i = 0; i < m_publicationCount; i++)
            {
                if (m_ptrArray[i]->getRef() == tempLibRef)
                {
                    cout << *m_ptrArray[i];
                }
            }
            cout << "\n";
            if (confirm("Check out publication?"))
            {
                do
                {
                    

                    cin.clear();
                    cin.ignore(2000, '\n');
                    cout << "Enter Membership number: ";
                    cin >> tempMembId;

                   

                        
                } while (cin.fail());
                
                tempDigit = tempMembId;
                while (tempDigit /= 10)
                {
                    tempDigitLength++;
                }
                while (tempDigitLength + 1 != 5)
                {
                    cout << "Invalid membership number, try again: ";
                    cin >> tempMembId;

                    tempDigitLength = 0;
                    tempDigit = tempMembId;
                    while (tempDigit /= 10)
                    {
                        tempDigitLength++;
                    }
                }

                

                


                getPub(tempLibRef)->set(tempMembId);
                m_changed = true;
                cout << "Publication checked out" << endl;

            }
        }
        
    }

    void LibApp::returnPub()
    {
        cout << "Return publication to the library" << endl;
        int tempLibRef = search(2);
        
        if (tempLibRef != -1)
        {
            getPub(tempLibRef)->write(cout);
            cout << endl;
            if (confirm("Return Publication?"))
            {
                Date todayDate;
                todayDate.setToToday();
                int daysDifference = todayDate - getPub(tempLibRef)->checkoutDate();
                if (daysDifference > 15)
                {
                    cout << "Please pay $" << std::setprecision(2) << fixed << (double)((daysDifference - 15) * 0.5) << " penalty for being " << daysDifference - 15 << " days late!" << endl;
                }

                getPub(tempLibRef)->set(0);
                m_changed = true;
                cout << "Publication returned" << endl;

            }
        }
        
    }


    void LibApp::run()
    {
        bool exitMainMenu = false;
        int userSelection = -999;
        while (exitMainMenu == false && userSelection != 0)
        {

            do
            {
                userSelection = m_mainMenu.run();
                if (userSelection == 1)
                {
                    newPublication();
                    std::cout << "\n";
                }
                else if (userSelection == 2)
                {
                    removePublication();
                    std::cout << "\n";
                }
                else if (userSelection == 3)
                {
                    checkOutPub();
                    std::cout << "\n";
                }
                else if (userSelection == 4)
                {
                    returnPub();
                    std::cout << "\n";
                }

            } while (userSelection != 0);

            if (m_changed == true)
            {
                int exitChoice = m_exitMenu.run();
                if (exitChoice == 1)
                {
                    save();
                }
                else if (exitChoice == 2)
                {
                    exitMainMenu = false;
                    userSelection = -999;
                    std::cout << "\n";
                }
                else
                {
                    if (confirm("This will discard all the changes are you sure?"))
                    {
                        exitMainMenu = true;
                    }
                }
            }

        }

        std::cout << "\n-------------------------------------------\nThanks for using Seneca Library Application\n";

        /*for (int i = 0; i < m_publicationCount; i++)
        {          
            if (m_ptrArray[i]->getTitle() != nullptr && m_ptrArray[i]->getRef()!= 0)
            {
                m_ptrArray[i]->pubDisplay();
                cout << "\n";
            }
        }*/

        std::ifstream f(m_fileName);
        cout << f.rdbuf();
        
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++) {
            delete m_ptrArray[i];
        }
    }
}
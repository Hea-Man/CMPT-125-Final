/*
This class controls the menu and should dictate what the other classes should do.
*/
#ifndef MENU_H
#define MENU_H

#include <iostream>      
#include <fstream>      
#include <string>        
#include <algorithm>    
#include <cassert>
#include "Supercars.h"
#include "Database.h"

using namespace std;

class Menu
{
    public:
        Menu(){}
        void add(database &d)
        {
            cout << "Add a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            int a = -1;
            supercar *s = new supercar(a);
            d.add_supercar(s);
        }
        void find(database &d)
        {
            string message;
            int stop = -1;
            while (stop < 0)
            {
                cout << "Find a Supercar\n";
                cout << "---------------------------------------------------\n\n";
                cout << "You can search for a supercar by:\n\n";
                cout << "(N)ame of Supercar.\n";
                cout << "(P)rice of Supercar.\n";
                cout << "(H)orsepower of Supercar.\n";
                cout << "(B)rand of Supercars.\n";
                cout << "(R)eturn to Main Menu.\n";
                getline(cin,message);
                cout << "\n";
                
                for (char &c : message)
                {
                    c = tolower(c);
                }
                if (message == "n" || message == "p" || message == "h" || message == "b" || message == "c")
                {
                    d.find_car(message);
                }
                else if (message == "r")
                {
                    stop++;
                }
                else
                {
                    cout << "I did not understand your answer. ";
                }
            }
        }

        void remove(database &d)
        {
            cout << "Remove a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            d.delete_supercar();
        }

        void list(database &d)
        {
            cout << "List all Supercars\n";
            cout << "--------------------------------------------------------------------------\n";
            d.list_all();
        }

        void sort(database &d)
        {
            string message;
            int stop = -1;
            while (stop < 0)
            {
                cout << "How do you want to sort your Supercar Data base? \n";
                cout << "---------------------------------------------------\n\n";
                cout << "List all fields in (A)lphabetical or Reverse Alphabetical order\n ";
                cout << "List all fields in Ascending or (D)escending order\n";
                getline(cin,message);
                cout << "\n";
                for (char &c : message)
                {
                    c = tolower(c);
                }
                if (message == "a" || message == "d" )
                {
                    d.sort_car(message);
                }
                else if (message == "r")
                {
                    stop++;
                }
                else
                {
                    cout << "I did not understand your answer. ";
                }

            }
        }

        void main_menu()
        {
            int stop = -1;
            database d("cars.txt");
            string message;
            stop = -1;
            int first = 0;
            while (stop < 0)
            {
                if (first == 0)
                {
                    first++;
                    cout << "Welcome to the Supercar Database!\n";
                    cout << "--------------------------------------------------------------------------\n\n";
                }
                cout << "Please choose from the menu below. ";
                cout << "To choose an option, please type the letter in the parenthesis corresponding ";
                cout << "to the choice you would like. \n\n";
                cout << "(A)dd a Supercar.\n";
                cout << "(D)elete a Supercar.\n";
                cout << "(F)ind a Supercar.\n";
                cout << "(L)ist all Supercars.\n";
                cout << "(Q)uit application.\n";
                getline(cin,message);
                cout << "\n";
                
                for (char &c : message)
                {   
                    c = tolower(c);
                }
                if (message == "a")
                {
                    add(d);
                }
                else if (message == "f")
                {
                    find(d);
                }
                else if (message == "d")
                {
                    remove(d);
                }
                else if (message == "l")
                {
                    list(d);
                }
                else if (message == "q")
                {
                    d.save_to_file("cars.txt");
                    stop++;
                }
                else
                {
                    cout << "I did not understand your answer. ";
                }
            }
        }
        ~Menu(){}
};


#endif
/*
This class controls the menu and should dictate what the other classes should do.
*/

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
        void add(database d)
        {
            cout << "Add a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            supercar s = supercar();
            d.add_supercar(s);
        }
        void find(database d)
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

        void remove(database d)
        {
            cout << "Remove a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            d.delete_supercar();
        }

        void list(database d)
        {
            cout << "List all Supercars\n";
            cout << "--------------------------------------------------------------------------\n\n";
            d.list_all();
        }

        void main_menu()
        {
            int stop = -1;
            string filename;
            while (stop < 0)
            {
                cout << "Please enter an appropriate filename. Enter in the following format: ";
                cout << "[file name].txt ";
                getline(cin,filename);
            }
            database d = database(filename);
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
                cout << "(F)ind a Supercar.\n";
                cout << "(D)elete a Supercar.\n";
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
                    stop++;
                    cout << "Goodbye\n\n";
                }
                else
                {
                    cout << "I did not understand your answer. ";
                }
            }
            d.save_to_file(filename);
        }
        ~Menu(){}
};
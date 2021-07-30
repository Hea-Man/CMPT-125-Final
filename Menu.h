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
        void add()
        {
            cout << "Add a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            //Add function to add car
        }
        void find()
        {
            string message;
            int stop = -1;
            while (stop < 0)
            {
                cout << "Find a Song\n";
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
                if (message == "n")
                {
                    cout << "You will search by name of car\n";
                }
                else if (message == "p")
                {
                    cout << "You will search by price of car\n";
                }
                else if (message == "h")
                {
                    cout << "You will search by horsepower of car\n";
                }
                else if (message == "b")
                {
                    cout << "You will search by brand of car\n";
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

        void remove()
        {
            cout << "Remove a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            //Add function to remove car
        }

        void list()
        {
            cout << "List all Supercars\n";
            cout << "--------------------------------------------------------------------------\n\n";
            //Add function to output all cars on list
        }

        void main_menu()
        {
            string message;
            int stop = -1;
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
                    add();
                }
                else if (message == "f")
                {
                    find();
                }
                else if (message == "d")
                {
                    remove();
                }
                else if (message == "l")
                {
                    list();
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
        }
        ~Menu(){}
};
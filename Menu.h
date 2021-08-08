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
        
        //This is a command that will direct the add supercar function
        void add(database &d)
        {
            cout << "Add a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            int a = -1;
            supercar *s = new supercar(a);
            d.add_supercar(s);
        }

        //This is a command that directs the find menu of the class
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

        //This directs the remove menu to remove a supercar
        void remove(database &d)
        {
            cout << "Remove a Supercar\n";
            cout << "--------------------------------------------------------------------------\n\n";
            d.delete_supercar();
        }

        //This function calls another function to list all the supercars in the database
        void list(database &d)
        {
            cout << "List all Supercars\n";
            cout << "--------------------------------------------------------------------------\n";
            d.list_all();
        }

        //This function directs the user through the sorting algorithms for the cars
        void sort(database &d)
        {
            string message;
            int stop = -1;
            while (stop < 0)
            {
                cout << "How do you want to sort your Supercar Data base? \n";
                cout << "---------------------------------------------------\n\n";
                cout << "(B)rand, (N)ame, (H)orsepower, (P)rice, (C)ylinders\n";
                getline(cin,message);
                cout << "\n";
                for (char &c : message)
                {
                    c = tolower(c);
                }
                if (message == "n" )
                {
                    d.string_compare_n();
                }
                else if (message == "b")
                {
                    d.string_compare_b();
                }
                else if (message == "h")
                {
                    d.int_compare_h();
                }
                else if (message == "p")
                {
                    d.int_compare_p();
                }
                else if (message == "c")
                {
                    d.int_compare_c();
                }
                else
                {
                    cout << "I did not understand your answer. ";
                }
                cout << "Would you like to reverse the order of the array? (Y)es or (N)o?\n";
                getline(cin,message);
                cout << "\n";
                for (char &c : message)
                {
                    c = tolower(c);
                }
                if (message == "y")
                {
                    d.reverse();
                    stop++;
                }
                else
                {
                    stop++;
                }
            }
        }

        //The function that controls and calls everything. This is the only function that should be
        //called to make the database work
        void main_menu()
        {
            int stop = -1;
            database d("database.txt");
            string message;
            stop = -1;
            cout << "Welcome to the Supercar Database!\n";
            cout << "--------------------------------------------------------------------------\n\n";
            while (stop < 0)
            {
                cout << "Please choose from the menu below. ";
                cout << "To choose an option, please type the letter in the parenthesis corresponding ";
                cout << "to the choice you would like. \n\n";
                cout << "(A)dd a Supercar.\n";
                cout << "(D)elete a Supercar.\n";
                cout << "(F)ind a Supercar.\n";
                cout << "(L)ist all Supercars.\n";
                cout << "(S)ort all Supercars \n";
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
                    cout << "Supercar Added\n\n";
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
                else if (message == "s")
                {
                    sort(d);
                }
                else if (message == "q")
                {
                    d.save_to_file("database.txt");
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
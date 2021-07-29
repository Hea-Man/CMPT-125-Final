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

        string main_menu()
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
                    cout << "You will add a car\n";
                }
                else if (message == "f")
                {
                    cout << "You will find a car\n";
                }
                else if (message == "d")
                {
                    cout << "You will delete a car\n";
                }
                else if (message == "l")
                {
                    cout << "You will list all cars\n";
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
            return "";
        }
};
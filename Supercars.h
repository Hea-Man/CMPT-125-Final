/*
This class should store one database record.

(1 mark) A class that stores a single database record.
 The name of this class is up to you, but it should describe what it stores. 
 For instance, if your database is storing songs, then a good name for this class is Song.

(5 marks) Using a modified version of your dynamic array class 
from assignment 3 (and not just using raw arrays without a class).

As described above, don't use vector, or any other C++ "container"
class from the STL or elsewhere. The marker will check this after they mark your project, 
and you have used vector or a similar class, then your score for this assignment will be set to 50% of the total mark 
(if your mark before this check is less than 50%, then your mark won't be changed).

*/
#ifndef SUPERCAR_H
#define SUPERCAR_H
//it basically saying when you compile only load the .h file once
#include <iostream>      
#include <fstream>      
#include <string>        
#include <algorithm>    
#include <cassert>
#include "cmpt_error.h"

using namespace std;

// Not to sure if the inputs need to be tested in side of constructor for being 
// sensible so I just added a few I thought would make sense

class supercar {
private:
    string brand;
    string name;
    int horsepower;
    int price;
    int cylinders;

public:

    // Default constructor:
    supercar()
    {}

    //Constructor:
    supercar(string b,string s, int hp, int prc, int cyln)
    :   brand(b) ,name(s) , horsepower(hp) , price(prc) , cylinders(cyln)
    {}

    supercar(int s)
    {
        int stop = s;
        printf("Please enter the name of the brand: ");
        while (stop == -1) {
            stop = 0;
            getline(cin , brand);

            // if bad
            for ( int i = 0 ; i < brand.size(); i ++) {
                if (brand[i] == '!' || brand[i] == '@' || brand[i] == '#' || brand[i] == '$'
                    || brand[i] == '\n' || brand[i] == '\t'  ) 
                {
                    printf("Please re enter the name of the brand: ");
                    stop = -1;
                }
            }
        }

        stop = -1;
        printf("Please enter the name of the car: ");
        while (stop==-1) {
            stop = 0;
            getline(cin,name);

            // if bad 
            for (int i = 0 ; i < name.size(); i++){
                if (name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$'
                    || name[i] == '\n' || name[i] == '\t'  )
                    {
                        printf("Please re enter the name of the car: ");
                        stop = -1;
                    }
            }
        }

        //Now checking if horsepower is valid:
        stop = -1;
        while (stop == -1) {

            printf("Please enter the horsepower:");
            //First getting a valid integer inside of horsepower
            while(!(cin>>horsepower)){
                cout << "ERROR: A number must be entered: Please re-enter Horsepower\n";

                //Clear input stream
                cin.clear();

                //Discard previous input - a function to clear one or more characters from the input buffer including next line character
                cin.ignore(123,'\n');
            }
            stop = 0 ;
            // if bad integer
            if (horsepower < 0 || horsepower > 5000){
                printf("ERROR: Horsepower cannot be less than zero OR greater than 5000 \n");
                stop = -1;
            }
        }

        //Now checking if price is valid:
        stop = -1;
        while (stop == -1) {
            printf("Please enter the price: ");
            //First getting a valid integer inside of price
            while(!(cin>>price)){
                cout << "ERROR: A number must be entered: Please re-enter Price\n";

                //Clear input stream
                cin.clear();

                //Discard previous input - a function to clear one or more characters from the input buffer including next line character
                cin.ignore(123,'\n');
            }
            stop = 0 ;
            // if bad integer
            if (price < 0){
                printf("ERROR: Price cannot be less than zero \n");
                stop = -1;
            }
        }

        stop = -1;
        while (stop == -1) {
            printf("Please enter the Cylinders  : ");
            //First getting a valid integer inside of Cylinders
            while(!(cin>>cylinders)){
                cout << "ERROR: A number must be entered: Please re-enter Cylinders\n";

                //Clear input stream
                cin.clear();

                //Discard previous input - a function to clear one or more characters from the input buffer including next line character
                cin.ignore(123,'\n');
            }
            stop = 0 ;
            // if bad integer
            if (cylinders < 0){
                printf("ERROR: Cylinders cannot be less than 0 ( Please enter 0 cylinders for an electric vehicle) \n");
                stop = -1;
            }
        }
    }// constructor end

    string getname() const {
        return name;
    }

    string getbrand() const {
        return brand;
    }

    int gethorsepower() const {
        return horsepower;
    }

    int getprice() const {
        return price;
    }

    int getcylinders() const {
        return cylinders;
    }


    //Potentially add setters if Heemant needs em :3

    void setname(string nm){
        int stop = -1;
        name = nm;
        while (stop==-1) {
            stop = 0;
            // if bad 
            for (int i = 0 ; i < name.size(); i++){
                if (name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$'
                    || name[i] == '\n' || name[i] == '\t'  )
                    {
                        printf("Please re enter the name of the car: ");
                        stop = -1;
                        getline(cin,name);
                    }
            }
            
        }
    }

    void setbrand(string brnd){
        int stop = -1;
        brand = brnd;
        while (stop==-1) {
            stop = 0;
            // if bad 
            for (int i = 0 ; i < brand.size(); i++){
                if (brand[i] == '!' || brand[i] == '@' || brand[i] == '#' || brand[i] == '$'
                    || brand[i] == '\n' || brand[i] == '\t'  )
                    {
                        printf("Please re enter the brand of the car: ");
                        getline(cin,brand);
                        stop = -1;
                    }
            }
        }
    }

    void sethorsepower(int hrp) {
        int stop = -1;
        horsepower = hrp;
        while (stop == -1) {
            stop = 0 ;
            // if bad
            if (horsepower < 0){
                printf("Please re enter the horsepower: ");
                stop = -1;
                cin >> horsepower;
            }
        }

    }

    void setprice(int prc) {
        int stop = -1;
        price = prc;
        while (stop == -1) {
            stop = 0 ;
            // if bad
            if (price < 0){
                printf("Please re enter the price: ");
                stop = -1;
                cin >> price;
            }
        }

    }


    void setcylinders(int cyl) {
        int stop = -1;
        cylinders=cyl;
        while (stop == -1) {
            stop = 0 ;
            // if bad
            if (cylinders < 0 && cylinders >16){
                printf("Please re enter the number of cylinders: ");
                stop = -1;
                cin >> price;
            }
        }

    }

    //Deconstructor:
    ~supercar(){
        cout<<"deconstructor called" << endl;
    }
};


#endif
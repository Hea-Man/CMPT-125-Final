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
    string name;
    string brand;
    int horsepower;
    int price;
    int cylinders;

public:

    // Default constructor:
    // supercar()
    // : name("unknown"), brand("unknown"), horsepower(0),price(0), cylinders(0) 
    // {}

    //Constructor:
    supercar(string s,string b, int hp, int p, int cyln)
    : name(s) , brand(b) , horsepower(hp) , price(p) , cylinders(cyln)
    {}

    supercar()
    {
        int stop = -1;
        printf("Please enter the name of the car");
        while (stop==-1) {
            stop = 0;
            getline(cin,name);

            // if bad 
            for (int i = 0 ; i < name.size(); i++){
                if (name[i] == '!' || name[i] == '@' || name[i] == '#' || name[i] == '$'
                    || name[i] == '\n' || name[i] == '\t'  )
                    {
                        printf("Please re enter the name of the car");
                        stop = -1;
                    }
            }
        }

        stop = -1;
        printf("Please enter the name of the brand");
        while (stop == -1) {
            stop = 0;
            getline(cin , brand);

            // if bad
            for ( int i = 0 ; i < brand.size(); i ++) {
                if (brand[i] == '!' || brand[i] == '@' || brand[i] == '#' || brand[i] == '$'
                    || brand[i] == '\n' || brand[i] == '\t'  ) 
                {
                    printf("Please re enter the name of the brand");
                    stop = -1;
                }
            }
        }

        stop = -1;
        printf("Please enter the horsepower");
        while (stop == -1) {
            stop = 0 ;
            cin >> horsepower;

            // if bad
            if (horsepower < 0){
                printf("Please re enter the horsepower");
                stop = -1;
            }
        }

        stop = -1;
        printf("Please enter the price");
        while (stop == -1) {
            stop = 0 ;
            cin >> price;

            // if bad
            if (price < 0){
                printf("Please re enter the price");
                stop = -1;
            }
        }

        stop = -1;
        printf("Please enter the cylinders");
        while (stop == -1) {
            stop = 0 ;
            cin >> cylinders;

            // if bad
            if (cylinders < 0){
                printf("Please re enter the Cylinders amount");
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


    //Deconstructor:
    ~supercar();
};
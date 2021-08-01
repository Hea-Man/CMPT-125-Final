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

class supercar
{
private:
    string name;
    int horsepower;
    int price;
    bool iselectric;

public:

    // Default constructor:
    supercar()
    : name("unknown"), horsepower(0),price(0)
    {}

    //Constructor:
    supercar(string s, int hp, int p, bool tf)
    : name(s) , horsepower(hp) , price(p) , iselectric(tf)
    {
        if (price <0){
            cmpt::error("Price can't be lower that $0");
        }

        if (horsepower < 0){
            cmpt::error("horsepower cann't be less than zero");
        }

        // One of the reasons why we should check inputs before the constructor
        // if (name.length() < 0){
        //     cmpt::error("Please enter a valid name");
        // }

        for (int i = 0 ; i < name.size(); i++){
            if (name[i] == "!" || name[i] == "@" || name[i] == "#" || name[i] == "$"
                || name[i] == "\\n" || name[i] == "\\t"  )
            {
                cmpt::error("Invalid character inside of name , please enter a sensible name");
            }
        }
    }

};
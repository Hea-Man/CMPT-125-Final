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

using namespace std;

class supercar
{
private:
    string name;
    int horsepower;
    int price;

public:

    // Default constructor:
    supercar()
    : name("unknown"), horsepower(0),price(0)
    {}

    //Constructor:
    supercar()


};
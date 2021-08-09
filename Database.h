#include <iostream>      
#include <fstream>      
#include <string>        
#include <algorithm>    
#include <cassert>      
#include "cmpt_error.h" 
#include "Supercars.h"
#include <iomanip>
/*
This stores all instances of Supercars.h. This is where we should implement our searching and sorting functions
*/

//Citations : find() function from this https://www.youtube.com/watch?v=w_d0MIYGz2I
using namespace std;

class database {
	private:
		supercar** data;
		int space;
		int used;

	public:
		//Adds a supercar to the array
		void add_supercar(supercar *s)
		{
			if (used >= space-1)
			{
				supercar* temporary[space];
				for (int x = 0; x < used; x++)
				{
					temporary[x] = data[x];
				}
				space *= 2;
				delete[] data;
				data = new supercar*[space];
				for (int x = 0; x < used; x++)
				{
					data[x] = temporary[x];
				}
			}
			data[used] = s;
			used++;
		}

		//This creates the database from the file
		database(const string& fname)
		{
			space = 10;
			used = 0;
			data = new supercar*[space];
			string brand;
			string name;
			int power;
			int price;
			int cylinders;
			string input;
			int val = 0;
			char c;
			fstream fin;
			fin.open(fname);
			if (fin.is_open())
			{
				while(fin.get(c))
				{
					if (c == ',' || c == '\n')
					{
						if (val == 0)
						{
							brand = input;
							val++;
							input = "";
						}
						else if (val == 1)
						{
							name = input;
							val++;
							input = "";
						}
						else if (val == 2)
						{
							power = stoi(input);
							val++;
							input = "";
						}
						else if (val == 3)
						{
							price = stoi(input);
							val++;
							input = "";
						}
						else
						{
							cylinders = stoi(input);
							val++;
							input = "";
						}
						if (val == 5)
						{
							supercar *s = new supercar (brand, name, power, price, cylinders);
							add_supercar(s);
							val = 0;
							input = "";
						}
					}
					else
					{
						input = input + c;
					}
			 	}
			}
		fin.close();
		}

		//Saves the array to a file
		void save_to_file(const string &fname)
		{
			cout << "Saving Data...";
			FILE* out = fopen("database.txt","w");
			fclose(out);
			fstream fout;
			fout.open(fname);
			for (int x = 0; x < used; x++)
			{
				fout << data[x]->getbrand() << ",";
				fout << data[x]->getname() << ",";
				fout << data[x]->gethorsepower() << ",";
				fout << data[x]->getprice() << ",";
				fout << data[x]->getcylinders() << "\n";
			}	
			fout.close();
			cout << "Data Saved\n";	
		}

		//prints one supercar to the terminal. Used only for the find() function
		void list_one(int index) const
		{
			if (used > 0)
			{
				string output = "";
				output = output + data[index]->getbrand() + " " + data[index]->getname() + " " + to_string(data[index]->gethorsepower()) + "hp ";
				output = output + to_string(data[index]->getcylinders()) + " " + to_string(data[index]->getprice());
				cout << output;
				cout << "\n\n";
			}
		}

		//Lists every supercar in the array
		void list_all() const
		{
			if (used > 0)
			{
				cout << setw(15) << "BRAND:" << setw(30) << "NAME:" << setw(30) << "HORSEPOWER:" 
					 << setw(30) << "CYLINDERS:" << setw(30) << "PRICE:";
				cout << "\n";
				for (int x=0; x<used;x++)
				{
					cout << setw(15) << data[x]->getbrand() << setw(30) << data[x]->getname() << setw(30) << to_string(data[x]->gethorsepower()) << "hp"
						 << setw(30) << to_string(data[x]->getcylinders()) << setw(30) << to_string(data[x]->getprice());
					cout << "\n";

				}
			}
		}
		
		//Finds a car in the array
		//One type of search should print all the records where the typed in string occurs as a substring in the appropriate field
		//One type of search should print all the records where the typed in int range is used to search for appropriate fields
		void find_car(const string &type) const
		{
			bool found = false;
			//Finding via name
			if (type == "n")
			{
				cout<<"Do you want to Find all records where the input occurs as a substring as well ?\n";
				cout<<"Please type (Y)es or (N)o:    ";
				char input;
				cin >> input;
				input = tolower(input);
				if (input == 'n'){
					string nme;
					cout << "Enter the name of the supercar you wish to find: ";
					cin.clear();
					cin.ignore(123,'\n');
					getline(cin,nme);
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getname() == nme)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with the name " << nme << " in the data base right now \n" ;
					}
				}
				else if (input == 'y'){
					string substr;
					cout << "Enter the substring of the Name you wish to find: ";
					cin.clear();
					cin.ignore(123,'\n');
					getline(cin,substr);
					cout <<"\n";
					// so this find() function inside of the string library returns the position if substr found other 
					//wise it returns a -1 value 
					for (int x = 0; x < used; x++)
					{
						int position = (data[x]->getname()).find(substr);
						if (position != -1) // if found print it
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with the name " << substr << " in the data base right now \n" ;
					}
				}
				//If user doesn't type E Or R
				else {
					cout << "Invalid answer Please try again \n";
				}
				
			}

			//Finding via brand
			if (type == "b")
			{
				bool found = false;
				cout<<"Do you want to Find all records where the input occurs as a substring as well ?\n";
				cout<<"Please type (Y)es or (N)o:    ";
				char input;
				cin >> input;
				input = tolower(input);
				if (input == 'n'){
					string nme;
					cout << "Enter the brand of the supercar you wish to find: ";
					cin.clear();
					cin.ignore(123,'\n');
					getline(cin,nme);
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getbrand() == nme)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with the brand " << nme << " in the data base right now \n" ;
					}
				}
				else if (input == 'y'){
					string substr;
					cout << "Enter the substring of the brand  you wish to find: ";
					cin.clear();
					cin.ignore(123,'\n');
					getline(cin,substr);
					cout <<"\n";
					// so this find() function inside of the string library returns the position if substr found other 
					//wise it returns a -1 value 
					for (int x = 0; x < used; x++)
					{
						int position = (data[x]->getbrand()).find(substr);
						if (position != -1) // if found print it
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with the brand " << substr << " in the data base right now \n" ;
					}
				}
				//If user doesn't type E Or R
				else {
					cout << "Invalid answer Please try again \n";
				}
			}

			//Finding Via price
			if (type == "p")
			{
				bool found = false;
				cout<<"Do you want to Find all records where the input occurs as an exactl value Or a range? ?\n";
				cout<<"Please type \n(E) for Exact value \n(R) For all values inside of a Range:    ";
				char input;
				cin >> input;
				input = tolower(input);

				//Finding all fields with the exact input price
				if (input == 'e'){
					int num;
					cout << "Enter the price of the supercar: ";
					int stop = -1;
					while (stop < 0)
					{
						cin >> num;
						if (num < 0)
						{
							cout << "That number is invalid. Please enter a valid number: ";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getprice() == num)
						{
							list_one(x);
							found = false;
						}
					}
					if (found == false) {
					cout << "There is no super car with the price " << num << " in the data base right now \n" ;
					}
				}

				//Finding all fields within a certain price range
				else if (input == 'r')
				{
					int lowerprice;
					int upperprice;
					int stop = -1;
					while (stop < 0)
					{
						cout << "Please enter the Lower limit of the price: ";
						cin >> lowerprice;
						cout <<"\nPlease enter the upper limit of the price: ";
						cin >> upperprice;

						//Checking lowerlimit and upper limit
						if (lowerprice < 0 || upperprice < 0 )
						{
							cout << "That price range is invalid. Please enter a valid number: ";
						}
						else if (lowerprice > upperprice)
						{
							cout<< " Lower limit can't be greater than upper limit";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getprice() >= lowerprice && data[x]->getprice() <= upperprice)
						{
							list_one(x);
							found = false;
						}
					}
					if (found == false) {
					cout << "There is no super car with that price range in the data base right now \n" ;
					}
				}

				//If user doesn't type E Or R
				else {
					cout << "Invalid answer Please try again \n";
				}
			}

			//Finding Via horsepower
			if (type == "h")
			{
				bool found = false;
				cout<<"Do you want to Find all records where the input occurs as an exactl value Or a range? ?\n";
				cout<<"Please type \n(E) for Exact value \n(R) For all values inside of a Range:    ";
				char input;
				cin >> input;
				input = tolower(input);

				//Finding all fields with the exact input price
				if (input == 'e'){
					int num;
					cout << "Enter the horsepower the supercar has: ";
					int stop = -1;
					while (stop < 0)
					{
						cin >> num;
						if (num < 0)
						{
							cout << "That number is invalid. Please enter a valid number: ";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->gethorsepower() == num)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with that Horsepower in the data base right now \n" ;
					}
				}
				//Finding all fields within a certain Horsepower range
				else if (input == 'r')
				{
					int lowerhp;
					int upperhp;
					int stop = -1;
					while (stop < 0)
					{
						cout << "Please enter the Lower limit of the Horsepower: ";
						cin >> lowerhp;
						cout <<"\nPlease enter the upper limit of the Horsepower: ";
						cin >> upperhp;
						if (lowerhp < 0 || upperhp < 0 )
						{
							cout << "That horsepower range is invalid. Please enter a valid number: \n";
						}
						else if (lowerhp > upperhp)
						{
							cout<< " Lower limit can't be greater than upper limit\n";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->gethorsepower() >= lowerhp && data[x]->gethorsepower() <= upperhp)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with that Horsepower range in the data base right now \n" ;
					}
				}
				//If user doesn't type E Or R
				else {
					cout << "Invalid answer Please try again \n";
				}
			}
			//Finding via cylinders
			if (type == "c")
			{
				bool found = false;
				cout<<"Do you want to Find all records where the input occurs as an exactl value Or a range? ?\n";
				cout<<"Please type \n(E) for Exact value \n(R) For all values inside of a Range:    ";
				char input;
				cin >> input;
				input = tolower(input);

				//Finding all fields with the exact input cylinders
				if (input == 'e'){
					int num;
					cout << "Enter the number of cylinders the supercar has: ";
					int stop = -1;
					while (stop < 0)
					{
						cin >> num;
						if (num < 0 )
						{
							cout << "That number is invalid. Please enter a valid number: ";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getcylinders() == num)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with those Cylinders in the data base right now \n" ;
					}
				}

				//Finding all fields within a certain Horsepower range
				else if (input == 'r')
				{
					int lowercyl;
					int uppercyl;
					int stop = -1;
					while (stop < 0)
					{
						cout << "Please enter the Lower limit of the Cylinders: ";
						cin >> lowercyl;
						cout <<"\nPlease enter the upper limit of the Cylinders: ";
						cin >> uppercyl;
						if (lowercyl < 0 || uppercyl < 0 )
						{
							cout << "That Cylinder range is invalid. Please enter a valid number: ";
						}
						else if (lowercyl > uppercyl)
						{
							cout<< " Lower limit can't be greater than upper limit";
						}
						else
						{
							stop++;
						}
					}
					cout << "\n";
					for (int x = 0; x < used; x++)
					{
						if (data[x]->getcylinders() >= lowercyl && data[x]->getcylinders() <= uppercyl)
						{
							list_one(x);
							found = true;
						}
					}
					if (found == false) {
					cout << "There is no super car with that Cylinders range in the data base right now \n" ;
					}
				}
				//If user doesn't type E Or R
				else {
					cout << "Invalid answer Please try again \n";
				}
			}
		} // find function 
		
		// Function to delete the supercar from the database
		void delete_supercar_b()
		{
			string brand;
			cout << "Enter the substring of the brand or the exact brand of the supercar you would like to remove: ";
			getline(cin,brand);
			cout <<"\n";
			bool found = false;
			for (int x = 0; x < used; x++)
			{
				int position = (data[x]->getbrand()).find(brand);
				if (position != -1)
				{
					found = true;
					string response;
					list_one(x);
					cout << "This is the search result. Are you sure you want to delete this? (Y)es or (N)o? ";
					getline(cin,response);
					cout << "\n";
					for (char &c : response)
					{
						c = tolower(c);
					}
					if (response == "y")
					{

						if (x == (used - 1))
						{
							delete data[x];
						}
						else
						{
							delete data[x];
							for (int y = x+1; y < used; y++)
							{
								data[y-1] = data[y];
							}
						}
						used--;
						if (x <= 2)
						{
							x = 0;
						}
						else
						{
							x = x-2;
						}
					}
				}
			}
			if (found == false){
				cout << "Super car you entered was not found in the data base, please try again \n\n";
			}
		}

		void delete_supercar_n()
		{
			string name;
			cout << "Enter the substring of the name or the exact name of the supercar you would like to remove: ";
			getline(cin,name);
			cout <<"\n";
			bool found = false;
			for (int x = 0; x < used; x++)
			{
				int position = (data[x]->getname()).find(name);
				if (position != -1)
				{
					found = true;
					string response;
					list_one(x);
					cout << "This is the search result. Are you sure you want to delete this? (Y)es or (N)o? ";
					getline(cin,response);
					cout << "\n";
					for (char &c : response)
					{
						c = tolower(c);
					}
					if (response == "y")
					{
						if (x == (used - 1))
						{
							delete data[x];
						}
						else
						{
							delete data[x];
							for (int y = x+1; y < used; y++)
							{
								data[y-1] = data[y];
							}
						}
						used--;
						if (x <= 2)
						{
							x = 0;
						}
						else
						{
							x = x-2;
						}
					}
				}
			}
			if (found == false){
				cout << "Super car you entered was not found in the data base, please try again \n\n";
			}
		}

		void delete_supercar_h()
		{
			int horsepower;
			string response;
			cout << "Enter the horsepower of the supercar you would like to remove: ";
			getline(cin,response);
			horsepower = stoi(response);
			cout <<"\n";
			bool found = false;
			for (int x = 0; x < used; x++)
			{
				if (data[x]->gethorsepower() == horsepower)
				{
					found = true;
					string response;
					list_one(x);
					cout << "This is the search result. Are you sure you want to delete this? (Y)es or (N)o? ";
					getline(cin,response);
					cout << "\n";
					for (char &c : response)
					{
						c = tolower(c);
					}
					if (response == "y")
					{
						if (x == (used - 1))
						{
							delete data[x];
						}
						else
						{
							delete data[x];
							for (int y = x+1; y < used; y++)
							{
								data[y-1] = data[y];
							}
						}
						used--;
						if (x <= 2)
						{
							x = 0;
						}
						else
						{
							x = x-2;
						}
					}
				}
			}
			if (found == false){
				cout << "Super car you entered was not found in the data base, please try again \n\n";
			}
		}

		void delete_supercar_p()
		{
			int price;
			string response;
			cout << "Enter the price of the supercar you would like to remove: ";
			getline(cin,response);
			price = stoi(response);
			cout <<"\n";
			bool found = false;
			for (int x = 0; x < used; x++)
			{
				if (data[x]->getprice() == price)
				{
					found = true;
					string response;
					list_one(x);
					cout << "This is the search result. Are you sure you want to delete this? (Y)es or (N)o? ";
					getline(cin,response);
					cout << "\n";
					for (char &c : response)
					{
						c = tolower(c);
					}
					if (response == "y")
					{
						if (x == (used - 1))
						{
							delete data[x];
						}
						else
						{
							delete data[x];
							for (int y = x+1; y < used; y++)
							{
								data[y-1] = data[y];
							}
						}
						used--;
						if (x <= 2)
						{
							x = 0;
						}
						else
						{
							x = x-2;
						}
					}
				}
			}
			if (found == false){
				cout << "Super car you entered was not found in the data base, please try again \n\n";
			}
		}

		void delete_supercar_c()
		{
			int cylinders;
			string response;
			cout << "Enter the number of cylinders of the supercar you would like to remove: ";
			getline(cin,response);
			cylinders = stoi(response);
			cout <<"\n";
			bool found = false;
			for (int x = 0; x < used; x++)
			{
				if (data[x]->getcylinders() == cylinders)
				{
					found = true;
					string response;
					list_one(x);
					cout << "This is the search result. Are you sure you want to delete this? (Y)es or (N)o? ";
					getline(cin,response);
					cout << "\n";
					for (char &c : response)
					{
						c = tolower(c);
					}
					if (response == "y")
					{
						if (x == (used - 1))
						{
							delete data[x];
						}
						else
						{
							delete data[x];
							for (int y = x+1; y < used; y++)
							{
								data[y-1] = data[y];
							}
						}
						used--;
						if (x <= 2)
						{
							x = 0;
						}
						else
						{
							x = x-2;
						}
					}
				}
			}
			if (found == false){
				cout << "Super car you entered was not found in the data base, please try again \n\n";
			}
		}

		//Function to Sort data base wrt to the name of the supercar
 		void sort_n()
        {
			int small;

			for (int i = 0 ; i < (used-1) ; i ++)
			{
				small = i;
				//Every j loop check in the whole array the value of j and small - assign small accordingly
				for (int j= i+1 ; j < used ; j++)
				{
					//if value at j is less than value at small , then store index j at small 
					//at the end of this loop the smallest value's index will be in small
					if (data[j]->getname() < data[small]->getname())
					{
						small = j;
					}
				}
				// Now we do the swap with the smallest value and the i index
				//shallow copying the superclass object at index i to temp
				supercar* temp[1];
				temp[0] = data[i];
				data[i] = data[small];
				data[small] = temp[0];
			}
        }
		
		//Function to Sort data base wrt to the brand of the supercar
		void sort_b()
        {
			int small;

			for (int i = 0 ; i < (used-1) ; i ++) 
			{
				small = i;
				//Every j loop check in the whole array the value of j and small - assign small accordingly
				for (int j= i+1 ; j < used ; j++)
				{
					//if value at j is less than value at small , then store index j at small 
					//at the end of this loop the smallest value's index will be in small
					if (data[j]->getbrand() < data[small]->getbrand()) 
					{
						small = j;
					}
				}
				// Now we do the swap with the smallest value and the i index
				//shallow copying the superclass object at index i to temp
				supercar* temp[1];
				temp[0] = data[i];
				data[i] = data[small];
				data[small] = temp[0];
			}
        }
		
		//Function to Sort data base wrt to the Horsepower of the supercar (increasing)
		void sort_h()
		{
			int min;
			for (int x = 0; x < (used-1); x++)
			{
				min = x;
				for (int y = x+1; y < used; y++)
				{
					if (data[y]->gethorsepower() < data[min]->gethorsepower())
					{
						min = y;
					}
				}
				if (min != x)
				{
					supercar* temp[1];
					temp[0] = data[x];
					data[x] = data[min];
					data[min] = temp[0];
				}
			}
		}
		
		//Function to Sort data base wrt to the Price of the supercar (increasing)
		void sort_p()
		{
			int min;
			for (int x = 0; x < (used-1); x++)
			{
				min = x;
				for (int y = x+1; y < used; y++)
				{
					if (data[y]->getprice() < data[min]->getprice())
					{
						min = y;
					}
				}
				if (min != x)
				{
					supercar* temp[1];
					temp[0] = data[x];
					data[x] = data[min];
					data[min] = temp[0];
				}
			}
		}
		
		//Function to Sort data base wrt to the Cylinders of the supercar (increasing)
		void sort_c()
		{
			int min;
			for (int x = 0; x < (used-1); x++)
			{
				min = x;
				for (int y = x+1; y < used; y++)
				{
					if (data[y]->getcylinders() < data[min]->getcylinders())
					{
						min = y;
					}
				}
				if (min != x)
				{
					supercar* temp[1];
					temp[0] = data[x];
					data[x] = data[min];
					data[min] = temp[0];
				}
			}
		}

		// Function to reverse the order of the Data base 
		//( used inside of our sort functions to implement Reverse Alphabetical order and Descending order)
		void reverse()
		{
			if (used > 1)
			{
				for (int x = 0; x < (used/2); x++)
				{
					supercar* temp[1];
					temp[0] = data[x];
					data[x] = data[used-1-x];
					data[used-1-x] = temp[0];
				}
			}
		}

		//Getter to get used
		int getused()
		{

			return used;
		}
		// Getter to get total space inside of array
		int getspace()
		{
			return space;
		}

		//destructor for database.h
		~database()
		{
			if (data != nullptr)
			{
				for (int x = 0; x < used; x++)
				{
					delete data[x];
				}
				delete[] data;
			}
			space = 0;
			used = 0;
			data = nullptr;
		}

}; // class database ends
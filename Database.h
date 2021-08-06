#include <iostream>      
#include <fstream>      
#include <string>        
#include <algorithm>    
#include <cassert>      
#include "cmpt_error.h" 
#include "Supercars.h"
/*
This stores all instances of Supercars.h. This is where we should implement our searching and sorting functions
*/
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
			cout << fname << "\n";
			string brand;
			string name;
			int power;
			int price;
			int cylinders;
			string n;
			fstream fin;
			int val = 0;
			fin.open(fname);
			if (fin.is_open())
			{
				while(fin.eof() != true)
				{
					fin >> n;
					if (val == 0)
					{
						brand = n;
						val++;
					}
					else if (val == 1)
					{
						name = n;
						val++;
					}
					else if (val == 2)
					{
						power = stoi(n);
						val++;
					}
					else if (val == 3)
					{
						price = stoi(n);
						val++;
					}
					else
					{
						cylinders = stoi(n);
						val++;
					}
					if (val == 5)
					{
						supercar *s = new supercar (brand, name, power, price, cylinders);
						add_supercar(s);
						val = 0;
					}
			 	}
			}
		fin.close();
		}

		//Saves the array to a file
		void save_to_file(const string &fname)
		{
			string n;
			fstream fout;
			fout.open(fname);
			for (int x = 0; x < used; x++)
			{
				fout << data[x]->getbrand() + "\t";
				fout << data[x]->getname() + "\t";
				fout << data[x]->gethorsepower() + "\t";
				fout << data[x]->getprice() + "\t";
				fout << data[x]->getcylinders() + "\n";
			}		
			fout.close();	
		}

		//destructor for database.h
		~database()
		{
			if (data != nullptr)
			{
				delete[] data;
			}
			space = 0;
			used = 0;
			data = nullptr;
		}

		//prints one supercar to the terminal. Used only for the find() function
		void list_one(int index) const
		{
			if (used > 0)
			{
				string output = "";
				output = output + data[index]->getname() + " " + data[index]->getbrand() + " " + to_string(data[index]->gethorsepower()) + "hp ";
				output = output + to_string(data[index]->getcylinders()) + " " + to_string(data[index]->getprice());
				cout << output;
				cout << "\n";
			}
		}

		//Lists every supercar in the array
		void list_all() const
		{
			if (used > 0)
			{
				string output = "";
				for (int x=0; x<used;x++)
				{
					output = output + data[x]->getname() + " " + data[x]->getbrand() + " " + to_string(data[x]->gethorsepower()) + "hp ";
					output = output + to_string(data[x]->getcylinders()) + " " + to_string(data[x]->getprice());
					cout << output;
					cout << "\n";
				}
			}
		}
		
		//Finds a car in the array
		int find_car(const string &type) const
		{
			if (type == "n")
			{
				string nme;
				cout << "Enter the name of the supercar you wish to find: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x]->getname() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == "p")
			{
				string nme;
				int num;
				cout << "Enter the price of the supercar: ";
				int stop = -1;
				while (stop < 0)
				{
					getline(cin,nme);
					num = stoi(nme);
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
					if (data[x]->getcylinders() == num)
					{
						list_one(x);
					}
				}
			}

			if (type == "h")
			{
				string nme;
				int num;
				cout << "Enter the horsepower the supercar has: ";
				int stop = -1;
				while (stop < 0)
				{
					getline(cin,nme);
					num = stoi(nme);
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
					}
				}
			}

			if (type == "b")
			{
				string nme;
				cout << "Enter the brand of the supercar: ";
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x]->getbrand() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == "c")
			{
				string nme;
				int num;
				cout << "Enter the number of cylinders the supercar has: ";
				int stop = -1;
				while (stop < 0)
				{
					getline(cin,nme);
					num = stoi(nme);
					if (num < 0 || num >= used)
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
					}
				}
			}
			return 0;
		}

		void delete_supercar()
		{
			string brand;
			string name;
			cout << "Enter the brand of the supercar you would like to remove: ";
			getline(cin,brand);
			getline(cin,name);
			for (int x = 0; x < used; x++)
			{
				if (data[x]->getbrand() == brand && data[x]->getname() == name)
				{
					cout << "Supercar Found. Deleting Supercar...";
					for (int y = x+1; y < used; y++)
					{
						data[y-1]->setbrand(data[y]->getbrand());
						data[y-1]->setname(data[y]->getname());
						data[y-1]->setcylinders(data[y]->getcylinders());
						data[y-1]->sethorsepower(data[y]->gethorsepower());
						data[y-1]->setprice(data[y]->getprice());
					}
					cout << "Supercar Deleted.\n";
					used--;
				}
			}		
		}

		int getused()
		{
			return used;
		}

		int getspace()
		{
			return space;
		}

/*
		void reverse()
		{
			if (used > 1)
			{
				for (int x = 0; x < (used/2); x++)
				{
					int temp = data[x];
					data[x] = data[used-1-x];
					data[used-1-x] = temp;
				}
			}
		}

		void sort()
		{
			std::sort(data,data+used);
		}

	// ...
	*/

}; // class database
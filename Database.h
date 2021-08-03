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

class Database {
	private:
		supercar* data;
		int space;
		int used;

	public:
		void add_supercar(supercar s)
		{
			if (used >= space-1)
			{
				supercar temporary[space];
				for (int x = 0; x < used; x++)
				{
					temporary[x] = data[x];
				}
				space *= 2;
				delete[] data;
				data = new supercar[space];
				for (int x = 0; x < used; x++)
				{
					data[x] = temporary[x];
				}
			}
			data[used] = s;
			used++;
		}

		Database(const string& fname)
		{
			space = 10;
			used = 0;
			data = new supercar[space];			
			string n;
			int p;
			fstream fin;
			fin.open(fname);
			if (fin.is_open())
			{
				while(fin.eof() != true)
				{
					fin >> n;
				}
			}
			fin.close();
		}

		~Database()
		{
			if (data != nullptr)
			{
				delete[] data;
			}
			space = 0;
			used = 0;
			data = nullptr;
		}
		void list_one(int index) const
		{
			if (used > 0)
			{
				if (used == 1)
				{
					string output = "";
					output = output + data[index].getname() + " " + data[index].getbrand() + " " + to_string(data[index].gethorsepower()) + "hp ";
					output = output + to_string(data[index].getcylinders()) + " " + to_string(data[index].getprice());
					cout << output;
					cout << "\n";
				}
			}
		}

		void list_all() const
		{
			if (used > 0)
			{
				string output = "";
				for (int x=0; x<used;x++)
				{
					output = output + data[x].getname() + " " + data[x].getbrand() + " " + to_string(data[x].gethorsepower()) + "hp ";
					output = output + to_string(data[x].getcylinders()) + " " + to_string(data[x].getprice());
					cout << output;
					cout << "\n";
				}
			}
		}
		
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
					if (data[x].getname() == nme)
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
					if (data[x].getcylinders() == num)
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
					if (data[x].gethorsepower() == num)
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
					if (data[x].getbrand() == nme)
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
					if (data[x].getcylinders() == num)
					{
						list_one(x);
					}
				}
			}
		}

		void delete_supercar(int index)
		{
			data[index].setbrand("");
			data[index].setname("");
			data[index].setcylinders(0);
			data[index].sethorsepower(0);
			data[index].setprice(0);
			for (int x = index; x < used; x++)
			{
				data[index].setbrand(data[index+1].getbrand());
				data[index].setname(data[index+1].getname());
				data[index].setcylinders(data[index+1].getcylinders());
				data[index].sethorsepower(data[index+1].gethorsepower());
				data[index].setprice(data[index+1].getprice());
			}
			used--;
		}

/*
		void set(int index, int s)
		{
			if (index < 0)
			{
				cmpt::error("Index is less than 0");
			}
			else if (index > used-1)
			{
				cmpt::error("Index is greater than Database used");
			}
			data[index] = s;
		}
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

}; // class Database
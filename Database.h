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
		void append(supercar s)
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
/*
		void list_one(int index) const
		{
			if (used > 0)
			{
				if (used == 1)
				{
					string output = "";
					output = output + data[index].name() + " " + data[index].brand() + " " + data[index].horsepower() + "hp ";
					output = output + data[index].cylinders() + " " + data[index].price();
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
					output = output + data[x].name() + " " + data[x].brand() + " " + data[x].horsepower() + "hp ";
					output = output + data[x].cylinders() + " " + data[x].price();
					cout << output;
					cout << "\n";
				}
			}
		}
		
		int find_car(const string &type) const
		{
			if (type == n)
			{
				string nme;
				cout << "Enter the name of the supercar you wish to find: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x].name() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == p)
			{
				string nme;
				cout << "Enter the price of the supercar you wish to find: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x].price() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == h)
			{
				string nme;
				cout << "Enter the horsepower number the supercar produces: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x].horsepower() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == b)
			{
				string nme;
				cout << "Enter the brand of the supercar you wish to find: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x].brand() == nme)
					{
						list_one(x);
					}
				}
			}

			if (type == c)
			{
				string nme;
				cout << "Enter the number of cylinders the supercar has: ";
				getline(cin,nme);
				cout << "\n";
				for (int x = 0; x < used; x++)
				{
					if (data[x].cylinders() == nme)
					{
						list_one(x);
					}
				}
			}
		}



		void prepend(int s)
		{
			if (used >= space)
			{
				int temporary[space];
				for (int x = 0; x < used; x++)
				{
					temporary[x] = data[x];
				}
				space *= 2;
				delete[] data;
				data = new int[space];
				used++;
				for (int x = 1; x < used; x++)
				{
					data[x] = temporary[x-1];
				}
				data[0] = s;
			}
			else
			{
				int temporary[space];
				for (int x = 0; x < used; x++)
				{
					temporary[x] = data[x];
				}
				used++;
				for (int x = 1; x < used; x++)
				{
					data[x] = temporary[x-1];
				}
				data[0] = s;
			}
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

		void remove_all(int n)
		{
			int temp[space];
			int count = 0;
			int numremoved = 0;
			for (int x = 0; x < used; x++)
			{
				if (data[x] != n)
				{
					temp[count] = data[x];
					count++;
				}
				else
				{
					numremoved++;
				}
			}
			used = used - numremoved;
			delete[] data;
			data = new int[space];
			for (int x = 0; x < used; x++)
			{
				data[x] = temp[x];
			}
		}

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

	// ...
	*/

}; // class Database
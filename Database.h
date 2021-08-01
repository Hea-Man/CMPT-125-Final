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
		//Question 1
		Database()
		{
			space = 10;
			used = 0;
			data = new supercar[space];
		}

		//Question 2
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
		string to_str() const
		{
			string output = "[";
			if (used > 0)
			{
				if (used == 1)
				{
					output = output + to_string(data[0]);
				}
				else
				{
					for (int x=0; x<used;x++)
					{
						if (x==used-1)
						{
							output = output + to_string(data[x]);
						}
						else
						{
							output = output + to_string(data[x]) + ", ";
						}
					}
				}
			}
			output = output + "]";
			return output;
		}
		
		int get(int index) const
		{
			if (index < 0)
			{
				cmpt::error("Index is less than 0");
			}
			else if (index > used-1)
			{
				cmpt::error("Index is greater than Database used");
			}
			return data[index];
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

		void append(int s)
		{
			if (used >= space-1)
			{
				int temporary[space];
				for (int x = 0; x < used; x++)
				{
					temporary[x] = data[x];
				}
				space *= 2;
				delete[] data;
				data = new int[space];
				for (int x = 0; x < used; x++)
				{
					data[x] = temporary[x];
				}
			}
			data[used] = s;
			used++;
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

		//Question 14
		Database(const string& fname)
		{
			space = 10;
			used = 0;
			data = new int[space];			
			int n;
			fstream fin;
			fin.open(fname);
			if (fin.is_open())
			{
				while(fin.eof() != true)
				{
					fin >> n;
					append(n);
				}
			}
			fin.close();
		}

	// ...
	*/

}; // class Database

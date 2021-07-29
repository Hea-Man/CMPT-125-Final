#include <iostream>      
#include <fstream>      
#include <string>        
#include <algorithm>    
#include <cassert>      
#include "cmpt_error.h" 

using namespace std;

class int_vec {
	private:
		int* data;
		int space;
		int used;

	public:
		//Question 1
		int_vec()
		{
			space = 10;
			used = 0;
			data = new int[space];
		}

		//Question 3
		int_vec(int n, int s)
		{
			space = 10;
			if (n >= space)
			{
				space = n;
			}
			if (n < 0)
			{
				cmpt::error("Invalid used Entered\n");
			}
			used = n;
			data = new int[space];
			for (int i = 0; i < used; i++)
			{
				data[i] = s;
			}
		}

		//Question 4
		int_vec(int_vec& other)
		{
			space = other.space;
			used = other.used;
			data = new int[space];
			for (int x = 0; x < used; x++)
			{
				data[x] = other.data[x];
			}
		}

		//Question 2
		~int_vec()
		{
			if (data != nullptr)
			{
				delete[] data;
			}
			space = 0;
			used = 0;
			data = nullptr;
		}

		//Question 5
		int size() const
		{
			return used;
		}

		int capacity() const
		{
			return space;
		}

		double pct_used() const
		{
			double average = (double)used/(double)space;
			double rounded = (int)(average * 1000.0)/1000.0;
			return rounded;
		}

		//Question 6
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

		void print()
		{
			cout << to_str();
		}

		void println()
		{
			cout << "\n" << to_str() + "\n";
		}

		//Question 7
		int get(int index) const
		{
			if (index < 0)
			{
				cmpt::error("Index is less than 0");
			}
			else if (index > used-1)
			{
				cmpt::error("Index is greater than int_vec used");
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
				cmpt::error("Index is greater than int_vec used");
			}
			data[index] = s;
		}

		//Question 8
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

		//Question 9
		void append(int_vec& other)
		{
			int size = other.used;
			for (int x = 0; x < size; x++)
			{
				append(other.data[x]);
			}
		}

		//Question 10
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

		//Question 11
		void clear()
		{
			used = 0;
			delete[] data;
			data = new int[space];
		}
		void compact()
		{
			if (space > used)
			{
				space = used;
			}
		}

		//Question 13
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
		int_vec(const string& fname)
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

}; // class int_vec

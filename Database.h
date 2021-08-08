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
DOES NOT SUPPORT SPACES IN CAR NAMES. WE GOTTA FIX THIS SOMEHOW.
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
			FILE* out = fopen("cars.txt","w");
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
		// Make changes so that the when outputted 
		void list_all() const
		{
			if (used > 0)
			{
				cout << setw(10) << "BRAND:" << setw(30) << "NAME:" << setw(30) << "HORSEPOWER:" 
					 << setw(30) << "CYLINDERS:" << setw(30) << "PRICE:";
				cout << "\n";
				for (int x=0; x<used;x++)
				{
					cout << setw(10) << data[x]->getbrand() << setw(30) << data[x]->getname() << setw(30) << to_string(data[x]->gethorsepower()) << "hp"
						 << setw(30) << to_string(data[x]->getcylinders()) << setw(30) << to_string(data[x]->getprice());
					cout << "\n";

				}
			}
		}
		
		//Finds a car in the array
		//One type of search should print all the records where the typed in string occurs as a substring in the appropriate field
		int find_car(const string &type) const
		{
			if (type == "n")
			{
				cout<<"Do you want to Find all records where the input occurs as a substring as well ?\n";
				cout<<"Please type (Y)es or (N)o:    ";
				char input;
				cin >> input;
				input = tolower(input);
				cout <<"test1\n";
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
						}
					}
				}
				else if (input == 'y'){
					cout <<"test 2\n";
					string substr;
					cout << "Enter the substring of the Name you wish to find: ";
					cin.clear();
					cin.ignore(123,'\n');
					getline(cin,substr);
					cout <<"\n";
					// so this find() function inside of the cstring library returns the position if substr found other 
					//wise it returns a -1 value 
					
					for (int x = 0; x < used; x++)
					{
						int position = (data[x]->getname()).find(substr);
						if (position != -1) // if found print it
						{
							list_one(x);
						}
					}
				}
				cout <<"test3\n";
				
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
						}
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
						}
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
			cout << "Enter the name of the super car you would like to remove: ";
			getline(cin,name);
			cout << "\n";
			bool deleted = false;
			for (int x = 0; x < used; x++)
			{
				if (data[x]->getbrand() == brand && data[x]->getname() == name)
				{
					deleted = true;
					cout << "Supercar Found.   ";
					if (x == (used - 1))
					{
						data[x]->setbrand("");
						data[x]->setname("");
						data[x]->sethorsepower(0);
						data[x]->setprice(0);
						data[x]->setcylinders(0);
					}
					else
					{
						for (int y = x+1; y < used; y++)
						{
							data[y-1]->setbrand(data[y]->getbrand());
							data[y-1]->setname(data[y]->getname());
							data[y-1]->sethorsepower(data[y]->gethorsepower());
							data[y-1]->setprice(data[y]->getprice());
							data[y-1]->setcylinders(data[y]->getcylinders());
						}
					}
					cout << "Supercar Deleted.\n";
					used--;
				}
			}
			if (deleted == false){
				cout << "Super car you entered was not found in the data base, please try again \n \n";
			}		
		}

		//So we need a sort method which will sort with respect to all fields 
        void sort_car(const string& type)
        {

            if (type == "1")
            {
                char ascending;
                cout << "Do you want to sort your fields in (A)scending order or (D)escending order?\n";
                cin >> ascending;
                ascending = tolower(ascending);
                //Ascending
                if (ascending == 'a') {
                    cout << "Please select the field which you would like to sort in Ascending Order\n";
                    cout << "(N)ame or (B)rand";
					cin.clear();
					cin.ignore(123,'\n');
                    string field;
                    cin >> field;
                    for (char &c:field){
						c = tolower(c);
					}
					string temp;
                    //Name
                    if (field == "n") {


                        /* for (int x = 0; x < used; x++)
                        {
							// To sort in Alphabetical order
                            for ( int z = x+1 ; z < used ; ++z){
								if(data[x]->getname() > data[z]->getname()){
									

									// We don't want to be swapping here lets try to figure out the minimum value 
									temp = data[x]->getname();
									data[x]->getname() = data[z]->getname();
									data[z]->getname() = temp;
								}
                            }

							// The x index is in correct location now so 

                        } */


						//Or Just make it based on a selection sorting algo that checks all elements and puts the smallest in index 0
						// and then moves onto the next index

						int i , j , small ;
						/* string nametemp,brandtemp;
						int horsepowertemp , cylinderstemp, pricetemp; */
						supercar temp("unknown", "unknown1122", 1 , 1 ,1);

						cout << temp.getname();
						
						for ( i = 0 ; i < used-1 ; i ++) {
							small = i;
							//Every j loop check in the whole array the value of j and small - assign small accordingly
							for ( j= i+1 ; j < used ; j++){
								//if value at j is less than value at small , then store index j at small 
								//at the end of this loop the smallest value's index will be in small
								if (data[j]->getname() < data[small]->getname()) {
									small = j;
								}
							}
							// Now we do the swap with the smallest value and the i index
							
							
							//shallow copying the superclass object at index i to temp
							temp = *data[i];
							cout << " \n";;
							//well its working so like woo - this on paper is sorting our data base
							cout<< temp.getbrand() << "\n " << temp.getname() << "\n" << temp.gethorsepower() << "\n" << temp.getcylinders() << "\n"; 
							data[i] = data[small];
							*data[small] = temp;

							cout << "what its being swapped with : " <<data[i]->getbrand() << "   " << data[i]->getname() ;
						}  
                    }
                }
            }
        }

		void int_compare_h()
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

		void int_compare_p()
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

		void int_compare_c()
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

		int getused()
		{

			return used;
		}

		int getspace()
		{
			return space;
		}

}; // class database
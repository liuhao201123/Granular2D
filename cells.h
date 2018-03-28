#include<iostream>
#include<iomanip>
using namespace std;

class cells
{
	public:
        cells(double a, double b, double c):
        age(0)
        {
            x = a;
            y = b;
            diameter = c;
        }
        void set(double a, double b, double c)
        {
            x = a;
            y = b;
            diameter = c;
        }
        void get()
        {
            cout << left<<  setw(12)<<"x";
            cout << right<< setw(12)<<"y";
            cout << right<< setw(12)<< "diameter";
            cout << right<< setw(12)<< "age"<< endl;
            
            cout << left<<  setw(12)<<x;
            cout << right<< setw(12)<<y;
            cout << right<< setw(12)<< diameter;
            cout << right<< setw(12)<< age<< endl;
        }
        void ageRecord()
        {
        	age = age + 1;
        }
        
		double x, y, diameter, age, theta;
	private:

	
};

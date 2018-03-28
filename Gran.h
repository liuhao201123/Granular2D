#include<iostream>
#include<vector>
#include"cells.h"

using namespace std;


class Gran
{
	public:
		Gran(int a)
		{
			num = a;
			initialization();
		};
		void initialization();
		void Division(int id, double theta);
		void Generation_Division();
		int DivisionAngle(int seed);
		void Minimization();
		void MD(int len, double* fxnew, double* fynew);
		double force(int len, double * fxnew, double * fynew);
		vector <cells> cell;
	private:
		int num;

		
};

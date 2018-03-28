#include<iostream>
#include<math.h>
#include"Gran.h"
#include<stdlib.h>

using namespace std;
const double PI  =3.141592653589793238463;
void Gran::initialization()
{
	cells temp_cell(0.e0,0.e0, 1.e0);
	cell.push_back(temp_cell);
	cout << "this is initialization  " << num<<endl;

};


void Gran::Division(int id, double theta)
{
	double rl, rs;
	theta = theta * PI/ 180.0;
	rl = (1+1.4)/2.0 / (1 + pow(1.4, 2));
	rs = (1+1.4)/2.0* pow(1.4, 2) / (1 + pow(1.4, 2));
	double x, y;
	x = rl * cos(theta) + cell[id].x; y = rl* sin(theta) + cell[id].y;
	cells temp_cell(cell[id]);
	temp_cell.set(x, y, rl); temp_cell.ageRecord();
	cell.push_back(temp_cell);
	
	x = cell[id].x - rs * cos(theta); y =cell[id].y- rs*sin(theta);
	cell[id].set(x, y, rs); cell[id].ageRecord();

}

void Gran::Generation_Division()
{
	int len = cell.size(), seed;
	seed = DivisionAngle(seed);
	for(int i = 0; i<len; i++ )
	{
		Division(i, 45);
	
	}
	/*for(auto it= cell.begin(); it != cell.end(); it++)
	{
		(*it).get();

	}*/
}

int Gran::DivisionAngle(int seed = 1)
{
	
	for(auto it= cell.begin(); it != cell.end(); it++)
	{
		it->theta = rand()%100000/100000.0 * 360;
		seed = seed + 1;
	
	}
	return seed;
}

void Gran::Minimization()
{	double gamma();
	int len = cell.size();
	double *fx = new double[len];
	double *fy = new double[len];
	for(int step = 0; step < 2; step++)
	{
		MD(len, fx, fy);
	}
	
	
	delete[] fx;
	delete[] fy;

}

void Gran:: MD(int len, double * fxnew, double * fynew)
{
	double *xo = new double[len];
	double *yo = new double[len];
	double *fxo = new double[len];
	double *fyo = new double[len];
	double gamma_n(0), temp(0), mean_force;
	
	for(int i =0; i<len; i++)
	{
		xo[i] = cell[i].x;
		yo[i] = cell[i].y;
		fxo[i] = fxnew[i];
		fyo[i] = fynew[i];
		cell[i].x += gamma_n* fxnew[i];
		cell[i].y += gamma_n* fynew[i];
	
	}
	mean_force = force(len, fxnew, fynew);
	gamma_n = 0;temp = 0;
	for (int i = 0; i< len; i++)
	{
		gamma_n -= (cell[i].x - xo[i])*(fxnew[i] - fxo[i])\
				  +(cell[i].y - yo[i])*(fynew[i] - fyo[i]);
	
	}
	
	for (int i = 0; i< len; i++)
	{
		temp += pow((fxnew[i] - fxo[i]), 2) + pow((fynew[i] - fyo[i]), 2);
	}
	gamma_n /= temp;
	delete[] xo;
	delete[] yo;
	delete[] fxo;
	delete[] fyo;
}

double Gran::force(int len, double * fxnew, double * fynew)
{
	
}







































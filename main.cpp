#include<iostream>
#include<vector>
#include<string>
#include"Gran.h"

void pp(double *fx, int len)
{

	for(int i = 0; i< len; i++)
	{
		cout << i<<endl;
	}

}

using namespace std;
int main(){
	int nn = 0;
	
	Gran grans(1);
	
//	grans.Division(0,45);
	for(int generation = 1; generation <=2; generation++)
	{
		grans.Generation_Division();	
	}

	for(auto it= grans.cell.begin(); it != grans.cell.end(); it++)
	{
		it ->get();
	}
	
	int len = 2;
	double *fx = new double[len];
	for(int i = 0; i<len; i++)
	{
		fx[i] = i;
	}
	
	pp( fx, len);
	
	
}

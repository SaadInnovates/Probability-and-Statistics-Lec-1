#include<iostream>
using namespace std;
#include"Generator.h"
int main()
{
	double ratios[] = { 0.1,0.2,0.2,0.3,0.05,0.15 };
	int values[] = {1,2,3,4,5,6};
	double* rPtr = &ratios[0];
	int* vPtr = &values[0];
	int size;
	cout << "Enter the size : ";
	cin >> size;
	Number_Generator g(ratios, values, sizeof(values) / sizeof(int), size);
	g.displayResultantArray();
	for (int i = 1; i <= 6; i++)
	{
		g.displayCount(i);
	}



	return 0;
}
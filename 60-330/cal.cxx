/*
Homework #1
Part 1
Michael Morand
103626334
60-330
January 24, 13
This program will perform the simpson's rule as asked in part a. Loops 100,000 times
By running the Time Utility, usr/bin/time ./a.out I get: 
13.46user 0.00system 0:13.46elapsed 100%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+369minor)pagefaults 0swaps
0:13.46 Seconds
*/
#include <iostream>


int main()
{	

	int a;
	double answer = 0; //This is the ans
	for(a = 0; a!= 100000; a++) //This for loop will run the program 100,000 times as requested.
	{	
		double x = 0;
		double loop = 0; //This value is required for reinitialization.
		double h = 0; //This value is required for reinitialization.
		double a = 0.0; //This value is required for reinitialization.
		double b = 1.0; //This value is required for reinitialization.
		h = (b - a) / 32000.0;//This is the h value, that is require to determine the formula
		int n = 1;
		x = h;
		loop += 4 / (1 + 0); //This is f(X0)
		for(;n!=16000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
		{
			
			loop += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
			x += h; //This increments the slices for the formula
			loop += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
			x += h;  //This increments the slices for the formula
		} 
		loop += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
		x += h; //This increments the slices for the formula
		loop += 4 / (1 + (x * x)); //This is f(Xn)
		answer = (h/3)*loop; //This is the h/3 
	}

	std::cout << answer << "\n"; //Gives the final answer to the user

	return 0;
}

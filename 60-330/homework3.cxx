/*
Homework #3
Michael Morand
103626334
60-330
Febuary 24, 13
This program will perform the simpson's rule as asked in part a. Loops 100,000 times
By running the Time Utility, /usr/bin/time ./a.out I get: 
Average Time After 6 Times: 0:04.72
Note: GCC Complier has Issues currently, use Clang++
*/

#include <iostream>
#include <unistd.h> 
#include <sys/wait.h>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <thread>

double final = 0;



void first(double h)
{
	double loop1;
	double x;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{ 	
				loop1 = 0;
				x = h;
				
				for(int n = 1; n!=4000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop1 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop1 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 


			}
			//std::cout << "loop1: " << loop1 << "\n";
			final += loop1;
			//return x;

}

void second(double h)
{
	

			double x = 0.250031;
			double loop2;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
			
				x = 0.250031;
				loop2 = 0;
				for(int n = 4000; n!=8000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop2 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop2 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 

			}
			//std::cout << "loop2: " << loop2 << "\n";
			final += loop2;
	//return x;
}

void third(double h)
{
	double x = 0.500031;
			double loop3;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
			
				x = 0.500031;
				loop3 = 0;
				for(int n = 8000; n!=12000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop3 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop3 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 


			}
			//std::cout << "loop3: " << loop3 << "\n";
			final += loop3;

	//return x;
}

void fourth(double h)
{
	
	
			double x = 0.750031;
			double loop4;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
				x = 0.750031;
				loop4 = 0;

				for(int n = 12000; n!=16000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop4 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop4 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)

					x += h;  //This increments the slices for the formula
				} 

			}
			//std::cout << "loop4: " << loop4 << "\n";
			final += loop4;
			
			
	
	//return x;
}



int main()
{	
	
	
	double x = 0.0;
	/*int pipe1[2]; //Pipe
	int pipe2[2]; //Pipe
	int pipe3[2]; //Pipe
	int pipe4[2]; //Pipe*/
	double loop = 0.0; //This value is required for reinitialization.
	double h = 0.0; //This value is required for reinitialization.
	double a = 0.0; //This value is required for reinitialization.
	double b = 1.0; //This value is required for reinitialization.
	double answer = 0; //This is the ans
	h = (b - a) / 32000.0;//This is the h value, that is require to determine the formula
	int n = 0;
	x = h;
	x += h;
	/*pipe(pipe1);//Initializes first pipe
	pipe(pipe2);//Initializes second pipe
	pipe(pipe3);//Initializes third pipe
	pipe(pipe4);//Initializes fourth pipe*/

	
		std::thread firstThread (first,h); //Creates the thread 
		std::thread secondThread (second,h);//Creates the thread 	
		std::thread thirdThread (third,h);//Creates the thread 
		std::thread fourthThread (fourth,h);//Creates the thread 

		firstThread.join();//Waits for the thread 
		secondThread.join();//Waits for the thread 
		thirdThread.join();//Waits for the thread 
		fourthThread.join();//Waits for the thread 
		//ssize_t p;
		/*wait(&p);
		wait(&p);
		wait(&p);
		wait(&p);*/
		//Wait or waitpid here with loop += ''''''' hence it adds it to the loop and the final will be totalled up below.
		//The problem has to due with below. It waits for input.
		/*read(pipe1[0], &readit1, sizeof(double));
		close(pipe1[0]);
		read(pipe2[0], &readit2, sizeof(double));
		close(pipe2[0]);
		read(pipe3[0], &readit3, sizeof(double));
		close(pipe3[0]);
		read(pipe4[0], &readit4, sizeof(double));
		close(pipe4[0]);*/
		//std::cout << "Values: " << readit1 << " , " << readit2 << " , " << readit3 << " , " << readit4 << "\n";
		loop = final; //loads the values in.
		//std::cout << "Final: " << final << "\n";
		loop += 4 / (1 + 0); //This is f(X0)
		x = 0.999969;	
		loop += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
		x += h; //This increments the slices for the formula
		loop += 4 / (1 + (x * x)); //This is f(Xn-1)
		x += h; //This increments the slices for the formula
		loop += 4 / (1 + (x * x)); //This is f(Xn)
		//std::cout << "Loop: " << loop << "\n";
		answer = (h/3)*loop; //This is the h/3 
		//std::cout << "H: " << h << "\n";
		//std::cout << "X " << x << "\n";
		std::cout << "Final Answer: " << answer << "\n"; //Gives the final answer to the user

	


	/*int a;
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
	 */
	//std::cout << answer << "\n"; //Gives the final answer to the user

	return 0;
}

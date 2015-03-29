/*
   Homework #1
   Part 2
   Michael Morand
   103626334
   60-330
   January 24, 13
   This program will perform the simpson's rule as asked in part a. Loops 100,000 times
   By running the Time Utility, usr/bin/time ./a.out I get: 
	0.00user 0.00system 0:04.51elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
	0inputs+0outputs (0major+400minor)pagefaults 0swaps
   Hence Time is: 0:04.51


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



int main()
{	
	
	pid_t pid;
	double readit1; 
	double readit2; 
	double readit3; 
	double readit4; 
	double x = 0.0;
	int pipe1[2]; //Pipe
	int pipe2[2]; //Pipe
	int pipe3[2]; //Pipe
	int pipe4[2]; //Pipe
	double loop = 0.0; //This value is required for reinitialization.
	double h = 0.0; //This value is required for reinitialization.
	double a = 0.0; //This value is required for reinitialization.
	double b = 1.0; //This value is required for reinitialization.
	double answer = 0; //This is the ans
	h = (b - a) / 32000.0;//This is the h value, that is require to determine the formula
	int n = 0;
	x = h;
	x += h;
	pipe(pipe1);//Initializes first pipe
	pipe(pipe2);//Initializes second pipe
	pipe(pipe3);//Initializes third pipe
	pipe(pipe4);//Initializes fourth pipe

	for (; n != 4; ++n) //This for loop initializes the 1 parent and four childs.
	{
		pid = fork(); //Forks 4 times
		if (pid == 0) 
		{
			break;		//If pid == 0, then i kill u cause i need only 1 parent
		}
	}	

	if(pid == 0)
	{
		
		if(n == 0)
		{
			double loop1;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{ 	
				loop1 = 0;
				x = h;
				
				for(n = 1; n!=4000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop1 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop1 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 


			}
			//std::cout << "If: 0, PID: " << pid << ", What I'm returning: " << loop << "\n";
			write(pipe1[1], &loop1, sizeof(double));
			close(pipe1[1]);
			
		}

		if(n == 1)
		{

			x = 0.250031;
			double loop2;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
			
				x = 0.250031;
				loop2 = 0;
				for(n = 4000; n!=8000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop2 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop2 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 

			}
			//std::cout << "If: 1, PID: " << pid << ", What I'm returning: " << loop << "\n";
			write(pipe2[1], &loop2, sizeof(double));
			close(pipe2[1]);
			
		}


		if(n == 2)
		{

			x = 0.500031;
			double loop3;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
			
				x = 0.500031;
				loop3 = 0;
				for(n = 8000; n!=12000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop3 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop3 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)
					x += h;  //This increments the slices for the formula
				} 


			}
			//std::cout << "If: 2, PID: " << pid << ", What I'm returning: " << loop << "\n";
			write(pipe3[1], &loop3, sizeof(double));
			close(pipe3[1]);
			
		}


		if(n == 3)
		{

			x = 0.750031;
			double loop4;
			for(int c = 0; c!= 100000; c++) //This for loop will run the program 100,000 times as requested.
			{	
				x = 0.750031;
				loop4 = 0;

				for(n = 12000; n!=16000; ++n) //This loop with loop the two functions 4(f(x)) = 4 / (1+x^2) and 2(f(x)) = 4 / (1+x^2)
				{

					loop4 += 4 * (4/(1+(x*x)));// 4(f(x)) = 4 / (1+x^2)
					x += h; //This increments the slices for the formula
					loop4 += 2 * (4/(1+(x*x)));// 2(f(x)) = 4 / (1+x^2)

					x += h;  //This increments the slices for the formula
				} 

			}

			//std::cout << "If: 3, PID: " << pid << ", What I'm returning: " << loop << "\n";
			write(pipe4[1], &loop4, sizeof(double));
			close(pipe4[1]);
			
		}			
		exit(0);
	}
	else
	{	
		
		//ssize_t p;
		/*wait(&p);
		wait(&p);
		wait(&p);
		wait(&p);*/
		//Wait or waitpid here with loop += ''''''' hence it adds it to the loop and the final will be totalled up below.
		//The problem has to due with below. It waits for input.
		read(pipe1[0], &readit1, sizeof(double));
		close(pipe1[0]);
		read(pipe2[0], &readit2, sizeof(double));
		close(pipe2[0]);
		read(pipe3[0], &readit3, sizeof(double));
		close(pipe3[0]);
		read(pipe4[0], &readit4, sizeof(double));
		close(pipe4[0]);
		//std::cout << "Values: " << readit1 << " , " << readit2 << " , " << readit3 << " , " << readit4 << "\n";
		loop = (readit1 + readit2 + readit3 +readit4);
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

	}


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

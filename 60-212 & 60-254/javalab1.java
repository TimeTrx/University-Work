


import java.util.*;


public class javalab1 {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		int numberSupplied = keyboard.nextInt(); //States that 12 is the number we are looking for.
		int I;
		int C = 0;
		int E = 0;//Flags are all set to zero
		int T = 0;
		int O;
		I = numberSupplied; //Sets I to 12
		while (T == 0)
		{
		    for (I = 2 ; I < numberSupplied ; I++) // Loop relates division to check.
		    {
				O = numberSupplied % I; //Math equation checks for prime
	
				if (O == 0) //If 1, not prime.
				{
				    C = 1; //Flags message to say its not prime
				}

		    }

		    if (C == 0)
		    {
				System.out.println (numberSupplied + " is a prime number!");//Output that the number is a prime number
				T = T + 1; // Flags the loop to stop
				E = 1;// Flags the to reset the math equation flag
		    }

		    if (E == 1)
		    {
				C = 0;
				E = 0;//Resets this flag
		    }

		    if (C == 1) //If it can be divided without remander
		    {
		    	System.out.println (numberSupplied + " is not a prime number, going to next number.");//outputs that it is not a prime number
		    }

		    numberSupplied = numberSupplied + 1; //Increases number to start all over again
		    C = 0;// Resets not a prime number flag
		}
		//makes 12 = 13
	    }

	}

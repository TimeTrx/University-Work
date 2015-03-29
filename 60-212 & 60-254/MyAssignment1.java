package aPackage;

public class MyAssignment1 {
	public static void main (String[] args)
	{
		int num1, num2, num3, num4; //Variables used in math logic equations
		int G, T, O, D; //Variables that change with the for loops
		int add1, add2, add3; //Variables to carry numbers.
		System.out.println ("The Answers For: ");
		System.out.println ("  TOO\n  TOO\n  TOO\n +TOO\n=GOOD");
		System.out.println ("are:\n");

		for (G = 0 ; G < 10 ; G++) //For loop letter G
		{
			num1 = G;

			for (T = 0 ; T < 10 ; T++) //For loop letter T
			{
				num2 = T;

				for (D = 0 ; D < 10 ; D++) //For loop letter D
				{
					num3 = D;
					for (O = 0 ; O < 10 ; O++) //For loop letter O
					{
						num4 = O;
						if ((num1 != num4) && (num1 != num3) && (num1 != num2) && (num2 != num3) && (num2 != num4) && (num3 != num4)) //Checks that no two numbers are the same
						{

							if ((num4 * 4 == num3) || (num4 * 4 == num3 + 10) || (num4 * 4 == num3 + 20) || (num4 * 4 == num3 + 30)) //Makes sure that O X 4 = D plus remainder
							{
								add1 = 0;
								add2 = 0; //Makes sure all the remainders are zero untill filled by
								add3 = 0;

								if (num4 * 4 == num3 + 10)
								{
									add1 = 1;

								}


								if (num4 * 4 == num3 + 20) //Gets the remainder, if any
								{
									add1 = 2;

								}

								if (num4 * 4 == num3 + 30)
								{
									add1 = 3;

								}

								if ((num4 * 4 + add1 == num4) || (num4 * 4 + add1 == num4 + 10) || (num4 * 4 + add1 == num4 + 20) || (num4 * 4 + add1 == num4 + 30)) //Makes sure that O X 4 = O plus remainder
								{
									if (num4 * 4 + add1 == num4 + 10)
									{
										add2 = 1;

									}


									if (num4 * 4 + add1 == num4 + 20) //Gets the remainder, if any
									{
										add2 = 2;

									}

									if (num4 * 4 + add1 == num4 + 30)
									{
										add2 = 3;

									}

									if ((num2 * 4 + add2 == num4) || (num2 * 4 + add2 == num4 + 10) || (num2 * 4 + add2 == num4 + 20) || (num2 * 4 + add2 == num4 + 30)) //Makes sure that T X 4 = O plus remainder
									{

										if (num2 * 4 + add2 == num4 + 10)
										{
											add3 = 1;

										}


										if (num2 * 4 + add2 == num4 + 20) //Gets the remainder, if any
										{
											add3 = 2;

										}

										if (num2 * 4 + add2 == num4 + 30)
										{
											add3 = 3;

										}

										if (add3 == num1) //Makes sure that G = remainder
										{

											System.out.println ("O= " + num4 + " D= " + num3 + " T= " + num2 + " G= " + num1); //Prints the values for O, D, T, and G
										}
									}
								}




							}
						}

					}
				}
			}


		}

	} 

}

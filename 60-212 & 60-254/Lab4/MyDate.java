import java.util.*;
public class MyDate {
	private int month, day, year;
	private String [] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	public MyDate(String input)
	{
		int num = 0;
		StringTokenizer super1 = new StringTokenizer(input,"/");//breaks the sentence into tokens
		while(super1.hasMoreTokens())
		{
			if(num == 0)
			{
			day = Integer.parseInt(super1.nextToken());
			}
			
			if(num == 1)
			{
				month = Integer.parseInt(super1.nextToken());
			}
			
			if(num == 2)
			{
				year = Integer.parseInt(super1.nextToken());
			}
			num++;
		}
	}
	
	public MyDate(MyDate ThisDate)
	{
	  day = ThisDate.day;
	  month = ThisDate.month;
	  year = ThisDate.year;
	}
	
		
		
	
	public String toString()
	{
		
		String newDate;
		String years = Integer.toString(year);
		
		newDate = String.format("%s %d, '%s", months[month -1], day, years.substring(2, 4));
		return newDate;
	}

	public boolean lessThan(MyDate nextDate)
	{
		return ((year < nextDate.year) 
				|| (year == nextDate.year &&  month < nextDate.month) 
				|| (year == nextDate.year && nextDate.month == month && day < nextDate.day));
		
	}
	
	
	public boolean equals(MyDate nextDate)
	{
		return ((month == nextDate.month) && (day == nextDate.day) && (year == nextDate.year));
	}

}

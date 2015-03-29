import Towers_of_Hanoi.*;

import java.io.*;
import java.util.*;
public class main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int  disks, start, end;
		
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Start");
		start = keyboard.nextInt();
		System.out.println("End");
		end = keyboard.nextInt();
		System.out.println("Disks");
		disks = keyboard.nextInt();
		
		HanoiFrame frame = new HanoiFrame(disks, start);
		recursive(disks, frame, start, end, diskother(start, end));
		return;
	}
	
	
	
	public static int diskother(int start, int end)
	{
		int other = 3 - (start + end);
		return other;
	}
	
	public static void recursive(int disks, HanoiFrame frame, int start, int end, int other)
	{
		if(disks == 1)
		{
		
		frame.storeMove(start, end);
		}
		
		else
		{
			recursive(disks-1, frame, start, other, end);
		frame.storeMove(start, end);
			recursive (disks-1, frame, other, end, start);
		
		}	
	}

}

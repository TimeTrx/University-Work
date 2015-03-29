package Towers_of_Hanoi;


import java.awt.*;
public class Disk {
	private Color c;
	private int width;
	
	public Disk(Color c, int width){
		this.c = c;
		this.width = width;
	}
	
	public void displayDisk(Graphics g, int spindle, int position){
		int xTopLeftCornerOfDisk, yTopLeftCornerOfDisk;
		g.setColor(c);
		xTopLeftCornerOfDisk = 80 + spindle * 90 - width/2;
		yTopLeftCornerOfDisk = 170 - position * 10;
		g.fillRoundRect(xTopLeftCornerOfDisk, 
				        yTopLeftCornerOfDisk,
				        width, 
				        10, 
				        5, 
				        5);
	}

}

package Towers_of_Hanoi;


import java.awt.Color;
import java.awt.Graphics;
import java.util.*;
public class HanoiTower {
	private Disk disksOnSpindle[][];
	private int numDisksOnSpindle[] = {0, 0, 0};
	private ArrayList<Pair> moves;
	private int numberOfMoves;
	private int moveNumber = 0;
	
	boolean flag = true;
	
	private Color colorList[] = {Color.blue, Color.green,   
            Color.RED, Color.yellow};
	
	
	public HanoiTower(int numDisks, int startSpindle){		
		
		if (numDisks > 4){
			System.out.println("Can't handle more than 4 disks");
			System.exit(0);
		}
		
		disksOnSpindle = new Disk[3][numDisks];
		numDisksOnSpindle[startSpindle] = numDisks;
		
		for (int i = 0, width = 44; i < numDisks; i++, width -=10){
			disksOnSpindle[startSpindle][i] = new Disk(colorList[i], width);
		}	
		moves = new ArrayList<Pair>(20);
	}
	
	public void storeMove(int fromSpindle, int toSpindle){
		moves.add(new Pair(fromSpindle, toSpindle));
		numberOfMoves ++;
	}
	
	public void showNextMove(){
		int fromSpindle, toSpindle;
		Pair nextMove;
		if (moveNumber < numberOfMoves){
			nextMove = moves.get(moveNumber);
			fromSpindle = nextMove.fromSpindle;
			toSpindle = nextMove.toSpindle;
			moveTopDisk(fromSpindle, toSpindle);
			moveNumber++;
		}
	}
	
	public void moveTopDisk(int fromSpindle, int toSpindle){
		Disk diskToBeMoved;
		int oldPositionOfDiskToMove, newPositionOfDiskToMove;
		if (numDisksOnSpindle[fromSpindle] == 0){
			System.out.println("Spindle does not have any disk");
			System.exit(0);
		} else{
			oldPositionOfDiskToMove = numDisksOnSpindle[fromSpindle] - 1;
			diskToBeMoved = disksOnSpindle[fromSpindle][oldPositionOfDiskToMove];
			numDisksOnSpindle[fromSpindle]--;
			newPositionOfDiskToMove = numDisksOnSpindle[toSpindle];
			disksOnSpindle[toSpindle][newPositionOfDiskToMove] = diskToBeMoved;
			numDisksOnSpindle[toSpindle]++;
		}
	}
	
	public void showHanoiTower(Graphics g){
		
		g.setColor(Color.black);
		
		g.fillRect(30,180, 261, 50);
		g.fillRect(79, 50, 2, 130);
		g.fillRect(169, 50, 2, 130);
		g.fillRect(259, 50, 2, 130);
		for (int spindle  = 0; spindle  < 3; spindle ++){
			for (int disk = 0; disk < numDisksOnSpindle[spindle]; disk ++){
					disksOnSpindle[spindle][disk].displayDisk(g, spindle, disk);
			}
		}
		flag = false;
	}

}


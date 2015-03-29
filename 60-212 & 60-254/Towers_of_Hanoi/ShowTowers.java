package Towers_of_Hanoi;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
public class ShowTowers extends JFrame implements ActionListener{
	JButton nextButton, previousButton;
	private Disk disksOnSpindle[][];
	private int numDisksOnSpindle[] = {0, 0, 0};
	Color colorList[] = {Color.blue, Color.green,   
                         Color.RED, Color.yellow};
	FancyPanel towerPanel;
	
	private class FancyPanel extends JPanel{
		public void paintComponent(Graphics g){
			super.paintComponent(g);
			
			g.setColor(Color.black);
			g.fillRect(30,180, 261, 50);
			g.fillRect(79, 50, 2, 130);
			g.fillRect(169, 50, 2, 130);
			g.fillRect(259, 50, 2, 130);
			for (int spindle  = 0; spindle  < 3; spindle ++){
				for (int disk = 0; disk < numDisksOnSpindle[spindle]; disk ++){
					disksOnSpindle[spindle][disk].displayDisk(g, spindle, disk);
					System.out.println("spindle = " + spindle + ", disk = " + 
					           disk);
				}
			    System.out.println("check" + numDisksOnSpindle[0] + ", " + 
					           numDisksOnSpindle[1]);
			}
		}
	}
	
	public ShowTowers(int numDisks, int startSpindle){		
		super("Tower of Hanoi");
		
		if (numDisks > 4){
			System.out.println("Can't handle more than 4 disks");
			System.exit(0);
		}
		
		disksOnSpindle = new Disk[3][numDisks];
		numDisksOnSpindle[startSpindle] = numDisks;
		
		for (int i = 0, width = 44; i < numDisks; i++, width -=10){
			disksOnSpindle[startSpindle][i] = new Disk(colorList[i],
					                                width);
		}
		
		JPanel buttonPanel;
		setLayout (new BorderLayout());
		
		towerPanel = new FancyPanel();
		towerPanel.setBackground(Color.WHITE);
		add(towerPanel, BorderLayout.CENTER);
		buttonPanel = new JPanel();
		buttonPanel.setLayout(new FlowLayout());
		nextButton = new JButton("Show Next Move");
		nextButton.addActionListener(this);
		buttonPanel.add(nextButton);
		previousButton = new JButton("Show previous Move");
		previousButton.addActionListener(this);
		buttonPanel.add(previousButton);
		add(buttonPanel, BorderLayout.SOUTH);
		setSize(WIDTH, HEIGHT);
		setVisible(true);
	}
	
	public void moveTopDisk(int fromSpindle,
			                int toSpindle){
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

		
	public void actionPerformed(ActionEvent e){
		if (e.getSource() == nextButton){
			System.out.println("next pressed");
			moveTopDisk(0, 1);
			towerPanel.repaint();
		} else {
			System.out.println("previous pressed");
		}
	}
	
	public static void main(String a[]){
		
		ShowTowers myTowerOfHanoi = new ShowTowers(4, 0);
		myTowerOfHanoi.setVisible(true);
	}

}


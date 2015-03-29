package Towers_of_Hanoi;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class HanoiFrame extends JFrame{
	public static final int WIDTH = 320;
	public static final int HEIGHT = 400;
		JButton nextButton, previousButton;
		private HanoiTower myTower;
		private class TowerPanel extends JPanel{
			public void paintComponent(Graphics g){
				super.paintComponent(g);
				myTower.showHanoiTower(g);
			}
		}
		TowerPanel myPanel = new TowerPanel();
		JPanel buttonPanel;
		public HanoiFrame(int numDisks, int initialSpindle){
			myPanel.setBackground(Color.WHITE);
			myTower = new HanoiTower(numDisks, initialSpindle);
			
			buttonPanel = new JPanel();
			nextButton = new JButton("Show Next Move");
			nextButton.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					System.out.println("next pressed");
					myTower.showNextMove();
					myPanel.repaint();
				}
			}
			);

			buttonPanel.add(nextButton); 
			add(buttonPanel, BorderLayout.SOUTH);
			add(myPanel, BorderLayout.CENTER);
			setSize(WIDTH, HEIGHT);
			setVisible(true);
		}
		
		public void storeMove(int fromSpindle, int toSpindle){
			myTower. storeMove(fromSpindle, toSpindle);
		}

	}


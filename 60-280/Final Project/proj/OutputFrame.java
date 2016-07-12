package proj;

import javax.swing.*;

import java.util.Iterator;
import java.util.Observable;
import java.util.Observer;
import java.awt.*;
import java.awt.event.*;

import javax.swing.event.*;
public class OutputFrame extends JFrame implements MyObserver{
	final int WIDTH = 200, HEIGHT = 300;
	private JTextArea outputArea;
	public OutputFrame(){
		outputArea = new JTextArea(20, 30);
		add(outputArea);
		setSize(WIDTH, HEIGHT);
		setVisible(true);
	}
	public void displayResult(String s){
//		System.out.println(s);
		outputArea.setText(s);
	}
	public void redisplay(TesterFrame testerFrame, Object myShapes){ //The First Observer, I mixed up Circle and rectangle, this should be called rectanglesquare
		String outputString1 = "";
		testerFrame.myPanel.repaint();
		//Square.firstInIt();
		for (int i = 0; i < testerFrame.numShapes; i++)
		{
			if ((testerFrame.myShapes.get(i) instanceof Square) || 
			    (testerFrame.myShapes.get(i) instanceof Rectangle))	
			outputString1 += testerFrame.myShapes.get(i).toString();
		}
		testerFrame.showSquaresAndRectangles.displayResult(outputString1);
	}
	
	public void rectangle(TesterFrame testerFrame, Object myShapes) { //The Second Observer, this should be called circle
		String outputString2 = "";
		testerFrame.myPanel.repaint();
		for (int i = 0; i < testerFrame.numShapes; i++){
			if ((testerFrame.myShapes.get(i) instanceof Circle) && 
				(((Circle)testerFrame.myShapes.get(i)).calculateArea() > 5000)){
				outputString2 += testerFrame.myShapes.get(i).toString();
			}
		}
		
		testerFrame.showBigCircles.displayResult(outputString2);
	}
	
	
}

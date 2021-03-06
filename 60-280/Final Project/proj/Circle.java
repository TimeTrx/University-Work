package proj;

import java.awt.Color;
import java.awt.Graphics;

/*
 * Written by Subir Bandyopadhyay Sept 1, 2012
 * Class Rectangle represents a rectangle. 
 * 
 * Properties of class Circle
 * referencePoint - the left top corner of enclosing square - the reference point for the circle.
 * diameter  - the diameter of the circle
 * lastMousePosition - the last position where the mouse was pressed, 
 * 						useful when moving the rectangle
 * colorCircle - color of the circle
 * shapeSelected - a boolean variable which is true if the circle is 
 * 					selected for moving 
 * 
 * capabilities of class Circle (See below for more details)
 * onThePerimeter - returns true if mouse is pressed very close to the circumference of the circle
 * changeColor - modify the color of the circle
 * changeColorTemporarily - modify the color of the circle to yellow - useful when selecting a circle
 * changeColorBack - revert back to original color
 * changeShape - modify the width or the height of the circle
 * moveShape - move the circle by dragging the mouse 
 * shapeIsSelected - mark a circle as "selected" by pressing the mouse button inside the trctangle
 * resetShapeSelected - reset the shapeSelected flag
 * calculateArea - determine the area of the circle
 * showMe - display the circle inside the frame
 * toString - return a string describing the circle.
 * savePositionWhereUserPressedMouse - useful when dragging a shape
 * 
 */
public class Circle extends Shape implements SecondInterface{
	private Coordinates referencePoint; //reference point for a square
	public final double PI = 3.14;
	private int diameter;

	private Coordinates lastMousePosition; // If a shape has 
	// been  selected, the position where the 
	// user has pressed the mouse to select the shape

	private Color colorCircle; // color of a circle 
	
	private Color originalColorCircle;// Used to save the original color when the color changes temporarily

	private boolean shapeSelected = false;
	private boolean perimeterSelected = false;// Whether the  circle has  been selected for 
	// moving by pressing mouse button inside the shape

	// Constructor creates a black circle with diameter 50  with the reference point at (200, 200)

	public Circle(){
		referencePoint = new Coordinates(200, 200);  // new figure is at the center of frame
		colorCircle = new Color(0, 0, 0);  // colour is black
		diameter =50;
	}

	/* 
	 * changeColor(c) modifies the color of the circle to the new color c
	 */

	public void changeColor(Color c){
		colorCircle = c ;
	}
	
	
	public void changeColorTemporarily(){	 
		originalColorCircle = colorCircle; 
		colorCircle = Color.yellow ;
		perimeterSelected = true;
	}
	
	public void changeColorBack(){	 
		colorCircle = originalColorCircle; 
		perimeterSelected = false;
	}

	/*
	 * Method onThePerimeter checks if the user pressed the mouse button on the perimeter. 
	 * If so, it returns true; otherwise it return false.
	 */

	public boolean onThePerimeter(Coordinates mousePosition)
	{// the perimeter is selected if the distance from the point (x, y) to the center  is 
		// between radius - 5 and radius + 5
		int distanceFromCenter;
		Coordinates centreOfCircle;
		
		centreOfCircle = new Coordinates(referencePoint.getX() + diameter/2,
				                         referencePoint.getY() + diameter/2);
		distanceFromCenter = (int) distance(mousePosition, centreOfCircle);
		if ((distanceFromCenter >= diameter/2 - 5) && 
				(distanceFromCenter <= diameter/2 + 5)) {
			return true;
		} else{
			return false;
		}
	}

	/* 
	 * Method shapeIsSelected() returns true if the user previously selected the shape by 
	 * pressing the mouse button with the cursor inside the shape.
	 */

	public boolean shapeIsSelected(){
		return shapeSelected;
	}

	/*
	 * Method shapeIsSelected(positionOfMouse) checks if the position of the mouse where the user
	 * pressed the left mouse button is within the shape (at least 5 pixels away from the perimeter.
	 * If so, the flag shapeSelected is set and the method returns true.
	 * Otherwise, the flag shapeSelected is reset and the method returns false.
	 */

	public boolean shapeIsSelected(Coordinates positionOfMouse){ 
		// Check if the user pressed the mouse button inside the shape
		double distance;

		Coordinates centreOfCircle;
		centreOfCircle = computeCenterOfCircle(referencePoint, diameter);
		distance = distance(positionOfMouse, centreOfCircle);
		if (distance < diameter/2 - 5){
			shapeSelected = true;
			lastMousePosition = positionOfMouse;
			return true; 
		} else {
			shapeSelected = false;
			return false;
		}
	}

	/*
	 * changeShape changes the diameter of the circle, if
	 * currentPhase is 3 .
	 * currentPhase = 0, means the user is moving the shape
	 *              = 1, a new shape is being created
	 *              = 2, the the color of the new shape is being modified,
	 *              = 3, the diameter of the circle is being modified,
	 */

	public void changeShape(int currentPhase, int size){
		int newReferencePointX, newReferencePointY;
		if (currentPhase == 3){
			newReferencePointX = referencePoint.getX() + (diameter - size)/2;
			newReferencePointY = referencePoint.getY() + (diameter - size)/2;
			referencePoint = new Coordinates(newReferencePointX, newReferencePointY);
			diameter = size; 
		} 

	}

	/*
	 * Method moveShape(currentPositionMouse) allows the user to drag the circle by dragging the mouse
	 * button. The shape is first selected by pressing the mouse button with the cursor inside the shape.
	 * Then, if the user drags the mouse, the shape should move with the mouse.
	 * Moving a circle simply means modifying the reference point of the circle so that the
	 * circle moves with the mouse position.
	 * The idea is that if the x and the y coordinate of the position of the mouse is moved by specified
	 * amounts,the reference point must change by exactly the same amount.
	 */

	void moveShape(Coordinates currentPositionMouse){	     	
		if (shapeSelected) {		
			// If a shape is selected for a move operation, change the reference point 
			// as the mouse is being dragged.
			referencePoint.setX(referencePoint.getX() + 
					currentPositionMouse.getX() -
					lastMousePosition.getX());
			referencePoint.setY(referencePoint.getY() +
					currentPositionMouse.getY() -
					lastMousePosition.getY());
			lastMousePosition = currentPositionMouse;
		}
	}

	private double distance(Coordinates point1, Coordinates point2){
		double dist; // dist is the distance from point1 to point2
		dist = Math.sqrt((double) ((point1.getX() - point2.getX())*
				(point1.getX() - point2.getX()) +
				(point1.getY() - point2.getY())*(point1.getY() - point2.getY())));
		return dist ;
	} 
	public Coordinates computeCenterOfCircle(Coordinates referencePoint, int diameter){
		int xValueOfCenter,yValueOfCenter;
		xValueOfCenter = referencePoint.getX() + diameter/2;;
		yValueOfCenter = referencePoint.getY() + diameter/2;
		return new Coordinates(xValueOfCenter, yValueOfCenter);
	}
	/* 
	 * resetShapeSelected() simply resets the value of shapeSelected to false.
	 */

	public void resetShapeSelected(){
		shapeSelected = false;
	}
	/*
	 * calculateArea() returns the area of the rectangle
	 */

	double calculateArea(){ 
		return (PI * diameter * diameter/4);
	}

	/*
	 * showMe(g) displays the rectangle using the Graphic object g.
	 * It sets the color to be used, and draws the rectangle using the specified 
	 * reference point, the width and the height.
	 */

	public void showMe(Graphics g){
		g.setColor(colorCircle);
		g.drawOval(referencePoint.getX(), // Draw a circle with the specified 
				// corner point and diameter
				referencePoint.getY(),   
				diameter,
				diameter);
	}

	/* 
	 * toString() returns the description of the rectangle - the color, 
	 * the reference point and the size.
	 */

	public String toString(){
		return ("Circle with reference point " + referencePoint + " having diameter " + diameter + "\n");
	}

	public void savePositionWhereUserPressedMouse(int x, int y){
		lastMousePosition = new Coordinates(x, y);
	}

	@Override
	public Object firstInIt() 
	{
		return TesterFrame.myShapes.get(0);	
	}

	@Override
	public Object nextInIt(int position) 
	{
		if(hasnext(position) != false)
		{
		return TesterFrame.myShapes.get((position+1));
		}
		return null;
	}

	@Override
	public Boolean hasnext(int position) 
	{
		if (TesterFrame.myShapes.get((position+1)) != null)
		{
		return true;
		}
		else 
		return false;
	}

	@Override
	public Object Current(int position) 
	{
			return TesterFrame.myShapes.get(position);
	}



}


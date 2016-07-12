
package proj;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class Compound extends Shape 
{


	private Coordinates referencePoint; //reference point for a rectangle is the 
	// top left corner of the rectangle

	private int height, width, numShapes;  // height and width of rectangle

	private Coordinates lastMousePosition; 
	/* 
	 * If a rectangle has been  selected for moving, lastMousePosition gives the position where the 
	 * user has pressed the mouse.
	 */

	private Color colorCompound; // color of a rectangle 
	private Color originalcolorCompound;// Used to save the original color when the color changes temporarily

	private boolean shapeSelected = false;
	private boolean perimeterSelected = false;
	/*
	 * shapeSelected = false means that the  rectangle has  been selected for 
	 * moving by pressing mouse button inside the shape.
	 */
	private ArrayList<Shape> Shapes;
	/*
	 * Method onThePerimeter checks if the user pressed the mouse button on the perimeter. 
	 * If so, it returns true; otherwise it return false.
	 */
	public Compound()
	{
		Shapes = new ArrayList<Shape>();
	}
	




	boolean onThePerimeter(Coordinates mousePosition)
	{
		int xWhereMousePressed, yWhereMousePressed;

		xWhereMousePressed = mousePosition.getX();
		yWhereMousePressed = mousePosition.getY();
		
		for(Shape s: Shapes)
		{
			/*
			 * If the position where the user pressed the mouse button is within 5 pixels of 
			 * any side of the rectangle, the method will return true;
			 * Otherwise, it will return false.
			 */
			if (((xWhereMousePressed >= ((Coordinates) s.referencePoint).getX() - 5) &&
					(xWhereMousePressed <= (((Coordinates) s.referencePoint).getX() + width + 5)) &&
					(yWhereMousePressed >= ((Coordinates) s.referencePoint).getY() - 5) &&
					(yWhereMousePressed <= (((Coordinates) s.referencePoint).getY() + 5)))) return true;// top edge is edge # 0

			if (((xWhereMousePressed >= ((Coordinates) s.referencePoint).getX() - 5) &&
					(xWhereMousePressed <= (((Coordinates) s.referencePoint).getX() + 5)) &&
					(yWhereMousePressed >= ((Coordinates) s.referencePoint).getY() - 5) &&
					(yWhereMousePressed <= (((Coordinates) s.referencePoint).getY() + height + 5)))) return true;// left edge is edge # 1

			if (((xWhereMousePressed >= ((Coordinates) s.referencePoint).getX() - 5) &&
					(xWhereMousePressed <= (((Coordinates) s.referencePoint).getX() + width + 5)) &&
					(yWhereMousePressed >= ((Coordinates) s.referencePoint).getY() + height - 5) &&
					(yWhereMousePressed <= (((Coordinates) s.referencePoint).getY()+ height + 5)))) return true;//bottom edge-edge # 2

			if (((xWhereMousePressed >= ((Coordinates) s.referencePoint).getX() + width - 5) &&
					(xWhereMousePressed <= (((Coordinates) s.referencePoint).getX() + width + 5)) &&
					(yWhereMousePressed >= ((Coordinates) s.referencePoint).getY() - 5) &&
					(yWhereMousePressed <= (((Coordinates) s.referencePoint).getY() + height + 5)))) return true;// right edge-edge # 3


		}
		return false;
	}

	/* 
	 * changeColor(c) modifies the color of the rectangle to the new color c
	 */

	public void changeColor(Color c)
	{
		for(Shape s: Shapes)
		{
			s.colorCompound = c ; 
		}
	}

	public void changeColorTemporarily(){
		for(Shape s: Shapes)
		{
			s.originalcolorCompound = colorCompound; 
			s.colorCompound = Color.yellow ;
			s.perimeterSelected = true;
		}
	}

	public void changeColorBack(){	 
		for(Shape s: Shapes)
		{
			s.colorCompound = originalcolorCompound; 
			s.perimeterSelected = false;
		}
	}

	/*
	 * changeShape changes the width (or the height) of the rectangle, if
	 * currentPhase is 3 (or 4).
	 * currentPhase = 0, means the user is moving the shape
	 *              = 1, a new shape is being created
	 *              = 2, the the color of the new shape is being modified,
	 *              = 3, the width of a rectangle is being modified,
	 *              = 4, the height of a rectangle is being modified.
	 */

	public void changeShape(int currentPhase, int size){
	/*	for(Shape s: Shapes)
		{
			if (currentPhase == 3){
				width = size; 
			} else {
				height = size;
			}
		} */
	}

	/*
	 * Method moveShape(currentPositionMouse) allows the user to drag the rectangle by dragging the mouse
	 * button. The shape is first selected by pressing the mouse button with the cursor inside the shape.
	 * Then, if the user drags the mouse, the shape should move with the mouse.
	 * Moving a rectangle simply means modifying the reference point (upper left corner point) so that
	 * rectangle moves with the mouse position.
	 * The idea is that if the x and the y coordinate of the position of the mouse is moved by specified
	 * amounts,the reference point must change by exactly the same amount.
	 */

	void moveShape(Coordinates currentPositionMouse){	
		boolean y = false;
		for(Shape s: Shapes)
		{
			if (shapeSelected) {
				// If a shape is selected for a move operation, change the reference point 
				// as the mouse is being dragged.
				((Coordinates) s.referencePoint).setX(referencePoint.getX() + 
						currentPositionMouse.getX() -
						lastMousePosition.getX());
				((Coordinates) s.referencePoint).setY(referencePoint.getY() +
						currentPositionMouse.getY() -
						lastMousePosition.getY());
				lastMousePosition = currentPositionMouse;
				y = true;
			}
			if(y)
			{
				shapeIsSelected();
			}
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
		int x, y;
		x = positionOfMouse.getX();
		y = positionOfMouse.getY();
		// Check if the user pressed the mouse button inside the shape
		for(Shape s: Shapes)
		{
		if ((x >= ((Coordinates) s.referencePoint).getX() + 5) &&
				(x <= ((Coordinates) s.referencePoint).getX() + width - 5) &&
				(y >= ((Coordinates) s.referencePoint).getY() + 5) &&
				(y <= ((Coordinates) s.referencePoint).getY() + height - 5)) {
			shapeSelected = true;
			lastMousePosition = positionOfMouse;
			return true;
		}
		}
			shapeSelected = false;
			return false;

		
		
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

		return (width * height);
	}

	/*
	 * showMe(g) displays the rectangle using the Graphic object g.
	 * It sets the color to be used, and draws the rectangle using the specified 
	 * reference point, the width and the height.
	 */

	public void showMe(Graphics g){
		for(Shape s: Shapes)
		{
			
			if(s instanceof Rectangle)
			{
			((Graphics) s.g).setColor(s.colorCompound);
			((Graphics) s.g).drawRect(((Coordinates) s.referencePoint).getX(), // Draw a rectangle with the specified 
					// corner point
					((Coordinates) s.referencePoint).getY(),  // width and height fir
					width,
					height);
			}
			if(s instanceof Circle)
			{
				((Graphics) s.g).setColor(s.colorCompound);
				((Graphics) s.g).drawRect(((Coordinates) s.referencePoint).getX(), // Draw a rectangle with the specified 
						// corner point
						((Coordinates) s.referencePoint).getY(),  // width and height fir
						width,
						height);
				}
			
			if(s instanceof Square)
			{
				((Graphics) s.g).setColor(s.colorCompound);
				((Graphics) s.g).drawRect(((Coordinates) s.referencePoint).getX(), // Draw a rectangle with the specified 
						// corner point
						((Coordinates) s.referencePoint).getY(),  // width and height fir
						width,
						height);
				
			}
			if (s instanceof Compound)
			{
				((Graphics) s.g).setColor(s.colorCompound);
				((Graphics) s.g).drawRect(((Coordinates) s.referencePoint).getX(), // Draw a rectangle with the specified 
						// corner point
						((Coordinates) s.referencePoint).getY(),  // width and height fir
						width,
						height);
			
			}
		}
		
	}

	/* 
	 * toString() returns the description of the rectangle - the color, 
	 * the reference point and the size.
	 */

	public String toString(){

		return ("Rectangle with reference point " + referencePoint + " having width "
				+ width + " and height " + height + "\n");

	}
	/*
	 * savePositionWhereUserPressedMouse(int x, int y)is used to 
	 * save the position where the user Pressed the mouse button.
	 * This is useful for moving the rectangle.
	 */

	public void savePositionWhereUserPressedMouse(int x, int y){

		lastMousePosition = new Coordinates(x, y);
	}

	public void add(Shape object) 
	{
		Shapes.add((Shape) object);
	}


}

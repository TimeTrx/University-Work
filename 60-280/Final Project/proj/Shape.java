package proj;

import java.awt.Color;
import java.awt.Graphics;


//New Abstract Class Project Phase 1
//Circle and Rectangle Extend This Class
public abstract class Shape
{
	
	
	public Object referencePoint;
	public Color colorCompound;
	public Color originalcolorCompound;
	public boolean perimeterSelected;
	public Object g;
	public abstract void changeColor(Color c);
	public abstract void changeColorTemporarily();
	public abstract void changeColorBack();
	abstract boolean onThePerimeter(Coordinates mousePosition);
	public abstract boolean shapeIsSelected();
	public abstract boolean shapeIsSelected(Coordinates positionOfMouse);
    public abstract void changeShape(int currentPhase, int size);
	abstract void moveShape(Coordinates currentPositionMouse);
	//public abstract Coordinates computeCenterOfCircle(Coordinates referencePoint, int diameter);  <- Circle Only
	public abstract void resetShapeSelected();
	abstract double calculateArea();
	public abstract void showMe(Graphics g);
	public abstract String toString();
	public abstract void savePositionWhereUserPressedMouse(int x, int y);
	
	
}

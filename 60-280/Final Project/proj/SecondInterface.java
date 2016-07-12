package proj;

public interface SecondInterface 
{
	int position = TesterFrame.numShapes;
	public Object firstInIt(); //Returns the first one this time
	public Object nextInIt(int position); //Returns the second one this time 
	public Boolean hasnext(int position); //Returns if there is a next
	public Object Current(int position); //Returns the current
}

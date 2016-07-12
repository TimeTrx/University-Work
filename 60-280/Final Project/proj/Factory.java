package proj;

public class Factory 
{
	public static Shape build(String th)
	{
		Shape thisShape = null;
		if(th.equals("Square"))
		{
			return thisShape = new Square();
		}
		if(th.equals("Rectangle"))
		{
			return thisShape = new Rectangle();
		}
		if(th.equals("Circle"))
		{
			return thisShape = new Circle();
		}
		else
		return thisShape = new Compound();
	}
}
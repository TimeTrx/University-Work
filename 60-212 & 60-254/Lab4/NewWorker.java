
public class NewWorker extends Person{
	
	private static int howManyWorkers;
	private int workerNumber;
	private MyDate dateJoiningCompany;
	private double Salary;
	private NewWorker Supervisor;
	
public NewWorker(String name, String date, double salary)
{
	super(name);
	dateJoiningCompany = new MyDate(date);
	Salary = salary;
	workerNumber = NewWorker.howManyWorkers++; 
}

public NewWorker(String name, String date)
{
	super(name);
	dateJoiningCompany = new MyDate(date);
	Salary = 0.0;
	workerNumber = NewWorker.howManyWorkers++; 
}

//public NewWorker(NewWorker w)
//{
//	super(new Name(w.getName).toString());
//	workerNumber = NewWorker.howManyWorkers++;
//	Name workerName = w.workerName;
//	
//	MyDate dateJoiningCompany = new MyDate(w.dateJoiningCompany);
//	Salary = w.Salary;
//	Supervisor = w.Supervisor;
//}

public void setSalary(double newSalary)
{
	Salary = newSalary;
}

public void setSupervisor(NewWorker setWorker)
{
	Supervisor = setWorker;
}

public static int  getHowManyWorkers()
{
	return NewWorker.howManyWorkers;
}

public NewWorker getSupervisor()
{
	return Supervisor;
//	if(Supervisor != null)
//	{
//		return Supervisor.workerName.toString();
//	}
//	
//	return "None";
}

//public String toString()
//{
//	
//	if(getSpouse() != null)
//	{
//		return "Name is " +getName().toString() + " Married to " +getSpouse();
//		
//	}
//	else 
//		return "Name is " + getName().toString();
//	
//}

public int getSalary()
{
	return (int) Salary;
}


}

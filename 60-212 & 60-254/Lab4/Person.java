
public class Person {
	private Name personName;
	private Person spouse;

	
	public Name getName()
	{
		return personName;
	}

	public Person(String fullName)
	{
		personName = new Name(fullName);
	}

	public void setSpouse(Person newSpouse)
	{
		spouse = newSpouse;
	}
	public Person getSpouse()
	{
		return spouse;
	}
	public String toString()
	{
		if (personName == null) System.out.println("NULL");
	if(spouse != null)
	{
		return "Name is " +personName.toString() + " Married to " +spouse.getName().toString();
		
	}
	else 
		return "Name is " +personName.toString();
	}
	
	public double getFamilyIncome()
	{
		double salary, spouseSalary;
		if(this instanceof NewWorker)
		{
			salary = ((NewWorker)this).getSalary();
		}
		else
		{
			salary = 0.0;
		}
		
		if(spouse == null)
		{
			spouseSalary = 0.0;
		} else if(spouse instanceof NewWorker)
		{
			spouseSalary = ((NewWorker)spouse).getSalary();
		}
		else
		{
			spouseSalary = 0.0;
		}
		
		return (salary + spouseSalary);
		
	/*	if(spouse == null)
		{
				if(NewWorker.class == this.getClass())
				{
					return ((NewWorker)this).getSalary();
				}
				else
				{
					return (int) 0.0;
				}
		}
		else
		{
			if(NewWorker.class == spouse.getClass())
			{
				return ((NewWorker)this).getSalary() + (spouse).getClass().getSalary();
			}
			
		} */
			
	
	}
}

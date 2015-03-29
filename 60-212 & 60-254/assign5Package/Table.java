package assign5Package;

public class Table {
	private int tableNumber ; // each table has a unique table number
	private int numPlaces ; // How many people can be seated at the table

	public Table(int n, int p){
		tableNumber = n ;
		numPlaces = p ;
	}

	public int getNumber(){
		return tableNumber ;
	}

	public int getPlaces(){
		return numPlaces;
	}

	public String toString(){
		return("Table " + tableNumber + " holds " + numPlaces + " people.");
	}

}

package assign5Package;
import java.util.* ;
public class NewBookingSystem {
	MyDate currentDate ;
	  private DelegatedObservable obs;

	  Restaurant restaurant = null ;
	  ArrayList<Booking> currentBookings;

	  private static NewBookingSystem uniqueInstance ;

	  public static NewBookingSystem getInstance(){
	    if (uniqueInstance == null) {
	      uniqueInstance = new NewBookingSystem() ;

	    }
	    return uniqueInstance ;
	  }

	  private NewBookingSystem(){
	    restaurant = new Restaurant() ;
	    obs = new DelegatedObservable();
	  }

	  public MyDate getDate(){
		  return currentDate;
	  }

	  public Observable getObservable() {
	                return obs;
	      }

	  public void display(MyDate date){
	    currentDate = date ;
	    currentBookings = restaurant.getBookings(currentDate);
	    obs.setChanged();
	    obs.notifyObservers(currentBookings);
	  }

	  public ArrayList<Booking>  getBookings(){
	    return currentBookings;
	  }
}

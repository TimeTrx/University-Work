package itratorAssign;



public class IteratorTester {
	public static void main(String args[]) {
	    int elements[] = { 5, 4, 2, 12,1, 15, 9, 3};
	    AbstractList myCollection;
	    AbstractList.AbstractIterator myIterator;
	    myCollection = new NewArrayOfIntWithIterator();
	    for (int i = 0; i < elements.length; i++){
	           myCollection.append(elements[i]);
	    }
	    myIterator = myCollection.createIterator(4);
	    myIterator.first();
	    while (!myIterator.isDone()){
	       System.out.println(myIterator.currentItem().toString() + "\n");
	       myIterator.next();
	    }
	  }

}

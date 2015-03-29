package itratorAssign;



public class NewArrayOfIntWithIterator extends AbstractList {


	public void append(int v){ // Inserts new int value into the next available cell in array
		table[numElementsInTable] = v;
		numElementsInTable++;
	}
	private Integer table[];
	private int numElementsInTable = 0;


	public NewArrayOfIntWithIterator(){
		table = new Integer[10];
	}

//	public class Iterator extends AbstractIterator implements MyIterator{
	public class Iterator extends AbstractIterator {
		private Integer result[];
		private int currentElement;
		private int numElementsInResult = 0; // Stores the number of elements in result
		private boolean endOfTable;

		private void insertSort(Integer newElement, Integer result[]){
			Integer tempValue1, tempValue2;
			int positionForNewElement = 0; // position where newElement has to be stored
			
			boolean flag = true; // flag is true as long as the position to insert newElement in result
			// has not been determined
			if (numElementsInResult == 0) {
				result[0] = newElement;
				numElementsInResult =  1;
			}
			else {
				for (int i = 0; (i < numElementsInResult) && flag; i++){
					if (result[i] < newElement){
						positionForNewElement = i;
						flag = false;
					}

					if (!flag){// position for new element has been determined
						tempValue1 = result[positionForNewElement];
						result[positionForNewElement] = newElement;
						for (int j = positionForNewElement + 1 ; j < numElementsInResult; j++){
							tempValue2 = result[j];
							result[j] = tempValue1;
							tempValue1 = tempValue2;
						}
						if (numElementsInResult < result.length) // Save the last element if there is space in result
							result[numElementsInResult] = tempValue1;
					}
					else if (numElementsInResult < result.length){// newElement is larger than the last element in result.
						result[numElementsInResult] = newElement;
					}

				}
				if (numElementsInResult < result.length) numElementsInResult ++;
			}
		}

		public Iterator(int n){
			result = new Integer[n]; // result stores the array to be returned
			int numElements = 0; // This stores the number of elements in the array

			for (int i = 0; i < numElementsInTable; i++){
				insertSort(table[i], result);
			}

		}

		public void first(){
			currentElement = 0;
			if (result.length > 0) endOfTable = false;
			else endOfTable = true;
		}

		public void next(){
			if (currentElement < result.length - 1)
				currentElement ++;
			else endOfTable = true;
		}

		public boolean isDone(){
			return endOfTable;
		}

		public Integer currentItem(){
			return result[currentElement];
		}
	}

	public Iterator createIterator(int numElements){
		return new Iterator(numElements);
	}



}

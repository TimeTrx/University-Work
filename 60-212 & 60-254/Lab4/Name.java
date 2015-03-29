import java.util.StringTokenizer;


public class Name {
	String firstName;
	String middleName;
	String lastName;

	public Name(String name1) {

		int num = 0;
		String[] str = new String[100];
		StringTokenizer super1 = new StringTokenizer(name1, "/ ,.");// breaks the
																	// sentence
																	// into
																	// tokens
		while (super1.hasMoreTokens()) {
			str[num] = super1.nextToken();
			num++;
		}

		if (num == 2) {
			firstName = str[0];
			lastName = str[1];
			middleName = null;
		}
		if (num == 3) {
			firstName = str[0];
			lastName = str[2];
			middleName = str[1];
		}
		
		

	}

	public String toString(String firstName, String middleName, String lastName) {
		String buffer;
		if (middleName != null) {
			buffer = String.format("%s, %s %c.", lastName, firstName,
					middleName.charAt(0));// not right check text book for format
		} else {
			buffer = String.format("%s, %s", lastName, firstName);
		}
		
		return buffer;
	}

	public void setName(String name1, String name2, double name3) 
	{
		int num = 0;
		String[] str = new String[100];
		StringTokenizer super1 = new StringTokenizer(name1, "/ ,.");// breaks the
																	// sentence
																	// into
																	// tokens
		while (super1.hasMoreTokens()) {
			str[num] = super1.nextToken();
			num++;
		}

		if (num == 2) {
			firstName = str[0];
			lastName = str[1];
			middleName = null;
		}
		if (num == 3) {
			firstName = str[0];
			lastName = str[2];
			middleName = str[1];
		}
	}

	public Name(Name n) 
	{
		firstName = n.firstName;
		middleName = n.middleName;
		lastName = n.lastName;
	}

}

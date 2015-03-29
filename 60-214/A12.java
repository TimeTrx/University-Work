import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Assignment1b {

	public static void main(String[] args) throws Exception {
		ArrayList<String> array = new ArrayList<String>();
		String fullinputfile = " ";
		int counter = 0;
		BufferedReader in = new BufferedReader(new FileReader(
				"C:/Users/Mike/Desktop/A1.tiny.txt"));
		// BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String inputfile;
		while ((inputfile = in.readLine()) != null) {
			fullinputfile = fullinputfile + " " + inputfile;
		}
		in.close();
		for (String ret : fullinputfile
				.split("[:();\\*,\\+=\\-\\/ ]|WRITE|READ|IF|ELSE|RETURN|BEGIN|END|MAIN|STRING|INT|REAL")) {

			if (!ret.contains("\"")) {
				Pattern check = Pattern.compile("[a-zA-Z][a-zA-Z0-9]*");
				Matcher match = check.matcher(ret);
				while (match.find()) {
					if (!array.contains(ret)) {
						counter = counter + 1;
						array.add(ret);
						System.out.println(ret);
					}
				}
			}
		}
		PrintWriter outputfile = new PrintWriter("A1.output");
		outputfile.println("identifers:" + counter);
		outputfile.close();
	}

}

import java.io.*;
import java.util.*;

public class Assignment1 {

	public static void main(String[] args) throws Exception {
		ArrayList<String> array = new ArrayList<String>();
		String fullinputfile = " ";
		int counter = 0;
		// BufferedReader in = new BufferedReader(new FileReader(args[0]));
		BufferedReader in = new BufferedReader(new FileReader(
				"C:/Users/Mike/Desktop/A1.tiny.txt"));
		String inputfile;

		while ((inputfile = in.readLine()) != null) {
			fullinputfile = fullinputfile + " " + inputfile;
		}
		in.close();
		StringTokenizer st = new StringTokenizer(fullinputfile,
				" \n\t;,()+-*/:=!");
		while (st.hasMoreElements()) {
			String token;
			token = st.nextToken();
			if (token.equals("WRITE") || token.equals("READ")
					|| token.equals("IF") || token.contains("\"")
					|| token.equals("ELSE") || token.equals("RETURN")
					|| token.equals("BEGIN") || token.equals("END")
					|| token.equals("MAIN") || token.equals("STRING")
					|| token.equals("INT") || token.equals("REAL")) {

			} else {
				if (Character.isLetter(token.charAt(0))
						&& !token.contains("\"")) {

					if (!array.contains(token)) {
						counter = counter + 1;
						System.out.println(token);
						array.add(token);
					}
				}
			}
		}

		PrintWriter outputfile = new PrintWriter("A1.output");
		outputfile.println("identifers:" + counter);
		outputfile.close();
	}
}

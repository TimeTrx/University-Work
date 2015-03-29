import java.io.*;
%%
%{
		int keywordcount = 0;
		int indentifercount = 0;
		int commentcount = 0;
		int numbercount = 0;
		int quotedstringcount = 0;
		public static void main(String [] args) throws java.io.IOException{
		A2 Scanner = new A2(new FileInputStream("A2.input"));
		while(Scanner.yylex() >= 0)
		{

		}
		Scanner.outputfile();
   }
	public void outputfile() throws java.io.IOException{
		PrintWriter Output = new PrintWriter(new FileOutputStream("A2.output"));
		Output.println("identifiers: "+ indentifercount);
		Output.println("keywords: "+ keywordcount);	
		Output.println("numbers: "+ numbercount);	
		Output.println("comments: "+ commentcount);	
		Output.println("quotedString: "+ quotedstringcount);
		Output.close();
	}

%}
%class A2
%integer
%eofval{ return null;
%eofval}
KEYWORD  = WRITE|READ|IF|ELSE|RETURN|BEGIN|END|MAIN|STRING|INT|REAL
%state COMMENT
%%
<YYINITIAL>"/**" {yybegin(COMMENT);}
<COMMENT> .|\n|\r  { }
<COMMENT>"**/"	{commentcount++; yybegin(YYINITIAL);}
<YYINITIAL> {KEYWORD} {keywordcount++;}  
<YYINITIAL> [0-9]*[.]?[0-9]+  { numbercount++;} 
<YYINITIAL> [a-zA-Z][a-zA-Z0-9]* {indentifercount++;}
<YYINITIAL> \"[^\"]*\" {quotedstringcount++;}
<YYINITIAL> \r|\n {}
<YYINITIAL> . {}

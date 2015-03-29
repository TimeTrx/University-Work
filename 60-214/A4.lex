import java.io.*;
import java_cup.runtime.*;
%%

%class A4Scanner
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%eofval{ return null;
%eofval}
KEYWORD  = WRITE|READ|IF|ELSE|RETURN|BEGIN|END|MAIN|STRING|INT|REAL
%state COMMENT
%%
<YYINITIAL>"/**" {yybegin(COMMENT);}
<COMMENT> .|\n|\r  { }
<COMMENT>"**/"	{yybegin(YYINITIAL);}
<YYINITIAL> BEGIN {return new Symbol (A4Symbol.BEGIN);}
<YYINITIAL> END {return new Symbol (A4Symbol.END);}
<YYINITIAL> "WRITE" {return new Symbol (A4Symbol.WRITE);}
<YYINITIAL> "READ" {return new Symbol (A4Symbol.READING);}
<YYINITIAL> IF {return new Symbol (A4Symbol.IF);}
<YYINITIAL> ELSE {return new Symbol (A4Symbol.ELSE);}
<YYINITIAL> RETURN {return new Symbol (A4Symbol.RETURN);}
<YYINITIAL> MAIN {return new Symbol (A4Symbol.MAIN, yytext());}
<YYINITIAL> STRING {return new Symbol (A4Symbol.STRING);}
<YYINITIAL> INT {return new Symbol (A4Symbol.INT);}
<YYINITIAL> REAL {return new Symbol (A4Symbol.REAL);}
<YYINITIAL> ":=" {return new Symbol (A4Symbol.ISE);}
<YYINITIAL> [0-9]*[.]?[0-9]+  {return new Symbol (A4Symbol.NUMBER, yytext());} 
<YYINITIAL> [a-zA-Z][a-zA-Z0-9]* {return new Symbol (A4Symbol.ID, yytext());}
<YYINITIAL> \"[^\"]*\" {return new Symbol (A4Symbol.QUOTEDSTRING, yytext());}
<YYINITIAL> \r|\n {}
<YYINITIAL> [(] {return new Symbol (A4Symbol.LBRACK);}
<YYINITIAL> [)] {return new Symbol (A4Symbol.RBRACK);}
<YYINITIAL> [;] {return new Symbol (A4Symbol.SEMICOLON);}
<YYINITIAL> [,] {return new Symbol (A4Symbol.COMMA);}
<YYINITIAL> [+-] { return new Symbol(A4Symbol.SOP, yytext()); }
<YYINITIAL> [/*] {return new Symbol (A4Symbol.MOP, yytext());}
<YYINITIAL> "==" {return new Symbol (A4Symbol.EQUALS);}
<YYINITIAL> "!=" {return new Symbol (A4Symbol.NEQUALS);}


<YYINITIAL> . {}


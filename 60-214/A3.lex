import java.io.*;
import java_cup.runtime.*;
%%
%class A3Scanner
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
<YYINITIAL> BEGIN {return new Symbol (A3Symbol.BEGIN);}
<YYINITIAL> END {return new Symbol (A3Symbol.END);}
<YYINITIAL> {KEYWORD} {}  
<YYINITIAL> [0-9]*[.]?[0-9]+  {return new Symbol (A3Symbol.NUMBER);} 
<YYINITIAL> [a-zA-Z][a-zA-Z0-9]* {return new Symbol (A3Symbol.STRING);}
<YYINITIAL> \"[^\"]*\" {return new Symbol (A3Symbol.QUOTEDSTRING);}
<YYINITIAL> \r|\n {}
<YYINITIAL> . {}


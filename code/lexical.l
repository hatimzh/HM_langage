%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "syntaxe.h"
extern int lineNumber;
int getTypeLex(char *t);

%}
%option noyywrap

TYPE 							boolean|number|string
DIGIT							[0-9]
BOOLEAN 						True|False
NUMBER 							{DIGIT}+|{DIGIT}+"\."{DIGIT}+
STRING 							\"([^"\n])*\"
Variable_Name 					[a-zA-Z][0-9a-zA-Z_]*
Comment 						"//"[^\n]*

%%

not|"!"					 		return NOT;
and							return AND;
or 							return OR;
"=="	 						return EQUALITY;
"!="	 						return DIFFERENT;
"<="	 						return LOWER_EQUAL;
">="	 						return GREATER_EQUAL;
var 							return VAR;
func	 						return FUNCTION;
return 							return RETURN;
if 								return IF;
elif 							return ELSEIF;
else 							return ELSE;
for 							return FOR;
from							return IN;
do 								return DO;
while 							return WHILE;
out							return PRINT;
in							return SCAN;
{Comment}						{ return COMMENT;}

{TYPE} 							{ yylval.type = getTypeLex(yytext); return VARIABLE_TYPE;}
{BOOLEAN} 						{ yylval.bval = !strcmp(yytext, "True") ? 1 : 0; return BOOLEAN;}
{NUMBER} 						{ yylval.nval = atof(yytext); return NUMBER;}
{STRING}						{ yytext[strlen(yytext)-1] = '\0'; yylval.sval = strdup(yytext+1); return STRING;}
{Variable_Name} 				{ yylval.sval = strdup(yytext); return VARIABLE_NAME; }

[ \t] ;
\n ++lineNumber;
.  return yytext[0];

%%

int getTypeLex(char *t){
	if(!strcmp(t, "boolean")) return 0;
	else 	if(!strcmp(t, "number")) return 1;
	 	  	else if(!strcmp(t, "string")) return 2;
}
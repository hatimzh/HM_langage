%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE* yyin;
int lineNumber;
int typeReturn;
FILE *file;

#define L 50
#define M 50
#define N 101

typedef union val{
	int b;
	float n;
	char *s;
} val;

typedef struct var{
	char *name;
	int type;
	val value;
	struct var *next;
} variable;

typedef struct f{
	char *name;
	int type;
	struct f *next;
} function;

function *functions[L];
variable *constants[M];
variable *variables[N];

int yylex(void);
void yyerror(const char *msg);
int hash(char *name);
variable* findVariable(char *name);
variable* findConstant(char *name);
function* findFunction(char *name);
int isVariableDeclared(char *name);
int isConstantDeclared(char *name);
int isFunctionDeclared(char *name);
variable* newDeclaredVariable(char *name, int type, variable *next);
variable* newConstant(char *name, int type, variable *next);
function* newFunction(char *name, int type, function *next);
void insertNewDeclaredVariable(char *name, int type);
void insertNewConstant(char *name, int type);
void insertNewFunction(char *name, int type);
int getType(char *name);
char* toCType(int type);
char* toCShortType(char *name);
char* toCPrint(char *string);
void listdeclation(char *s1, char *s2, char *del);
FILE* createfile();

%}

%union {
	int type;
	int bval;
	float nval;
	char *sval;
}

%token IMPORT <sval>BIBLIO_NAMES
%token NOT AND OR
%token INCREMENT_SIGN DECREMENT_SIGN
%token EQUALITY DIFFERENT LOWER_EQUAL GREATER_EQUAL
%token VAR
%token FUNCTION RETURN
%token IF ELSEIF ELSE
%token SWITCH CASE OTHERS
%token FOR IN DO WHILE
%token PRINT SCAN
%token <type>VARIABLE_TYPE <sval>VARIABLE_NAME
%token <bval>BOOLEAN <nval>NUMBER <sval>STRING
%token COMMENT

%type <sval> functionArgumentList functionArgument functionTypes ifClause elseIfClauses elseIfClause elseClause forTypes instruction print scan declaration assignment concatenation scanType condition logicalExpression logicalTerm logicalTypes comparisionExpression arithmiticExpression arithmiticTerm arithmiticFactor arithmiticTypes calledFunction arguments types

/*switch type*/

%start program
%%
program 					: {file = createfile();} code {fclose(file);}
							;

code 						: functionList mainProgram
							| mainProgram
							| import functionList mainProgram
							| import mainProgram
							| {fprintf(file,"int main(){ return 0;}");}
							;

import 						: IMPORT BIBLIO_NAMES ';' {fprintf(file,"#include<%s.h>\n",$2);}
							;

functionList				: functionList function
							| functionList listComment function
							| function
							| listComment function
							;

listComment					: listComment '' COMMENT
							| COMMENT
							;

function 					: FUNCTION VARIABLE_NAME '(' {if(isFunctionDeclared($2)){ yyerror("Function already defined"); exit(-1);} insertNewFunction($2, -1);fprintf(file, "void "); fprintf(file,"%s", $2); fprintf(file, "(");} functionArgumentList ')' '{' {fprintf(file, "){\n");} statementList '}' {fprintf(file, "}\n");}
							| VARIABLE_TYPE FUNCTION VARIABLE_NAME '(' {if(isFunctionDeclared($3)){ yyerror("Function already defined"); exit(-1);} insertNewFunction($3, $1); switch($1){ case 0 : {fprintf(file, "int ");break;} case 1 : {fprintf(file, "float ");break;} case 2 : {fprintf(file, "char *");break;} default : break;} fprintf(file,"%s", $3); fprintf(file, "(");} functionArgumentList ')' '{' {fprintf(file, "){\n");} statementList RETURN functionTypes ';' '}' {fprintf(file, "return "); fprintf(file, $12); fprintf(file, ";\n"); fprintf(file, "}\n");}
							;

functionArgumentList		: functionArgumentList ',' {fprintf(file, ", ");} functionArgument
							| functionArgument
							| {}
							;

functionArgument 			: VARIABLE_TYPE VARIABLE_NAME {switch($1){ case 0 : {fprintf(file, "int ");break;} case 1 : {fprintf(file, "float ");break;} case 2 : {fprintf(file, "char *");break;} default : break;} fprintf(file, " "); fprintf(file, $2);}
							;

functionTypes				: arithmiticExpression {typeReturn = 1; $$ = $1;}
							| logicalExpression {typeReturn = 0; $$ = $1;}
							| concatenation {typeReturn = 2; $$ = $1;}
							;

mainProgram 				:  {fprintf(file,"\nint main(){\n");} statementList {fprintf(file,"printf(\" \\n\\nEnd of execution.\\nTape Enter to finish ...\\n\");getchar();getchar();\n}");}
							;

statementList				: statementList statement
							| statement
							;

statement 					: ifStatement
							| forStatement
							| whileStatement
							| doWhileStatement
							| listInstruction
							;

ifStatement 				: ifClause elseIfClauses elseClause
							| ifClause elseClause
							| ifClause elseIfClauses
							| ifClause
							;

ifClause 					: IF condition '{' {fprintf(file,"if("); fprintf(file,$2); fprintf(file,"){\n");} statementList '}'  {fprintf(file,"}\n");}
							;

elseIfClauses 				: elseIfClauses elseIfClause
							| elseIfClause
							;

elseIfClause 				: ELSEIF condition '{'  {fprintf(file,"else if("); fprintf(file,$2); fprintf(file,"){\n");} statementList '}' {fprintf(file,"}\n");}
							;

elseClause 					:   ELSE '{' {fprintf(file,"else{\n");} statementList '}' {fprintf(file,"}\n");}
							;

forStatement 				: FOR VARIABLE_NAME IN forTypes {fprintf(file,"for(int "); fprintf(file,$2); fprintf(file,"= (int)"); fprintf(file,$4);} '-' forTypes '{' {fprintf(file,";"); fprintf(file,$2); fprintf(file,"<="); fprintf(file,$7); fprintf(file,";"); fprintf(file,$2); fprintf(file,"++){\n");}  statementList '}' {fprintf(file,"}\n");}
							;

forTypes					: NUMBER { char tmp[32]="\0"; sprintf(tmp,"%f",$1); $$ = tmp;}
							| VARIABLE_NAME { char *tmp; tmp = strdup($1); $$ = tmp;}
							;

doWhileStatement 			: DO '{' {fprintf(file,"do{(");} statementList '}' WHILE condition ';' {fprintf(file,"\n}while("); fprintf(file,$7); fprintf(file,");\n");}
							;

whileStatement 				: WHILE condition '{' {fprintf(file,"while("); fprintf(file,$2); fprintf(file,"){\n");} statementList '}' {fprintf(file,"}\n");}
							;

listInstruction				: listInstruction instruction
							| instruction
							;

instruction 				: declaration {fprintf(file,"%s",$1);}
							| assignment {fprintf(file,"%s",$1);}
							| scan {fprintf(file,"%s",$1);}
							| print {fprintf(file,"%s",$1);}
							| listComment {}
							| calledFunction ';'{fprintf(file,"%s;\n",$1)}
							;

print 						: PRINT '(' STRING ')' ';' {$$ = strdup("printf("); strcat($$, toCPrint($3)); strcat($$, ");\n");}

scan 						: SCAN '(' scanType ')' ';'	{
															char out[1024];
															if(isFunctionDeclared($3)){ yyerror("Can t affect value to functions"); exit(-1);}
															if(isConstantDeclared($3)){ yyerror("Can t affect value to constant"); exit(-1);}
															if(!isVariableDeclared($3)){ yyerror("Can t affect value to undeclared variable"); exit(-1);}
															else{
																strcpy(out, "scanf(\"");
																switch(getType($3)){
																	case 0 :{strcat(out, "%d\",&"); strcat(out, $3); strcat(out, ");\n"); break;}
																	case 1 :{strcat(out, "%f\",&"); strcat(out, $3); strcat(out, ");\n"); break;}
																	case 2 :{strcat(out, "%s\","); strcat(out, $3); strcat(out, ");\n"); break;}
																	default :{exit(-1);}
																}
																$$ = out;
															}
														}
							;

scanType 					: VARIABLE_NAME {$$ = $1;}
							;

declaration					: VAR VARIABLE_NAME '(' VARIABLE_TYPE ')' ';'						{	char out[1024];
																								switch($4){
																									case 0 :{strcpy(out, "int "); strcat(out, $2); break;}
																									case 1 :{strcpy(out, "float "); strcat(out, $2); break;}
																									case 2 :{strcpy(out, "char ");
																											 char* var = strtok($2, ",");
																										     while(var != NULL){
																												strcat(out, "*"); strcat(out, var); strcat(out, ",");
																									        	var = strtok(NULL, ",");
																									         }
																											 out[strlen(out)-1] = ' ';
																									         break;}
																									default :{exit(-1);}
																								}
																								strcat(out, ";\n");
																								$$ = out;
																								insertNewDeclaredVariable($2, $4);
																							}
							| VAR VARIABLE_NAME '(' VARIABLE_TYPE ')' '=' types ';'				{	char *value = strdup($7), out[1024]="\0";
																								switch($4){
																									case 0 :{	strcpy(out, "int "); strcat(out, $2);
																												strcat(out, "="); !strcmp(value, "1")?strcat(out, "1"):strcat(out, "0"); break;
																											}
																									case 1 :{	strcpy(out, "float ");
																											 	strcat(out, $2); strcat(out, "="); strcat(out, value);
																												break;
																											}
																									case 2 :{	strcpy(out, "char *");
																												strcat(out, $2); strcat(out, "=strdup(\"");strcat(out, value); strcat(out, "\"),");
																												break;
																											}
																									default :{exit(-1);}
																								}
																								strcat(out, ";\n");
																								insertNewDeclaredVariable($2, $4);
																								$$ = out;

																							}
							;

assignment 					: VARIABLE_NAME '=' types ';' 		{ 	if(isFunctionDeclared($1)){ yyerror("Can t affect value to functions"); exit(-1);}
																	if(isConstantDeclared($1)){ yyerror("Can t affect value to constanst"); exit(-1);}
																	if(!isVariableDeclared($1)){ yyerror("Can t affect value to undeclared variable"); exit(-1);}
																	char *value =strdup($3);
																	$$ = $1;
																	switch(getType($1)){
																		case 0 :{strcat($$, "="); !strcmp(value, "1")?strcat($$, "1"):strcat($$, "0"); break;}
																		case 1 :{strcat($$, "="); strcat($$, value); break;}
																		case 2 :{strcat($$, "=strdup(\""); strcat($$, value); strcat($$, "\")"); break;}
																	}
																	strcat($$, ";\n");
																}
							;

condition 					: '(' logicalExpression ')' {$$ = $2;}
							;

logicalExpression 			: logicalExpression AND logicalTerm {strcpy($$, $1); strcat($$, "&&"); strcat($$, $3);}
							| logicalExpression OR logicalTerm  {strcpy($$, $1); strcat($$, "||"); strcat($$, $3);}
							| logicalTerm {$$ = $1;}
							;

logicalTerm 				: '(' logicalExpression ')' {strcpy($$, "("); strcat($$, $2); strcat($$, ")");}
							| NOT logicalTerm {strcpy($$, "!"); strcat($$, $2);}
							| logicalTypes {$$ = $1;}
							;

logicalTypes				: comparisionExpression {$$ = $1;}
							| BOOLEAN {char tmp[2]; gcvt($1, 1, tmp); $$ = tmp;}
							| VARIABLE_NAME	{$$ = $1;}
							;

comparisionExpression 		: arithmiticExpression EQUALITY arithmiticExpression {strcpy($$, $1); strcat($$, "=="); strcat($$, $3);}
							| arithmiticExpression DIFFERENT arithmiticExpression {strcpy($$, $1); strcat($$, "!="); strcat($$, $3);}
							| arithmiticExpression '<' arithmiticExpression {strcpy($$, $1); strcat($$, "<"); strcat($$, $3);}
							| arithmiticExpression '>' arithmiticExpression {strcpy($$, $1); strcat($$, ">"); strcat($$, $3);}
							| arithmiticExpression LOWER_EQUAL arithmiticExpression {strcpy($$, $1); strcat($$, "<="); strcat($$, $3);}
							| arithmiticExpression GREATER_EQUAL arithmiticExpression {strcpy($$, $1); strcat($$, ">="); strcat($$, $3);}
							;

arithmiticExpression		: arithmiticExpression '+' arithmiticTerm {strcpy($$, $1); strcat($$, "+"); strcat($$, $3);}
							| arithmiticExpression '-' arithmiticTerm {strcpy($$, $1); strcat($$, "-"); strcat($$, $3);}
							| arithmiticExpression '%' arithmiticTerm {strcpy($$, $1); strcat($$, "%"); strcat($$, $3);}
							| arithmiticTerm {$$ = $1;}

							;

arithmiticTerm				: arithmiticTerm '*' arithmiticFactor {strcpy($$, $1); strcat($$, "*"); strcat($$, $3);}
							| arithmiticTerm '/' arithmiticFactor {strcpy($$, $1); strcat($$, "/"); strcat($$, $3);}
							| arithmiticFactor {$$ = $1;}
							;


arithmiticFactor			: '(' arithmiticExpression ')' {strcpy($$, "("); strcat($$, $2); strcat($$, ")");}
							| '-' arithmiticFactor { strcpy($$, "-"); strcpy($$, $2);}
							| arithmiticTypes {$$ = $1;}
							;

arithmiticTypes				: NUMBER { char tmp[32]="\0"; sprintf(tmp,"%f",$1); $$ = tmp; }
							| VARIABLE_NAME {$$ = $1;}
							| calledFunction {$$ = $1;}
							;

calledFunction 				: VARIABLE_NAME '(' arguments ')' {if(!isFunctionDeclared($1)){ yyerror("function is not declared"); exit(-1);} char *tmp; tmp = $1; strcat(tmp, "("); strcat(tmp, $3); strcat(tmp, ")"); $$ = tmp;}
							;

arguments 					: arguments ',' types {char *tmp; tmp = $$; strcat(tmp, ", "); strcat(tmp, $3); $$ = tmp;}
							| types {$$=$1;}
							| {$$ = " ";}
							;

concatenation				: concatenation '.' STRING { strcat($$, $3);}
							| concatenation '.' VARIABLE_NAME { strcat($$, $3);}
							| STRING { $$ = $1;}
							| VARIABLE_NAME {$$ = $1;}
							;

types 						: concatenation {$$ = $1;}
							| arithmiticExpression {$$ = $1;}
							| logicalExpression {$$ = $1;}
							;
%%

void yyerror(const char *msg){
	printf("\nline %d : %s\n", lineNumber, msg);
}

int hash(char *name){
	int x = 0;
	while(*name != '\0')
		x = 23 * x + * (name++);
	return x % N;
}

variable* findVariable(char *name){
	variable *p;
	for(p = variables[hash(name)]; p != NULL ; p = p -> next){
		if(!strcmp(name, p->name))
			return p;
			}
	return NULL;
}

variable* findConstant(char *name){
	variable *p;
	for(p = constants[hash(name)]; p != NULL ; p = p -> next)
		if(!strcmp(name, p->name))
			return p;
	return NULL;
}

function* findFunction(char *name){
	function *p;
	for(p = functions[hash(name)]; p != NULL ; p = p -> next)
		if(!strcmp(name, p->name))
			return p;
	return NULL;
}

int isVariableDeclared(char *name){
	if(findVariable(name))
		return 1;
	return 0;
}

int isConstantDeclared(char *name){
	if(findConstant(name))
		return 1;
	return 0;
}

int isFunctionDeclared(char *name){
	if(findFunction(name))
		return 1;
	return 0;
}

variable* newDeclaredVariable(char *name, int type, variable *next){
	variable *r = (variable *)malloc(sizeof(variable));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("\nERROR : No enough space\n");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	switch(type){
		case 0: r->value.b = 0;break;
		case 1: r->value.n = 0;break;
		case 2: r->value.s = strdup('\0');break;
	}
	r->next = next;
	return r;
}

variable* newConstant(char *name, int type, variable *next){
	variable *r = (variable *)malloc(sizeof(variable));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	r->next = next;
	return r;
}

function* newFunction(char *name, int type, function *next){
	function *r = (function *)malloc(sizeof(function));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	r->next = next;
	return r;
}

void insertNewDeclaredVariable(char *name, int type){
	if(isFunctionDeclared(name)){
		yyerror("Name already used by a function");
		exit(-1);
	}
	else if(isConstantDeclared(name)){
		yyerror("Name already used by a constant");
		exit(-1);
		 }
		 else if(!isVariableDeclared(name))
		 				variables[hash(name)] = newDeclaredVariable(name, type, variables[hash(name)]);
			  else{
		 		yyerror("Variable already declared");
		 		exit(-1);
		 	  }
}

void insertNewConstant(char *name, int type){
	if(isFunctionDeclared(name)){
		yyerror("Name already used by a function");
		exit(-1);
	}
	else if(isVariableDeclared(name)){
		yyerror("Name already used by a variable");
		exit(-1);
		 }
		 else if(!isConstantDeclared(name)){;
			constants[hash(name)] = newConstant(name, type, constants[hash(name)]);}
			  else{
		 		yyerror("constants already declared");
		 		exit(-1);
		 	  }
}

void insertNewFunction(char *name, int type){
	if(isConstantDeclared(name)){
		yyerror("Name already used by a constant");
		exit(-1);
	}
	else if(isVariableDeclared(name)){
		yyerror("Name already used by a variable");
		exit(-1);
		 }
		 else if(!isFunctionDeclared(name))
				functions[hash(name)] = newFunction(name, type, functions[hash(name)]);
			  else{
		 		yyerror("function already declared");
		 		exit(-1);
		 	  }
}

int getType(char *name){
	if(isVariableDeclared(name))
		return findVariable(name)->type;
	else if(isConstantDeclared(name))
			return findConstant(name)->type;
		 else{
			yyerror("Variable or constant is not declared");
			exit(-1);
		 }
}

char* toCType(int type){
	if(type == 1) return "float";
	else if(type == 0) return "int";
		 else return "char*";
}

char* toCShortType(char *name){
	int type = getType(name);
	if(type == 1) return "%.2f";
	else if(type == 0) return "%d";
		 else return "%s";
}

char* toCPrint(char *string){
	char *p = string;
	char message[4096] ="\0";
	char parameters[1024] ="\0";
	char var[32][256];
	int i=0;
	int k=0;

	for(p;*p;p++){
		if(*p =='|' && *(p-1) != '$'){
			char *q = ++p;
			int j=0;
			for(q;*q != '|';q++,j++,p++)
				var[i][j] = *q;
			strcat(message, toCShortType(var[i]));
			i++;p++;
		}
		k=(strlen(message));
		if(*p =='$'){
			p++;
		}
		else
			message[k++]=*p;
	}
	for(int j =0; j < i; j++){
			strcat(parameters, ",");
			strcat(parameters, var[j]);
	}
	char *out = malloc(strlen(message) + strlen(parameters));

	strcpy(out, "\"");
	strcat(out, message);
	strcat(out, "\"");
	strcat(out, parameters);
	return out;
}

void listdeclation(char *s1, char *s2, char *del){
	strcat(s1, del);
	strcat(s1, s2);
}

FILE* createfile(){
	char filename[] = "code.c";
	FILE *file;
	file = fopen(filename, "w");
	if(file == NULL){
		yyerror("Can't create file code.c");
		exit(-1);
	}
	fprintf(file, "#include<stdio.h>\n#include<stdlib.h>\n#include<string.h>\n");
	return file;
}

int main(int argc,char ** argv){
	if(argc>1) yyin=fopen(argv[1],"r");
	lineNumber=1;
	if(!yyparse())
			printf("--- CODE CORRECT ---");
}

%option noyywrap
%{
#include <stdio.h>
int counter = 0;
%}
%%
"programa" {printf("<PROG ,%i>",counter);}
"var" {printf("<VAR ,%i>",counter);}
"inteiro" {printf("<INT ,%i>",counter);}
"booleano" {printf("<BOOL ,%i>",counter);}
"procedimento" {printf("<PROCED ,%i>",counter);}
"funcao" {printf("<FUNC ,%i>",counter);}

"inicio" {printf("<INI ,%i>",counter);}
"fim" {printf("<END ,%i>",counter);}
"se" {printf("<IF ,%i>",counter);}
"entao" {printf("<THEN ,%i>",counter);}
"senao" {printf("<ELSE ,%i>",counter);}
"enquanto" {printf("<WHILE ,%i>",counter);}
"leia" {printf("<READ ,%i>",counter);}
"escreva" {printf("<WRITE ,%i>",counter);}


"<>" {printf("<DIV ,%i>",counter);}
"=" {printf("<EQUAL ,%i>",counter);}
"<" {printf("<SMALLER ,%i>",counter);}
"<=" {printf("<SMALLEREQ ,%i>",counter);}
">" {printf("<BIGGER ,%i>",counter);}
">=" {printf("<BIGGEREQ ,%i>",counter);}
"+" {printf("<ADD ,%i>",counter);}
"-" {printf("<SUBTR ,%i>",counter);}
"*" {printf("<MULT ,%i>",counter);}
"div" {printf("<DIVIDE ,%i>",counter);}
"e" {printf("<AND ,%i>",counter);}
"ou" {printf("<OR ,%i>",counter);}
":=" {printf("<ATRIB ,%i>",counter);}
":" {printf("DOUBLEDOT ,%i>",counter);}
";" {printf("<DOTCOMMA ,%i>",counter);}


"verdadeiro" {printf("<TRUE ,%i>",counter);}
"falso" {printf("<FALSE ,%i>",counter);}
"nao" {printf("<NO ,%i>",counter);}

"}" {printf("<OPENBRACKET, %i>", counter);}
"{" {printf("<CLOSEBRACKET, %i>", counter);}
"." {printf("<DOT, %i>", counter);}
\n {printf("\n"); counter++; }
. {;}

(0|([1-9][0-9]*)) {printf("<NUM, %i>", counter);}
(_|[a-zA-Z])([a-zA-Z]|[0-9])* {printf("<ID, %i>", counter);}



%%
int main(int argc, char **argv)
	{
	if (argc > 1) {
	if (!(yyin = fopen(argv[1], "r"))) {
		perror(argv[1]);
		return(1);
		}
	}
	yylex();
	return 0;
}

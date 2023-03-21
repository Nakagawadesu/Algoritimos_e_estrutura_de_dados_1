%option noyywrap
%{
int chars = 0;

%}
%%
a[a-z]a {
printf("\na palavra A comeca e termina com a\n");
}

%%
int main()
{
yylex();

return 0;
}
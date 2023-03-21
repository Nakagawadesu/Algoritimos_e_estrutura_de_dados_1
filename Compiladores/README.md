Program Structure: 

In the input file, there are 3 sections: 

1. Definition Section: The definition section contains the declaration of variables, regular definitions, manifest constants. In the definition section, text is enclosed in “%{ %}” brackets. Anything written in this brackets is copied directly to the file lex.yy.c

Syntax: 

%{
   // Definitions
%}
2. Rules Section: The rules section contains a series of rules in the form: pattern action and pattern must be unintended and action begin on the same line in {} brackets. The rule section is enclosed in “%% %%”. 

Syntax:  

%%
pattern  action
%%
Examples: Table below shows some of the pattern matches.  

Pattern	It can match with
[0-9]	all the digits between 0 and 9
[0+9]	either 0, + or 9
[0, 9]	either 0, ‘, ‘ or 9
[0 9]	either 0, ‘ ‘ or 9
[-09]	either -, 0 or 9
[-0-9]	either – or all digit between 0 and 9
[0-9]+	one or more digit between 0 and 9
[^a]	all the other characters except a
[^A-Z]	all the other characters except the upper case letters
a{2, 4}	either aa, aaa or aaaa
a{2, }	two or more occurrences of a
a{4}	exactly 4 a’s i.e, aaaa
.	any character except newline
a*	0 or more occurrences of a
a+	1 or more occurrences of a
[a-z]	all lower case letters
[a-zA-Z]	any alphabetic letter
w(x | y)z	wxz or wyz
3. User Code Section: This section contains C statements and additional functions. We can also compile these functions separately and load with the lexical analyzer.

Basic Program Structure:  

%{
// Definitions
%}

%%
Rules
%%

User code section
How to run the program: 
To run the program, it should be first saved with the extension .l or .lex. Run the below commands on terminal in order to run the program file. 

Step 1: flex filename.l or flex filename.lex depending on the extension file is saved with 
Step 2: gcc lex.yy.c 
Step 3: ./a.out 
Step 4: Provide the input to program in case it is required

Note: Press Ctrl+D or use some rule to stop taking inputs from the user. Please see the output images of below programs to clear if in doubt to run the programs

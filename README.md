# Reverse-Polish-Notation
  Reverse Polish notation lexer, parser and very small compiler that generates jvm assembly code.
  The programs just calculates the mathematical expression (+, -, * , /) and prints out the answer.

# Project for learning and experimenting
  the purpose of this project is to create this simple compiler without any compiler generator tools.
  all the compoments are handwritten by me (simple lexer, top down parser and code generation)

# Lexer
  tokens:
  * integers 
  * math op [+, -, *, /]
  * keywords [start, end]
  * semicolon [to seperate the expressions]
  * EOF

# Parser
  Simple top down parser, implemented with recursive descent.

# Code generation
  code generated for jasmin assember that can run on the java virtual machine

# Makefile
  * make [Compiles the files needed for execution]
  * make clean [cleans files]
  
# How to run
  * ./run < filename > [only files without extension supported]

# Prerequisite
  * gcc compiler
  * java
  * jasmin [on linux you can just sudo apt install jasmin-sable]
  * make [needed for make file otherwise you can compile the files by your self]

# LL Grammar
  * s ::= start stmts end
  * stmts ::= stmt  ;  listStmts
  * listStmts ::=  stmts  | EPSILON
  * stmt ::= rev
  * rev ::= num rec_rev
  * rec_rev ::= rev op rec_rev | EPSILON

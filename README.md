# Reverse-Polish-Notation
Reverse Polish Notation handwriten lexer, parser and maybe little compiler generating jvm assembly

# Project for learning and experimenting
 ## created 7/15/2021 3am in the morning 

# Makefile
  * make [Compiles the files needed for execution]
  * make clean [cleans files]
  
# How to run
  * ./run < filename >

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

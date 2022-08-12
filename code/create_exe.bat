flex -olexical.c lexical.l
bison -d -osyntaxe.c syntaxe.y
gcc syntaxe.c lexical.c -o MH_langage.exe
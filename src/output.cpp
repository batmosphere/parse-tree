mukund@kothari:~/Desktop/parse-tree$ g++ ui/src/main.cpp -o dist/parsetree
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree 
Error: specify infix string and output options.
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b"
Error: specify infix string and output options.
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 12345
Infix String: a+b
Prefix String: +ab
New Infix String: a+b
Tree Height: 2
Truth Value: 0
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 1
Infix String: a+b
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 2
Prefix String: +ab
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 3
New Infix String: a+b
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 4
Tree Height: 2
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 5
Truth Value: 0
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "a+b" 5243
Prefix String: +ab
New Infix String: a+b
Tree Height: 2
Truth Value: 0
mukund@kothari:~/Desktop/parse-tree$ dist/parsetree "~(((~(t+t))*f)+(t+f)+t)" 12345
Infix String: ~(((~(t+t))*f)+(t+f)+t)
Prefix String: ~+*~+ttf++tft
New Infix String: t+t~*f+t+f+t~
Tree Height: 6
Truth Value: 0
mukund@kothari:~/Desktop/parse-tree$

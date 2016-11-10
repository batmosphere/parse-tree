mukund@kothari:~/Desktop/Lic assignment complete/parse-tree/src$ g++ main.cpp
mukund@kothari:~/Desktop/Lic assignment complete/parse-tree/src$ ./a.out "(~p)>q" 12345678
Infix String: (~p)>q
Prefix String: >~pq
New Infix String: p~>q
normal Tree Height: 3
Truth Value: 0
CNF of logic formula: p+q
CNF tree height: 2
Validity of propositional logic formula:  Not Valid 

mukund@kothari:~/Desktop/Lic assignment complete/parse-tree/src$ ./a.out "(~((~p)+q))>(~(p>q))" 12345678
Infix String: (~((~p)+q))>(~(p>q))
Prefix String: >~+~pq~>pq
New Infix String: p~+q~>p>q~
normal Tree Height: 5
Truth Value: 1
CNF of logic formula: p~+q+p*p~+q+q~
CNF tree height: 5
Validity of propositional logic formula:  Valid 

mukund@kothari:~/Desktop/Lic assignment complete/parse-tree/src$ ./a.out "(p+(~p))>(q*(~q))" 12345678
Infix String: (p+(~p))>(q*(~q))
Prefix String: >+p~p*q~q
New Infix String: p+p~>q*q~
normal Tree Height: 4
Truth Value: 0
CNF of logic formula: p~+q*p~+q~*p+p~+q~
CNF tree height: 5
Validity of propositional logic formula:  Not Valid 

mukund@kothari:~/Desktop/Lic assignment complete/parse-tree/src$ 

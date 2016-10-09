#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;

class Parser {
private:
	Node *root;
	char *infix;
	char *prefix;
	char stack[1000];
	//char *stack;
	int tp;
	void push(char elem)
	{	/* Function for PUSH operation */
		stack[++tp] = elem;
	}
	char pop()
	{	/* Function for POP operation */
		return (stack[tp--]);
	}
	int pr(char elem)
	{	/* Function for precedence */
		switch (elem)
		{
			case '#': return 0;
			case ')': return 1;
			case '~': return 2;
			case '*': return 3;
			case '+': return 4;
			case '>': return 5;
		}
	}

public:
	bool infixToPrefix(char *infix, char prefix[1000]) {
		Helper helper;
		tp = -1;
		char ch;
		char elem;
		int k = 0;
		push('#');
		helper.reverse(infix);
		//stack[0]='#';
		int length = strlen(infix);
		//cout<<length<<endl;
		for (int i = 0; i < length; i++) {
			ch = infix[i];
			if ( ch == ')')
				push(ch);
			else if (isalnum(ch))
				prefix[k++] = ch;
			else if ( ch == '(')
			{
				while ( stack[tp] != ')')
					prefix[k++] = pop();
				elem = pop(); /* Remove ) */
			}
			else
			{	/* Operator */
				while ( pr(stack[tp]) >= pr(ch) )
					prefix[k++] = pop(); push(ch);
			}
		}
		while ( stack[tp] != '#') {
			/* Pop from stack till empty */
			prefix[k++] = pop();
			//cout<< pop();
		}
		prefix[k] = '\0'; /* Make prfx as valid string */
		//cout<<"\nOVER\n";
		helper.reverse(prefix);
		helper.reverse(infix);
		return true;
	}
};
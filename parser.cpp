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
	int prefixlength;
	int currentindex;
	int maxheight;
	char stack[10000];
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

	bool isOperator(char ch)
	{
		return ch == '+' || ch == '>' || ch == '*' || ch == '~';
	}

	bool insertNode(Node *node) {
		char ch = prefix[currentindex];
		//cout<<"Current: "<< currentindex<<" "<<ch<< endl;
		//cout<<"\tParent: "<<node->getIndex()<<" "<<node->getData()<<endl;
		if(isOperator(ch)){
			if(node->getLeft()==NULL){
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex-1);
				node->setLeft(newNode);
				//cout<<"\t\tLeft: "<<newNode->getData()<<endl;
				insertNode(newNode);
				insertNode(node);
			}
			else if(node->getRight()==NULL && node->getData()!='~'){
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex-1);
				node->setRight(newNode);
				//cout<<"\t\tRight: "<<newNode->getData()<<endl;
				insertNode(newNode);
			}
			else{
				return true;
			}
		}
		if(isalpha(ch)){
			if(node->getLeft()==NULL){
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex-1);
				node->setLeft(newNode);
				//cout<<"\t\tLeft: "<<newNode->getData()<<endl;
				insertNode(node);
			}
			else if(node->getRight()==NULL && node->getData()!='~'){
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex-1);
				node->setRight(newNode);
				//cout<<"\t\tRight: "<<newNode->getData()<<endl;
			}
			return true;
		}
		return true;
	}

	int heightCalculator(Node *node,int height){
		height++;
		int leftheight=1;
		int rightheight=1;
		if(node->getLeft()!=NULL){
			leftheight = heightCalculator(node->getLeft(),height);
		}
		if(node->getRight()!=NULL){
			rightheight = heightCalculator(node->getRight(),height);
		}
		int currentmaxheight = leftheight>rightheight?leftheight:rightheight;
		maxheight=maxheight>currentmaxheight?maxheight:currentmaxheight;
		return currentmaxheight+1;
	}
public:
	bool infixToPrefix(char *infix, char *prefix) {
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
		}
		prefix[k] = '\0'; /* Make prfx as valid string */
		helper.reverse(prefix);
		helper.reverse(infix);
		return true;
	}

	bool prefixToTree(char *prefix, Node *root) {
		this->prefixlength = strlen(prefix);
		this->prefix = prefix;
		currentindex=1;
		root->setData(prefix[0]);
		root->setIndex(0);
		insertNode(root);
	}

	bool treeToInfix(Node *node){
		if(node!=NULL){
			treeToInfix(node->getLeft());
			cout<<node->getData();
			treeToInfix(node->getRight());
		}
		return true;
	}

	int getTreeHeight(Node *node){
		maxheight = 1;
		heightCalculator(node,0);
		return maxheight;
	}
};
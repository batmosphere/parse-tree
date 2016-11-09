#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Parser {
private:
	Node *root;
	char *infix;
	char *prefix;
	char newinfix[20];
	int prefixlength;
	int currentindex;
	int maxheight;
	char stack[10000];
	char sprefix[20];
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
		case '#':
			return 0;
		case ')':
			return 1;
		case '~':
			return 2;
		case '*':
			return 3;
		case '+':
			return 4;
		case '>':
			return 5;
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
		if (isOperator(ch)) {
			if (node->getLeft() == NULL) {
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex - 1);
				node->setLeft(newNode);
				//cout<<"\t\tLeft: "<<newNode->getData()<<endl;
				insertNode(newNode);
				insertNode(node);
			}
			else if (node->getRight() == NULL && node->getData() != '~') {
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex - 1);
				node->setRight(newNode);
				//cout<<"\t\tRight: "<<newNode->getData()<<endl;
				insertNode(newNode);
			}
			else {
				return true;
			}
		}
		if (isalpha(ch)) {
			if (node->getLeft() == NULL) {
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex - 1);
				node->setLeft(newNode);
				//cout<<"\t\tLeft: "<<newNode->getData()<<endl;
				insertNode(node);
			}
			else if (node->getRight() == NULL && node->getData() != '~') {
				currentindex++;
				Node *newNode = new Node(ch);
				newNode->setIndex(currentindex - 1);
				node->setRight(newNode);
				//cout<<"\t\tRight: "<<newNode->getData()<<endl;
			}
			return true;
		}
		return true;
	}

	int heightCalculator(Node *node, int height) {
		height++;
		int leftheight = 1;
		int rightheight = 1;
		if (node->getLeft() != NULL) {
			leftheight = heightCalculator(node->getLeft(), height);
		}
		if (node->getRight() != NULL) {
			rightheight = heightCalculator(node->getRight(), height);
		}
		int currentmaxheight = leftheight > rightheight ? leftheight : rightheight;
		maxheight = maxheight > currentmaxheight ? maxheight : currentmaxheight;
		return currentmaxheight + 1;
	}

	bool infixCalculator(Node *node, char *infix) {
		if (node != NULL) {
			infixCalculator(node->getLeft(), infix);
			infix[currentindex++] = node->getData();
			infixCalculator(node->getRight(), infix);
		}
		return true;
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
		currentindex = 1;
		root->setData(prefix[0]);
		root->setIndex(0);
		insertNode(root);
	}

	bool treeToInfix(Node *node, char *infix) {
		currentindex = 0;
		//this->newinfix = infix;
		infixCalculator(node, infix);
		infix[currentindex] = '\0';
		return true;
	}

	int getTreeHeight(Node *node) {
		maxheight = 1;
		heightCalculator(node, 0);
		return maxheight;
	}

	bool evaluateTree(Node *node) {
		bool var1 = false;
		bool var2 = false;
		char ch = node->getData();

		if (isOperator(ch) && ch == '~') {
			var1 = evaluateTree(node->getLeft());
		}
		else if (isOperator(ch)) {
			var1 = evaluateTree(node->getLeft());
			var2 = evaluateTree(node->getRight());
		}
		else if (isalpha(ch)) {
			if (ch == 't' || ch == 'T') {
				return true;
			}
			return false;
		}

		bool result;

		switch (ch) {
		case '+':
			result = var1 || var2;
			break;
		case '*':
			result = var1 && var2;
			break;
		case '~':
			result = !var1;
			break;
		case '>':
			result = !var1 || var2;
			break;
		}
		return result;
	}

	bool impl_free(Node *node){
		// cout<<"Hi Again"<<endl;
		//cout<<node->getData()<<endl;
		if(node==NULL){
			return false;
		}
		if(node->getData()=='>'){
			//cout<<"Data Matched"<<endl;	
			char ch= '+';
			node->setData(ch);
			//cout<<"Data Changed: "<<node->getData()<<endl;	
			char c1='~';
			Node *negation = new Node(c1);
			negation->setLeft(node->getLeft());
			node->setLeft(negation);

		}
		if (node != NULL) {
			impl_free(node->getLeft());
			impl_free(node->getRight());
		}
		return true;
	}
	bool doublenegation(Node *node){
		if(node==NULL ){
			//cout<<"abc\n";
			return false;
			
		}

		if(node->getLeft()->getData() =='~' && node->getLeft() !=NULL && node->getLeft()->getLeft()->getData() == '~' && node->getLeft()->getLeft() != NULL){
			
			node->setLeft(node->getLeft()->getLeft()->getLeft());
			
		}
		if (node->getRight()->getData()=='~' && node->getRight() != NULL && node->getRight()->getLeft()->getData() == '~' && node->getRight()->getLeft() != NULL )
		{	
			node->setRight(node->getRight()->getLeft()->getLeft());
			//cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
			//cout<<node->getRight()->getData()<<endl;
			
		}
		
		if(node->getLeft()->getData() =='~' && node->getLeft() !=NULL &&  node->getLeft()->getLeft()->getData() == '+' && node->getLeft()->getLeft() != NULL){
			node->getLeft()->setData('*');
			Node *negation1 = new Node('~');
			Node *negation2 = new Node('~');
			negation1->setLeft(node->getLeft()->getLeft()->getLeft());
			negation2->setLeft(node->getLeft()->getLeft()->getRight());
			node->getLeft()->setLeft(negation1);
			node->getLeft()->setRight(negation2);
			
		}
		if(node->getRight()->getData() =='~' && node->getRight() != NULL &&  node->getRight()->getLeft()->getData() == '+' && node->getRight()->getLeft() != NULL){
			node->getRight()->setData('*');
			Node *negation1 = new Node('~');
			Node *negation2 = new Node('~');
			negation1->setLeft(node->getRight()->getLeft()->getLeft());
			negation2->setLeft(node->getRight()->getLeft()->getRight());
			node->getRight()->setLeft(negation1);
			node->getRight()->setRight(negation2);
			
		}
		if(node->getLeft()->getData() =='~' && node->getLeft() !=NULL &&  node->getLeft()->getLeft()->getData() == '*' && node->getLeft()->getLeft() != NULL){
			node->getRight()->setData('+');
			Node *negation1 = new Node('~');
			Node *negation2 = new Node('~');
			negation1->setLeft(node->getRight()->getLeft()->getLeft());	
			negation2->setLeft(node->getRight()->getLeft()->getRight());
			node->getRight()->setLeft(negation1);
			node->getRight()->setRight(negation2);
			
		}
		if(node->getRight()->getData() =='~' && node->getRight() != NULL &&  node->getRight()->getLeft()->getData() == '*' && node->getRight()->getLeft() != NULL){
			node->getRight()->setData('+');
			Node *negation1 = new Node('~');
			Node *negation2 = new Node('~');
			negation1->setLeft(node->getRight()->getLeft()->getLeft());	
			negation2->setLeft(node->getRight()->getLeft()->getRight());
			node->getRight()->setLeft(negation1);
			node->getRight()->setRight(negation2);
			
		}
		if (node->getLeft()->getLeft() != NULL && node->getLeft()->getLeft()->getLeft() != NULL ) {
			doublenegation(node->getLeft()); }
		if (node->getRight()->getLeft()!=NULL && node->getRight()->getLeft()->getLeft() != NULL){
					doublenegation(node->getRight());
					//cout<<"hello twice\n";
		}
		
		return true;
	}	
	
	int validity(char *newinfix){
		
		for(int i=0; i<20;i++){
			if( ((int)newinfix[i] >= 65 && (int)newinfix[i] <= 90 ) || ((int)newinfix[i] >= 97 && (int)newinfix[i] <= 122 ))
			{	
				if(rand() % 2){
					//cout<<rand()%2;
					newinfix[i]='f';
				}
				else
					newinfix[i] = 't';
			}

		}
		infixToPrefix(newinfix,sprefix);
		Node *root1 = new Node();
		prefixToTree(sprefix,root1);
		
		int l = evaluateTree(root1);
		return l;
	}

	bool distr(Node *node){
	if(node== NULL)
	return false;
	
		if(node->getData() == '+' && node->getLeft()->getData()=='*'){
			node->setData('*');
			Node *add = new Node('+');
			node->getLeft()->setData('+');
			add->setLeft(node->getLeft()->getRight());
			node->getLeft()->setRight(node->getRight());
			add->setRight(node->getRight());
			node->setRight(add);
			
		}
		if(node->getData() == '+' && node->getRight()->getData()=='*'){
			node->setData('*');
			Node *add = new Node('+');
			node->getRight()->setData('+');
			add->setRight(node->getRight()->getLeft());
			node->getRight()->setLeft(node->getLeft());
			add->setLeft(node->getLeft());
			node->setLeft(add);
		}
		if (node != NULL) {
			distr(node->getLeft());
			distr(node->getRight());
		}
		return true;
		
}	
};

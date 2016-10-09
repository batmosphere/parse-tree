#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "node.cpp"
#include "helper.cpp"
#include "parser.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	char c = 'x';
	char *infix;
	char prefix[1000];
	Node *root = new Node();
	infix = argv[1];
	Parser parser;
	cout<<endl;
	parser.infixToPrefix(infix,prefix);
	cout<<"Prefix Length: "<<strlen(prefix)<<endl;
	cout<<infix<<endl;
	cout<<prefix<<endl;
	parser.prefixToTree(prefix,root);
	parser.treeToInfix(root);
	int maxheight = parser.getTreeHeight(root);
	
	cout<<endl;
	cout<<"Height: "<<maxheight<<endl;
	bool rval = parser.evaluateTree(root);
	cout<<"Truth Value: "<<rval<<endl;
	cout<<endl;
	return 0;
}

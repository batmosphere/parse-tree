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
	char prefix[10000];
	char newinfix[10000];
	Node *root = new Node();
	infix = argv[1];
	Parser parser;
	parser.infixToPrefix(infix,prefix);
	parser.prefixToTree(prefix,root);
	parser.treeToInfix(root,newinfix);
	int maxheight = parser.getTreeHeight(root);
	bool truthvalue = parser.evaluateTree(root);
	cout<<"Prefix Length: "<<strlen(prefix)<<endl;
	cout<<"Infix String: "<<infix<<endl;
	cout<<"Prefix String: "<<prefix<<endl;
	cout<<"New Infix String: "<<newinfix<<endl;
	cout<<"Tree Height: "<<maxheight<<endl;
	cout<<"Truth Value: "<<truthvalue<<endl;
	return 0;
}

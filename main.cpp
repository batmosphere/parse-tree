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
	parser.infixToPrefix(infix,prefix);
	cout<<endl;
	cout<<infix<<endl;
	cout<<prefix<<endl;
	cout<<endl;
	parser.prefixToTree(prefix,root);
	return 0;
}

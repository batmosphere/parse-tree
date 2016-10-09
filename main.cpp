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
	infix = argv[1];
	cout<<infix<<endl;
	// Helper helper;
	// helper.reverse(infix);
	Parser parser;
	parser.infixToPrefix(infix,prefix);
	// prefix[0]='h';
	// prefix[1]='h';
	// prefix[2]='h';
	//cout<<infix<<endl;
	cout<<prefix<<endl;
	//Node *root = new Node(c);
	return 0;
}

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
	char *options;
	char prefix[10000];
	char newinfix[10000];
	char cnf1[10000];
	if (argc != 3) {
		cout << "Error: specify infix string and output options." << endl;
		return 1;
	}
	Node *root = new Node();
	infix = argv[1];
	Parser parser;
	parser.infixToPrefix(infix, prefix);
	parser.prefixToTree(prefix, root);
	parser.treeToInfix(root, newinfix);
	int maxheight = parser.getTreeHeight(root);
	bool truthvalue = parser.evaluateTree(root);
	parser.impl_free(root);
	parser.doublenegation(root);
	parser.treeToInfix(root, cnf1);
	int cnfheight = parser.getTreeHeight (root);
	Helper helper;
	options = argv[2];
	if (strlen(options) == 0) {
		cout << "Error: No output parameters." << endl;
		return 2;
	}
	if (helper.haschar(options, '1')) cout << "Infix String: " << infix << endl;
	if (helper.haschar(options, '2')) cout << "Prefix String: " << prefix << endl;
	if (helper.haschar(options, '3')) cout << "New Infix String: " << newinfix << endl;
	if (helper.haschar(options, '4')) cout << "normal Tree Height: " << maxheight << endl;
	if (helper.haschar(options, '5')) cout << "Truth Value: " << truthvalue << endl;
	if (helper.haschar(options, '6')) cout << "impl free: " << cnf1 << endl;
	if (helper.haschar(options, '7')) cout << "double negation: " << cnf1 << endl;
	if (helper.haschar(options, '8')) cout << "cnf tree height: " << cnfheight << endl;
	return 0;
}
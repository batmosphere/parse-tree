#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "node.cpp"
#include "helper.cpp"
#include "parser.cpp"
using namespace std;

int flag = 1,k=0;
int main(int argc, char *argv[]) {
	char c = 'x';
	char *infix;
	char *options;
	char prefix[20];
	char newinfix[20];
	char cnf[20];
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
	// parser.treeToInfix(root, cnf2);
	parser.doublenegation(root);
	// cout<<"hello again\n";
	parser.distr(root);
	parser.treeToInfix(root, cnf);
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
	// if (helper.haschar(options, '6')) cout << "impl free: " << cnf2 << endl;
	if (helper.haschar(options, '6')) cout << "CNF of logic formula: " << cnf << endl;
	if (helper.haschar(options, '7')) cout << "CNF tree height: " << cnfheight << endl;
	if (helper.haschar(options, '8')) {	
	for(k=0;k<50;k++)
	{
		flag = parser.validity( newinfix );
		//cout<<"ASDFSDFSDFSDF\n";
		if(flag==0)
			break;
	}

	cout << "Validity of propositional logic formula: ";
	if(!flag)
		cout<<" Valid "<<endl;
	else
		cout<<" Not Valid "<<endl;
	}
	return 0;
}

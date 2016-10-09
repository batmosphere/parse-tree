class Node {
private:
	char data;
	Node *left, *right, *parent;
public:
	Node(char data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

	char getData() {
		return this->data;
	}
	void setData(char data) {
		this->data = data;
	}
	Node *getLeft() {
		return this->left;
	}
	void setLeft(Node *left) {
		this->left = left;
	}
	Node *getRight() {
		return this->right;
	}
	void setRight(Node *right) {
		this->right = right;
	}
	Node *getParent() {
		return this->parent;
	}
	void setParent(Node *parent) {
		this->parent = parent;
	}
};
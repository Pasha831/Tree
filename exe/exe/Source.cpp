#include <iostream>
using namespace std;

struct Link
{
	int data;

	Link* left;
	Link* right;
};
class Tree
{
private:
	Link* root;
	void addin(Link* tmp, int d);
public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		delete root;
	}
	void add(int d);
	void show();
};

void Tree::addin(Link* tmp, int d)
{
	if (d > tmp->data) // IF d > root->data 
	{
		if (tmp->right == NULL)
		{
			tmp->right = new Link;
			tmp->right->data = d;
			tmp->right->right = NULL;
			tmp->right->left = NULL;
		}
		else
		{
			addin(tmp->right, d);
		}
	}
	else // IF d <= root->data
	{
		if (tmp->left == NULL)
		{
			tmp->left = new Link;
			tmp->left->data = d;
			tmp->left->left = NULL;
			tmp->left->right = NULL;
		}
		else
		{
			addin(tmp->left, d);
		}
	}
}
void Tree::add(int d)
{
	if (root == NULL)
	{
		root = new Link;
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		addin(root, d);
	}
}
void Tree::show() // Left - Root - Right
{
	
}
int main()
{
	Tree tree;

	tree.add(4);
	tree.add(21);
	tree.add(313);
	tree.add(19);

	tree.add(2);
	tree.add(0);
	tree.add(3);

	tree.show();

	system("pause");
}

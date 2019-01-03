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
	void addin(Link* tmp, int d);
	void showTree();
	void print(Link* root);
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
void Tree::showTree()
{
	print(root);
}
void Tree::print(Link* root)
{
	if (root == NULL)   // Базовый случай
	{
		return;
	}
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}
int main()
{
	Tree tree;
	tree.add(12);
	tree.add(1);
	tree.add(20);
	tree.add(0);
	tree.add(5);
	tree.add(22);
	tree.add(15);

	tree.showTree();

	system("pause");
}

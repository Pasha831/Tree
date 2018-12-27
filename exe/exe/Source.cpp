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
};
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
		Link* tmp = root;
		bool t = false;
		while (!t)
		{
			if (d > tmp->data)
			{
				tmp->right = new Link;
				tmp->right->data = d;
			}
			if (d <= tmp->data)
			{
				tmp->left = new Link;
				tmp->left->data = d;
			}
			else
			{

			}
			t = true;
		}
	}
}
int main()
{
	Tree tree;
	tree.add(0);
	tree.add(6);
	system("pause");
}
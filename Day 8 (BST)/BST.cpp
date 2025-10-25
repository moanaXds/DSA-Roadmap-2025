#include<iostream>

using namespace std;


class Node {
public:
	Node* left;
	Node* right;
	int data;

	Node(int val)
	{
		left = right = NULL;
		data = val;
	}
};


//--------------------------

//        TRAVERSAL

//--------------------------


void preorder(Node* root)
{
	if (root == NULL)return;

	cout << root->data << " ";

	preorder(root->left);

	preorder(root->right);

}

void inorder(Node* root)
{
	if (root == NULL)return;

	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);

}

void postorder(Node* root)
{
	if (root == NULL)return;

	postorder(root->left);

	postorder(root->right);

	cout << root->data << " ";
}

//--------------------------

//        INSRTION

//--------------------------

Node* insert_data_in_tree(Node* root, int value)
{
	if (root == NULL)
	{
		Node* newnode = new Node(value);
		return newnode;
	}

	if (value < root->data)
	{
		root->left = insert_data_in_tree(root->left, value);

	}

	if (value > root->data)
	{
		root->right = insert_data_in_tree(root->right, value);
	}

	return root;
}

//--------------------------

//        DELETION

//--------------------------

Node* delete_data_in_tree(Node* root, int value)
{
	if (root == NULL)return NULL;


	if (value < root->data)
	{
		root->left = delete_data_in_tree(root->left, value);
	}

	else if (value > root->data)
	{
		root->right = delete_data_in_tree(root->right, value);
	}

	//     -----   LOGIC FOR ALL 3 CASES   ----
	else
	{

		//  -----   ROOT HAS 0 CHILD ( return NULL to previous level)  ----
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}


		//  -----   ROOT HAS 1 CHILD ( delete current root , return it non NULL child (temp) to root's parent)  ----

		if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}




		//  -----   ROOT HAS 2 CHILD ( move immediate right(using temp) and innermost left  : replace ----
		else
		{
			Node* temp = root->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}

			// delete root
			root->data = temp->data;

			//delete innermost 
			root->right = delete_data_in_tree(root->right, temp->data);
		}

	}
	return root;
}



//--------------------------

//        BUILD TREE

//--------------------------

Node* BUILD_BST(int arr[], int size)
{
	Node* root = NULL;

	for (int i = 0; i < size; i++)
	{
		root = insert_data_in_tree(root, arr[i]);
	}

	return root;
}

bool SEARCH_IN_BST(Node* root, int val)
{
	if (root == NULL)return false;

	if (root->data == val)return true;


	if (val < root->data)
	{
		return SEARCH_IN_BST(root->left, val);
	}

	if (val > root->data)
	{
		return SEARCH_IN_BST(root->right, val);
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Node* root = BUILD_BST(arr, size);

	cout << "-------   INORDER ----------\n";
	inorder(root);
	cout << endl;

	cout << "-------   PREORDER ----------\n";
	preorder(root);
	cout << endl;

	cout << "-------   POSTORDER ----------\n";
	postorder(root);
	cout << endl;

	cout << "-------   SEARCH ----------\n";
	bool result = SEARCH_IN_BST(root, 0);
	cout << "Search : " << result << endl;

	cout << "-------   DELETE ----------\n";
	root = delete_data_in_tree(root, 1);
	inorder(root);
	cout << endl;


	return 0;
}
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

typedef struct Node
{
   char name[1024];
   Node *left;
   Node *right;
   int count;

   Node(char s[])
   {
	  assert( s != NULL);
      strcpy(name , s);
	  count  = 1;
	  left = right = NULL;
   }
}Node;

void insert(Node *&root , char s[])
{
	if (root == NULL)
	{
		root = new Node(s);
	}
	else
	{
		if (strcmp((root)->name , s) == 0)
			(root)->count++;
		else
		{
			if (strcmp((root)->name , s) > 0)
			{
				insert((root)->left,s);
			}
			else
			{
				insert((root)->right ,s);
			}
		}
	}
}

void travel(Node *root)
{
	if (root != NULL)
	{
		travel(root->left);
		std ::cout << root->name <<" "<<root->count<< std::endl;
	    travel(root->right);
	}
}

void deleteNode(Node *&root)
{
   if (root->left == NULL && root->right == NULL)
   {
	   delete root;
	   root = NULL;
   }
   if (root->left != NULL && root->right == NULL)
   {
	   Node *q = root->left;
	   strcpy(root->name,q->name);
	   root->left = q->left;
	   delete q;
	   q = NULL;
   }
   if (root->left == NULL && root->right != NULL)
   {
       Node * q = root->right;
	   strcpy(root->name,q->name);
	   root->right = q->right;
	   delete q;
	   q = NULL;
   }
   if (root->left != NULL && root->right != NULL)
   {
       Node *q = root;
	   Node *s = root->left;

	   while (s->right != NULL)
	   {
           q = s;
		   s = s->right;
	   }

	   strcpy(root->name,s->name);

	   if (q != root)
	   {
		   q->right = s->left;
	   }
	   else
	   {
		   q->left = s->left;
	   }

	   delete s;
	   s = NULL;
   }

   return ;
}

void eraseNode(Node *root,char s[])
{
   if ( root != nullptr)
  {
    if (strcmp(root->name,s) == 0)
	{	
		deleteNode(root);
		return;
	}
	else if (strcmp(root->name,s) > 0 )
	{
	   eraseNode(root->left , s);
	}
	else
	{
		eraseNode(root->right , s);
	}
  }
   else
	   std::cout << " No such Nodes " <<std::endl;
}

void destory(Node * &root)
{
	if (root != NULL)
	{
		destory(root->left);
		destory(root->right);
	    delete root;
	    root = NULL;
	}
}

int main()
{/*
	char str[1024] = {0x00};
	Node * root = NULL;
	while (std::cin >> str)
	{
	   insert(root,str);
	}

	travel(root);

	eraseNode(root,"2");

	travel(root);


	destory(root);


	travel(root);*/
	double d = 5/2;
	cout << d;
    return 0;
}
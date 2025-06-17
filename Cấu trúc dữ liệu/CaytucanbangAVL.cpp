#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
 
using ll = long long;
using namespace std;
 
const ll mod = 1000000007;


struct Node{
	int data;
	Node *left;
	Node *right;
	int height;
};

int getheight(Node* node){
	if (node == NULL) return 0;
	return 1 + max(getheight(node->left), getheight(node->right));
}

Node* rotateLeft(Node* root){
	Node* y = root->right;
	
	root->right = y->left;
	y->left = root; 
	
	root->height = 1 + max(getheight(root->left), getheight(root->right));
	y->height = 1 + max(getheight(y->left), getheight(y->right));	
	
	return y;
}

Node* rotateRight(Node* root){
	Node* x = root->left;
	
	root->left = x->right;
	x->right = root; 
	
	root->height = 1 + max(getheight(root->left), getheight(root->right));
	x->height = 1 + max(getheight(x->left), getheight(x->right));	
	
	return x;
}

Node* balance(Node* root, int x){
	root->height = 1 + max(getheight(root->left), getheight(root->right));
	
	int valbalance = getheight(root->left) - getheight(root->right);
	
	if (valbalance > 1 && x < root->left->data){
		return rotateRight(root); 
	}
	
	if (valbalance < -1 && x > root->right->data){
		return rotateLeft(root);
	}
	
	if (valbalance > 1 && x > root->left->data){
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	
	if (valbalance < -1 && x < root->right->data){
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}
	
	return root;
}

Node* createNode(int x){
	Node* p = new Node();
	p->data = x;
	p->left = NULL; p->right = NULL;
	p->height = 1;
	return p;
}

Node* insertNode(Node* root, int x){
	if (root == NULL){
		Node* n = createNode(x);
		root = n;
		return root;
	}
	
	if (x > root->data){
		root->right = insertNode(root->right, x);
	}else if (x < root->data){
		root->left = insertNode(root->left, x);
	}else{
		return root;
	}
	
	root = balance(root, x);
	return root;
}

void createTree(Node* &root, int a[], int n){
	for(int i = 0; i < n; i++){
		root = insertNode(root, a[i]);
	}
}

Node* left_most(Node* t){
	if(t == NULL)
		return t;
	else{
		while(t->left != NULL){
			t = t->left;
		}
	}
	return t;
}

Node* remove(Node* root, int x){
	if (root == NULL) return root;
	
	if (root->data == x){
		if (root->left == NULL){
			root = root->right;
			return root;
		}else if (root->right == NULL){
			root = root->left;
			return root;
		}
		
		Node* tmp = left_most(root->right);
		root->data = tmp->data;
		
		root->right = remove(root->right, tmp->data);
	}else if (x < root->data){
		root->left = remove(root->left, x);
	}else if (x > root->data){
		root->right = remove(root->right, x);
	}
	return root;
}

void NLR(Node* root){
	if (root != NULL){
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(Node* root){
	if (root != NULL){
		NLR(root->left);
		cout << root->data << " ";
		NLR(root->right);
	}
}

void LRN(Node* root){
	if (root != NULL){
		NLR(root->left);
		NLR(root->right);
		cout << root->data << " ";
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int a[] = {3, 2, 1};
	int n = 3;
	
	Node* node = NULL;
	createTree(node, a, n);
	
	NLR(node);
	
	return 0;
}


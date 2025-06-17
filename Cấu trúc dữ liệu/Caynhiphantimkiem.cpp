#include <bits/stdc++.h>
 
#define fo(i, n) for (int i = 0; i < (n); i++)
 
using ll = long long;
using namespace std;
 
const ll mod = 1000000007;


struct Node{
	int data;
	Node *left;
	Node *right;
};


Node* createNode(int x){
	Node* p = new Node();
	p->data = x;
	p->left = NULL; p->right = NULL;
	return p;
}

Node* findInsert(Node* root, int x){
	if (root == NULL){
		return NULL;
	}
	
	Node* p = root;
	Node* f = p;
	
	while(p != NULL){
		f = p;
		if (p->data > x){
			p = p->left;
		}else{
			p = p->right;
		}
	}
	return f;
}

void insertNode(Node* &root, int x){
	Node* n = createNode(x);
	if (root == NULL){
		root = n;
		return;
	}else{
		Node* f = findInsert(root, x);
		if (f != NULL){
			if (f->data > x){
				f->left = n;
			}else{
				f->right = n;
			}
		}
	}
}

void createTree(Node* &root, int a[], int n){
	for(int i = 0; i < n; i++){
		insertNode(root, a[i]);
	}
}

Node* searchNode(Node* root, int x){
	if (root == NULL) return NULL;
	
	Node* p = root;
	
	while(p != NULL){
		if (p->data == x) return p;
		else if (p->data > x) p = p->left;
		else p = p->right;
	}
	
	return NULL;
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
	
	int a[] = { 40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47 };
	int n = 11;
	
	Node* node = NULL;
	createTree(node, a, n);
	
	int t;
	cin >> t;
	
	Node* newTree = remove(node, t);
	NLR(newTree);
	
	return 0;
}


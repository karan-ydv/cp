#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

node* createBST(int arr[], int beg, int end)
{
	if (beg > end)  return NULL;
	int mid = (beg + end)/2;
	node *root = new node(arr[mid]);
	root->left = createBST(arr, beg, mid - 1);
	root->right = createBST(arr, mid + 1, end);
	return root;
}

void preOrder(node* node)
{
	if (node == NULL)	return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);
    node* root = createBST(a, 0, n - 1);
    preOrder(root);
}
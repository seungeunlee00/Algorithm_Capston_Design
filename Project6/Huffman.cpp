#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

struct nodetype {
	string symbol;
	int frequency;
	nodetype* left;
	nodetype* right;
	nodetype(string s, int f) : symbol(s), frequency(f) {
		left = NULL;
		right = NULL;
	}
};

struct compare {
	bool operator()(nodetype *n1, nodetype *n2) {
		return (n1->frequency > n2->frequency);
	}
};

void printTree(struct nodetype* root, string str) {
	if (!root) {
		return;
	}

	if (root->symbol != "@") {
		cout << root->symbol << " " << str << endl;
	}

	printTree(root->left, str + "0"); 
	printTree(root->right, str + "1");
}

void Huffman(string data[], int freq[], int size){
	priority_queue<nodetype*, vector<nodetype*>, compare> PQ;

	for (int i = 0; i < size; i++) {
		PQ.push(new nodetype(data[i], freq[i]));
	}

	struct nodetype* left, * right, * r;

	while (PQ.size()!=1) {
		left = PQ.top();
		PQ.pop();
		right = PQ.top();
		PQ.pop();

		r = new nodetype("@", left->frequency+right->frequency);
		r->left = left;
		r->right = right;

		PQ.push(r);
	}
	printTree(PQ.top(), " ");
}

int main() {
	string data1[] = { "r","A","B","C","D","E","F" };
	int freq1[] = { 27,15,12,9,5,10,11 };
	int size1 = 7;

	Huffman(data1, freq1, size1);

	cout << "\n";

	string data2[] = { "ROOT","ABC","ABCC","AB","A","B","BABA" };
	int freq2[] = { 27,12,7,19,35,40,15 };
	int size2 = 7;

	Huffman(data2, freq2, size2);
	return 0;
}

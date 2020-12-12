#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct node {
	int weight;
	char letter;
	node *left_child = NULL, *right_child = NULL;

	node(int w, char l) {
		weight = w;
		letter = l;
	}
};

struct compare {
	bool operator()(const node* a, const node* b) const {
		return a->weight < b->weight;
	}
};

node* huffman(string s) {
	map<char, int> a;
	for (char i : s)
		if (isalpha(i))
			a[tolower(i)]++;

	multiset<node*, compare> weights;
	for (auto i : a)
		weights.insert(new node(i.second, i.first));
	for (auto i : weights)
		cout << "'" << i->letter << "':\t" << i->weight << "\n";

	while (weights.size() > 1) {
		node* ins = new node(0, 0);

		auto it = weights.begin();
		ins->weight += (*it)->weight;
		ins->left_child = *it;

		it++;
		ins->weight += (*it)->weight;
		ins->right_child = *it;

		weights.erase(weights.begin());
		weights.erase(weights.begin());

		weights.insert(ins);
	}

	return *weights.begin();
}

void print_codes(node* root, vector<bool> v) {
	if (root->left_child != NULL) {
		v.push_back(0);
		print_codes(root->left_child, v);
		v.pop_back();
	}

	if (root->right_child != NULL) {
		v.push_back(1);
		print_codes(root->right_child, v);
		v.pop_back();
	}

	if (root->left_child == NULL && root->right_child == NULL) {
		cout << root->letter << ":\t";
		for (bool i: v)
			cout << 1*i;
		cout << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	string s;
	getline(cin, s);

	node* t = huffman(s);

	cout << "=-=-=-=-=-=-=\n";
	vector<bool> v;
	print_codes(t, v);

	return 0;
}

// Кирилл(4 балла) Докажите, что энтропия монетки принимает наибольшее значение для правильной монетки.Ступаков
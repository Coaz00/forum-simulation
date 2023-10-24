#ifndef TREE_H
#define TREE_H

#include "Post.h"

#include<stack>

class Tree {
public:
	Tree(Post* root);
	~Tree();

	Post* getRoot() const;

	Post* findPost(const string& text) const;

	void print() const;

	void sortAnswers();

private:
	Post* root_; // question
};

#endif
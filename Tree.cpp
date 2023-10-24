#include "Tree.h"

Tree::Tree(Post* root) : root_(root)
{
}

Tree::~Tree()
{
	delete root_;
}

Post* Tree::getRoot() const
{
	return root_; 
}

Post* Tree::findPost(const string& text) const
{
	stack<Post*> s;
	Post* curr = root_, * right;
	while (1) {
		if (curr->getText() == text) return curr;
		if (!curr->getAnswers().empty()) curr = curr->getAnswers().front().first;
		else {
			if (!s.empty()) {
				curr = s.top();
				s.pop();
			}
			else break;
		}
		right = curr->findRightBrother();
		if (right != nullptr) s.push(right);
	}

	return nullptr;
}

void Tree::print() const
{
	stack<Post*> s;
	Post* curr = root_, * right;
	cout << endl;
	while (1) {
		curr->print();
		if (!curr->getAnswers().empty()) curr = curr->getAnswers().front().first;
		else {
			if (!s.empty()) {
				curr = s.top();
				s.pop();
			}
			else break;
		}
		right = curr->findRightBrother();
		if (right != nullptr) s.push(right);
	}
	cout << endl;
}

void Tree::sortAnswers()
{
	root_->sortAnswers();
}



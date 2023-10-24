#include "Post.h"

unsigned int Post::id = 0;

Post::Post(const string& text) : text_(text), parent_(nullptr)
{
	answers_.reserve(10);
	id_ = id++;
}

Post::~Post()
{
	if (parent_ != nullptr) {
		vector<pair<Post*, int>>::iterator it;
		for (it = parent_->answers_.begin(); it != parent_->answers_.end(); it++)
			if ((*it).first->getId() == id_) {
				parent_->answers_.erase(it);
				break;
			}
	}

	for (auto i : answers_)
		delete i.first;

	answers_.clear();
}

string Post::getText() const
{
	return text_;
}

unsigned int Post::getId() const
{
	return id_;
}

vector<pair<Post*, int>>& Post::getAnswers() 
{
	return answers_;
}

Post* Post::getParent() const
{
	return parent_;
}

void Post::changeText(const string& text)
{
	text_ = text;
}

void Post::setParent(Post* parent)
{
	parent_ = parent;
}

void Post::addAnswer(const string& text)
{
	Post* answer = new Post(text);
	answer->setParent(this);

	pair<Post*,int> p;
	p.first = answer;
	p.second = 0;

	answers_.push_back(p);
}

Post* Post::findRightBrother()
{
	bool flag = false;

	for (auto& i : parent_->getAnswers()) {
		if (flag) return i.first;
		if (i.first->id_ == id_) flag = true;
	}

	return nullptr;
}

void Post::print() const
{
	for (int i = 0; i < this->depth(); i++)
		cout << "   ";

	cout << id_ << ')' << text_;
	if (parent_ != nullptr) cout << '[' << parent_->id_ << ']';
	else cout << '[' << ']';

	Post* curr = parent_;
	if (curr != nullptr) {
		for (auto& i : curr->getAnswers())
			if (i.first->getId() == id_)
				cout << '{' << i.second << '}' << endl;
	}
	cout << endl;
}

int Post::depth() const
{
	int count = 0;
	Post* tmp = parent_;
	while (tmp != nullptr) {
		count++;
		tmp = tmp->parent_;
	}

	return count;
}

void Post::upvote(int id, int votes)
{
	for (auto& i : answers_) 
		if (i.first->getId() == id)
			i.second = i.second + votes;
}

void Post::sortAnswers()
{
	stack<Post*> s;
	Post* curr = this, * right;

	while (1) {
		curr->sortArray();
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

}

void Post::sortArray()
{
	int j;
	pair<Post*, int> K;

	for (int i = 1; i < answers_.size(); i++) {
		K = answers_[i];
		j = i - 1;
		while (j >= 0 && answers_[j].second < K.second) {
			answers_[j + 1] = answers_[j];
			j--;
		}
		answers_[j + 1] = K;
	}
}




#include "Forest.h"

Forest::Forest()
{
}

Forest::~Forest()
{
	for (auto i : trees_)
		delete i;

	trees_.clear();
}

list<Tree*>& Forest::getTrees()
{
	return trees_;
}

void Forest::addQuestion(const string& text)
{
	trees_.push_back(new Tree(new Post(text)));
}

void Forest::addAnswer(const string& post, const string& reply)
{
	findPost(post)->addAnswer(reply);
}

void Forest::printQuestions() const
{
	if(trees_.empty()){
		cout << "Ne postoji nijedno pitanje!" << endl << endl;
		return;
	}

	for (auto i : trees_) {
		cout << i->getRoot()->getId() << ')' << ' ';
		cout << i->getRoot()->getText() << endl;
	}
	cout << endl;
}

Tree* Forest::findQuestion(const string& text) const
{
	for (auto i : trees_)
		if (i->getRoot()->getText() == text)
			return i;

	return nullptr;
}

Tree* Forest::findQuestion(int id) const
{
	for (auto i : trees_)
		if (i->getRoot()->getId() == id)
			return i;

	return nullptr;
}

Post* Forest::findPost(const string& text) const
{
	for (auto i : trees_) {
		Post* post = i->findPost(text);
		if (post != nullptr) return post;
	}

	return nullptr;
}

void Forest::removeQuestion(Post* question)
{
	list<Tree*>::iterator it;

	for (it = trees_.begin(); it != trees_.end(); it++) 
		if (question->getId() == (*it)->getRoot()->getId()) {
			trees_.erase(it);
			delete question;
			break;
		}
	
}

void Forest::sortAnswers()
{
	for (auto i : trees_)
		i->sortAnswers();
}

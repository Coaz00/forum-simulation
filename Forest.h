#ifndef FOREST_H
#define FOREST_H
#include "Tree.h"
#include <list>
#include <iostream>


class Forest {
public:
	Forest();
	~Forest();

	list<Tree*>& getTrees();

	void addQuestion(const string& text);
	void addAnswer(const string& post, const string& text);

	void printQuestions() const;

	Tree* findQuestion(const string& text) const;
	Tree* findQuestion(int id) const;

	Post* findPost(const string& text) const;

	void removeQuestion(Post* question);
	
	void sortAnswers();

private:
	list<Tree*> trees_; //list of trees with question as a root
};

#endif
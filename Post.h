#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Post{
public:
	static unsigned int id;

	Post(const string& text);
	~Post();

	string getText() const;
	unsigned int getId() const;
	vector<pair<Post*, int>>& getAnswers();
	Post* getParent() const;

	void changeText(const string& text);
	void setParent(Post* parent);

	void addAnswer(const string& text);

	Post* findRightBrother();

	void print() const;

	int depth() const;

	void upvote(int id, int votes);

	void sortAnswers();

private:
	string text_;
	vector<pair<Post*, int>> answers_; // second part of pair is answer's grade
	unsigned int id_; // unique for every post
	Post* parent_;

	void sortArray();
};

#endif
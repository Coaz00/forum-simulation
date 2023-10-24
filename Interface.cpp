#include "Forest.h"
#include <iostream>

using namespace std;

int main() {

	string text;
	int option;
	Post* post;
	Tree* question;

	Forest* forest = new Forest();

	cout << "Dobrodosli u simulaciju platforme za postavljanje pitanja i odgovore na njih." << endl;
	while (1) {
		
		cout << "Izaberite zeljenu opciju:" << endl;
		cout << "1)Dodaj novo pitanje" << endl;
		cout << "2)Dodaj odgovor na pitanje ili komentar" << endl;
		cout << "3)Pretraga pitanja" << endl;
		cout << "4)Pretraga odgovora" << endl;
		cout << "5)Povecanje ocene odgovora" << endl;
		cout << "6)Sortiraj odgovore/komentare po oceni" << endl;
		cout << "7)Ispisi pitanja" << endl;
		cout << "8)Ispisi pitanje sa odgovorima i komentarima" << endl;
		cout << "9)Brisanje odgovora" << endl;
		cout << "10)Brisanje pitanja" << endl;
		cout << "0)Izadji iz simulacije" << endl;

		cin >> option;
		cout << endl;

		switch(option) {
			case 1:
				cout << "Unesite vase pitanje:" << endl;
				getline(cin >> ws,text);
				forest->addQuestion(text);
				cout << endl;
				continue;
			case 2:
				cout << "Unesite tekst pitanja/odgovora na koje zelite odgovoriti" << endl;
				getline(cin >> ws, text);
				post = forest->findPost(text);
				if (post == nullptr) {
					cout << "Trazeno pitanje ne postoji!" << endl << endl;
					continue;
				}
				cout << "Unesite tekst odgovora" << endl;
				getline(cin >> ws, text);
				post->addAnswer(text);
				cout << endl;
				continue;
			case 3:
				cout << "Unesite pitanje koje zelite da nadjete" << endl;
				getline(cin >> ws, text);
				question = forest->findQuestion(text);
				if (question == nullptr) cout << "Pitanje ne postoji!" << endl;
				else {
					cout << "Pitanje je uspesno pronadjeno!" << endl;
					question->getRoot()->print();
				}
				
				continue;
			case 4:
				cout << "Unesite pitanje za koje je vezan odgovor" << endl;
				getline(cin >> ws, text);
				question = forest->findQuestion(text);
				cout << "Unesite odgovor za pretragu" << endl;
				getline(cin >> ws, text);
				post = question->findPost(text);
				if (post == nullptr) cout << "Odgovor ne postoji!" << endl;
				else {
					cout << "Odgovor je uspesno pronadjen" << endl;
					post->print();
				}
				continue;
			case 5:
				cout << "Unesite odgovor ciju ocenu zelite povecati" << endl;
				getline(cin >> ws, text);
				post = forest->findPost(text);
				if (post == nullptr) {
					cout << "Odgovor ne postoji!" << endl;
					continue;
				}
				cout << "Za koliko zelite povecati ocenu odgovora?" << endl;
				cin >> option;
				cout << endl;
				if (post->getParent() == nullptr) {
					cout << "Pitanja nemaju ocenu!" << endl;
					continue;
				}
				post->getParent()->upvote(post->getId(), option);
				continue;
			case 6:
				forest->sortAnswers();
				cout << "Odgovori su uspesno sortirani!" << endl;
				continue;
			case 7:
				forest->printQuestions();
				continue;
			case 8:
				cout << "Unesite pitanje za koje zelite da ispisete odgovore/komentare" << endl;
				getline(cin >> ws, text);
				question = forest->findQuestion(text);
				question->print();
				continue;
			case 9:
				cout << "Unesite odgvor koji zelite da obrisete" << endl;
				getline(cin >> ws, text);
				post = forest->findPost(text);
				if (post == nullptr) {
					cout << "Odgovor ne postoji!" << endl;
					continue;
				}
				delete post;
				continue;
			case 10:
				cout << "Unesite pitanje koje zelite da obrisete" << endl;
				getline(cin >> ws, text);
				question = forest->findQuestion(text);
				forest->removeQuestion(question->getRoot());
				continue;
			case 0:
				cout << "Dovidjenja!" << endl << endl;
				return 0;
			default:
				cout << "Nemoguc izbor! Pokusajte ponovo." << endl << endl;
				continue;
		}
	}

}
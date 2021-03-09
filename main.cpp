#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		vector<string> lines;
 		string s;
		
		file();
		~file();
		
		void pobierz();
};

file::file() {
	input.open("c:\\dane_obrazki.txt");
 	output.open("wyjscie.txt");
}

file::~file() {
	input.close();
 	output.close();
}

void file::pobierz() {
	input>>s;
	lines.push_back(s);
}

class zadanie64_4 :public file{
	private:
		int countX1 = 0;
		int countY1 = 0;
		int countXErr = 0;
		int countYErr = 0;
		int numPicture = 0;
		int row = 0;

		struct data {
		    string name;
		    int numPic;
		    int value;
		};
		
		vector<data> sub;
		vector<string> picture;
	public:
		void checkRows();
		void checkColumns();
		void checkPicture();
};

void zadanie64_4::checkRows() {
	
	int x = 0;	//pomocnicza zmienna
	
	for ( int i = 0; i < lines.size() - 1; i++ ) {	//iterowanie po wszystkich wierszach obrazka
		for ( int j = 0; j < 20; j++ ) {	//iterowanie po konkretnych wierszach obrazka
			if (lines[i][j] == '1') {
				countX1++;
			}	
		}
		
		if (countX1 % 2 == 0) {	//sprawdznie czy liczba jedynek jest parzysta i przypisanie zmiennej x odpowiedniej wartoœci char 48 = 0, 49 = 1 
			x = 48;
		} else {
			x = 49;
		}
		
		if (!(x == (int)lines[i][lines[i].length()-1])) {	//sprawdzanie czy bit parzystosci rozni sie w wierszu
			countXErr++;
			sub.push_back ({"x", numPicture, i});
//			cout<<"blad w wierszu "<<i+1<<" nr obrazka "<<numPicture<<" | liczba "<<lines[i][lines[i].length()-1]<<endl;
		}
	
		countX1 = 0;
	}
}

void zadanie64_4::checkColumns() {
	
	int y = 0;	//pomocnicza zmienna
	
	for ( int i = 0; i < lines.size() - 1; i++ ) {  //iterowanie po wszystkich kolumnach obrazka
		for ( int j = 0; j < 20; j++ ) { 	//iterowanie po konkretnych kolumnach obrazka
			if (lines[j][i] == '1') {
				countY1++;
			}
		}
		
		if (countY1 % 2 == 0) {	//sprawdznie czy liczba jedynek jest parzysta i przypisanie zmiennej y odpowiedniej wartoœci char 48 = 0, 49 = 1 
			y = 48;
		} else {
			y = 49;
		}
		
		if (!(y == (int)lines[20][i])) {	//sprawdzanie czy bit parzystosci rozni sie w wierszu
			countYErr++;
			sub.push_back ({"y", numPicture, i});
//			cout<<"blad w kolumnie "<<i+1<<" obrazek nr: "<<numPicture<<endl;
		}
		
		countY1 = 0;
	}
	

}

void zadanie64_4::checkPicture() {
	while(!input.eof()) { 
		this->pobierz();
		
		if (lines.size() == 21) {
			numPicture++;
			this->checkRows();
			this->checkColumns();
			lines.clear();
		}
	}
	
	vector<int> black_list;
		
//	for ( int i = 0; i < sub.size() - 1; i++ ) {
//		for ( int j = 0; j < sub.size() - 1; j++ ) { 
//			if (sub[i].numPic == sub[j].numPic) {
//				cout<<sub[i].numPic<<" | "<<sub[j].name<<endl;
////				if (sub[i].name == sub[j].name) {
////					if (!(find(black_list.begin(), black_list.end(), sub[i].numPic) != black_list.end())) {
////						black_list.push_back(sub[i].numPic);
//////						sub.erase (sub.begin()+j);
////					}
//////				cout<<sub[i].numPic<<" | "<<sub[j].name<<endl;
//////				sub.erase (sub.begin()+j);
////				}
//			}
//		}
//	}
	

	
	for ( int i = 0; i < sub.size() - 1; i++ ) { 
		cout<<sub[i].numPic<<" | "<<sub[i].name<<endl;
	}

}

int main(int argc, char** argv) {
	zadanie64_4 l;
	l.checkPicture();
	return 0;
}

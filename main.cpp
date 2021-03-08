#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		vector<string> line;
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
}

class zadanie64_4 :public file{
	private:
		int countX1 = 0;
		int countY1 = 0;
		int countXErr = 0;
		int countYErr = 0;
		int numPicture = 0;
		int row = 0;
		vector<int> data;
		vector<string> picture;
	public:
		void checkPicture();
};

void zadanie64_4::checkPicture() {
	
	while(!input.eof()) {
		this->pobierz();
		line.push_back(s);	//pojedyniczy wiersz
		picture.push_back(s);	//pojedyniczy obrazek
		numPicture++;
		row++;
		
		
		for( int i = 0; i < line[0].length()-1; i++) {	//liczenie 1 w danym wierszu obrazka
			
			if (line[0][i] == '1') {
				countX1++;
			}
			
		}
		
		int x = 0;
		
		if (countX1 % 2 == 0) {	//sprawdznie czy liczba jedynek jest parzysta i przypisanie zmiennej x odpowiedniej wartoœci char 48 = 0, 49 = 1 
			x = 48;
		} else {
			x = 49;
		}
		
		if (!(x == (int)line[0][line[0].length()-1])) {	//sprawdzanie czy bit parzystosci rozni sie w wierszu
			countXErr++;
			data.push_back(row);
		}
		
		if (picture[picture.size() - 1].length() == 20) {	//liczenie 1 w kolumnach, sprawdzanie ich z bitami parzystosci
			
			for (int i = 0; i < picture.size() - 1; i++) {
				for (int j = 0; j < 20; j++) { 
					if (picture[j][i] == '1') {
						countY1++;
					}
				}
				
				int y = 0;
				
				if (countY1 % 2 == 0) {	//sprawdznie czy liczba jedynek jest parzysta i przypisanie zmiennej y odpowiedniej wartoœci char 48 = 0, 49 = 1 
					y = 48;
				} else {
					y = 49;
				}
				
				if (!(y == (int)picture[20][i])) {	//sprawdzanie czy bit parzystosci rozni sie w wierszu
					countYErr++;
					data.push_back(i);
				}
				
				if (countXErr <= 1 && countYErr <=1) {

				}
				
				countY1 = 0;	//restart countY1 dla kazdej kolumny
			}
			
			row = 0;
			picture.clear();
		}
		
		countX1 = 0;	//restart wartosci dla kazdego obrazka
		countXErr = 0;
		countYErr = 0;
		line.clear();
	}
}

int main(int argc, char** argv) {
	zadanie64_4 l;
	l.checkPicture();
	return 0;
}

#include <fstream>
#include <iostream>
using namespace std;

int main(void) {
	string filename = "input_es1.txt";
	ifstream ifs(filename);
	if (ifs.is_open()) { // Controllo se il file si apre correttamente
		cout << "Il file è stato aperto correttamente.\n";
		while(!ifs.eof()) {
			string città;
			double temp1;
			double temp2;
			double temp3;
			double temp4;
			ifs >> città >> temp1 >> temp2 >> temp3 >> temp4;
			double media_temperature=(temp1+temp2+temp3+temp4)/4;
			cout << "Città: " << città << ", Media temperature: " << media_temperature << "\n";
		}
	}
	else { 
	  cout << "Errore nell'aprire il file.\n";
	}
	return 0;
}
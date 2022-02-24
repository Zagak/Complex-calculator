#include"Meniu.h"

using namespace std;


void main(int argc, char* argv[]) {
	
	
	Meniu fis("ecuatii_citire.txt","ecuatii_afisare.txt","fisier.bin");
	int alegere;
	int tipAfisaj;
	
	cout << "Unde doresti sa introduci ecuatiile ? : 1->consola /2->fisier ";
	do {
		cin >> alegere;
		
		if (alegere == 1) {
			cout << "Introdu ecuatiile (tasteaza 'exit' cand ai terminat)" << endl;
			cin >> fis;

		}
		else if (alegere == 2) {
			fis.citireFisier();
		}
		else {
			cout << "Optiune inexistenta" << endl;
		}

	} while (alegere != 1 && alegere != 2);


	system("CLS");

	cout<< "Unde doresti sa fie afisate ecuatiile ? : 1->consola /2->fisier " ;
	do {
		cin >> alegere;
		do {
			cout << "Doresti sa ti se afiseze doar rezultatul sau intreaga rezolvare ? : 1->tot / 2->rezultatul ";
			cin >> tipAfisaj;
			if (alegere == 1 && tipAfisaj == 1) {
				fis.setTipAfisaj(true);
				cout << fis;
			}
			else if (alegere == 1 && tipAfisaj == 2) {
				cout << fis;
			}
			else if (alegere == 2 && tipAfisaj == 1) {
				fis.setTipAfisaj(true);
				fis.afisareFisier();
				system("CLS");
			}
			else if(alegere == 2 && tipAfisaj == 2) {
				fis.afisareFisier();
				system("CLS");
			}
			else {
				cout << "Optiune inexistenta" << endl;
			}
		}while (tipAfisaj != 1 && tipAfisaj != 2);

	} while (alegere != 1 && alegere != 2);

    
	

}

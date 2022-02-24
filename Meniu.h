#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Ecuatie.h"

using namespace std;

class Meniu {
private:
	ifstream inf;
	ofstream outf;
	vector<string> rezultate;
	fstream salvari;
	bool afisare;
public:
	Meniu(string fisier_citire, string fisier_scriere,string f_binar,bool afisam=false) {
		this->afisare = afisam;
		inf.open(fisier_citire, ios::in);
		outf.open(fisier_scriere, ios::out | ios::trunc);
		salvari.open(f_binar, ios::in | ios::out | ios::binary );
	}


	void citireFisier() {
		string ecuatia;
		while (!inf.eof()) {
			getline(inf, ecuatia);

			rezultate.push_back(ecuatia);
		}

	}

	void afisareFisier() {
		for (int i = 0; i < rezultate.size(); i++) {
			Ecuatie ec(rezultate[i]);
			/// <summary>
			Element compara;
			while (!salvari.eof()) {
				salvari.read((char*)&compara, sizeof(Element));
				for (int i = 0; i < ec.getSize(); i++) {
					if (ec[i].getElementChar() == compara.getElementChar()) {
						ec[i].setElementNumber(compara.getElementNumber());
						ec[i].setElementChar('$');
					}
				}
			}

			if (ec[ec.getSize() - 2].getElementChar() == '=') {
				compara = ec.pop_back();
				salvari.write((char*)&compara , sizeof(Element));
				ec.pop_back();
			}
			/// </summary>

			if (this->afisare == true) {
				outf << ec.calcul(true, &outf) << endl;
			}
			else {
				outf << ec.calcul(&outf) << endl;
			}
		}
	}

	void setTipAfisaj(bool tip) {
		this->afisare = tip;
	}

	friend ostream& operator<<(ostream&, Meniu&);
	friend istream& operator>>(istream&, Meniu&);



	~Meniu() {
		inf.close();
		outf.close();
		salvari.close();
	}
};

ostream& operator<<(ostream& out, Meniu& m) {
	for (int i = 0; i < m.rezultate.size(); i++) {
		try {
			Ecuatie ec(m.rezultate[i]);
			if (m.afisare == true) {
				out << ec.calcul(true) << endl << endl;
			}
			else {
				out << ec.calcul() << endl << endl;
			}
		}
		catch (char e) {
			out << "In aceasta ecuatie s-a introdus un caracter gresit !" << endl;
		}
		catch (int z) {
			out << "Nu se poate imparti la zero !" << endl;
		}
		catch (...) {
			out << "Ceva nu a mers bine" << endl;
		}
		
	}
	return out;
}

istream& operator>>(istream& in, Meniu& m) {
	string ecuatia;
	float rez;
	while (1) {
		try {
			getline(in >> ws, ecuatia);
			if (ecuatia == "exit"||ecuatia=="EXIT") break;
			//Ecuatie ec(ecuatia);
			//m.rezultate.push_back(ec.calcul());
			m.rezultate.push_back(ecuatia);
		}
		catch (char e) {
			cout << "In aceasta ecuatie s-a introdus un caracter gresit !" << endl;
		}
		catch (int z) {
			cout << "Nu se poate imparti la zero !" << endl;
		}
		catch (...) {
			cout << "Ceva nu a mers bine"<<endl;
		}
	}
	return in;
}

#pragma once
#include<iostream>
#include"Element.h"
#include"Operatii.h"


using namespace std;

class Ecuatie {
private:
	Element* el = new Element;
	int size = 0;

public:

	Element pop_back() {
		return el[size - 1];
		this->size--;
		
	}

	void push_back(Element el) {
		Element* _temp = new Element[++size];

		for (int i = 0; i < size - 1; i++) {
			_temp[i] = this->el[i];
		}
		if (this->el != NULL)delete[]this->el;
		this->el = new Element[size];
		_temp[size - 1] = el;

		for (int i = 0; i < size; i++) {
			this->el[i] = _temp[i];
		}
	}


	static string taieSpatii(string s) {
		int i = 0;
		string temp;
		while (s[i] != '\0') {
			if (s[i] != ' ') temp.push_back(s[i]);
			i++;
		}
		return temp;
	}

	Ecuatie(int poz_s,int poz_f,Ecuatie ecuatie) {
		for (int i = poz_s; i <= poz_f; i++) {
			this->push_back(ecuatie[i]);
		}
	}

	Ecuatie(string ecuatie_netaiata) {

		string ecuatie = taieSpatii(ecuatie_netaiata);

		int i = 0;
		int j = 0;
		int k = 0;
		int inceput = 0;
		int f = 0;
		int marime = 0;

		Element* temp;

		while (ecuatie[j] != '\0') {
			float numar = 0;
			temp = new Element;

			while (((int)(ecuatie[j]) >= 48) & ((int)(ecuatie[j++]) <= 57)) {
				if (((ecuatie[j]) == 48) && ((int)(ecuatie[j - 1]) >= 48) && ((int)(ecuatie[j - 1]) <= 57) && (int)(ecuatie[j + 1]) >= 48 && ((int)(ecuatie[j + 1]) <= 57)) numar *= 10;
				numar += ((int)(ecuatie[j - 1]) - 48);
				numar *= 10;
				marime++;
			}

			if (numar != 0)j--;

			if (numar == 0 && ecuatie[j - 1] == 0) {
				temp->setElementNumber(0);
				this->push_back(*temp);
				j--;
			}

			if ((numar != 0)) {
				if (f == 0) { temp->setElementNumber(numar / 10); numar = 0;}
				else if (f == 1) {
					
					if (el[size-2].getElementNumber() - (int)el[size-2].getElementNumber() > 0.1) {
						cout << "Un numar nu poate avea mai multe parti fractionale !"; exit(EXIT_FAILURE);
					}
					else {
						el[size - 1].setElementNumber(el[size - 1].getElementNumber() + (numar / 10) * pow(10, -marime));
						numar = 0;
					}
				}
			}
			marime = 0;
			f = 0;

			if ((((int)ecuatie[j - 1] >= 48) && (int)ecuatie[j - 1] <= 57) && (f == 0))this->push_back(*temp);
			else if ((ecuatie[j - 1] == '.') && (f == 0)) {
				f = 1;
			}
			else if ((ecuatie[j - 1] != '\0') && (f == 0)) {
				temp->setElementChar(ecuatie[j - 1]);
				this->push_back(*temp);
			}

			delete temp;
		}

		for (int i = 0; i < size; i++) {
			if (this->el[i].getElementNumber() - (int)this->el[i].getElementNumber() != 0) {
				for (int j = i; j < size - 1; j++) {
					this->el[j + 1] = this->el[j + 2];
				}
				this->size--;

			}
		}
	}

	void setEcuatie(string ecuatie_netaiata) {

		string ecuatie = taieSpatii(ecuatie_netaiata);

		int i = 0;
		int j = 0;
		int k = 0;
		int inceput = 0;
		int f = 0;
		int marime = 0;

		Element* temp;

		while (ecuatie[j] != '\0') {
			float numar = 0;
			temp = new Element;


			while (((int)(ecuatie[j]) >= 48) & ((int)(ecuatie[j++]) <= 57)) {
				if (((ecuatie[j]) == 48) && ((int)(ecuatie[j - 1]) >= 48) && ((int)(ecuatie[j - 1]) <= 57) && (int)(ecuatie[j + 1]) >= 48 && ((int)(ecuatie[j + 1]) <= 57)) numar *= 10;
				numar += ((int)(ecuatie[j - 2]) - 48);
				numar *= 10;
				marime++;
			}

			if (numar != 0)j--;


			if ((numar != 0)) {
				if (f == 0) { temp->setElementNumber(numar / 10); numar = 0; }
				else if (f == 1) {
					el[size - 1].setElementNumber(el[size - 1].getElementNumber() + (numar / 10) * pow(10, -marime));
					numar = 0;
				}
			}
			marime = 0;
			f = 0;

			if ((((int)ecuatie[j - 1] >= 48) && (int)ecuatie[j - 1] <= 57) && (f == 0))this->push_back(*temp);
			else if ((ecuatie[j - 1] == '.') && (f == 0)) {
				f = 1;
			}
			else if ((ecuatie[j - 1] != '\0') && (f == 0)) {
				temp->setElementChar(ecuatie[j - 1]);
				this->push_back(*temp);
			}

			delete temp;
		}

		for (int i = 0; i < size; i++) {
			if (this->el[i].getElementNumber() - (int)this->el[i].getElementNumber() != 0) {
				for (int j = i; j < size - 1; j++) {
					this->el[j + 1] = this->el[j + 2];
				}
				this->size--;

			}
		}

	}

	~Ecuatie() {
		delete[]this->el;
		this->el = nullptr;
	}

	void regrupare(int locuri, int pozitie) {
		this->size = this->size - locuri;
		for (int i = pozitie; i < this->size; i++) {
			this->el[i] = this->el[i + locuri];
		}
	}
	/*
	float rezultatEcuatie() {
		for (int ordin = 3; ordin >= 1; ordin--) {
			for (int i = 0; i <= this->size; i++) {
				if (size == 1) return el[0].getElementChar();
				if (el[i].getElementChar() != '$' && el[i].getElementChar() != '(' && el[i].getElementChar() != ')' && el[i].getElementChar() != '[' && el[i].getElementChar() != ']' && el[i].getElementChar() != '{' && el[i].getElementChar() != '}') {
					if (el[i].getElementOrdin() == 1 && ordin == 1) {
						switch (el[i].getElementChar()) {
						case'+': {
							if (el[i - 1].getElementChar() == '$') {
								Adunare ad(el[i - 1], el[i + 1]);
								el[i - 1] = ad.operatie();
								this->regrupare(2, i);
								i--;
							}
							else {
								Adunare ad(el[i + 1]);
								el[i + 1] = ad.operatie_unar();
								this->regrupare(1, i);
							}
						}
							   break;

						case'-': {
							if (el[i - 1].getElementChar() == '$') {
								Scadere sc(el[i - 1], el[i + 1]);
								el[i - 1] = sc.operatie();
								this->regrupare(2, i);
								i--;

							}
							else {
								Scadere sc(el[i + 1]);
								el[i + 1] = sc.operatie_unar();
								this->regrupare(1, i);
							}
						}
							   break;
						}
					}

					if (el[i].getElementOrdin() == 2 && ordin == 2) {
						switch (el[i].getElementChar()) {

						case'*': {
							if (el[i - 1].getElementChar() == '$') {
								Inmultire in(el[i - 1], el[i + 1]);
								el[i - 1] = in.operatie();
								this->regrupare(2, i);
								i--;
							}
						}
							   break;

						case'/': {
							if (el[i - 1].getElementChar() == '$') {
								Impartire imp(el[i - 1], el[i + 1]);
								el[i - 1] = imp.operatie();
								this->regrupare(2, i);
								i--;

							}
						}
							   break;
						}
					}

				}
			}
		}
	}
	*/

	float rezultatEcuatie() {
		for (int ordin = 4; ordin >= 1; ordin--) {
			for (int i = 0; i < this->size; i++) {
				if (el[i].getElementChar() != '$' && el[i].getElementChar() != '(' && el[i].getElementChar() != ')' && el[i].getElementChar() != '[' && el[i].getElementChar() != ']' && el[i].getElementChar() != '{' && el[i].getElementChar() != '}') {
					switch (el[i].getElementChar()) {
					case'+': {
						if (ordin == 1) {
							if (el[i - 1].getElementChar() == '$') {
								Adunare ad(el[i - 1], el[i + 1]);
								el[i - 1] = ad.operatie();
								this->regrupare(2, i);
								i--;
							}
						}

						if (el[i - 1].getElementChar() != '$' && el[i-1].getElementChar() != '(' && el[i-1].getElementChar() != ')' && el[i-1].getElementChar() != '[' && el[i-1].getElementChar() != ']' && el[i-1].getElementChar() != '{' && el[i-1].getElementChar() != '}' && ordin == 4) {
							Adunare ad(el[i + 1]);
							el[i + 1] = ad.operatie_unar();
							this->regrupare(1, i);
						}

					}
						   break;

					case'-': {
						if (ordin == 1) {
							if (el[i - 1].getElementChar() == '$') {
								Scadere sc(el[i - 1], el[i + 1]);
								el[i - 1] = sc.operatie();
								this->regrupare(2, i);
								i--;

							}
						}
						if (el[i - 1].getElementChar() != '$' && el[i-1].getElementChar() != '(' && el[i-1].getElementChar() != ')' && el[i-1].getElementChar() != '[' && el[i-1].getElementChar() != ']' && el[i-1].getElementChar() != '{' && el[i-1].getElementChar() != '}' && ordin == 4) {
							Scadere sc(el[i + 1]);
							el[i + 1] = sc.operatie_unar();
							this->regrupare(1, i);
						}

					}
						   break;

					case'*': {
						if (ordin == 2) {
							if (el[i - 1].getElementChar() == '$') {
								Operatie* op = new Inmultire (el[i - 1], el[i + 1]);/////
								//Inmultire in(el[i - 1], el[i + 1]);
								//el[i - 1] = in.operatie();
								el[i - 1] = op->operatie();////
								this->regrupare(2, i);
								i--;
							}
						}
					}
						   break;

					case'/': {
						if (ordin == 2) {
							if (el[i - 1].getElementChar() == '$') {
								Impartire imp(el[i - 1], el[i + 1]);
								el[i - 1] = imp.operatie();
								this->regrupare(2, i);
								i--;
							}
						}
					}
						   break;

					case'^': {
						if (ordin == 3) {
							if (el[i - 1].getElementChar() == '$') {
								Putere pu(el[i - 1], el[i + 1]);
								el[i - 1] = pu.operatie();
								this->regrupare(2, i);
								i--;
							}
						}
					}
					case'#': {
						if (ordin == 3) {
							if (el[i - 1].getElementChar() == '$') {
								Radical rad(el[i - 1], el[i + 1]);
								el[i - 1] = rad.operatie();
								this->regrupare(2, i);
								i--;
							}
						}
					}
					}
				}
			}
		}
		return (float)el[0];
	}

	void eliminare(int poz_s, int poz_f) {
		this->size = this->size - (poz_f - poz_s);
		int j = poz_f;
		for (int i = poz_s; i < this->size; i++) {
			this->el[i] = this->el[j++];
		}
	}

	void calculeazaParanteze(int poz_s, int poz_f, const char* tip,bool afiseazaPasi=false, ofstream* f = nullptr) {
		
		for (int i = poz_s; i <= poz_f; i++) {
			if (el[i].getElementChar() == tip[0]) {
				calculeazaParanteze(i + 1, poz_f,tip,afiseazaPasi,f);
				poz_f = size - 1;
				
			}

			if (el[i].getElementChar() == tip[1]) {
				Element cobai;
				Ecuatie temp(poz_s, i - 1, *this);
				cobai.setElementNumber(temp.rezultatEcuatie());
				this->el[poz_s - 1] = cobai;
				this->eliminare(poz_s, i + 1);
				if (afiseazaPasi == true&&f==nullptr) cout << *this << endl;
				if (afiseazaPasi == true && f != nullptr) *f << *this << endl;
				poz_f = i;
			}

		}
	}

	float calcul(bool afiseaza=false,ofstream* f=nullptr) {
		if (afiseaza == true&&f==nullptr) cout << *this<<endl;
		if (afiseaza == true && f != nullptr) *f << *this << endl;
		for (int prioritate = 1; prioritate <= 3; prioritate++) {
			if (prioritate == 1) calculeazaParanteze(0, this->getSize() - 1, "()",afiseaza,f);
			if (prioritate == 2) calculeazaParanteze(0, this->getSize() - 1, "[]",afiseaza,f);
			if (prioritate == 3) calculeazaParanteze(0, this->getSize() - 1, "{}",afiseaza,f);
		}
		return this->rezultatEcuatie();
	}

	/*
	void calculeaza(int poz_s, int poz_f) {
		for (int prioritate = 1; prioritate <= 3; prioritate++) {
			
			for (int i = poz_s; i <= poz_f; i++) {
				if (el[i].getElementChar() == '(' && prioritate == 1) {
					cout << "i+1:" << i + 1<<endl;
					cout << "size:" << size << endl;
					calculeaza(i + 1, poz_f);
					poz_f = size - 1;
					
				}
				
				else if (el[i].getElementChar() == '[' && prioritate == 2) {
					calculeaza(i + 1, poz_f);
					poz_f = size - 1;
				}
				else if (el[i].getElementChar() == '{' && prioritate == 3) {
					calculeaza(i + 1, poz_f);
					poz_f = size - 1;
				}
				


				if (el[i].getElementChar() == ')' && prioritate == 1) {
					Element cobai;
					Ecuatie temp(poz_s, i - 1, *this);
					cout << "i-1:" << i - 1 << endl;
					cout << "temp : " << temp << endl;
					cout << "poz_s : " << poz_s << endl;
					cobai.setElementNumber(temp.rezultatEcuatie());
					this->el[poz_s - 1] = cobai;
					cout << *this << endl;
					this->eliminare(poz_s, i + 1);
					cout << *this << endl;
					poz_f = i;
				}
				
				else if (el[i].getElementChar() == ']' && prioritate == 2) {
					Element cobai;
					Ecuatie temp(poz_s, i - 1, *this);
					cout << "temp : " << temp << endl;
					cout << "poz_s : " << poz_s << endl;
					cobai.setElementNumber(temp.rezultatEcuatie());
					this->el[poz_s - 1] = cobai;
					cout << *this << endl;
					this->eliminare(poz_s, i + 1);
					cout << *this << endl;
					poz_f = i;
				}
				else if (el[i].getElementChar() == '}' && prioritate == 3) {
					Element cobai;
					Ecuatie temp(poz_s, i - 1, *this);
					cout << "temp : " << temp << endl;
					cout << "poz_s : " << poz_s << endl;
					cobai.setElementNumber(temp.rezultatEcuatie());
					this->el[poz_s - 1] = cobai;
					cout << *this << endl;
					this->eliminare(poz_s, i + 1);
					cout << *this << endl;
					poz_f = i;
				}
			}
			
		}
		
	}
	*/

	friend ostream& operator<<(ostream& out, Ecuatie& ec);
	friend istream& operator>>(istream& in, Ecuatie ec);

	Element operator[](int i) {
		return el[i];
	}

	Ecuatie(const Ecuatie& ec) {
		this->size = size;
		this->el = new Element[ec.size];
		for (int i = 0; i < ec.size; i++) {
			this->el[i] = ec.el[i];
		}

	}

	int getSize() {
		return this->size;
	}

	void setSize(int sizze) {
		if (sizze >= 0)this->size = sizze;
		else cout << "Marimea nu poate fi negativa !";
	}
};

ostream& operator<<(ostream& out, Ecuatie& ec) {
	for (int i = 0; i < ec.size; i++) {
		if (ec.el[i].getElementChar() == '$') out << ec.el[i].getElementNumber() << " ";
		else out << ec.el[i].getElementChar() << " ";;
	}
	return out;
}

istream& operator>>(istream& in, Ecuatie ec) {
	if (ec.el != nullptr)delete[]ec.el;
	ec.size = 0;
	string ecuatia;
	in >> ecuatia;
	ec.setEcuatie(ecuatia);
	return in;
}
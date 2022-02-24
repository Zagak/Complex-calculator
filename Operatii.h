#pragma once
#include<iostream>
#include"Element.h";
using namespace std;

class Operatie {
protected:
	Element operand_s;
	Element operand_d;
	const int ordin = 0;

public:
	Operatie(Element s, Element d) :operand_s(s), operand_d(d) {}

	Operatie(Element d) : operand_d(d) {}

	virtual Element& operatie() = 0;

	virtual int getOrdin() = 0;


	friend ostream& operator<<(ostream&, Operatie&);
	friend istream& operator>>(istream&, Operatie&);
};

ostream& operator<<(ostream& out, Operatie& op) {
	out << "Operandul stang este : " << op.operand_s << endl;
	out << "Operandul drept este : " << op.operand_d << endl;
	return out;
}

istream& operator>>(istream& in, Operatie& op) {
	cout << "Operandul stang : ";
	in >> op.operand_s;
	cout << endl;
	cout << "Operandul drept : ";
	in >> op.operand_d;
	cout << endl;

	return in;
}

class Adunare :public Operatie {
private:
	const int ordin = 1;
	static int numar_operatori;
public:
	Adunare(Element s, Element d) :Operatie(s, d) {}
	Adunare(Element d) :Operatie(d) {}

	Element& operatie() {
		numar_operatori++;
		Element rez;
		rez.setElementNumber(operand_s.getElementNumber() + operand_d.getElementNumber());
		return rez;
	}
	Element& operatie_unar() {
		numar_operatori++;
		Element rez;
		rez.setElementNumber(operand_d.getElementNumber());
		return rez;
	}
	static int getNumarAparitiiPlus() {
		return numar_operatori;
	}
	int getOrdin() {
		return ordin;
	}

	bool operator==(int nr) {
		if (operand_s.getElementNumber() + operand_d.getElementNumber() == nr) return true;
		else return false;
	}

	bool operator!=(int nr) {
		if (operand_s.getElementNumber() + operand_d.getElementNumber() != nr) return true;
		else return false;
	}

};
int Adunare::numar_operatori = 0;

class Scadere :public Operatie {
private:
	const int ordin = 1;
	static int numar_operatori;
public:
	Scadere(Element s, Element d) :Operatie(s, d) {}
	Scadere(Element d) :Operatie(d) {}

	Element& operatie() {
		numar_operatori++;
		Element rez;
		rez.setElementNumber(operand_s.getElementNumber() - operand_d.getElementNumber());
		return rez;
	}
	Element& operatie_unar() {
		numar_operatori++;
		Element rez;
		rez.setElementNumber(-operand_d.getElementNumber());
		return rez;
	}
	static int getNumarAparitiiScadere() {
		return numar_operatori;
	}
	int getOrdin() {
		return ordin;
	}

	bool operator==(int nr) {
		if (operand_s.getElementNumber() - operand_d.getElementNumber() == nr) return true;
		else return false;
	}

	bool operator!=(int nr) {
		if (operand_s.getElementNumber() - operand_d.getElementNumber() != nr) return true;
		else return false;
	}
};
int Scadere::numar_operatori = 0;

class Inmultire :public Operatie {
private:
	const int ordin = 2;
	static int numar_operatori;
public:
	Inmultire(Element s, Element d) :Operatie(s, d) {}

	Element& operatie() {
		numar_operatori++;
		Element rez;
		rez.setElementNumber(operand_s.getElementNumber() * operand_d.getElementNumber());
		if (rez.getElementNumber() == 0)rez.setElementNumber(0);
		return rez;
	}
	static int getNumarAparitiiInmultire() {
		return numar_operatori;
	}
	int getOrdin() {
		return ordin;
	}

	bool operator==(int nr) {
		if (operand_s.getElementNumber() * operand_d.getElementNumber() == nr) return true;
		else return false;
	}

	bool operator!=(int nr) {
		if (operand_s.getElementNumber() * operand_d.getElementNumber() != nr) return true;
		else return false;
	}
};
int Inmultire::numar_operatori = 0;

class Impartire :public Operatie {
private:
	const int ordin = 2;
	static int numar_operanzi;
public:
	Impartire(Element s, Element d) :Operatie(s, d) {}

	Element& operatie() {
		numar_operanzi++;
		Element rez;
		try {
			if (operand_d.getElementNumber() == 0) throw(404);
			else {
				rez.setElementNumber(operand_s.getElementNumber() / operand_d.getElementNumber());
				return rez;
				
			}
		}
		catch (char e) {
			cout << "Nu se poate imparti la zero!";
		}
		
	}
	static int getNumarAparitiiImpartire() {
		return numar_operanzi;
	}
	int getOrdin() {
		return ordin;
	}

	bool operator==(int nr) {
		if (operand_s.getElementNumber() / operand_d.getElementNumber() == nr) return true;
		else return false;
	}

	bool operator!=(int nr) {
		if (operand_s.getElementNumber() / operand_d.getElementNumber() != nr) return true;
		else return false;
	}
};
int Impartire::numar_operanzi = 0;

class Putere : public Operatie {
private:
	const int ordin = 3;
	static int numar_operatori;
public:
	Putere(Element s, Element d) :Operatie(s, d) {}

	Element& operatie() {
		numar_operatori++;
		Element rez;

		float nr = 1;
		for (int i = 0; i < Operatie::operand_d.getElementNumber(); i++) {
			nr *= Operatie::operand_s.getElementNumber();
		}
		
		rez.setElementNumber(nr);
		return rez;
	}
	static int getNumarAparitiiPutere() {
		return numar_operatori;
	}
	int getOrdin() {
		return ordin;
	}
	bool operator==(int nr) {
		if (pow(operand_s.getElementNumber(), operand_d.getElementNumber() == nr)) return true;
		else return false;
	}

	bool operator!=(int nr) {
		if (pow(operand_s.getElementNumber(), operand_d.getElementNumber() != nr)) return true;
		else return false;
	}
};
int Putere::numar_operatori = 0;

class Radical : public Operatie {
private:
	const int ordin = 3;
	static int numar_operatori;
public:
	Radical(Element s, Element d) :Operatie(s, d) {}

	Element& operatie() {
		numar_operatori++;
		Element rez;
		if (Operatie::operand_s.getElementNumber() == 0 || Operatie::operand_s.getElementNumber() == 1) rez.setElementNumber(Operatie::operand_s.getElementNumber());

		int i = 1, result = 1;
		while (result <= Operatie::operand_s.getElementNumber())
		{
			i++;
			result = pow(i, Operatie::operand_d.getElementNumber());
		}

		rez.setElementNumber(i - 1);
		return rez;
	}
	static int getNumarAparitiiPutere() {
		return numar_operatori;
	}
	int getOrdin() {
		return ordin;
	}

	bool operator==(int nr) {
		Radical rad(operand_s, operand_d);
		if ((float)rad.operatie() == nr) return true;
		else return false;
	}

	bool operator!=(int nr) {
		Radical rad(operand_s, operand_d);
		if ((float)rad.operatie() != nr) return true;
		else return false;
	}
};
int Radical::numar_operatori = 0;

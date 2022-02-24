#pragma once
#include<iostream>

using namespace std;

class Element {
private:
	float numar=0;
	char _operator;
public:
	Element() :_operator('$') {}

	void setElementChar(char c) {
		try {
			bool ok = false;
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#' || c == '.' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') this->_operator = c;
		
			else throw(c);     
		}
		catch (char c) {
			cout << "Caracter incorect !";
		}
	}
	

	void setElementNumber(float nr) {
			this->numar = nr;
	}

	char getElementChar() {
		return this->_operator;
	}

	float getElementNumber() {
		return this->numar;
	}

	operator float() {
		return this->numar;
	}

	operator int() {
		return (int)this->numar;
	}

	operator char() {
		return this->_operator;
	}


	Element operator=(float nr) {
		Element temp;
		temp.numar = nr;
		return temp;
	}

	Element operator=(char ch) {
		Element temp;
		temp._operator = ch;
		return temp;
	}

	bool esteNumar(Element el) {
		if (el.getElementChar() == '$') return true;
		else return false;
	}

	bool esteOperator(Element el) {
		if (el.getElementChar() != '$') return true;
		else return false;
	}

	friend ostream& operator<<(ostream&, Element&);
	friend istream& operator>>(istream&, Element&);
};

ostream& operator<<(ostream& out, Element& el) {
	if (el._operator == '$') out << el.getElementNumber();
	else out << el.getElementChar();
	return out;
}

istream& operator>>(istream& in, Element& el) {
	string temp;
	int numar = 0;

	in >> temp;
	if (((int)(temp[0]) >= 48) && (int)(temp[0]) <= 57) {
		for (int i = 0; i < temp.size(); i++) {
			numar += ((int)(temp[i]) - 48);
			numar *= 10;
		}
		el.numar = numar / 10;
	}
	else el._operator = temp[0];

	return in;
}
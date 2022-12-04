#include <iostream>
#include <math.h>
#include <clocale>

using namespace std;

class Vec{
    double* Vector;
	int num;   
	int state = 0;

public:
    Vec() : Vec(1) {}
	Vec(int n);
	Vec(int n, double b);
	Vec(int n, int p);
	Vec& operator = (const Vec& s);
	~Vec() {
		cout << " Vector was deleted !!! \n";
		if (Vector) delete[] Vector;
	}

    void SetX();
	int GetX();
	void AddX();
	void SubtractionX();
	void MultiplicationX();
	void DivisionX();
	void ComparisonX1();
	void ComparisonX2();
	void ComparisonX3();
	void Output();

};

Vec::Vec(int n) {
	if (n <= 0) n = 1;
	num = n;
	Vector = new double[n];
	for (int i = 0; i < n; i++) {
		Vector[i] = 0.0;
	}
}

Vec::Vec(int n, double b) : Vec(n) {
	for (int i = 0; i < num; i++) {
		Vector[i] = b;
	}
}

Vec::Vec(int n, int p) : Vec(n) {
	for (int i = 0; i < num; i++)
		Vector[i] = p;
}

Vec& Vec::operator=(const Vec& s) {
	if (num != s.num)
	{
		if (Vector) delete[] Vector;
		num = s.num;
		Vector = new double[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   
    Vector[i] = s.Vector[i];

	return *this;
}

void Vec::SetX() {
	int n, x;
	do {
		cout << "Enter N (in which position) and X (what number to change to): ";
		cin >> n >> x;
		if (n<0 || n>num) {
			state = 1;
			cout << "ERROR";
		}
	} while (n<0 || n>num);
	state = 0;

	Vector[n] = x;
}

int Vec::GetX() {
	int n;
	do {
		cout << "Enter N from which position you want to extract the element: ";
		cin >> n;
	} while (n<0 || n>num);

	return Vector[n];
}

void Vec::AddX() {
	int x;
	cout << "Enter X - which should be added: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vector[i] += x;
	}
}

void Vec::SubtractionX() {
	int x;
	cout << "Enter X - what number should be subtracted: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vector[i] -= x;
	}
}

void Vec::MultiplicationX() {
	double x;
	cout << "Enter X - what number should be multiplied: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vector[i] *= x;
	}
}

void Vec::DivisionX() {
	double x;
	cout << "Enter X - what number should be divided: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vector[i] /= x;
	}
}

void Vec::ComparisonX1() {
	cout << "We compare the value of the vector, if it is equal to the number 50 \n";
	
	for (int i = 0; i < num; i++) {
		if (Vector[i] == 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}

void Vec::ComparisonX2() {
	cout << "We compare the value of the vector, if it is greater than the number 50 \n";

	for (int i = 0; i < num; i++) {
		if (Vector[i] >= 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}

void Vec::ComparisonX3() {
	cout << "We compare the value of the vector, if it is less than the number 50 \n";

	for (int i = 0; i < num; i++) {
		if (Vector[i] <= 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}

void Vec::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v[" << i << "] = " << Vector[i] << endl;
		}
	}
}

int main(){
	int a;
	Vec B;
	Vec P1, P2(5), P3(5, 12);
	cout << " - конструктор без параметрів \n";
	P1.Output();
	cout << " - конструктор з одним параметром \n";
	P2.Output();
	cout << " - конструктор із двома параметрами \n";
	P3.Output();
	cout << " Введіть число а: ";
	cin >> a;
	Vec P4(6, a);
	P4.Output();
	cout << " - конструктор копій та операцію присвоєння \n";
	B = P4;
	B.Output();
	cout << " - функцію, яка присвоює елементу масиву деяке значення \n";
	P4.SetX();
	P4.Output();
	cout << " - функцію яка одержує деякий елемент масиву; \n";
	cout << " Значення в позиції N: " << P4.GetX();
	cout << '\n';
	cout << " - функція додавання; \n";
	P4.AddX();
	P4.Output();
	cout << " - функція віднімання; \n";
	P4.SubtractionX();
	P4.Output();
	cout << " - функція множення; \n";
	P4.MultiplicationX();
	P4.Output();
	cout << " - функція ділення; \n";
	P4.DivisionX();
	P4.Output();
	cout << " - функція порівняння; \n";
	P4.ComparisonX1();
	P4.ComparisonX2();
	P4.ComparisonX3();

	return 1;
}
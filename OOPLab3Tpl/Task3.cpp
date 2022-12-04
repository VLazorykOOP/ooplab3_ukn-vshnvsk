#include <iostream>
#include <math.h>
#include <clocale>

using namespace std;

class Matrix{
    double* Matr;
	int row;
	int column;
	int state = 0;

public:
	Matrix();
	Matrix(int n);
	Matrix(int n, int m, double x);
	Matrix& operator = (const Matrix& s);
	void setX(double x);
	double getX();
	void MultiplicationX();
	void AddX(Matrix& A);
	void SubtractionX(Matrix& A);
	void CalculationX1(Matrix& A);
	void CalculationX2(Matrix& A);
	void CalculationX3(Matrix& A);
	~Matrix() {
		cout << " Matrix was deleted !!! \n";
		if (Matr) delete[] Matr;
	}
	void Output();
};

Matrix::Matrix() {
	row = 4;
	column = 3;
	Matr = new double[row * column];
	for (int i = 0; i < row * column; i++) {
		Matr[i] = 0;
	}
}

Matrix::Matrix(int n) {
	if (n < 0 || n > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		row = n;
		column = n;
		Matr = new double[row * column];
		for (int i = 0; i < row * column; i++) {
			Matr[i] = 0;
		}
	}
}

Matrix::Matrix(int n, int m, double x) {
	if (n < 0 || n > 1.e+100 || m < 0 || m > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		row = n;
		column = m;
		Matr = new double[row * column];
		for (int i = 0; i < row * column; i++) {
			Matr[i] = x;
		}
	}
}

Matrix& Matrix::operator=(const Matrix& s) {
	if (Matr) delete[] Matr;
	row = s.row;
	column = s.column;
	Matr = new double[row * column];
	for (int i = 0; i < row * column; i++) {
		Matr[i] = s.Matr[i];
	}
	return *this;
}

void Matrix::setX(double x = 10) {
	int z, y;
	cout << "Enter the values ​​of n and m to which element to set the default value: ";
	cin >> z >> y;
	if (z < 0 || z > row || y < 0 || y > column)
		cout << " ERROR !!!\n";
	else {
		Matr[z * column + y] = 10;
	}
}
double Matrix::getX() {
	int z, y;
	cout << "Enter the value of n and m from which place you want to get the value: ";
	cin >> z >> y;
	if (z < 0 || z > row || y < 0 || y > column)
		cout << " ERROR !!!\n";
	else {
		return Matr[z * column + y];
	}
}

void Matrix::MultiplicationX(){
	double z;
	cout << "Enter the value you want to multiply by: ";
	cin >> z;

	for (int i = 0; i < row * column; i++) {
		Matr[i] *= z;
	}
}

void Matrix::AddX(Matrix& A) {
	if(A.row != row || A.column != column)
		cout << " ERROR !!!\n";
	else {
		for (int i = 0; i < row * column; i++) {
			Matr[i] += A.Matr[i];
		}
	}
}

void Matrix::SubtractionX(Matrix& A) {
	if (A.row != row || A.column != column)
		cout << " ERROR !!!\n";
	else {
		for (int i = 0; i < row * column; i++) {
			Matr[i] -= A.Matr[i];
		}
	}
}

void Matrix::CalculationX1(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.column; i++) {
		x = x + A.Matr[i];
	}
	for (int i = 0; i < row * column; i++) {
		y = y + Matr[i];
	}
	if (x == y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}

void Matrix::CalculationX2(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.column; i++) {
		x = x + A.Matr[i];
	}
	for (int i = 0; i < row * column; i++) {
		y = y + Matr[i];
	}
	if (x >= y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}

void Matrix::CalculationX3(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.column; i++) {
		x = x + A.Matr[i];
	}
	for (int i = 0; i < row * column; i++) {
		y = y + Matr[i];
	}
	if (x <= y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}

void Matrix::Output() {
	if (row != 0 && column != 0) {
		for (int i = 0; i < row ; i++) {
			for (int j = 0; j < column; j++) {
				cout << "      " << Matr[i * column + j];
			}
			cout << "\n";
		}
	}
}

int main(){
    Matrix B1;
	Matrix M1, M2(10), M3(5, 4, 25), M4(5, 4, 80), M5(5, 4, 200);
	cout << "Матриця 4 на 3 заповнена нулями: \n";
	M1.Output();
	cout << "Матриця n на n заповнена нулями: \n";
	M2.Output();
	cout << "Матриця n на m заповнена значенням value(x): \n";
	M3.Output();
	B1 = M3;
	cout << "Матриця B1: \n";
	B1.Output();
	cout << "Матриця яка приймає параметр по замовчуванню: \n";
	M3.setX();
	M3.Output();
	cout << "Матриця яка приймає параметр по замовчуванню: " << M3.getX() << "\n";
	cout << "Множення матриці на число: \n";
	M3.MultiplicationX();
	M3.Output();
	cout << "Додавання двох матриць: \n";
	M3.AddX(M4);
	M3.Output();
	cout << "Віднімання двох матриць: \n";
	M3.SubtractionX(M5);
	M3.Output();
	cout << "Порівняння двох матриць: \n";
	M3.CalculationX1(M5);
	M3.CalculationX2(M5);
	M3.CalculationX3(M5);

	Matrix Q1(-10), Q2(-4, 3, 20), Q3(4, -3, 20);
	M1.setX();
	M1.getX();
	Matrix Q4(9, 5, 25);
	M3.AddX(Q4);
	M3.SubtractionX(Q4);

	return 0;
}
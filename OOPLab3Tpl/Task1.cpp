#include <iostream>
#include <math.h>
#include <clocale>

using namespace std;

class Rectangle{
    double h;  //height
    double w;  //width
    unsigned int color;

public:
    Rectangle() : h(2.0), w(3.0), color(0){}
    Rectangle(double hi, double wi) : h(hi), w(wi), color(0){}
    Rectangle(unsigned int c) : h(2.0), w(3.0){if (c>=0) color = c; else color = 0;}
    Rectangle(double hi, double wi, int c) {
		if (hi < 0 || hi > 1.e+100) {
			cout << " Error input height !!! \n";
			h = 1;
		}
		else
			h = hi;

		if (wi < 0 || wi > 1.e+100) {
			cout << " Error input height !!! \n";
			w = 1;
		}
		else
			w = wi;

		if (c < 0 || c > 10000) {
			cout << " Error input height !!! \n";
			color = 0;
		}
		else
			color = c;

		return;
	}

    double getHeight() const 
    {
		return h;
	}

	double getWidth() const 
    {
		return w;
	}

	double getColor() const 
    {
		return color;
	}

    void setHeight(double h) {
		if (h < 0 || h > 1.e+100) {
			cout << " Error input height !!! \n";
			return;
		}
		this->h = h;
	}

	void setWidth(double w) {
		if (w < 0 || w > 1.e+100) {
			cout << " Error input width !!! \n";
			return;
		}
		this->w = w;
	}

    void setColor(int col) {
		if (col < 0 || col > 10000) {
			cout << " Error set color !!! \n";
			return;
		}
		this->color = col;
	}

	double Square() {
		return h * w;
	}
	double Perimetr() {
		return 2 * h + 2 * w;
	}
	void printInfo() {
		cout << " height = " << h << " width = " << w << " color = " << color << endl;
		cout << " S = " << Square() << " P = " << Perimetr() << endl;
	}
};

int main(){
    Rectangle obj;
	obj.printInfo();
	double in_h; double in_w; int in_c;
	cout << " Input height, width, color Rectangle  "; cin >> in_h >> in_w >> in_c;
	Rectangle obj1(in_h), obj2(in_w), obj3(in_c), obj4(in_h, in_w, in_c);
	cout << " 1: " << endl;
	obj1.printInfo();
	cout << " 2: " << endl;
	obj2.printInfo();
	cout << " 3: " << endl;
	obj3.printInfo();
	cout << " 4: " << endl;
	obj4.printInfo();
	cout << " 5: " << endl;
	obj.setHeight(-15);
	obj.printInfo();
	cout << " 6: " << endl;
	obj.setHeight(50);
	obj.printInfo();
	cout << " 7: " << endl;
	obj.setHeight(2.e100);
	obj.printInfo();
	cout << " 8: " << endl;
	obj.setWidth(-15);
	obj.printInfo();
	cout << " 9: " << endl;
	obj.setWidth(50);
	obj.printInfo();
	cout << " 10: " << endl;
	obj.setWidth(2.e100);
	obj.printInfo();
	cout << " 11: " << endl;
	obj.setColor(-20);
	obj.printInfo();
	cout << " 12: " << endl;
	obj.setColor(100);
	obj.printInfo();
	cout << " 13: " << endl;
	obj.setColor(10001);
	obj.printInfo();

	cout << "\n End testing \n";

	return 0;
}
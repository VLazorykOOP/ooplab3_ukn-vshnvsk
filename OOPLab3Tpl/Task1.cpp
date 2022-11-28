#include <iostream>
#include <math.h>
#include <clocale>

using namespace std;

class Rectangle{
    double h;
    int w;
    unsigned int color;

public:
    Rectangle(){h = 0; w = 0; color = 0;};
    Rectangle(unsigned int c){h = 0; w = 0; color = c;};

    double Square(){
        cout << "Square:"<< h*w << endl;
        return h*w;
    }
};

int main(){
    Rectangle obj;
    obj.Square();

    return 0;
}
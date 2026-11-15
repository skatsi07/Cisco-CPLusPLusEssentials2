#include <iostream>

using namespace std;
class negative_input : public exception {
    public:
        negative_input() {}
        ~negative_input() {}
        void print() {
            cout << "Negative input is not allowed!" << endl;
        }
};

//add functions code here
float square_area(float a) {
    if (a <= 0){
        throw negative_input();

    }
    return a * a;
}
float rectangle_area(float a, float b) {
    if (a <= 0 || b <= 0){
        throw negative_input();
    }
    return a * b;
}


int main(void) {
	float a, b, r;
	cin >> a;
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a,b);
		cout << rsquare << endl << rrectangle << endl;
	} catch (negative_input &e) {
        e.print();
    }

	return 0;
}
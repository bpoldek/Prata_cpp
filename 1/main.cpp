#include <iostream>

int main()
{
    using namespace std;

    double * p3 = new double[3];
    p3[0] =0.2;
    p3[1]= 0.5;
    p3[2]= 0.8;

    cout << "p3[0] to: "<< p3[0] << endl;
    cout << "p3[1] to: "<< p3[1] << endl;
    cout << "p3[2] to: "<< p3[2] << endl;
    p3 = p3 +1;
    cout << "p3 =p3 + p3" << endl;
    cout << "p3[0] to: "<< p3[0] << endl;
    cout << "p3[1] to: "<< p3[1] << endl;
    cout << "p3[2] to: "<< p3[2] << endl;
    p3 = p3 - 1;
    cout << "p3 =p3 - p3" << endl;
    cout << "p3[0] to: "<< p3[0] << endl;
    cout << "p3[1] to: "<< p3[1] << endl;
    cout << "p3[2] to: "<< p3[2] << endl;
    return 0;
}

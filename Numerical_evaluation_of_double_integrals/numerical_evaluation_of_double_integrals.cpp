#include <iostream>
#include <math.h>
using namespace std;

/*float f(float x, float y)
{
    return sqrt(3 * x * y + 2);
}*/

/*float f(float x, float y)
{
    return sqrt(x * y - y * y);
}*/

/*float f(float x, float y)
{
    return (x * y - 1) / (x * x + y * y + 1);
}*/

float f(float x, float y)
{
    return y / ((x * y + 1) * x);
}

int main()
{
    float x1, y1, x2, y2, x3, y3;
    float x4, y4;
    float lungime_latura1, lungime_latura2, lungime_latura3;
    float semiperimetru;
    float aria;
    float valoare_integrala;
    //cout << "Functia este sqrt(3xy-2)^(1/2)" << endl;
    //cout << "Functia este sqrt (xy-y^2)^(1/2)" << endl;
    //cout << "Functia este (xy-1)/x^2+y^2+1 cu x intre 2 si 4 si y intre 1 si 2" << endl;
    cout << "Functia este y/(xy+1)x" << endl; 
    cout << "Introduceti coordonata x a primului varf: ";
    cin >> x1;
    cout << "Introduceti coordonata y a primului varf: ";
    cin >> y1;
    cout << "Introduceti coordonata x a celui de-al doilea varf: ";
    cin >> x2;
    cout << "Introduceti coordonata y a celui de-al doilea varf: ";
    cin >> y2;
    cout << "Introduceti coordonata x a celui de-al treilea varf: ";
    cin >> x3;
    cout << "Introduceti coordonata y a celui de-al treilea varf: ";
    cin >> y3;
    cout << "Introduceti coordonata x a celui de-al patrulea varf: ";
    cin >> x4;
    cout << "Introduceti coordonata y a celui de-al patrulea varf: ";
    cin >> y4;

    lungime_latura1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    lungime_latura2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    lungime_latura3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    semiperimetru = (lungime_latura1 + lungime_latura2 + lungime_latura3) / 2;

    aria = sqrt(semiperimetru * (semiperimetru - lungime_latura1) * (semiperimetru - lungime_latura2) * (semiperimetru - lungime_latura3));

    valoare_integrala = (aria / 12) * (f(x1, y1) + f(x2, y2) + f(x3, y3) + 9 * f((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3));

    lungime_latura1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    lungime_latura2 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
    lungime_latura3 = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

    semiperimetru = (lungime_latura1 + lungime_latura2 + lungime_latura3) / 2;

    aria = sqrt(semiperimetru * (semiperimetru - lungime_latura1) * (semiperimetru - lungime_latura2) * (semiperimetru - lungime_latura3));

    valoare_integrala += (aria / 12) * (f(x1, y1) + f(x3, y3) + f(x4, y4) + 9 * f((x1 + x3 + x4) / 3, (y1 + y3 + y4) / 3));

    cout << "Valoarea integralei este: " << valoare_integrala;


    
}



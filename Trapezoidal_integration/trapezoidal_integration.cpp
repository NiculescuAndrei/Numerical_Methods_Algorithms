#include <iostream>
#include<math.h>
using namespace std;

/*float f(float x)
{
    return 1. / (x + 1);
}*/

/*float f(float x) {
    if (x >= -1 && x < 0)
        return 0.4 * pow((1 + x), 3) + 0.6 * (1 + x) - 5 * x;
    if (x >= 0 && x <= 1)
        return 1 / (1 + x);
}*/

float f(float x)
{
    return exp(pow(x,2));
}

int main()
{
    float a, b, eps;
    float h;
    float integrala_aux;
    int numar_pasi = 1;
   // cout << "f(x) = 1/(x+1)" << endl;
   // cout << "f(x) = 0.4(x+1)^3 + 0.6(x+1) - 5x pentru x in intervalul [-1,0)" << endl;
   // cout << "f(x) = 1/(x+1) pentru x in intervalul [0,1]" << endl;
    cout << "f(x) = e^x^2" << endl;
    cout << "Introduceti valoarea lui a: ";
    cin >> a;
    cout << "Introduceti valoarea lui b: ";
    cin >> b;
    cout << "Introduceti precizia cu care vreti sa aproximati integrala: ";
    cin >> eps;

    int n = 1;
    float integrala = (f(a) + f(b)) * (b - a) / 2;

    do
    {
        numar_pasi++;
        n = 2 * n;
        h = (b - a) / n;
        integrala_aux = integrala;
        float s = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            s += f(a + i * h);
        }
        integrala = (f(a) + 2 * s + f(b)) * h / 2;
    } while (fabs(integrala - integrala_aux) > eps);

    cout << "Valoarea integralei, obtinuta cu precizia " << eps << " in " << numar_pasi << " pasi este " << integrala << endl;

}



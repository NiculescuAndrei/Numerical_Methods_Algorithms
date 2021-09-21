#include <iostream>
#include<math.h>
using namespace std;

/*float f(float x)
{
    return 1. / (x + 1);
}*/

float f(float x)
{
    return pow((x * x + exp(1)), 1. / 4);
}

int main()
{
    float a, b, eps;
    float h;
    float integrala_aux;
    int numar_pasi = 1;
    // cout << "f(x) = 1/(x+1)" << endl;
    cout << "f(x) = (x^2 + e)^1/4" << endl;
    
    cout << "Introduceti valoarea lui a: ";
    cin >> a;
    cout << "Introduceti valoarea lui b: ";
    cin >> b;
    cout << "Introduceti precizia cu care vreti sa aproximati integrala: ";
    cin >> eps;

    int n = 1;
    float integrala = (f(a) + 4*f((a+b)/2) + f(b)) * (b - a) / 6;

    do
    {
        numar_pasi++;
        n = 2 * n;
        h = (b - a) / n;
        integrala_aux = integrala;

        float s1 = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            s1 += f(a + i * h);
        }

        float s2 = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            s2 += f(a + i * h + h / 2);
        }

        integrala = (f(a) + 2 * s1 + 4 * s2 + f(b)) * h / 6;
    } while (fabs(integrala - integrala_aux) > eps);

    cout << "Valoarea integralei, obtinuta cu precizia " << eps << " in " << numar_pasi << " pasi este " << integrala << endl;

}



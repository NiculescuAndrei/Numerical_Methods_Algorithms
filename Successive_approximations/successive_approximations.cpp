#include <iostream>
#include <math.h>
using namespace std;

float g(float x)
{
    return pow(x, 1. / 4) + 2;
}

int main()
{
    float x0, x1, dif, eps = 0.004;
    int itmax;
    int it = 0;

    cout << "Introduceti numarul de iteratii in care vreti sa aflati solutia aproximata: " << endl;
    cin >> itmax;

    cout << "\nIntroduceti aproximatia initiala a solutiei exacte: " << endl;
    cin >> x0;

    do
    {
        x1 = g(x0);
        dif = fabs(x1 - x0);
        x0 = x1;
        it++;
    } while (dif > eps && it <= itmax);

    if (it > itmax)
    {
        cout << "\nNu se poate obtine solutia in " << itmax << " iteratii cu precizia " << eps << endl;
        return 0;
    }

    cout << "\nSolutia pentru ecuatia x = pow(x, 1./4) + 2  cu contractia pow(x, 1./4) + 2, obtinuta in " << it << " iteratii cu precizia " << eps << " este " << x1 << endl;

}

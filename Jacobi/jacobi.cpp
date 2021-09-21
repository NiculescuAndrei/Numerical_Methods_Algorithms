#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    int itmax;
    int count = 0;

    float a[10][10];
    float b[10];
    float x[10] = { 0 };
    float y[10];

    bool dominant_diagonala_linii = false;
    bool dominant_diagonala_coloane = false;

    float eps = 0.0001;
    float sum;
    float max;

    cout << "Introduceti ordinul matricei: ";
    cin >> n;

    // Citire matrice
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Introduceti elementul a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "Introduceti numarul de iteratii in care vreti sa aflati solutia sistemului: " << endl;
    cin >> itmax;
    
    cout << endl;
    // Citire coloana de termeni liberi
    for (int i = 0; i < n; i++)
    {
        cout << "Introduceti elementul b[" << i << "]: ";
        cin >> b[i];
    }

    // Verificare matrice domimant diagonala pe linii
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum += fabs(a[i][j]);
            }
        }
        if (fabs(a[i][i]) >= sum)
        {
            count++;
        }
    }
    if (count < n)
    {
        cout << "\nMatricea nu este dominant diagonala pe linii" << endl;
    }
    else
    {
        // Verificare matrice strict domimant diagonala pe linii
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += fabs(a[i][j]);
                }
            }
            if (fabs(a[i][i]) > sum)
            {
                cout << "\nMatricea este strict dominant diagonala pe linii" << endl;
                dominant_diagonala_linii = true;
                break;
            }
            else
            {
                if (i == n - 1)
                {
                    cout << "\nMatricea este dominant diagonala pe linii" << endl;
                }
            }
        }
    }

    count = 0;

    // Verificare matrice domimant diagonala pe coloane
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum += fabs(a[j][i]);
            }
        }
        if (fabs(a[i][i]) >= sum)
        {
            count++;
        }
    }
    if (count < n)
    {
        cout << "\nMatricea nu este dominant diagonala pe coloane" << endl;
    }
    else
    {
        // Verificare matrice strict domimant diagonala pe coloane
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += fabs(a[i][j]);
                }
            }
            if (fabs(a[i][i]) > sum)
            {
                cout << "\nMatricea este si strict dominant diagonala pe coloane" << endl;
                dominant_diagonala_coloane = true;
                break;
            }
            else
            {
                if (i == n - 1)
                {
                    cout << "\nMatricea este dominant diagonala pe coloane" << endl;
                }
            }
        }
    }

    if (dominant_diagonala_linii == true || dominant_diagonala_coloane == true)
    {
        cout << "\nPutem aplica metoda Jacobi pentru aceasta matrice!" << endl;
    }
    else
    {
        cout << "\nNu se poate obtine solutia sistemului deoarece matricea nu este strict dominant diagonala pe linii sau coloane"<<endl;
        return 0;
    }

    int it = 0;

    do
    {
        max = 0;

        // Calculam elementele vectorului x la pasul k+1 in functie de cele de la pasul k si le stocam in y
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += a[i][j] * x[j];
                }
            }
            y[i] = (b[i] - sum) / a[i][i];
        }

        // Calculam distana maxima dintre elementele vectorului la pasul k+1 si k.
        for (int j = 0; j < n; j++)
        {
            if (max < fabs(y[j] - x[j]))
            {
                max = fabs(y[j] - x[j]);
            }
        }
        cout << "\nLa iteratia " << it + 1 << " max este = " << max;

        for (int i = 0; i < n; i++)
        {
            x[i] = y[i];
        }

        it++;

    } while (max > eps && it <= itmax);

    if (it > itmax)
    {
        cout << "\nNu se poate obtine solutia in " << itmax << " iteratii, cu precizia " << eps << endl;
        return 0;
    }

    cout << "\nSolutia obtinuta in " << it << " iteratii, cu precizia " << eps << " este: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }


}


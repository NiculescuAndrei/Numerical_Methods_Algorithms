#include <iostream>

using namespace std;

int main()
{
    int n;
    float det = 1;
    float a[10][10];

    cout << "Introduceti ordinul matricei careia vreti sa ii calculati determinantul: ";
    cin >> n;

    // Citire elemente matrice
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Introduceti elementul a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "\nMatricea careia vreti sa-i calculati determinantul este: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
   

    do
    {
        // Verificare element nenul pentru a interschimba liniile daca este cazul
        if (a[0][0] == 0)
        {
            int i = 1;
            
            while (i <= n  && a[i][0] == 0)
            {
                i = i + 1;
            }

            // Daca i parcurge toata coloana fara sa gaseasca vreun element nenul inseamna ca determinantul este 0
            if (i >= n)
            {
                cout << "det(A) = 0" << endl;
                return 0;
            }

            // Interschimbare linii 0 si i
            for (int j = 0; j <= n - 1; j++)
            {
                float aux = a[0][j];
                a[0][j] = a[i][j];
                a[i][j] = aux;
            }

            cout << "\nDeterminantul dupa interschimbarea liniilor 0 si " << i << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << a[i][j] << "   ";
                }
                cout << endl;
            }

            det = -det;
        }

        // Calculare produs a[0][0]^(n-2)
        for (int i = 1; i <= n - 2; i++)
        {
            det = det * a[0][0];
        }

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= n - 1; j++)
            {
                a[i][j] = a[0][0] * a[i][j] - a[i][0] * a[0][j];
            }
        }

        n--;

        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                a[i][j] = a[i + 1][j + 1];
            }
        }

        cout << "\nDeterminantul dupa calculul determinantului de ordinul " << n + 1 << " este: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << "   ";
            }
            cout << endl;
        }

    } while (n != 1);

    cout << "\ndet(A) = " << a[0][0] << "/" << det;
    det = a[0][0] / det;
    cout << " = " << det << endl;

    return 0;
}



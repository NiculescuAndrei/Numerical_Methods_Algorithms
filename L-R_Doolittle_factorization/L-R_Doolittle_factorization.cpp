#include <iostream>
using namespace std;

int main()
{
    float a[10][10];
    int n;
    float aux;
    float piv;
    float s;

    cout << "Introduceti ordinul matricii: ";
    cin >> n;

    // Citire elemente matrice extinsa
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "Introduceti elementul a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    // Afisare matrice initiala
    cout << "\nMatricea initiala este: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }

    // Daca a[0][0] este 0 cautam un element nenul pe liniile de sub el.
    if (a[0][0] == 0)
    {
        int i = 0;
        
        do
        {
            i = i + 1;
        } while (a[i][0] == 0 && i <= n-1);

        if (i >= n)
        {
            cout << "Sistemul nu are solutie unica";
            return 0;
        }

        for (int j = 0; j <= n; j++)
        {
            aux = a[0][j];
            a[0][j] = a[i][j];
            a[i][j] = aux;
        }
    }

    // Calculam prima coloana din L
    for (int i = 1; i <= n - 1; i++)
    {
        a[i][0] = a[i][0] / a[0][0];
    }

    cout << "\nDupa ce calculam prima coloana din L" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n - 1; k++)
    {
        int i = k;

        // Verificam ca pivotul sa nu fie 0 pentru a nu imparti mai departe la el ( la 0 ).
        do
        {
            s = 0;
            piv = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[i][h] * a[h][k];
            }

            piv = a[i][k] - s;
            i = i + 1;
        } while (piv == 0 && i <= n - 1);

        if (piv == 0)
        {
            cout << "Sistemul nu are solutie unica";
            return 0;
        }

        if (i != k + 1)
        {
            for (int j = 0; j <= n; j++)
            {
                aux = a[k][j];
                a[k][j] = a[i - 1][j];
                a[i - 1][j] = aux;
            }

            cout << "\nDupa permutarea liniei " << i - 1 << " cu linia " << k << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << a[i][j] << "   ";
                }
                cout << endl;
            }
        }
        
        // Calculam linia k+1 din R
        for (int j = k; j <= n - 1; j++)
        {
            s = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[k][h] * a[h][j];
            }

            a[k][j] = a[k][j] - s;
        }

        cout << "\nDupa ce calculam linia " << k + 1 << " din R " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << a[i][j] << "   ";
            }
            cout << endl;
        }

        // Calculam coloana k+1 din L
        for (int i = k + 1; i <= n - 1; i++)
        {
            s = 0;

            for (int h = 0; h <= k - 1; h++)
            {
                s = s + a[i][h] * a[h][k];
            }

            a[i][k] = (a[i][k] - s) / a[k][k];
        }

        cout << "\nDupa ce calculam coloana " << k + 1 << " din L " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << a[i][j] << "   ";
            }
            cout << endl;
        }
    }

    cout << "\nMatricea L este: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << '1' << "   ";
            }
            else if (i > j)
            {
                cout << a[i][j] << "   ";
            }
            else
            {
                cout << '0' << "   ";
            }
        }
        cout << endl;
    }

    cout << "\nMatricea R este: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                cout << '0' << "   ";
            }
            else
            {
                cout << a[i][j] << "   ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        s = 0;
        for (int k = 0; k <= i - 1; k++)
        {
            s = s + a[i][k] * a[k][n];
        }
        a[i][n] = a[i][n] - s;
    }

    cout << "\nDupa ce rezolvam sistemul L*y = b obtinem coloana y de forma: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "y" << i << " = " << a[i][n] << endl;
    }

    a[n - 1][n] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        s = 0;
        for (int j = n - 1; j >= i + 1; j--)
        {
            s = s + a[i][j] * a[j][n];
        }

        a[i][n] = (a[i][n] - s) / a[i][i];
    }

    cout << "\nDupa ce rezolvam sistemul R * x = Y obtinem coloana y de forma: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i << " = " << a[i][n] << endl;
    }
}


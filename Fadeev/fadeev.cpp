#include <iostream>
using namespace std;
int main()
{
    int n;
    float a[10][10], b[10][10], d[10][10];
    float c[10];

    cout << "Introduceti ordinul matricei: ";
    cin >> n;

    // Citim elementele matricei input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Introduceti elementul a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Initializam matricea B cu matricea unitate In
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= n - 1; k++)
    {
        // Calculam Ak, folosind Ak = A * Bk-1, si notam D = Ak
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = 0;
                for (int h = 0; h < n; h++)
                {
                    d[i][j] = d[i][j] + a[i][h] * b[h][j];
                }
            }
        }

        // calculam ck, folosind ck = -Tr(Ak)/k
        c[k - 1] = 0;
        for (int i = 0; i < n; i++)
        {
            c[k - 1] += d[i][i];
        }
        c[k - 1] = -(c[k - 1] / k);

        // calculam Bk, folosind Bk = ck * In + Ak
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    b[i][j] = d[i][j] + c[k - 1];
                }
                else
                {
                    b[i][j] = d[i][j];
                }
            }
        }
    }

    // Calculam An = D
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = 0;
            for (int h = 0; h < n; h++)
            {
                d[i][j] = d[i][j] + a[i][h] * b[h][j];
            }
        }
    }

    // Calculam cn = -Tr(An)/n
    c[n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        c[n - 1] = c[n - 1] + d[i][i];
    }
    c[n - 1] = -(c[n - 1] / n);

    if (c[n - 1] == 0)
    {
        cout << "\nMatricea nu este inversabila" << endl;
    }
    else
    {
        cout << "\nMatricea este inversabila" << endl;;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << -b[i][j] / c[n - 1] << "   ";
            }
            cout << endl;
        }
    }

    cout << "\nCoeficientii polinomului caracteristic sunt: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "c" << i << " = " << c[i] << endl;
    }



}

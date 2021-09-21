#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a[10][10];
    int n;
    float eps = 0.00001;
    float piv, aux;
    int lin, col;
    int npc = 0;
    int vector1[10] = { 0 };
    int vector2[10] = { 0 };

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
    cout << "Matricea initiala este: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }

    // Alegerea pivotului de n-1 ori
    for (int k = 0; k < n - 1; k++)
    {
        piv = fabs(a[k][k]);
        lin = k;
        col = k;

        // Cautam elementul din matricea care incepe cu elementul a[k][k] care are valoarea maxima in modul 
        for (int i = k; i < n; i++)
        {
            for (int j = k; j < n; j++)
            {
                if (piv < fabs(a[i][j]))
                {
                    piv = fabs(a[i][j]);
                    lin = i;
                    col = j;
                }
            }
        }

        if (piv <= eps)
        {
            cout << "Sistemul nu are solutie unica";
            return 0;
        }

        cout << "\nPivotul la pasul " << k << " are modulul " << piv << " care este pe linia " << lin << " si coloana " << col << endl;

        // Daca s-a gasit un element cu valoarea in modul mai mare decat pivotul ales initial, iar acesta se afla pe o alta linie, se interschimba liniile.
        if (lin != k)
        {
            for (int j = 0; j < n + 1; j++)
            {
                aux = a[k][j];
                a[k][j] = a[lin][j];
                a[lin][j] = aux;
            }
            cout << "\nDupa interschimbarea liniilor " << k << " si " << lin << " la pasul " << k << " matricea este: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << a[i][j] << "   ";
                }
                cout << endl;
            }
        }

        // Daca s-a gasit un element cu valoarea in modul mai mare decat pivotul ales initial, iar acesta se afla pe o alta coloana, se interschimba coloanele.
        if (col != k)
        {
            vector1[npc] = k;
            vector2[npc] = col;
            npc++;
            for (int i = 0; i < n; i++)
            {
                aux = a[i][k];
                a[i][k] = a[i][col];
                a[i][col] = aux;
            }
            cout << "\nDupa interschimbarea coloanelor " << k << " si " << col << " la pasul " << k << " matricea este: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << a[i][j] << "   ";
                }
                cout << endl;
            }
        }

        // Formula dreptunghiului pentru calculul elementelor de sub linia pivotului ( in afara de cele de sub coloana care sunt 0 )
        for (int i = k + 1; i < n; i++)
        {
            for (int j = k + 1; j < n + 1; j++)
            {
                a[i][j] = (a[k][k] * a[i][j] - a[i][k] * a[k][j]) / a[k][k];
            }
        }

        // Punem pe coloanele de sub pivot
        for (int coloana_pivot = k + 1; coloana_pivot < n; coloana_pivot++)
        {
            a[coloana_pivot][k] = 0;
        }

        // Afisare pentru a vizualiza evolutia matricii
        cout << "\nDupa pasul " << k << " matricea este: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << a[i][j] << "   ";
            }
            cout << endl;
        }
    }

    if (fabs(a[n - 1][n - 1]) <= eps)
    {
        cout << "Sistemul nu are solutie unica" << endl;
        return 0;
    }

    cout << "Dupa aplicarea metodei lui Gauss se obtine matricea: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }

    a[n - 1][n] = a[n - 1][n] / a[n - 1][n - 1];

    // Parcurgem liniile de la final spre inceput pentru a afla celelalte necunoscute
    for (int i = n - 2; i >= 0; i--)
    {
        float s = 0;
        // Parcurgem pozitiile de pe linia de unde calculam necunoscuta de la final pana la pozitia necunoscutei exclusiv
        // pentru a calcula suma produselor dintre coeficienti si necunoscute pe care le-am aflat anterior
        for (int j = n - 1; j >= i + 1; j--)
        {
            s = s + a[i][j] * a[j][n];
        }

        a[i][n] = (a[i][n] - s) / a[i][i];
    }

    if (npc != 0)
    {
        for (int i = npc - 1; i >= 0; i--)
        {
            aux = a[vector1[i]][n];
            a[vector1[i]][n] = a[vector2[i]][n];
            a[vector2[i]][n] = aux;
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i << " = " << a[i][n] << endl;
    }

    return 0;
}


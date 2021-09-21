#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a[10][10];
    float piv;
    int lin;
    float aux;
    int n;
    int numar_permutari = 0;

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
        piv = a[k][k];
        lin = k;
        
        // Cautam elementul din coloana cu pivotul care are valoarea maxima in modul 
        for (int i = k + 1; i < n; i++)
        {
            if (piv < fabs(a[i][k]))
            {
                piv = fabs(a[i][k]);
                lin = i;
            }
        }

        if (piv == 0)
        {
            cout << "Sistemul nu are solutie unica";
            return 0;
        }

        cout << "\nPivotul la pasul " << k << " are modulul " << piv << " care este pe linia " << lin << " si coloana " << k;

        // Daca s-a gasit un element cu valoarea in modul mai mare decat pivotul ales initial, iar acesta se afla pe o alta linie, se interschimba liniile.
        if (lin != k)
        {
            cout << "\nSe interschimba liniile " << k << " si " << lin;
            numar_permutari++;
            for (int j = 0; j < n + 1; j++)
            {
                aux = a[k][j];
                a[k][j] = a[lin][j];
                a[lin][j] = aux;
            }
            cout << "\nDupa interschimbarea liniilor la pasul " << k << " matricea este: " << endl;
        }
        else
        {
            cout << "\nElementul cu valoarea maxima este deja pe pozitia pivotului si nu este nevoie de nici o permutare!" << endl;
        }

        // Afisare pentru a vizualiza evolutia matricii
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << a[i][j] << "   ";
            }
            cout << endl;
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

    if (a[n - 1][n - 1] == 0)
    {
        cout << "Sistemul nu are solutie unica";
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

    // Afisare solutii
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i << " = " << a[i][n] << endl;
    }
    cout << "\nNumarul permutarilor efectuate este: " << numar_permutari << endl;
    return 0;

}



#include <iostream>
using namespace std;

int main()
{
    float a[10][10];
    int n;

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
        if (a[k][k] != 0)
        {
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

        }
        else
        {
            // Interschimbam linia care contine pivotul 0 cu prima linie care are un element nenul pe aceeasi coloana cu pivotul
            bool gasire_element_nenul = false;
            for (int contor_linie = k; contor_linie < n; contor_linie++)
            {
                int aux;
                // Daca gasim un element nenul pe aceeasi coloana cu pivotul interschimbam liniile element cu element
                if (a[contor_linie][k] != 0)
                {
                    gasire_element_nenul = true;
                    for (int contor_coloana = 0; contor_coloana <= n; contor_coloana++)
                    {
                        aux = a[k][contor_coloana];
                        a[k][contor_coloana] = a[contor_linie][contor_coloana];
                        a[contor_linie][contor_coloana] = aux;
                    }
                    break;
                }
            }

            if (gasire_element_nenul == false)
            {
                cout << "Sistemul nu are solutie unica" << endl;
                return 0;
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

    // Calculam ultima necunoscuta
    a[n-1][n] = a[n-1][n] / a[n-1][n-1];

    // Parcurgem liniile de la final spre inceput pentru a afla celelalte necunoscute
    for (int i = n - 2; i >= 0; i--)
    {
        int s = 0;
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

    return 0;
}


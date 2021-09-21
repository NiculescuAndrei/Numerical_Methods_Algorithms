#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a[10][10], y[10][10];
    int n;
    float piv;
    int lin;
    float aux;
    int numar_permutari = 0;
    bool este_solutie_unica = false;

    cout << "Introduceti ordinul matricei: ";
    cin >> n;

    // Matricea A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Introduceti elementul a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Repeta pana cand se gaseste un y(0) care genereaza o solutie unica a sistemului
    do
    {
        // y(0)
        for (int i = 0; i < n; i++)
        {
            cout << "Introduceti elementul y[" << i << "][" << n - 1 << "] = ";
            cin >> y[i][n - 1];
        }

        // Calculam y(1), y(2), ..., y(n-1), unde y(k) = A * y(k-1), 1 <= k <= n
        for (int j = n - 2; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                y[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    y[i][j] = y[i][j] + a[i][k] * y[k][j + 1];
                }
            }
        }

        // Calculam y(n) = A * y(n-1) si pastram -y(n)
        for (int i = 0; i < n; i++)
        {
            y[i][n] = 0;
            for (int k = 0; k < n; k++)
            {
                y[i][n] = y[i][n] + a[i][k] * y[k][0];
            }
            y[i][n] = -y[i][n];
        }

        // Afisam matricea extinsa y
        cout << "Matricea extinsa y este: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << y[i][j] << "   ";
            }
            cout << endl;
        }

        // Aplicam Gauss cu pivotare partiala
        for (int k = 0; k < n - 1; k++)
        {
            piv = fabs(y[k][k]);
            lin = k;

            // Cautam elementul din coloana cu pivotul care are valoarea maxima in modul 
            for (int i = k + 1; i < n; i++)
            {
                if (piv < fabs(y[i][k]))
                {
                    piv = fabs(y[i][k]);
                    lin = i;
                }
            }

            if (piv == 0)
            {
                cout << "Sistemul nu are solutie unica";
                cout << "Incercati sa introduceti alte valori pentru y(0)" << endl;
                este_solutie_unica = true;
                continue;
            }
            else
            {
                este_solutie_unica = true;
            }

            cout << "\nPivotul la pasul " << k << " are modulul " << piv << " care este pe linia " << lin << " si coloana " << k;

            // Daca s-a gasit un element cu valoarea in modul mai mare decat pivotul ales initial, iar acesta se afla pe o alta linie, se interschimba liniile.
            if (lin != k)
            {
                cout << "\nSe interschimba liniile " << k << " si " << lin;
                numar_permutari++;
                for (int j = 0; j < n + 1; j++)
                {
                    aux = y[k][j];
                    y[k][j] = y[lin][j];
                    y[lin][j] = aux;
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
                    cout << y[i][j] << "   ";
                }
                cout << endl;
            }

            // Formula dreptunghiului pentru calculul elementelor de sub linia pivotului ( in afara de cele de sub coloana care sunt 0 )
            for (int i = k + 1; i < n; i++)
            {
                for (int j = k + 1; j < n + 1; j++)
                {
                    y[i][j] = (y[k][k] * y[i][j] - y[i][k] * y[k][j]) / y[k][k];
                }
            }

            // Punem pe coloanele de sub pivot
            for (int coloana_pivot = k + 1; coloana_pivot < n; coloana_pivot++)
            {
                y[coloana_pivot][k] = 0;
            }

            // Afisare pentru a vizualiza evolutia matricii
            cout << "\nDupa pasul " << k << " matricea este: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << y[i][j] << "   ";
                }
                cout << endl;
            }

        }

        if (y[n - 1][n - 1] == 0)
        {
            cout << "Sistemul nu are solutie unica" << endl;
            cout << "Incercati sa introduceti alte valori pentru y(0)" << endl;
            este_solutie_unica = false;
            continue;
        }

        cout << "Dupa aplicarea metodei lui Gauss se obtine matricea: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << y[i][j] << "   ";
            }
            cout << endl;
        }

        y[n - 1][n] = y[n - 1][n] / y[n - 1][n - 1];

        // Parcurgem liniile de la final spre inceput pentru a afla celelalte necunoscute
        for (int i = n - 2; i >= 0; i--)
        {
            float s = 0;
            // Parcurgem pozitiile de pe linia de unde calculam necunoscuta de la final pana la pozitia necunoscutei exclusiv
            // pentru a calcula suma produselor dintre coeficienti si necunoscute pe care le-am aflat anterior
            for (int j = n - 1; j >= i + 1; j--)
            {
                s = s + y[i][j] * y[j][n];
            }

            y[i][n] = (y[i][n] - s) / y[i][i];
        }

        // Afisare solutii
        cout << "Solutiile sistemului sunt: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "c" << i << " = " << y[i][n] << endl;
        }
        cout << "Numarul permutarilor efectuate este: " << numar_permutari << endl;
    }while (este_solutie_unica == false);

    // Afisare solutii
   /* cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "c" << i << " = " << y[i][n] << endl;
    }
    cout << "\nNumarul permutarilor efectuate este: " << numar_permutari << endl;*/

    return 0;


    
}


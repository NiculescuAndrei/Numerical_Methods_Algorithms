#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Introduceti gradul maxim al polinomului de interpolare: ";
    cin >> n;

    bool continua = true;
    bool verifica;

    float l;
    float p;

    float *x = new float[n+1];
    float* f = new float[n+1];

    cout << "Introduceti nodurile de interpolare: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    cout << "Introduceti valorile atasate nodurilor de interpolare: " << endl;;
    for (int i = 0; i <= n; i++)
    {
        cout << "f[" << i << "] = ";
        cin >> f[i];
    }

    float z;
    int optiune;

    // Citim puncte in care sa estimam functia cu ajutorul polinomului Lagrange pana cand vrea utilizatorul
    while (continua == true)
    {
        cout << "\nApasati 1 daca vreti sa aproximati functia f in alt punct" << endl;
        cout << "Apasati 2 pentru a opri programul" << endl;
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "\nIntroduceti nodul pe care vreti sa-l evaluati cu polinomul Lagrange: ";
            cin >> z;
            // Daca valoarea introdusa nu se incadreaza in intervalul [x[0],x[n]] atunci nu putem estima
            if (z < x[0] || z > x[n])
            {
                cout << "Nu putem aproxima f in " << z << endl;
                continue;
            }
            // Daca valoarea introdusa se afla deja in vectorul x atunci extragem de acolo rezultatul in loc sa calculam suma
            else
            {
                verifica = false;
                for (int i = 0; i <= n; i++)
                {
                    if (z == x[i])
                    {
                        cout << "Valoarea aproximativa a functiei f in " << z << " este " << f[i] << endl;
                        verifica = true;
                        break;
                    }
                }
                if (verifica == true)
                {
                    continue;
                }
            }
            break;
        case 2:
            continua = false;
            continue;
            break;
        }

        l = 0;
        for (int k = 0; k <= n; k++)
        {
            p = 1;
            // Verificam daca f[k] este 0 pentru a nu il lua in considerare la suma
            if (f[k] == 0)
            {
                continue;
            }
            else
            {
                for (int i = 0; i <= n; i++)
                {
                    if (i != k)
                    {
                        p = p * (z - x[i]) / (x[k] - x[i]);
                    }
                }
                l = l + f[k] * p;
            }
        }

        cout << "Valoarea aproximativa a functiei f in " << z << " este " << l << endl;
    }

    delete[] x;
    delete[] f;
    return 0;
}


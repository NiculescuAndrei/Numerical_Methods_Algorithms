#include <iostream>
using namespace std;

int main()
{
	int n;
	float a[10], b[10], c[10], t[10];

	cout << "Introduceti ordinul matricei: " << endl;
	cin >> n;

	// Citim elementele diagonalei principale
	for (int i = 0; i < n; i++)
	{
		cout << "Introduceti elementul a[" << i << "]: " << endl;
		cin >> a[i];
	}

	// Citim elementele diagonalei de deasupra celei principale
	for (int i = 0; i < n-1; i++)
	{
		cout << "Introduceti elementul b[" << i << "]: " << endl;
		cin >> b[i];
	}

	// Citim elementele diagonalei de sub cea principala
	for (int i = 0; i < n-1; i++)
	{
		cout << "Introduceti elementul c[" << i << "]: " << endl;
		cin >> c[i];
	}

	// Citim coloana termenilor liberi
	for (int i = 0; i < n; i++)
	{
		cout << "Introduceti elementul t[" << i << "]: " << endl;
		cin >> t[i];
	}

	// Calculam elementele matricelor L si R
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] == 0)
		{
			cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul pe linia " << i;
			return 0;
		}

		// Formam pe l in c
		c[i] = c[i] / a[i];

		// Formam pe r in a
		a[i + 1] = a[i + 1] - c[i] * b[i];
	}

	cout << "\nVectorul l este: " << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << "c[" << i << "] = " << c[i] << "	";
	}

	cout << endl;

	cout << "\nVectorul r este: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i] << "	";
	}

	cout << endl;

	// Rezolvam L * y = t si aflam elementele coloanei y
	for (int i = 1; i < n; i++)
	{
		t[i] = t[i] - c[i - 1] * t[i - 1];
	}

	cout << "\nVectorul y este: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "t[" << i << "] = " << t[i] << "	";
	}

	cout << endl;

	if (a[n - 1] == 0)
	{
		cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul pe linia " << n - 1;
		return 0;
	}

	// Rezolvam R * x = y si aflam solutia sistemului

	t[n - 1] = t[n - 1] / a[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		t[i] = (t[i] - t[i + 1] * b[i]) / a[i];
	}

	cout << "\nVectorul x este: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "t[" << i << "] = " << t[i] << "	";
	}

	cout << endl;

	return 0;
}


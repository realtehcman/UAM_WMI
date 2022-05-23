/* 
 * Autor Maksym Dmyterko
 * Przybliżony czas wykonywania programu 0m0.001s
*/

/* 
----------------------------------------------------------------------------------------------------
UWAGA!
Programa stosuje ISO C++ 2011 standard. Jeżeli występuje błąd, musi Pan włączyć  -std=c++11 albo
-std=gnu++11 compiler w opcjach. Albo w CMD albo w terminalu wpisać polecenie:
    g++  --std=c++11 dmyterko_zad_3.cpp
zatem proszę odpalić a.exe albo a.out jeżeli posiada Pan system Linux
----------------------------------------------------------------------------------------------------
 */

#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;

//Zmienna globalna
unsigned int n = 0;


void introduction() {
    cout << "Opis:" << endl;
    cout << "Program, ktory sprawdza liczbe pierwsza dla dany liczby naturalny n przez test pierwszości Miller-Rabin"
         << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
         << endl << endl;
}

void checkingRange(unsigned int &n) {
    unsigned int upperBound = 1000000000; //10^9
    while (n < 1 || n > upperBound) {
        cout << "\nPan musi wpisac n ktora jest wieksza niz 1 i mniej niż 10^9 (miliard)" << endl;
        cout << "prosze wpisac n: ";
        cin >> n;
    }

}

//zwraca (x^y) % p
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        // y musi być teraz liczbą parzystą 
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Wywoływanie funkcji żeby usunąć wszystkie k trials.
//Zwraca false jeżeli n nie jest liczbą pierwszą
bool miillerTest(int d, int n) {
    // Wybieramy losową liczbę w zakresie [2..n-2]
    // Sprawdzamy corner cases; sprawdzamy czy n > 4
    int a = 2 + rand() % (n - 4);

    int x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Kwadratujemy dopóki jedna z następujących nie zachodzi
    // (i)   d nie osiąga n-1
    // (ii)  (x^2) % n nie jest 1
    // (iii) (x^2) % n nie jest n-1
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}

bool isPrime(int n, int k) {
    // Corner cases
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Szukamy r żeby n = 2^d * r + 1 dla r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Powtórzamy 'k' razy
    for (int i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false;

    return true;
}


int main() {

    introduction();

    cout << "Szanowny Panie Profesorze,";

    while (true) {
        cout << "\nprosze wpisac n: ";
        cin >> n;
        checkingRange(n);

        int k = 4; //liczba powtórzeń

        if (isPrime(n, k))
            cout << n << " jest liczba pierwsza." << endl;
        else
            cout << n << " nie jest liczba pierwsza." << endl;

        cout << "Prosze nacisnac Ctrl + C aby wyjsc\n";
    }
    return 0;
}

/* UZASADNIAM SWÓJ KOD
----------------------------------------------------------------------------------------------------
UWAGA!
Programa stosuje ISO C++ 2011 standard. Jeżeli występuje błąd, musi Pan włączyć  -std=c++11 albo
-std=gnu++11 compiler w opcjach. Albo w CMD albo w terminalu wpisać polecenie:
    g++  --std=c++11 dmyterko_zad_3.cpp
zatem proszę odpalić a.exe albo a.out jeżeli posiada Pan system Linux
----------------------------------------------------------------------------------------------------

1. Skoro musimy wybrać liczbę naturalną n, wybieramy właściwy typ danych. W danym przypadku
wybrałem unsigned int jaki ma zakres od 0 do 4,294,967,295. Uwaga, jeżeli użytkownik wpisze n więcej
niż 4,294,967,295, to będzie nieskończona pętla

2. Dalej w procedurze checkingRange() zrobiłem ograniczenie od 1 do 10^9 włącznie

2.1 Gdyby użytkownik wyszedł z zakresu, program nada komunikat

3. Wykorzystałem algorytm Miller-Rabin.
3.1 wartość k poinformuje w jakiej ilości n jest licbą pierwszą z prawdopodobieństwiem
co najwyżej 4^(−k)

*/

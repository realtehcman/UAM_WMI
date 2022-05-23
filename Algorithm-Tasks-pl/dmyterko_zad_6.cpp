/*
* Autor Maksym Dmyterko
* Przybliżony czas wykonywania programu 0m0.004s
*/

/*
----------------------------------------------------------------------------------------------------
UWAGA!
Programa stosuje ISO C++ 2011 standard. Jeżeli występuje błąd, musi Pan włączyć  -std=c++11 albo
-std=gnu++11 compiler w opcjach. Albo w CMD albo w terminalu wpisać polecenie:
    g++  --std=c++11 dmyterko_zad_6.cpp
zatem proszę odpalić a.exe albo a.out jeżeli posiada Pan system Linux
----------------------------------------------------------------------------------------------------
 */

#include<iostream>
#include<cmath> //dla funkcji fabs (wartość absolutna)
#include<iomanip> //mówi ile cyfr będzie widoczne dla użytkownika po odpaleniu
#include <sstream>


using namespace std;

void introduction() {
    cout << "Opis:" << endl;
    cout << "Program, obliczajacy wartosc liczby e z dana dokladnoscia eps > 0" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * *" << endl << endl;
}


void checkingRange(long double &n) {
    int lowerBound = 0;
    while (n <= lowerBound) {
        cout << "\nPan musi wpisac epsilon ktory jest wiekszy od 0" << endl;
        cout << "prosze wpisac eps: ";
        cin >> n;
    }
}

//method overloading (Przeciążanie funkcji)
void checkingRange(int &n) {
    int lowerBound = 0;
    while (n <= lowerBound) {
        cout << "\nPan musi wpisac wartosc ktora jest wieksza od 0" << endl;
        cout << "prosze wpisac ilosc cyfr, ktora chce Pan zobaczyc po kropce: ";
        cin >> n;
    }
}


int main() {
    introduction();

    long double eps = 0; //określa dokładność liczby e (1.0/10000000)
    int amount = 0; //ilość cyfr po kropeczce

    cout
            << "1. Niech wpisze Pan ile cyfr chce Pan zobaczyc po kropce (musi byc liczba calkowita i nie wolno wpisac 0 i ponizej): ";
    cin >> amount;
    checkingRange(amount);
    amount += 1; //bo funkcja setprecision() określa ilość wszytkich dane wyjśćiowe (wraz z cyfrą przed przecinkiem)

    cout << endl << "2. Prosze Pana okreslic jaka wielkosc epsilona musi byc (tylko dla eps > 0)" << endl;
    cout << "naprzyklad wartosc moze byc: 1, .001, 0.000001, 1e-19..." << endl;
    cout << endl << "Teraz prosze Pana wpisac wartosc eps: ";

    string str;
    cin >> str;

    string parsed, input = str;
    stringstream input_stringstream(input);

    //przetwarzanie string
    if (getline(input_stringstream, parsed, '.')) {
        eps = stold(str); //konwertacja do long double typ danych; funkcja stold() dostępna w c++11
    } else {
        eps = stoi(str); //konwertacja stringa do int typ danych; funkcja stoi() dostępna w c++11

    }
    checkingRange(eps);


    long double e = 2.0, e0;
    long double factorial = 1;

    int counter = 2;
    long double moduloDifference;

    do {
        e0 = e; //dla tego, żeby potem sprawdzić warunek
        factorial *= counter++;
        e += 1.0 / factorial;

        moduloDifference = fabs(e - e0); //określi różnice między dwoma e
    } while (moduloDifference >= eps); //sprawdzamy warunek

    cout << endl << "Wynik:" << endl;
    cout << setprecision(amount) << e;

    //wydrukujemy zera żeby spełnić ilość cyfr po kropce; warunek 1 (Niech wpisze...)
    if (e == 2.5) {
        for (int i = 0; i < amount - 2; ++i) {
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}


/*
* UZASADNIAM SWÓJ KOD
----------------------------------------------------------------------------------------------------
UWAGA!
Programa stosuje ISO C++ 2011 standard. Jeżeli występuje błąd, musi Pan włączyć  -std=c++11 albo
-std=gnu++11 compiler w opcjach. Albo w CMD albo w terminalu wpisać polecenie:
    g++  --std=c++11 dmyterko_zad_6.cpp
zatem proszę odpalić a.exe albo a.out jeżeli posiada Pan system Linux
----------------------------------------------------------------------------------------------------

1. Mój program sprawdza jaki typ danych użytkownik użył dla wartości epsilona. Jeżeli użytkownik użył . (kropki),
to mamy double long typ danych. W jeżeli tylko cyfra, to mamy int typ danych
2. checkingRange na linijce 31 sprawdza czy uźytkownik określił epsilon większy od 0. Jeżeli nie, to pisz komunikat
 od funkcji checkingRange()
 
3. W linijce 41 mamy method overloading. Tu sprawdzamy czy ilość cyfr, którą użytkownik chce zobaczyć jest większa
 od zero

4. Dla przechowania liczb e wykorzystujemy duży typ danych -- long double
5. W linijce 89 mamy implementację postaci dla znalezienia e
        e0 = e;
        factorial *= counter++;
        e += 1.0 / factorial;

5.  Chciałem użyć funkcję:
    double factorial(double n)
    {
        double result = 1;
        for(double i = 1; i <= n; i++)
        {
            result = result*i;
        }
        return result;
    }

jednak w takim razie program będzie działać wolniej. Wieć, wyliczyłem silnię razem z liczbą Eulera od
linijki 89 do 92

*/

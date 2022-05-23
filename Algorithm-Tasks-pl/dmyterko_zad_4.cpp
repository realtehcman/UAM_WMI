/* 
 * Autor Maksym Dmyterko
 * Przybliżony czas wykonywania programu 0m0.001s
*/

#include <iostream>

using namespace std;

#define ZAKRES 100


void introduction() {
    cout << "Opis:" << endl;
    cout << "Program, ktory generuje tablice liczb pierwszych z przedzialu [2,100] za pomoca sita Eratostenesa" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
         << endl;
}

void sieveOfEratosthenes(unsigned short int n) {
    int tablica[ZAKRES];

    //inicjuję tablicę jaka zawiera tylko true
    for (unsigned short int i = 0; i <= n; i++)
        tablica[i] = 1;


    for (unsigned short int i = 2; i * i <= n; i++) {
        if (tablica[i] == 1) //sprawdza czy jest liczbą pierwszą
        {
            for (unsigned short int j = i; i * j <= n; j++)
                tablica[i * j] = 0; // jeśli mnożniki wskazują, że ten element nie jest liczbą pierwszą, wstawiamy false
        }
    }

    // wypisuje liczby pierwsze z tablicy
    for (unsigned short int i = 2; i <= n; i++)
        if (tablica[i] == 1)
            cout << i << " ";
}

int main() {
    unsigned short int n = ZAKRES;
    introduction();

    cout << "Szanowny Panie Profesorze,\nprzedstawiam tablice, ktora jest wygenerowana liczbami pierwszymi:\n";

    sieveOfEratosthenes(n);
    cout << endl;

    return 0;
}
/* UZASADNIAM SWÓJ KOD

1. Tworzę stały zakres, który zawiera 100 żeby ograniczyć tablicę oraz pętlę

2. Pomysł tego algorytmu:
Tworzymy tablicę z zakresu 2 do 100 włącznie, która zawiera tylko true. Dalej wykorzystamy mnożniki
żeby znaleźć które elementy nie są liczbą pierwszą i wstawiamy false
Na końcu piszemy tablicę która zawiera tylko true

*/

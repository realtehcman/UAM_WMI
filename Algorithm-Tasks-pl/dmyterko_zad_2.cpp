/* 
 * Autor Maksym Dmyterko
 * Przybliżony czas wykonywania programy 0m0.140s
*/

#include <stdio.h>
#include <iostream>

#include <cmath>

// stały
#define MAXPN    5  /* max liczba sprawdzań */
#define NELEM 4096  /* max ilość w tablice */

using namespace std;

void introduction() {
    cout << "Opis:" << endl;
    cout << "Program, ktory wypisuje wszystkie liczby doskonale nie wieksze niż 10^9 (miliard)" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

int main(void) {
    introduction();

    /* deklaracja zmiennych */
    unsigned sum = 0, pncount = 0;
    unsigned i, j, prime, perfectNumber;


    for (prime = 2; prime < 32; prime++) {                           /* generuje kandydatów */
        unsigned n = 0;
        unsigned divisors[NELEM] = {0};                              /* tablica dzielników */

        perfectNumber = pow(2, prime - 1) * (pow(2, prime) - 1);   /* 2^(n - 1) * (2^n - 1) */

        for (i = 1; i <= perfectNumber / 2; i++) {                   /* szuka dzielników oraz sumy */
            if (perfectNumber % i == 0) {
                sum += i;
                divisors[n++] = i;                                   /* zapisuje dzielniki na tablicy */
            }

            if (n == NELEM) {                                              /* protect array bound */
                fprintf(stderr, "error: f full.\n");
                return 1;
            }

        }
        if (sum == perfectNumber) {                          /* sprawdza czy liczba jest doskonała */
            printf("Liczba doskonala: %10u :", perfectNumber);
            for (j = 0; j < n; j++)                                     /* wypisuje dzielniki */
                printf(j ? ", %u" : " %u", divisors[j]);
            putchar('\n');
            if (++pncount == MAXPN)
                break;
        }
        sum = 0;                                            /* resetuje sumę dla nstępnych iteracji */
    }

    return 0;
}
/* UZASADNIAM SWÓJ KOD

1. Wszystkie liczby doskonałe w zakresie 10^9: 6, 28, 496, 8126, 33550336. Dla tego użyłem stałą
#define MAXPN    5  żeby ograniczyć do pięciu liczb doskonalych

2. Alogrytm jest oparty na (2^(n-1)) × (2^(n) - 1)

*/
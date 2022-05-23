//!obowiazkowo uzyc -std=c11

/* 
 * Autor Maksym Dmyterko
 * Przybliżony czas wykonywania programu 0m0.037s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 9
#define MIN_DIGITS 3

void introduction() {
    printf("Opis:\n");
    printf("Program, ktory wypisuje wszystkie liczby k-cyfrowe liczby Armstronga dla k = 3,...,9.\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
}

// pwr[d][n] jest d^n
long long pwr[10][MAX_DIGITS + 1];

// Cyfry i końcowy indeks liczby.
int digits[MAX_DIGITS];
int m;

// Napełnia pwr.
void fill_tbls(void) {
    for (int d = 0; d < 10; d++) {
        pwr[d][0] = 1;
        for (int p = 1; p <= MAX_DIGITS; p++)
            pwr[d][p] = pwr[d][p - 1] * d;
    }
}

// Porównanie sort szybkiego dla malejących liczb całkowitych
int cmp_ints_desc(const void *vpa, const void *vpb) {
    const int *pa = vpa, *pb = vpb;
    return *pb - *pa;
}

// Sprawdź aktualną liczbę i wypisz, jeśli jest to liczbą Armstronga
void test(void) {
    long long sum = 0;

    for (int i = 0; i <= m; i++)
        sum += pwr[digits[i]][m + 1];

    int sum_digits[MAX_DIGITS * 2];
    int n = 0;

    for (long long s = sum; s; s /= 10)
        sum_digits[n++] = s % 10;
    if (n == m + 1) {
        qsort(sum_digits, n, sizeof(int), cmp_ints_desc);
        if (memcmp(sum_digits, digits, n * sizeof(int)) == 0) {

            int k = 0;
            for (int temp = sum; temp != 0; k++)
                temp /= 10;

            printf("Dla k = %d \t %lld\n", k, sum);
        }
    }
}

// Rekurencyjny generator nierosnących ciągów cyfr.
// Wywołuje test, gdy ciąg jest kompletny.
void gen(int i, int min, int max) {
    if (i > m)
        test();
    else {
        for (int d = min; d <= max; d++) {
            digits[i] = d;
            gen(i + 1, 0, d);
        }
    }
}

// Wypełnia tabele
int main() {
    introduction();

    fill_tbls();

    for (m = MIN_DIGITS - 1; m < MAX_DIGITS; m++)
        gen(0, 1, 9);

    return 0;
}

/* UZASADNIAM SWÓJ KOD

1. Zrobiłem k-cyfrowe ograniczenie (MIN_DIGITS, MAX_DIGITS) zgodnie z zadaniem.

2. Mój kod napełnia tablicę potęgami, wykorzystuje szybkie sortowanie oraz porownuje, pisze jeżeli to jest liczba
Armstronga

3. Używamy gcc compiler

*/
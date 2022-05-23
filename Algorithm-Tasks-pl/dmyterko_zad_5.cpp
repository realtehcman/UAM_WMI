/* 
 * Autor Maksym Dmyterko
 * Przybliżony czas wykonywania programu 0m0.007s
*/

#include<iostream>
#include<cmath>

#define PARA 5

using namespace std;


void introduction() {
    cout << "Opis:" << endl;
    cout << "Program, ktory wypisuje wszystkie pary liczb zaprzyjaznionych nie wiekszych niż 10^4" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

//zwraca sumę wszystkich właściwych dzielników n
int getSumOfFactors(unsigned short n) {
    if (n <= 1) {
        return 0;
    }

    unsigned short count = 1; // 1 zawsze jest dzielnikiem
    unsigned short sqrt_n = (unsigned short) sqrt(n); // ograniczenie górne dla for pętli

    for (unsigned short i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            // i oraz n / i są dzielnikami n
            count += i;
            if (i != n / i) {
                count += n / i;
            }
        }
    }
    return count;
}

int main() {

    introduction();

    unsigned short counter = 1;
    unsigned short num = 0;

    for (;;) {
        num++;
        unsigned short sumOfFactors = getSumOfFactors(num);

        //wyłączenie liczb doskonałych
        if (num == sumOfFactors)
            continue;

        if (num > sumOfFactors && getSumOfFactors(sumOfFactors) == num) {
            cout << "Para " << counter << ": " << num << " " << sumOfFactors << "\n";
            counter += 1;
        }

        if (counter > PARA)
            break;

    }
    return 0;
}

/* UZASADNIAM SWÓJ KOD
1. Skoro jest 5 takich par: (220, 284), (1184, 1210), (2620, 2924) (5020, 5564), (6232, 6368) w zakresie do
10^4 włącznie,robimy break kiedy counter jest większy od PARA czyli piątki

// 2. unsigned short zawiera 0 do 65,535
UWAGA! Jeżeli Pan wpisze w stałej PARA 9, to wyjdzie zły wynik. Ponieważ 9 para (63020, 76084) przekroczy 
zakres tego typu danych (65,535)

2. getSumOfFactors wykorzysta postać n = ((p_1)^a_1)*((p2)^(a_2))* … (p_k(a_k)).
więcej pod adresem: https://www.geeksforgeeks.org/sum-factors-number/
Dzięki temu pomysłowi, mój kod jest szybszy od zwykłego dodawania dzielników

3. Szukamy sumy dzielników oraz porównujemy z sumą dzielnikow wyliczanego dzielnika. Gdyby one były równe,
to piszemy parę

4. Aby upewnić się, że program nie znajdzie dwukrotnie tej samej pary, na przykład 220 i 284, oraz 284 i 220,
zachowujemy dodatkowy warunek, w którym liczba powinna być większa niż suma dzielników (num > sumOfFactors).

*/
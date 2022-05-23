# Algorithm-Tasks
Zad. 1 (3pkt) Napisać program wypisujący wszystkie k-cyfrowe liczby
Armstronga dla k=3,4,...,9.
Wskazówka: k-cyfrową liczbę nazywamy liczbą A., jeżeli jest ona równa
suma k-tych potęg wszystkich cyfr tej liczby. Przykładowo: 153 jest
3-cyfrową liczba A., ponieważ 1^3+5^3+3^3=153.

Zad. 2 (3pkt) Napisać program wypisujący wszystkie liczby doskonałe nie
większe niż 10^9.
Wskazówka: Liczba n jest liczbą doskonałą, jeśli jest równa sumie swoich
dzielników właściwych. Przykładowo, 6 jest liczbą doskonałą, ponieważ jej
dzielnikami właściwymi 6 są liczby 1, 2 i 3 oraz 6=1+2+3.

Zad. 3 (2pkt) Napisać program sprawdzający czy dana liczba naturalna n
nie większa niż 10^9 jest liczbą pierwszą.
Wskazówka: Liczba n jest pierwsza, jeśli jej jedynymi dzielnikami są 1
oraz n. Przykładowo, liczba 6 nie jest pierwsza, ponieważ oprócz 1 i 6
dzieli się także przez 2 i 3, natomiast liczba 7 jest pierwsza, ponieważ
nie ma innych dzielników niż 1 i 7.

Zad. 4 (2pkt) Napisać program generujący tablicę liczb pierwszych z
przedziału [2,100] za pomocą sita Eratostenesa oraz wypisujący te liczby
na ekranie monitora.
Wskazówka: Sito E. polega na cyklicznym odrzucaniu liczb złożonych z
badanego przedziału, jest opisane np. w Wikipedii.

Zad. 5 (2pkt) Dwie liczby nazywamy zaprzyjaźnionymi, jeżeli każda z nich
jest równa sumie dzielników właściwych drugiej liczby. Przykładowo,
liczby 220 i 284 są zaprzyjaźnione. Napisać program wypisujący wszystkie
pary liczb zaprzyjaźnionych nie większych niż 10^4.

Zad. 6 (3pkt) Napisać program obliczający wartość liczby e z daną
dokładnością eps>0.
Wskazówka: Liczba e = 1+1/1!+1/2!+...+1/n!+...=2.7172... może być
obliczona jako suma elementów ciągu x_0, x_1, x_2, ..., gdzie x_0=1, x_1
= 1+ 1/1!, x_2 =1+1/1!+1/2!, ..., przy czym sumowanie kontynuowane jest
tak długo jak długo zachodzi warunek |x_(i+1)-x_i|>=eps.



1.    Program #1 jest zrobiona w jęz. C11. Więc, kompilujemy za pomocy gcc 
2.    Program #3 zarówno program #6 stosują C++ 2011 standart. Więc, jeżeli użyje Pan coś innego, to programy nie przejdą fazy kompilacji. Uprzejmie proszę użyć polecenie:
    g++ --std=c++11 dmyterko_zad_#.cpp
3.    Wielokrotnie próbowałem przesłać dmyterko_zad_6.cpp na Teams, i za każdym razem Teams przemianuje na dmyterko_zad_6 1.cpp, dmyterko_zad_6 2.cpp, dmyterko_zad_6 3.cpp 
    To chyba jakiś błąd w systemie Teams

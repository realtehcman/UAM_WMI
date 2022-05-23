/* * * * * * * * * * * * * * * * * * * * * * * * * * * 
    All rights are reserved by Maksym Dmyterko©
* * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <unistd.h>

int daneWejsciowe(int ilosc, int *ciag);
void kompresja(int ilosc, int *ciag);


int jedynka = 0;
int zero = 0;

    int main(){
    
    int ilosc = 0;

    printf("Ile binarów chcesz wpisac?\n");
    scanf("%d", &ilosc);

    printf("%d? OK\n", ilosc);

    int ciag[ilosc];
    
    if(daneWejsciowe(ilosc, ciag)){
        return 1;
    }

    kompresja(ilosc, ciag);

    printf("\n    cyfra w kwadratowych nawiasach [] znacze ile raz binar powtórzał się w ciągu\n");
    return 0;
}

int daneWejsciowe(int ilosc, int *ciag){

    printf("\n\nWpisz binarny ciąg:\n");

    int elementIndex = 1;
    for (int i = 0; i < ilosc; i++){
        printf("Wpisz wartość dla %d elemntu: ", elementIndex);
        elementIndex++;
        scanf("%d", &ciag[i]);
        
        if (ciag[i] !=1 && ciag[i] !=0 ) {
            printf("Nie wpisałeś binarów.\n");

            return 1;
        }
    }

        printf("\n\nWpisałeś:\n");
        for (int i = 0; i < ilosc; i++){
            printf("%d", ciag[i]);
            printf("\n");
        }

        return 0;
}

void kompresja(int ilosc, int *ciag){
    printf("\n* * * * * * * * * * * * * * * \n");
        printf("\tKONWERTUJĘ\n");
    printf("* * * * * * * * * * * * * * * \n\n");

    sleep(2);

        for (int i = 0; i < ilosc; i++) { 
                if (ciag[i] == 0 ) {
                    zero++;
                    if(ciag[i+1] != 0){
                        printf("0[%d]\n", zero);
                        zero = 0;
                    }
                }
                else if (ciag[i] == 1  ) {
                    jedynka++;
                    if(ciag[i+1] != 1){
                        printf("1[%d]\n", jedynka);
                        jedynka = 0;
                    }
                }

            }

    return;
}

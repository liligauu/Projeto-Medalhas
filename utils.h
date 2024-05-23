#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void LeString(char string[], int tamanho){
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
    setbuf(stdin, NULL);
}

void LimpaTela(){
    #ifdef __Win32
        system("cls");
    #else
        system("clear");
    #endif
}

/*void ordenarVetor(int numeros[]){
    int tamanhovetor = (sizeof(numeros)/4);
    int i, j, temp;
    
    if(true){
        for (int i = 0; i < tamanhovetor; i++){   
            for (int j = 0; j < tamanhovetor; j++){
                if(numeros[j] > numeros[j+1]){
                    temp = numeros[j];
                    numeros[j] = numeros[j+1];
                    numeros[j+1] = temp;
                }
            }
        }
    }else{
    }    
}
*/


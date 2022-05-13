#include <stdio.h>
#include <math.h>

int jumpSearch(int [], int, int);

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("%d",jumpSearch(a,12,12));
    return 0;
}

int jumpSearch(int arreglo[], int tamA, int objetivo){
    int tamBloques, numBloques = sqrt(tamA);
    tamBloques = tamA/numBloques;
    int indice = -1, limiteSuperior = tamBloques, limiteInferior = 0;
    
    while(limiteSuperior<tamA){
        if(objetivo==arreglo[limiteSuperior]){
            indice = limiteSuperior;
            return indice;
        }
        else if(objetivo>arreglo[limiteSuperior]){
            limiteInferior = limiteSuperior;
            limiteSuperior = limiteSuperior+tamBloques;
        }
        else{
            for(int i=limiteInferior;i<limiteSuperior;i++){
                if(arreglo[i] == objetivo){
                    indice = i;
                    break;
                }
            }
            return indice;
        }
    }
    if(indice==-1){
        for(int i=limiteInferior+1;i<tamA;i++){
            if(arreglo[i] == objetivo){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

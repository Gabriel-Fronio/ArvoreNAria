#include "../headers/ArvoreNAria.h"

ArvoreNAria::ArvoreNAria(unsigned int tamanho) {
    ArvoreNAria::NoRaiz = new No(tamanho);
}

void ArvoreNAria::inserirNo(Info info) {
    No* noAtual = ArvoreNAria::NoRaiz;
    //bool inserted = false;
    while(true) {
        int tam = sizeof(noAtual -> getInfos());
        for(int i=0; i<tam; i++) {
            if(noAtual -> getInfos()[i] == 0) {
                noAtual -> setInfo(i, info);
                break;
            }
        }
        for (int j=0; j<tam; j++){
            if(info<*noAtual->getInfos()[j]){
//fazer operator<
//fazer logica que, se for menor, ir para ponteiro localizado em j-1
            }
        }
    }
}
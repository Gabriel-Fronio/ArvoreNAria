#include "../headers/No.h"
#include "../headers/Info.h"
#include <stdio.h>

No::No(unsigned int n){
    No::tamanho = n;
    No::infos = new Info*[n-1]();
    No::ptrs = new No*[n]();
    for(int i=0; i<n-1; i++){
        No::infos[i] = 0;
        No::ptrs[i] = 0;
    }
    No::ptrs[n-1] = 0;
}

Info** No::getInfos() const{
    return No::infos;
}

void No::addInfo(Info& info){
    int tam = No::tamanho;
    for(int i=0; i<tam; i++){
        if(No::infos[i] == NULL){
            No::infos[i] = &info;
            break;
        }
        if(info < *No::infos[i]){
            for(int j=tam-1; j>i; j--){
                No::infos[j] = No::infos[j-1];
            }
            No::infos[i] = &info;
            break;
        }
    }
}

No** No::getPtrs() const{
    return No::ptrs;
}

int No::getTamanho() const{
    return No::tamanho;
}

void No::setPtr(int pos, No* ptr){
    No::ptrs[pos] = ptr;
}

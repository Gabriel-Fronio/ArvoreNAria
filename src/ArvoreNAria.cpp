#include "../headers/ArvoreNAria.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using std::string;

ArvoreNAria::ArvoreNAria(unsigned int tam) {
    ArvoreNAria::NoRaiz = new No(tam);
    ArvoreNAria::tamanho = tam;
}

void ArvoreNAria::inserirNo(Info& info) {
    No* noAtual = ArvoreNAria::NoRaiz;
    No* noPai = NULL;
    bool inserted = false;
    while(!inserted) {
        int tam = ArvoreNAria::tamanho - 1;
        for(int i=0; i<tam; i++) {
            if(noAtual -> getInfos()[i] == NULL) { // verifica se ainda há espaço
                noAtual -> addInfo(info);
                inserted = true;
                break;
            }
        }

        if(inserted)//sai do while
            break;

        noPai = noAtual;

        for (int j=0; j<tam; j++){
            if(info<*noAtual->getInfos()[j]){
                if(noAtual -> getPtrs()[j] == NULL)
                    noAtual -> setPtr(j, new No(tam+1));
                noAtual = noAtual -> getPtrs()[j];
                break;
            }
        }

        if(noPai == noAtual){// significa que a info eh maior que todas as infos do vetor (nao entrou no if)
            if(noAtual -> getPtrs()[tam] == NULL)
                noAtual -> setPtr(tam, new No(tam+1));
            noAtual = noAtual -> getPtrs()[tam];
        }
    }
}

No* ArvoreNAria::getNoRaiz() const{
    return NoRaiz;
}

int ArvoreNAria::getTamanho() const{
    return tamanho;
}

std::ostream& operator<<(std::ostream& stream, const ArvoreNAria& arvore){
    ArvoreNAria av = arvore;
    string *ret = new string[50];
    for(int i=0; i<50; i++)
        ret[i] = "";
    ret = av.printa(*av.getNoRaiz(), ret, 0);
    for(int j=0; j<50; j++)
        if(ret[j] != "")
            stream << ret[j] << "\n";
    return stream;
}

string* ArvoreNAria::printa(No no, string ret[], int nivelAtual){
    No* noAtual = &no;
    string *reserva = ret;
    reserva[nivelAtual] += "[";
    for(int i=0; i< tamanho -1; i++)
        if(&noAtual->getInfos()[i] != NULL){
            char intStr [10];
            itoa(noAtual->getInfos()[i]->getInfo(), intStr, 10);
            string str(intStr);
            reserva[nivelAtual] += str + ",";
        }
    reserva[nivelAtual] = reserva[nivelAtual].substr(0, reserva[nivelAtual].size()-1);
    reserva[nivelAtual] += "]";

    No* noPai = noAtual;

    for(int j=0; j<tamanho; j++)
        if(noAtual->getPtrs()[j] != NULL){
            noAtual = noAtual->getPtrs()[j];
            reserva = printa(*noAtual, reserva, nivelAtual+1);
            noAtual = noPai;
        }
    return reserva;
}

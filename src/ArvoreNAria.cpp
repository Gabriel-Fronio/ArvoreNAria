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
        if(noAtual->getInfos()[i] != NULL){
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

bool ArvoreNAria::removerNo(Info info){
    int tam = ArvoreNAria::tamanho-1;
    if(noEhFolha(*ArvoreNAria::getNoRaiz())){
        if(!noContemInfos(*ArvoreNAria::getNoRaiz())){
                if(getNoRaiz()->getInfos()[0]->getInfo() == info.getInfo()){
                    getNoRaiz()->getInfos()[0] = NULL;
                    ArvoreNAria::NoRaiz = NULL;
                    return true;
                }
                return false;
        }
        else{
            for(int i=0; i<tam; i++){
                if(info.getInfo() == ArvoreNAria::getNoRaiz()->getInfos()[i]->getInfo()){
                    for(int j=i; j<tam-1; j++)
                        this->getNoRaiz()->getInfos()[j] = this->getNoRaiz()->getInfos()[j+1];
                    this->getNoRaiz()->getInfos()[i] = NULL;
                    return true;
                }
            }
            return false;
        }
    }
    else{
        No* no = procurarInfo(info, this->getNoRaiz());
        if(no == NULL)
            return false;
        if(noEhFolha(*no)){
            if(!noContemInfos(*no)){
                if(no->getInfos()[0]->getInfo() == info.getInfo()){
                    no->getInfos()[0] = NULL;
                    return true;
                }
                return false;
            }
            else{
                for(int i=0; i<tam; i++){
                    if(no->getInfos()[i]->getInfo() == info.getInfo()){
                        for(int j=i; j<tam-1; j++)
                            no->getInfos()[j] = no->getInfos()[j+1];
                        no->getInfos()[tam-1] = NULL;
                        return true;
                    }
                }
            }
        }
        else{
            No* paiAtual = no;
            No* atual = no;
            int indice = 0; // indice da menor info do no
            int indicePai = 0;
            for(int i=0; i<tam; i++){
                if(no->getInfos()[i]->getInfo() == info.getInfo()){
                    if(no->getPtrs()[i+1] != NULL){
                        indice = i+1;
                        atual = no->getPtrs()[i+1];
                        while(true){ // acha a menor informacao da subarvore i+1 (ptr vai indo acessando o ind da menor info do ptr ate o ptr ser nulo)
                            indicePai = indice;
                            indice = acharMenorInfo(*atual);
                            if(atual->getPtrs()[indice] == NULL)
                                break;
                            paiAtual = atual;
                            atual = atual->getPtrs()[indice];
                        }
                        Info* reserva = atual->getInfos()[indice];
                        if(!noContemInfos(*atual)){
                            paiAtual->getPtrs()[indicePai] = NULL;
                        }
                        /*else{
                            for(int j=indice; j<tam-1; j++)
                                atual->getInfos()[j] = atual->getInfos()[j+1];
                            atual->getInfos()[tam-1] = NULL;
                            //atual->getInfos()[indice] = NULL;
                        }*/
                        removerNo(*reserva);
                        no->getInfos()[i] = reserva;
                        return true;
                    }
                    else if(no->getPtrs()[i] != NULL){
                        indice = i;
                        atual = no->getPtrs()[i];
                        while(true){
                            indicePai = indice;
                            indice = acharMaiorInfo(*atual);
                            if(atual->getPtrs()[indice] == NULL)
                                break;
                            paiAtual = atual;
                            atual = atual->getPtrs()[indice];
                        }
                        Info* reserva = atual->getInfos()[indice];
                        if(!noContemInfos(*atual)){
                            paiAtual->getPtrs()[indicePai] = NULL;
                        }
                        /*else{
                            for(int j=indice; j<tam-1; j++)
                                atual->getInfos()[j] = atual->getInfos()[j+1];
                            atual->getInfos()[tam-1] = NULL;
                            //atual->getInfos()[indice] = NULL;
                        }*/
                        removerNo(*reserva);
                        no->getInfos()[i] = reserva;
                        return true;
                    }
                    else{ // não há nenhuma subárvore no vetor de nós nas posições i e i+1
                        for(int j=i+1; j<=tam; j++){
                            if(no->getPtrs()[j] != NULL){
                                indice = j;
                                atual = no->getPtrs()[j];
                                while(true){
                                    indicePai = indice;
                                    indice = acharMenorInfo(*atual);
                                    if(atual->getPtrs()[indice] == NULL)
                                        break;
                                    paiAtual = atual;
                                    atual = atual->getPtrs()[indice];
                                }
                                Info* reserva = atual->getInfos()[indice];
                                if(!noContemInfos(*atual)){
                                    paiAtual->getPtrs()[indicePai] = NULL;
                                }
                                /*else{
                                    for(int k=indice; k<tam-1; k++)
                                        atual->getInfos()[k] = atual->getInfos()[k+1];
                                    atual->getInfos()[tam-1] = NULL;
                                    //atual->getInfos()[indice] = NULL;
                                }*/
                                removerNo(*reserva);
                                no->getInfos()[j-1] = reserva;
                                return true;
                            }
                            else{
                                if(j != tam)
                                    no->getInfos()[j-1] = no->getInfos()[j];
                                else{
                                    for(int k=i; k>=0; k--){
                                        if(no->getPtrs()[k] != NULL){
                                            indice = k;
                                            atual = no->getPtrs()[k];
                                            while(true){
                                                indicePai = indice;
                                                indice = acharMaiorInfo(*atual);
                                                if(atual->getPtrs()[indice] == NULL)
                                                    break;
                                                paiAtual = atual;
                                                atual = atual->getPtrs()[indice];
                                            }
                                            Info* reserva = atual->getInfos()[indice];
                                            if(!noContemInfos(*atual)){
                                                paiAtual->getPtrs()[indicePai] = NULL;
                                            }
                                            /*else{
                                                for(int l=indice; l<tam-1; l++)
                                                    atual->getInfos()[l] = atual->getInfos()[l+1];
                                                atual->getInfos()[tam-1] = NULL;
                                                //atual->getInfos()[indice] = NULL;
                                            }*/
                                            removerNo(*reserva);
                                            no->getInfos()[k] = reserva;
                                            return true;
                                        }
                                        else{
                                            if(k == 0)
                                                return false;
                                            no->getInfos()[k] = no->getInfos()[k-1];
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
            return false;
        }
    }
    return false;
}

int ArvoreNAria::acharMenorInfo(No no){
    Info menor = *no.getInfos()[0];
    int ind = 0;
    for(int i=0; i<this->tamanho-1; i++){
        if(no.getInfos()[i] == NULL)
            continue;
        if(*no.getInfos()[i] < menor){
            menor = no.getInfos()[i]->getInfo();
            ind = i;
        }
    }
    return ind;
}

int ArvoreNAria::acharMaiorInfo(No no){
    Info maior = *no.getInfos()[0];
    int ind = 0;
    for(int i=0; i<this->tamanho-1; i++){
        if(no.getInfos()[i] == NULL)
            continue;
        if(*no.getInfos()[i] > maior){
            maior = no.getInfos()[i]->getInfo();
            ind = i;
        }
    }
    return ind;
}

bool ArvoreNAria::noEhFolha(No no){
    int t = ArvoreNAria::tamanho;
    for(int i=0; i<t; i++)
        if(no.getPtrs()[i] != NULL)
            return false;
    return true;
}

bool ArvoreNAria::noContemInfos(No no){
    int t = ArvoreNAria::tamanho-1;
    if(t == 1){
        if(no.getInfos()[0] == NULL)
            return false;
        else
            return true;
    }
    int umaInfo = false; //variavel para indicar q o no contem pelo menos uma info (senao n existiria)
    for(int i=0; i<t; i++)
        if(no.getInfos()[i] != NULL){
            if(umaInfo) // se ja tinha passado por uma info, quer dizer q tem mais q uma
                return true;
            else
                umaInfo = true; // ainda n tinha passado por nenhuma info, indica q agora passou por uma
        }
    return false;
}

No* ArvoreNAria::procurarInfo(Info info, No* no){
    if(no == NULL)
        return NULL;
    for(int i=0; i<no->getTamanho()-1; i++){
         if(no->getInfos()[i]->getInfo() == info.getInfo())
            return no;

         if(no->getInfos()[i]->getInfo() > info.getInfo())
            return procurarInfo(info, no->getPtrs()[i]);
    }
    return procurarInfo(info, no->getPtrs()[no->getTamanho()-1]);
}

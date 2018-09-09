#ifndef ArvoreNAria_Class
#define ArvoreNAria_Class

#include "No.h"
#include <stdio.h>
#include <iostream>
#include <string>
using std::string;

class ArvoreNAria{
    No* NoRaiz;
    int tamanho;

    public:
        int getTamanho() const;
        No* getNoRaiz() const;
        ArvoreNAria(unsigned int tamanho);
        bool noEhFolha(No no);
        bool noContemInfos(No no);
        bool removerNo(Info info);
        No* procurarInfo(Info info, No* no);
        void inserirNo(Info& info);
        int acharMenorInfo(No no);
        int acharMaiorInfo(No no);
        friend std::ostream& operator<<(std::ostream& stream, const ArvoreNAria& arvore);
        string* printa(No no, string ret[], int nivelAtual);
};

#endif

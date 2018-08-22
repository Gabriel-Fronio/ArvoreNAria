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
        void removerNo(Info info);
        void procurarNo(Info info);
        void inserirNo(Info& info);
        friend std::ostream& operator<<(std::ostream& stream, const ArvoreNAria& arvore);
        string* printa(No no, string ret[], int nivelAtual);
};

#endif

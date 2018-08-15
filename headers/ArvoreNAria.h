#ifndef ArvoreNAria_Class
#define ArvoreNAria_Class

#include "No.h"

class ArvoreNAria{
    No* NoRaiz;
    public:
        ArvoreNAria(unsigned int tamanho);        
        void inserirNo(Info i);
};

#endif
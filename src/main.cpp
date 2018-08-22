#include <iostream>
#include <stdio.h>
#include "..\headers\ArvoreNAria.h"
#include "..\headers\Info.h"

int main(){
    ArvoreNAria *arvore = new ArvoreNAria(3);
    arvore ->inserirNo(*new Info(15));
    arvore ->inserirNo(*new Info(8));
    arvore ->inserirNo(*new Info(9));
    arvore ->inserirNo(*new Info(5));
    arvore ->inserirNo(*new Info(3));
    arvore ->inserirNo(*new Info(21));
    arvore ->inserirNo(*new Info(17));
    arvore ->inserirNo(*new Info(12));
    std::cout << *arvore;
    getchar();
}

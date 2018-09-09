#include <iostream>
#include <stdio.h>
#include "..\headers\ArvoreNAria.h"
#include "..\headers\Info.h"

int main(){
    ArvoreNAria *arvore = new ArvoreNAria(2);
    arvore ->inserirNo(*new Info(15));
    arvore ->inserirNo(*new Info(9));
    arvore ->inserirNo(*new Info(8));
    arvore ->inserirNo(*new Info(7));
    //arvore ->removerNo(*new Info(9));


    arvore ->inserirNo(*new Info(5));
    arvore ->inserirNo(*new Info(3));
    arvore ->inserirNo(*new Info(21));
    arvore ->inserirNo(*new Info(18));
    arvore ->inserirNo(*new Info(12));
    arvore ->inserirNo(*new Info(11));
    arvore ->inserirNo(*new Info(26));
    arvore ->inserirNo(*new Info(30));
    arvore ->inserirNo(*new Info(2));
    arvore ->inserirNo(*new Info(13));
    arvore ->inserirNo(*new Info(14));
    arvore ->inserirNo(*new Info(16));
    arvore ->inserirNo(*new Info(10));
    arvore ->inserirNo(*new Info(17));
    //arvore ->inserirNo(*new Info(17));
    std::cout << *arvore;
    getchar();
    arvore->removerNo(*new Info(15));
    std::cout << *arvore;
    getchar();
    arvore->removerNo(*new Info(10));
    std::cout << *arvore;
    getchar();
    arvore->removerNo(*new Info(11));
    std::cout << *arvore;
    getchar();
    arvore->removerNo(*new Info(8));
    std::cout << *arvore;
    getchar();
    arvore->removerNo(*new Info(2));
    std::cout << *arvore;
    getchar();
}

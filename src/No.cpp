#include "../headers/No.h"
#include "../headers/Info.h"

No::No(unsigned int n){
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

void No::setInfo(int pos, Info i){
    *No::infos[pos] = i;
}
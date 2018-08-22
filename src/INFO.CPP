#include "..\headers\Info.h"

bool Info::operator<(Info& outra) const{
    return info<outra.info;
}

Info::Info(int inf){
    info = inf;
}

int Info::getInfo() const {
    return info;
}

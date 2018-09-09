#include "..\headers\Info.h"

bool Info::operator<(Info& outra) const{
    return info<outra.info;
}

bool Info::operator>(Info& outra) const{
    return info>outra.info;
}

Info::Info(int inf){
    info = inf;
}

int Info::getInfo() const {
    return info;
}

bool Info::operator==(Info& outra) const{
    return info == outra.info;
}

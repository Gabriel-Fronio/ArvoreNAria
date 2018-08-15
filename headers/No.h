#ifndef No_Class
#define No_Class

#include "Info.h"

class No {
    Info **infos;
    No **ptrs;
    
    public:
        No(unsigned int n);
        Info** getInfos() const;
        void setInfo(int pos, Info i);
};

#endif
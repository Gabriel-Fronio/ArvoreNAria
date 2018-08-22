#ifndef No_Class
#define No_Class

#include "Info.h"

class No {
    Info** infos;
    No **ptrs;
    int tamanho;

    public:
        No(unsigned int n);
        Info** getInfos() const;
        int getTamanho() const;
        No** getPtrs() const;
        void addInfo(Info& i);
        void setPtr(int pos, No* ptr);
};

#endif

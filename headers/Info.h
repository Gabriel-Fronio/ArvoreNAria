#ifndef Info_Class
#define Info_Class

class Info{
    int info;
    public:
        Info(int inf);
        bool operator<(Info& info) const;
        int getInfo() const;
};

#endif

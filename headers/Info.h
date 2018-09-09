#ifndef Info_Class
#define Info_Class

class Info{
    int info;
    public:
        Info(int inf);
        int getInfo() const;
        bool operator<(Info& info) const;
        bool operator>(Info& info) const;
        bool operator==(Info& info) const;
};

#endif

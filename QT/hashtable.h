#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<cassert>
#include<string>
#include<iostream>
#include<assert.h>
#include <QDebug>
#include<QString>
using namespace std;
template<typename E>
class KVpair {
private:
    char k[20];
    E e;
public:
    KVpair() {}
    KVpair(char* kval, E& eval)
    {
        strcpy_s(k , kval);
        e = eval;
    }
    KVpair(const KVpair& o)
    {
        strcpy_s(k , o.k); e = o.e;
    }

    void operator =(const KVpair& o)
    {
        strcpy_s(k ,o.k); e = o.e;
    }

    char* key() { return k; }
    void setKey(char* ink)
    { strcpy_s(k,strlen(ink)+1, ink); }
    E& value() { return e; }
};

template < typename E>
class hashdict {
private:


    int currcnt;


    int p(char* K, int i) const
    {
        return i;
    }

    int h(int x) const { return x % M; }
    int h(char* x) const {
        int i, sum;
        for (sum = 0, i = 0; x[i] != '\0'; i++) sum += (int)x[i];
        return sum % M;
    }
public:
    char EMPTYKEY[20];
     char TombStone[20];
    KVpair< E>* HT;
    int M;
    hashdict(int sz, char* k="0000") {
        M = sz;
        strcpy_s(EMPTYKEY , k);
        currcnt = 0;
        HT = new KVpair< E>[sz];
        for (int i = 0; i < M; i++)
            HT[i].setKey(EMPTYKEY);
        QString  filename;
        std::string str = filename.toStdString();
        const char*ch = str.c_str();
        strcpy_s(TombStone,ch);
    }

    ~hashdict() { delete HT;

    }

    E & find2(char*k)
    {
        int home;
        int pos = home = h(k);
        for (int i = 1; (strcmp(k, (HT[pos]).key())) &&
            strcmp(EMPTYKEY ,(HT[pos]).key()); i++)
            pos = (home + p(k, i)) % M;
        if (!strcmp(k, HT[pos].key()))
        {

            return (HT[pos]).value();
        }
    }
  bool find( char* k, E&obj)
  {

        int home;
        int pos = home = h(k);

        for (int i = 1; (strcmp(k , (HT[pos]).key())) &&
            strcmp(EMPTYKEY ,(HT[pos]).key()); i++)
            pos = (home + p(k, i)) % M;
        if (!strcmp(EMPTYKEY, (HT[pos]).key()))
        {

            return false;
        }
        else {

            obj = HT[pos].value();

            return true;

        }
    }
    int size() { return currcnt; }


    void insert(char* k,  E& it) {
        //Q_ASSERT(currcnt < M);
        int home;
        int pos = home = h(k);
        for (int i = 1; strcmp(EMPTYKEY, (HT[pos]).key())&&strcmp(TombStone, (HT[pos]).key()); i++) {
            pos = (home + p(k, i)) % M; // probe

        }
        KVpair< E> temp(k, it);
        HT[pos] = temp;
        currcnt++;
    };
    void remove(char*k)
    {
        int home;
        int pos = home = h(k);
        for (int i = 1; (strcmp(k, (HT[pos]).key())) &&
            (strcmp(EMPTYKEY, (HT[pos]).key())); i++)
            pos = (home + p(k, i)) % M;
        if (!strcmp(k, HT[pos].key()))
        {
       qDebug()<<"成功删除";
           HT[pos].setKey(TombStone);
       currcnt--;
        }
    }



    /*E removeAny() {
        assert(currcnt != 0, "Hash table is empty");
        int i;
        for (i = 0; i<M; i++)
            if ((HT[i]).key() != EMPTYKEY) {
                (HT[i]).setKey(EMPTYKEY);
                currcnt--;
                break;
            }
        return (HT[i]).value();
    }

    void clear() {
        for (int i = 0; i<M; i++) (HT[i]).setKey(EMPTYKEY);
        currcnt = 0;
    }*/

};



#endif // HASHTABLE_H

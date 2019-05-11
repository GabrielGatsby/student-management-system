#ifndef MYHASHMAP_H
#define MYHASHMAP_H
#include<typeinfo>
#include<string>
#include<iostream>
#include<fstream>
#include<QString>
#include<qdebug.h>
using namespace std;

//自创判断是否相同的函数
static int mystrcmp(string a, string b){
    return a.compare(b);
}

static int mystrcmp(int a,int b){
    if(a < b)
        return -1;
    if(a = b)
        return 0;
    if(a > b)
        return 1;
}

template<typename K, typename E>
class KVpair{
public:
    K key;
    E elem;

public:
    KVpair<K,E>* next;

    KVpair(K k = NULL, E e = NULL, KVpair<K,E>* n = NULL){
        key = k;
        elem = e;
        next = n;
    }

    K getKey(){
        return key;
    }

    E &getElem(){
        return elem;
    }


    void setTombstone(){
        if(typeid(key) == typeid(string))
            key = "-1";
    }

    bool isTombstone(){
        if(typeid(key) == typeid(string))
            if(!key.compare("-1"))
                return true;
        return false;
    }

};

template<typename K, typename E>
class myhashmap{
public:
    KVpair<K,E> **HT;
    int current;//哈希表占用量
    int true_current;//真实元素数量
    int maximum;//哈希表大小
    int half_maximum;//哈希表半个大小


public:


   myhashmap(int sz = 2000){
        current = 0;
        true_current = 0;
        half_maximum = sz;
        maximum = 2 * half_maximum;
        HT = new KVpair<K,E>*[maximum];//此时存储了一组空指针，注意，是空的
        for(int i=0;i<maximum;i++)//这句一定要加
            HT[i] = NULL;
    }



    unsigned long hashvalue(string str){//将输入字符串转换成长整型数返回
        int i,sum;
        for(sum=0,i=0;i<str.size();i++){
            sum+=(int)str[i];}
        return sum;
    }

    int myhash(K k){
        return hashvalue(k)%maximum;
    }//取余

    //二次哈希
    int p(K k, int i){
        int hashval = hashvalue(k);
        return i*i;
    }

    void hashInsert(KVpair<K,E>* nowKVpair){
        int double_hash=0;
        int home;
        int pos=home=myhash(nowKVpair->getKey())%maximum;
        while(HT[pos]!=NULL){
            if(!mystrcmp(HT[pos]->getKey(),nowKVpair->getKey())){
                KVpair<K,E>* temp;
                temp=HT[pos];
                while(temp->next){
                    temp=temp->next;
                    //qDebug()<<"         ffffffffffff!";
                }
                temp->next=nowKVpair;
                QString aaa = QString::number(pos, 10);
                //qDebug()<<"位置1："<<aaa;
                break;
            }
            else{
                double_hash++;
                pos = (home + p(nowKVpair->getKey(),double_hash))%maximum;
            }
        }
        if(HT[pos]==NULL){
            HT[pos]=nowKVpair;
            QString aaa = QString::number(pos, 10);
            //qDebug()<<"位置2："<<aaa;
        }
    }

    void insert(KVpair<K,E>* nowKVpair){
        if(current>=half_maximum){
            //cout<<"超过哈希表一半，不要再插入咯"<<endl;
            return;
        }
        hashInsert(nowKVpair);
        true_current++;
    }

    KVpair<K,E>* hashSearch(K key){
        int double_hash = 0;
        int home;
        int pos = home = myhash(key)%maximum;
        while(HT[pos]!=NULL){
            if(!mystrcmp(HT[pos]->getKey(),key)){
                return HT[pos];
            }
            else{
                double_hash++;
                pos = (home + p(key,double_hash))%maximum;
            }
        }
        if(HT[pos]==NULL){
            //cout<<"找不到";
            return NULL;
        }
    }

    KVpair<K,E>* search(K key){
        return hashSearch(key);
    }

    int getMaximum(){
        return maximum;
    }

    KVpair<K,E>* getPlace(int i){
        return HT[i];
    }

    ~myhashmap(){
        for(int i = 0 ; i < maximum; i++){
            if(HT[i]!=NULL){
                KVpair<K,E>* temp1;
                KVpair<K,E>* temp2;
                temp1=temp2=HT[i];
                while(temp1!=NULL){
                    temp2 = temp1->next;
                    delete temp1;
                    temp1 = temp2;
                }
                HT[i] = NULL;
            }
        }
    }

    clear(){
        for(int i = 0 ; i < maximum; i++){
            if(HT[i]!=NULL){
                KVpair<K,E>* temp1;
                KVpair<K,E>* temp2;
                temp1=temp2=HT[i];
                while(temp1!=NULL){
                    temp2 = temp1->next;
                    delete temp1;
                    temp1 = temp2;
                }
                HT[i] = NULL;
            }

        }

        current = 0;
        true_current = 0;

    }


};

#endif // MYHASHMAP_H

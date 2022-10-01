#include "./CacheDAO.h"
using namespace std;



int CacheDAO::getCacheSize(){
    return cacheSize;
}

void CacheDAO::insertEntry(string key, string value){
    m[key]={value,++timestamp};
    cout<<"Entry inserted to Database "<<key<<" "<<value<<endl;
}

void CacheDAO::removeEntry(string key){
    if(m.find(key)!=m.end()){
        m.erase(key);
        cout<<"Entry Erased from the DB "<<key<<endl;
    }
    cout<<"Entry Is not present in the DB "<<key<<endl;
}

void CacheDAO::evictEntry(string key){
    if(m.find(key)!=m.end()){
        m.erase(key);
        cout<<key<<" Entry is Evicted from the DB"<<endl;
    }
}

string CacheDAO::getValue(string key){
    if(m.find(key)==m.end()){
        cout<<"Key Not present"<<endl;
        return "";
    }
    else
        return m[key].first;
}

void CacheDAO::updateEntry(string key,string value){
    if(m.find(key)==m.end()){return;}
    else
        m[key]={value,++timestamp};
}

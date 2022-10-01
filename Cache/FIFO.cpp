#include "./FIFO.h"
using namespace std;

void FIFO::insert(string key,string value){
      int cacheSize = nCacheDAO->getCacheSize();
      if(nFIFOQ.size()==cacheSize) {
        evict();
      }
      nCacheDAO->insertEntry(key,value);
      nFIFOQ.push_front(key);
}

void FIFO::remove(string key){
    nCacheDAO->removeEntry(key);
    deque<string>::iterator it= nFIFOQ.begin();

    while(it++!=nFIFOQ.end()){
        if(*it==key){
            nFIFOQ.erase(it);
        }
    }
}

void FIFO::update(string key,string value){
    if(nCacheDAO->getValue(key)==""){
        cout<<"Key is not present in the cache"<<endl;
    }else{
        nCacheDAO->updateEntry(key,value);
    }
}

string FIFO::getValue(string key){
    return nCacheDAO->getValue(key);
}

void FIFO::evict(){
    string key;
    key = nFIFOQ.back();
    nFIFOQ.pop_back();
    nCacheDAO->evictEntry(key);
}



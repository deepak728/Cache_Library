#include "./LRU.h"
using namespace std;

void LRU::insert(string key,string value){
    if(nCacheDAO->getCacheSize()==nList.size()){
        evict();
    }
    nCacheDAO->insertEntry(key,value);
    if(nLRUMap.find(key)==nLRUMap.end()){
        nList.push_front(key);
        nLRUMap[key]=nList.begin();
    }
    moveEntryToFront(key);
}

void LRU::remove(string key){
    if(nLRUMap.find(key)==nLRUMap.end()){
        cout<<"Key is not Present"<<endl;
        nCacheDAO->removeEntry(key);
        return; 
    }
    nList.erase(nLRUMap[key]);
    nLRUMap.erase(key);
    nCacheDAO->removeEntry(key);
}

void LRU::moveEntryToFront(string key){
    if(nLRUMap.find(key)==nLRUMap.end()) return;
    nList.erase(nLRUMap[key]);
    nList.push_front(key);
    nLRUMap[key]=nList.begin();
}

void LRU::update(string key,string value){
    moveEntryToFront(key);
    nCacheDAO->updateEntry(key,value);
}

string LRU::getValue(string key){
    moveEntryToFront(key);
    return nCacheDAO->getValue(key);
}

void LRU::evict(){
    string key = nList.back();
    nList.pop_back();
    nLRUMap.erase(key);
    nCacheDAO->evictEntry(key);
}



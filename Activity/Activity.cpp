#include "./Activity.h"

using namespace std;

void Activity::setCacheType(CacheType cacheType){
    nCacheType = cacheType;
    if(nCacheType==LFUCache)
        nCache = new LFU();
    else if (nCacheType == LRUCache)
        nCache= new LRU();
    else if (nCacheType == FIFOCache)
        nCache = new FIFO();
    else 
        nCache = new Custom();
}

void Activity::addEntry(string key,string value){
    nCache->insert(key,value);
}
void Activity::removeEntry(string key){
    nCache->remove(key);
}
void Activity::updateEntry(string key,string value){
    nCache->update(key,value);
}
string Activity::getValue(string key){
    return nCache->getValue(key);
}

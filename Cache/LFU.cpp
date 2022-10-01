#include "./LFU.h"
using namespace std;

void LFU::insert(string key,string value){
    if(nKeyValue.find(key)!=nKeyValue.end()){
        update(key,value);
        return;
    }
    if(nKeyValue.size()==nCacheDAO->getCacheSize())
        evict();
    
    min_freq=0;
    nCacheDAO->insertEntry(key,value);
    nCount[key]=0;
    nCountList[min_freq].push_front(key);
    nKeyValue[key]=nCountList[min_freq].begin();
    return;
}

void LFU::remove(string key){
    if(nKeyValue.find(key)==nKeyValue.end()){
        cout<<"Key Not Found"<<endl;
        return;
    }
    nCacheDAO->removeEntry(key);
    nCountList[nCount[key]].erase(nKeyValue[key]);
    nKeyValue.erase(key);
    if(nCountList[nCount[key]].size()==0)
        nCountList.erase(nCount[key]);
    
    nCount.erase(key);
}

void LFU::update(string key,string value){
    if(nKeyValue.find(key)==nKeyValue.end()) return;
    nCacheDAO->updateEntry(key,value);
    update_freq(key);
}

void LFU::update_freq(string key){
    nCountList[nCount[key]].erase(nKeyValue[key]);
    if(nCountList[nCount[key]].size()==0){
        if(min_freq==nCount[key])
            min_freq++;
    }
    nCount[key]++;
    nCountList[nCount[key]].push_front(key);
    nKeyValue[key]=nCountList[nCount[key]].begin();
}


string LFU::getValue(string key){
        if(nKeyValue.find(key)==nKeyValue.end()) return "";
        update_freq(key);
        return nCacheDAO->getValue(key);
}

void LFU::evict(){
    string key=nCountList[min_freq].back();
    nCountList[min_freq].pop_back();
    nKeyValue.erase(key);
    nCount.erase(key);
    if(nCountList[min_freq].size()==0)
        nCountList.erase(min_freq);
    nCacheDAO->evictEntry(key);
}



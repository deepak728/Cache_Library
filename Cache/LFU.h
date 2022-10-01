#pragma once 
#include<bits/stdc++.h>
#include "./Cache.h"
#include "./Evict.h"
#include "../CacheDAO/CacheDAO.h"



class LFU:public Cache, public Evict{
    private:
        CacheDAO* nCacheDAO = new CacheDAO();
        unordered_map<string,int> nCount;
        unordered_map<string,list<string>::iterator> nKeyValue;
        unordered_map<int,list<string>> nCountList;
        int min_freq=0;
    public:

        void insert(string key,string value);
        void remove(string key);
        void evict();
        string getValue(string key);
        void update(string key,string value);
        void update_freq(string key);
};
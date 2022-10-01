#pragma once 
#include<bits/stdc++.h>
#include "./Cache.h"
#include "./Evict.h"
#include "../CacheDAO/CacheDAO.h"

class LRU:public Cache, public Evict{
    private:
        CacheDAO* nCacheDAO = new CacheDAO();
        list<string> nList;
        unordered_map<string,list<string>::iterator> nLRUMap;
    public:
        void insert(string key,string value);
        void remove(string key);
        void evict();
        string getValue(string key);
        void update(string key,string value);
        void moveEntryToFront(string key);
};
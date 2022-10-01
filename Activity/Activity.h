#pragma once 

#include<bits/stdc++.h>
#include "../Common/Common.h"
#include "../Cache/FIFO.h"
#include "../Cache/LRU.h"
#include "../Cache/LFU.h"
#include "../Cache/Custom.h"
#include "../Cache/Cache.h"

class Activity{
    private : 
        CacheType nCacheType;
    public:
        Cache* nCache;
        void addEntry(string key,string value);
        void removeEntry(string key);
        void updateEntry(string key,string value);
        string getValue(string key);
        void setCacheType(CacheType cacheType);

};
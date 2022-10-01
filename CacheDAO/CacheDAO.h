#pragma once 
#include <bits/stdc++.h>

class CacheDAO{
    private: 
        int timestamp=0;
        static const int cacheSize = 3;
        map<string,pair<string,int>> m;
    public : 
        int getCacheSize();
        void insertEntry(string key,string value);
        void removeEntry(string key);
        string getValue(string key);
        void evictEntry(string key);
        void updateEntry(string key,string value);
};
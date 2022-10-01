#pragma once 
#include<bits/stdc++.h>

class Cache{
    public:
        virtual void insert(string key,string value)= 0;
        virtual void remove(string key)=0;
        virtual void update(string key,string value)=0;
        virtual string getValue(string key)=0;
};
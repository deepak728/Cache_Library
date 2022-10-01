
#include<bits/stdc++.h>
#include "../Activity/Activity.h"
#include "../Common/Common.h"

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    Activity* nActivity = new Activity();
   
   string command;
   string cmd1,cmd2,cmd3,cmd4,cmd5;

   while(cin>>command){
        if(command=="Set_Cache"){
            cin>>cmd1;
            if(cmd1=="FIFO")
                nActivity->setCacheType(FIFOCache);
            else if (cmd1=="LRU")
                nActivity->setCacheType(LRUCache);
            else if (cmd1=="LFU")
                nActivity->setCacheType(LFUCache);
            else if (cmd1=="LRU")
                nActivity->setCacheType(CustomCache);

        } else if (command=="Add"){
            cin>>cmd1>>cmd2;
            nActivity->addEntry(cmd1,cmd2);

        }else if (command=="Remove"){
            cin>>cmd1;
            nActivity->removeEntry(cmd1);
        }else if (command=="Update"){
            cin>>cmd1>>cmd2;
            nActivity->updateEntry(cmd1,cmd2);
        }else if (command=="Get_Value"){
            cin>>cmd1;
            cout<<"Value of "<<cmd1<<" is "<<nActivity->getValue(cmd1)<<endl;
        }else if (command==""){

        }else if (command==""){

        }else if (command==""){

        }else if (command==""){

        }else if (command==""){

        }else if (command==""){

        }else if (command==""){

        }
   }



}

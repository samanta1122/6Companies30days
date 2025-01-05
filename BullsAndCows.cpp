#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int a(string &secret,string &guess,vector<int>&mp){
       int count=0;
       for(int i=0;i<secret.size();i++){
        if(secret[i]==guess[i]){
            mp[i]=1;
            count++;
        }
       }
       return count;
   }
   int b(string &secret,string &guess,vector<int> &mp){
    int count=0;
      for(int i=0;i<secret.size();i++){
        if(secret[i]!=guess[i]){
            bool ispresent=false;
            for(int j=0;j<guess.size();j++){
                if(secret[i]==guess[j] && mp[j]==0){
                    mp[j]=1;
                    ispresent=true;
                    break;
                }
            }
            if(ispresent){
                count++;
            }
        }
        else{
            mp[i]=1;
        }

      }
      return count;
   }
    string getHint(string secret, string guess) {
        vector<int> mp(secret.size(),0);
        string ans=to_string(a(secret,guess,mp))+"A"+to_string(b(secret,guess,mp))+"B";
        return ans;
    }
};
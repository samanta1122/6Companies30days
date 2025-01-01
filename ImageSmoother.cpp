#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<int>temp(n);
        int prevCorner = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int sum = 0;
                int cnt = 0;
                //bottom row
                if(i+1<m){
                    if(j-1>=0){
                        sum += img[i+1][j-1];
                        cnt++;
                    }
                    sum +=img[i+1][j];
                    cnt++;
                    if(j+1<n){
                        sum += img[i+1][j+1];
                        cnt++;
                    }
                }
                //right neighbor
                if(j+1<n){
                    sum += img[i][j+1];
                    cnt++;
                }
                if(j-1 >= 0){
                    sum += temp[j-1];
                    cnt++;
                }
                //current num
                sum += img[i][j];
                cnt++;
                //top
                if(i-1>=0){
                    if(j-1>=0){
                        sum += prevCorner;
                        cnt++;
                    }

                    sum += temp[j];
                    cnt++;

                    if(j+1<n){
                        sum += temp[j+1];
                        cnt++;
                    }
                }
                if(i-1>=0){
                    prevCorner = temp[j];
                }
                
                temp[j] = img[i][j];
                img[i][j] = sum/cnt;
            }
        }
        return img;
    }
};
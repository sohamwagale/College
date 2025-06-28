#include<bits/stdc++.h>
using namespace std;
//Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n])
            count++;
        if (count > 1)
            return false;
    }
    return true;
}

bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        if (nums[i] > nums[i + 1])
            count++;
        if(nums[n-1]>nums[0]) count++;
        if (count > 1)
            return false;
    }
    return true;
}

bool check(vector<int>& nums) {
    bool flag =true;
    bool rflag = false;
    int pivot = 0;
    int n= nums.size();
    int i=0;
    int ri =0;
    for(int i=0;i<n-1;i++){    
        if(nums[i]>nums[i+1]){
            pivot = i+1;
            rflag=true; 
            break;
        }
    }
    if(!rflag) return flag;
    for(int i=pivot;i<n-1;i++){    
        if(nums[i]>nums[i+1] || nums[i]>nums[0] || nums[i+1]>nums[0]){
            flag=false;
        }
    }
    if(nums[n-1]>nums[0]) flag =false;
    return flag;
}

int main(){
    vector<int> nums = {3,4,5,1,2};
    check(nums);
}
#include<bits/stdc++.h>
using namespace std;

int maxFrequencyElement(vector<int>& nums) {
    map<int, int> mp;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        mp[nums[i]]++;
    }
    int minf = sz;
    int minfe;

// Print frequency map (for debugging)
    cout << "Frequency of elements:\n";
    for (auto& x : mp) {
        cout << "Element: " << x.first << ", Frequency: " << x.second << endl;
    }


    for (auto& x: mp) {
        if(x.second <= minf){
            minf=x.second;
            minfe=x.first;
        }
        
    }  
    return minfe;
}

int main() {
    vector<int> nums = {1, 3, 2, 2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,45,5,5,5,5 ,3, 1, 3}; // Example input
    
    int result = maxFrequencyElement(nums);
    cout << "Element with the Lowest frequency: " << result << endl;
    
    return 0;
}
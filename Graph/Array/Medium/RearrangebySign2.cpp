#include<bits/stdc++.h>
using namespace std;
vector<int> RearrangebySign(vector<int> A, int n){
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        if(A[i] > 0){
            pos.push_back(A[i]);
        }else{
            neg.push_back(A[i]);
        }
    }
    if(pos.size() > neg.size()){
        //first fill the array with pos and neg till point where pos and neg are become equal 
        for(int i = 0; i < neg.size(); i++){
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        // Fill the remaining positives at the end of the array.
        int idx = 2 * neg.size();
        int i = neg.size();
        while(i < pos.size()){
            A[idx++] = pos[i++];
        }
    }else{
         //first fill the array with pos and neg till point where pos and neg are become equal 
        for(int i = 0; i < pos.size(); i++){
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        // Fill the remaining negatives at the end of the array.
        int idx = 2 * pos.size();
        int i = pos.size();
        while(i < neg.size()){
            A[idx++] = neg[i++];
        }
    }
    return A;
    
}
int main() {
    
  // Array Initialisation.
  
  vector<int> A {1,-2,-4,-5,3,4,9,-7,-6,-10,-9};
  int n = A.size();
  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
#include<bits/stdc++.h>
using namespace std;
//Brute force approach
vector<int> RearrangebySign(vector<int> A, int n){
    
    vector<int> pos;
    vector<int> neg;
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        if(A[i] < 0)
          neg.push_back(A[i]);
        else 
          pos.push_back(A[i]);
    }
    //copy the pos and neg array elements to the ans array
    for(int i = 0; i < n/2; i++){
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }
    return ans;
}
vector<int> _RearrangebySign(vector<int> A, int n){
    vector<int> result(n);
    int pos = 0;
    int neg = 1;
    for(int i = 0; i < n; i++){
        if(A[i] > 0){
          result[pos] = A[i];
          pos += 2;
        }else{
            result[neg] = A[i];
            neg += 2;
        }
    }
    return result;
}
int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = _RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
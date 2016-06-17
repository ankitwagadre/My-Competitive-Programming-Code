/* Sample program illustrating input/output */
#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;
int main(void){
   int test;
   cin >> test;
   for(int t=0; t<test; t++){

      int N;
      cin >> N;

      //int V[N];
      vector<int> v;
      for(int i = 0; i < N; i++){
         int a;
         cin >> a;
         v.push_back(a);
      }
      sort(v.begin(), v.end());

      int cnt = 0;
      if(N%2 == 0)
      {
          for(int i = 0; i < N - 1; i += 2)
          {
              //cout << " hi "<<  v[i] <<" diff = " <<  v[i+1] - v[i] << endl;
              cnt += v[i+1] - v[i];
          }
      }
      else
      {
          for(int i = 1; i < N; i++)
          {
              if (v[i] < v[i-1] + 1)
              {
                  cnt += v[i-1] + 1 - v[i];
                  v[i] = v[i-1] + 1;
              }
          }
      }

      //int result;
      cout << cnt << "\n";
   }


   return 0;
}

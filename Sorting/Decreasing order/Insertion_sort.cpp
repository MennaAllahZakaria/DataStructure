#include <bits/stdc++.h> 
#define nl            "\n"
#define sz(x)         int(x.size())



 using namespace std;
 

template<typename T = int> istream& operator>>(istream& in, vector<T>& v){
    for (T& i : v) in >> i;
    return in;
}

template<typename T = int> ostream& operator<<(ostream& out, const vector<T>& v){
    for (const T& x : v)
        out << x << ' ';
    return out;
}

/*
Time complexity

worst case   -> o(n^2)

best case    -> o(n)

average case -> o(n^2)
-------------------------
Space complexity

worst case   o(1)


*/






void insertion_sort(vector<int> &v){

for ( int i=1;i<sz(v);i++){

int val = v[i];

int j=i-1;
while (j>=0 && val>v[j]){
    v[j+1]=v[j];
    j--;
}

v[j+1]=val;
}



}

//-------------------------------------------------------------------------------------\\



int main(){
   
    int n;
    cin >>n;

    vector<int>v(n);
 cin>>v;
  insertion_sort(v);
    cout<<v;

    return 0;
}

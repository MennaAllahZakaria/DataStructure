 //         اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        

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
----------------------
worst case   -> o(n^2)

best case    -> o(n^2)

average case -> o(n^2)


Space complexity
----------------------
worst case   o(1)


*/



void selection_sort(vector<int>& v){

for ( int i=sz(v)-1;i>0;i--){
int max_index=i;
for ( int j=0;j<i;j++){

    if ( v[j]>v[max_index]) max_index=j;
}

swap(v[i],v[max_index]);

}
}




int main(){
  
    int n;
    cin >>n;

    vector<int>v(n);
  cin>>v;
  selection_sort(v);
  
  cout<<v;
    return 0;
}

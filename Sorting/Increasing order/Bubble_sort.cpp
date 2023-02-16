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

worst case   -> o(n^2)

best case    -> o(n)

average case -> o(n^2)

Space complexity

worst case   o(1)


*/



void Bubble_sort(vector<int>& v){
bool not_Sorted = true;

for ( int i=0;i<sz(v);i++){

for ( int j=1;j<sz(v)-i;j++){
if ( v[j-1]>v[j]){
    swap(v[j-1],v[j]);
    not_Sorted=false;
}
}
// if not_Sorted still true the vector is sorted now
if ( not_Sorted) return;
}

}

//-------------------------------------------------------------------------------------\\





int main(){
   
    int n;   cin >>n;
    vector<int>v(n);
     cin>>v;
    Bubble_sort(v);
    cout<<v;

    return 0;
}

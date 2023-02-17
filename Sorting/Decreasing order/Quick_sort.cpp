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

best case    -> o(n log (n))

average case -> o(n log (n))
-------------------------
Space complexity

worst case   o(n)

Queck sort is divide and conquer algorithm

*/



// quick sort in decreasing order

int partition( vector<int>&v, int l,int h){
       int pivot=v[h],i=l;
     for ( int j=l;j<h;j++){
        if ( v[j]> pivot) swap( v[i++],v[j]);
     }

swap(v[i],v[h]);
return i;
}

void quick_sort(vector<int> &v,int l,int h){
//base case
if ( h<=l) return;

int pi= partition(v,l,h);

quick_sort(v,l,pi-1);
quick_sort(v,pi+1,h);

}


//-------------------------------------------------------------------------------------\\

int main(){
   
    int n;    cin >>n;
    vector<int>v(n);
    cin>>v;
        quick_sort(v,0,n-1);
    cout<<v;

    return 0;
}


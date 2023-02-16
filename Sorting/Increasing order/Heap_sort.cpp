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

worst case   -> o(n log (n))

best case    -> o(n log (n))

average case -> o(n log (n))
-------------------------
Space complexity

worst case   o(1)


*/

void heapify(vector<int>&v,  int i)
{
int largest = i, l=2*i+1, r=l+1;

    if (l < sz(v) && v[l] > v[largest]) largest = l;
    if (r < sz(v) && v[r] > v[largest]) largest = r;
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, largest);
    }
}
  

void heap_sort(vector<int> &v){
 for (int i = sz(v)/2-1; i >= 0; i--)  {
    heapify(v, i);
 }
    for (int i = sz(v)-1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, 0);
    }

}


//-------------------------------------------------------------------------------------\\





int main(){
 
    int n;
    cin >>n;

    vector<int>v(n);
 cin>>v;
heap_sort(v);
    cout<<v;

    return 0;
}

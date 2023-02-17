 //         اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        

#include <bits/stdc++.h> 
#define nl            "\n"
#define sz(x)         int(x.size())



 using namespace std;
  void menna_allah(){
 ios_base ::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen("input3.txt","r", stdin), freopen ("output3.txt", "w", stdout);
  #endif

}

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

worst case   o(n)


Marge sort is divide and conquer algorithm

*/


// merge sort in decreasing order

void Merge(vector<int>&v, int low , int mid , int hight){
int size_1 = mid-low+1,   size_2 = hight-mid;

vector<int>left(size_1),right(size_2);

for ( int i=0;i<size_1;i++) left[i]=v[low+i];
for ( int i=0;i<size_2;i++) right[i]=v[mid+i+1];
int idx=low,l=0,r=0;
while ( l<size_1&& r<size_2){
v[idx++]=(left[l]>=right[r]?left[l++]:right[r++]);

}


while ( l<size_1) v[idx++]=left[l++];
while ( r<size_2) v[idx++]=right[r++];

}

void merge_sort(vector<int> &v,int low  ,int hight){
    // base case
    if ( hight<=low) return;

int mid=low+(hight-low)/2;
 merge_sort(v, low  , mid);
 merge_sort(v, mid+1, hight);

Merge(v,low,mid,hight);

}


//-------------------------------------------------------------------------------------\\


int main(){
    menna_allah();
    int n;
    cin >>n;

    vector<int>v(n);
 cin>>v;

merge_sort(v,0,n-1);
cout<<v;

    return 0;
}

 //         اللهم لا سهل الا ما جعلته سهلا و انت تجعل الصعب ان شئت سهل        

#include <bits/stdc++.h> 
#define nl            "\n"
#define sz(x)         int(x.size())
#define all(x)        x.begin(), x.end()  


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

worst case   -> o(n k)

best case    -> o(n k)

average case -> o(n k)
-------------------------
Space complexity

worst case   o(n+k)


*/





void distribute(vector<int> &v, deque<int > digit[],int power){
 
    for ( auto i:v){
        digit[(i/power)%10].push_front(i);
    }
}

void collect(deque<int> digit[],vector<int>&v){
    int i=0;

    for (int j=9;j>=0;j--){
        while ( !digit[j].empty()){
          v[i++]=digit[j].back();
          digit[j].pop_back();
        }
    }
}



void radix_sort(vector<int> &v,int mx){

int power=1;
deque<int> digit[10];
for ( int i=0;i<mx;i++){
    distribute(v,digit,power);
    collect(digit,v);
    power*=10;
}

}



//-------------------------------------------------------------------------------------\\




int main(){
   
    int n;
    cin >>n;

    vector<int>v(n);
 cin>>v;
 
 // to get the number of characters of the maximum element 
 int mx=sz(to_string(*max_element(all(v))));

radix_sort(v,mx);

    cout<<v;

    return 0;
}

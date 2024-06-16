#include <bits/stdc++.h>
using namespace std;

//템플릿 map -> 템플릿 vector<pair<>>
template<typename X,typename Y>
class pairvec;

//dict--------------------
template<typename K,typename V>
class dict{
    map<K,V> data;
    public:
    
    void insert(pair<K,V> p){ data.insert(p); }
    operator pairvec<K,V> ();
};

//pairvec----------------
template<typename X,typename Y>
class pairvec{
    vector<pair<X,Y>> data;

    public:
    void push(pair<X,Y> p){ data.push_back(p); }
    operator dict<X,Y> ();
};

//dict -> pairvec
template<typename K, typename V>
dict<K,V>::operator pairvec<K,V> (){
    pairvec<K,V> p;
    for( auto x : data ){
        p.push({x.first,x.second});
    }
    return p;
}

//pairvec -> dict
template<typename X, typename Y>
pairvec<X,Y>::operator dict<X,Y> (){
    dict<X,Y> d;
    for( int i=0; i<data.size(); i++ ){
        // d.data[data[i].first] = data[i].second;
        d.insert({data[i].first, data[i].second});
    }
    return d;
}

int main(){

dict<int,string> d;
pairvec<int,string> p;

p.push({1,"kim"});
p.push({2,"lee"});

d = p;

d.insert({-1,"um"});
d.insert({6,"six"});

p = d;
    return 0;
}
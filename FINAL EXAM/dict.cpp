#include <bits/stdc++.h>
using namespace std;

//딕셔너리 구현
template<typename K, typename V>
class dic{
    map<K,V> data;
    vector<K> keys;
    vector<V> vals;
    public:
    void push(K key, V val);
    void find_by_key(K key);
    void find_by_val(V val);

    template <typename k, typename v>
    friend ostream& operator << (ostream& out, dic<k,v> d);
};

//push
template<typename K, typename V>
void dic<K,V>::push(K key, V val){
    data[key] = val;
    keys.push_back(key);
    vals.push_back(val);
}
//f key
template<typename K, typename V>
void dic<K,V>::find_by_key(K key){
    if( data.find(key) != data.end() ){
        cout<<"key:"<<key<<" -> "<<data.at(key)<<endl;
        return;
    }
    cout<<"key:"<<key<<" not found"<<endl;
}
//f val
template<typename K, typename V>
void dic<K,V>::find_by_val(V val){
    for( int i=0; i<keys.size(); i++ ){
        if( data.find(keys[i]) != data.end() && data.at(keys[i]) == val){
            cout<<"val:"<<data.at(keys[i])<<" -> "<<keys[i]<<endl;
            return;
        }
    }
    cout<<"val:"<<val<<" not found"<<endl;
}


template<typename K,typename V>
ostream& operator << (ostream& out, pair<K,V> p){
    out<<"("<<p.first<<","<<p.second<<")";
    return out;
}
template<typename K,typename V>
ostream& operator << (ostream& out, dic<K,V> d){
    for( auto x : d.data ) cout<<x;
    out<<endl;
    return out;
}

template<typename K,typename V>
class UI{
    public:
    static void push(dic<K,V>& d){
        K key; V val;
        cin>>key>>val;
        d.push(key,val);
    }
    static void f_by_key(dic<K,V>& d){
        K key; cin>>key;
        d.find_by_key(key);
    }
    static void f_by_val(dic<K,V>& d){
        V val; cin>>val;
        d.find_by_val(val);
    }
    static void print( const dic<K,V>& d){
        cout<<d;
    }
};


int main(){

dic<string,string> dict;

while(1){
    cout<<"0:exit  1:push  2:f_by_key  3:f_by_val  4:print"<<endl;
    int x; cin>>x;
    if( x == 0 ){
        cout<<"exit\n"; return 0;
    }else if( x == 1 ){
        UI<string,string>::push(dict);
    }else if( x == 2 ){
        UI<string,string>::f_by_key(dict);
    }else if( x == 3 ){
        UI<string,string>::f_by_val(dict);
    }else if( x == 4 ){
        UI<string,string>::print(dict);
    }
}


    return 0;
}
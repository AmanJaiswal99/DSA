#include <iostream>
using namespace std;
#include <unordered_map>
 

int main(){

    unordered_map<string,int> m;
    //insert way 1
    m["mango"] = 100;

    //insert way 2
    m.insert(make_pair("Apple",120));

    // search
    if(m.count("mango")==1){
        cout << "prince of mango is " <<m["mango"] << endl;
    }

    if(m.count("guava")==0){
        cout << "guava doesnt exist" << endl;
    }

    // iterator to search

    auto f = m.find("mango");
    if(f!=m.end()){
        cout << "mango exists " << endl;
    }else{
        cout << "mango doesnt exist" << endl;
    }

    // deletion
    
    m.erase("apple");

}
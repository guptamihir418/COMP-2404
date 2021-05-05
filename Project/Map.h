#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>

template <class T>
class Map


/* This is Map class, Collection class which is very important, and used by 3 recordgenerator class*/

{
    template <class V>
    friend ostream& operator<<(ostream&, const Map<V>&);

    public:
        // Map();
        // ~Map();
        void add(T, Record*);
        int getSize();
        vector<T>& getKeyCollection(); // returned using a reference?
        vector<Record*>& operator[] (T);
    
    private:   
        vector<T> keys;
        vector<vector<Record*> > values;

};

// get size returns the size of any vector because size is same
template <class T>
int Map<T>::getSize(){

    return keys.size();

}

template <class T>
vector<T>& Map<T>::getKeyCollection(){

    return keys;
}




template <class T>
void Map<T>::add(T key, Record* rec){

    // if found add inside for loop
    for(int i = 0; i<keys.size(); ++i){

        if(key == keys[i]){
            values[i].push_back(rec);
            return;
        }

    }

    vector<Record*> r;
    r.push_back(rec);

    // if not found
    // means added at last
    keys.push_back(key);
    // values[keys.size()].push_back(rec);
    values.push_back(r);

}



template <class T>
vector<Record*>& Map<T>::operator[](T key){


    for (int i = 0; i<keys.size(); ++i){

        if(key == keys[i]){
            return values[i];
        }

    }
    cerr<<"Key not found"<<endl;
    exit(1);
}





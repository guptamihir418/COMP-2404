#ifndef REPORTDATA_H
#define REPORTDATA_H
#include <iostream>
using namespace std;
#include <string>
#include <iterator>

#include "CompareBehaviour.h"

template <class T>

class ReportData


/* report data class is the vector of whole reports*/
{

    template <class V>
    friend ostream& operator<<(ostream&, ReportData<V>&);
    public:

        ReportData(CompareBehaviour<T>*); 
        ~ReportData();
        void add(T, string);

    private:

        template <class U>
        class ReportRow{
            public:
                U key;
                string row;

                ReportRow(U k, string r) {
                    key = k;
                    row = r;
                }

        };

        vector<ReportRow<T> > reportRows;
        CompareBehaviour<T>* comparison;


};


template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* c)
{
    comparison = c;
}

template <class T>
ReportData<T>::~ReportData(){ delete comparison; }


template <class T>
void ReportData<T>::add(T key, string row){


    ReportRow<T> temp(key, row);

    typename vector<ReportRow<T> >::iterator itr;

    for(itr = reportRows.begin(); itr != reportRows.end(); ++itr){

        if(comparison->compare(key, itr->key)){
            reportRows.insert(itr, temp);
            return;
        }
    }

    reportRows.push_back(temp);

}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& rd){


    for(int i = 0; i<rd.reportRows.size(); ++i){

        output<<rd.reportRows[i].row;

    }

    return output;

}




#endif
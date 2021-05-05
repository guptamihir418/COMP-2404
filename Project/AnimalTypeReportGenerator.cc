#include <iostream>
using namespace std;
#include <sstream>
#include <iomanip>
#include <fstream>

#include "AnimalTypeReportGenerator.h"

AnimalTypeReportGenerator::AnimalTypeReportGenerator(CompareBehaviour<int>* c){

    reportResults = new ReportData<int>(c);

}
AnimalTypeReportGenerator::~AnimalTypeReportGenerator(){

    delete reportResults;

}


void AnimalTypeReportGenerator::formatData(Map<string> map){

    string key;
    vector<Record*> temp;
    Record* tempRec;
    for(int i = 0; i<map.getSize(); ++i){
        key = map.getKeyCollection().at(i);

        temp = map[key];

        tempRec = temp[0]; // only one record

        stringstream ss;

        if(tempRec->getSubRegion() == "All"){
            
            ss << setw(4) << left << tempRec->getProvince() << setw(30) << left << " "<< setw(6)<< right << 0 << endl;
            reportResults->add(0, ss.str());
        }
        else{

            ss<< setw(4) << left << tempRec->getProvince() << setw(30) << left << tempRec->getSubRegion() <<"     "<< tempRec->getAnimalCount()<<endl;
            reportResults->add(tempRec->getAnimalCount(), ss.str());


        }

    }
}

void AnimalTypeReportGenerator::compute(){

    int animalMapSize = AniTypeMap.getSize();
    vector<Record*> temp;

    Record* tempRec1;
    Map<string> highestMap;

    temp = AniTypeMap["Horses-Ponies"];

    for(int i = 0; i<temp.size(); ++i){
        int animalCount = 0;
        tempRec1 = temp[i];

        if((tempRec1->getYear() == 2011) || (tempRec1->getProvince() == "CAN")){
            continue;
        }

        if (tempRec1->getSubRegion() == "All"){
            animalCount = 0;
        }

        for(int j = i+1; j<temp.size(); ++j){

            if(temp[j]->getSubRegion() == "All"){
                continue;
            }

            if(temp[j]->getYear() == 2011){

                continue;
            }

            if(tempRec1->getProvince() == temp[j]->getProvince()){

                    if(temp[j]->getAnimalCount() > animalCount){

                        tempRec1 = temp[j];
                        animalCount = tempRec1->getAnimalCount();
                    }
            }
        }

        highestMap.add(tempRec1->getProvince(), tempRec1);
    }
    formatData(highestMap);
}
void AnimalTypeReportGenerator::printReport(){
    cout<<*reportResults<<endl;

    ofstream outfile("Report3.txt", ios::out);

    if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
    }

    outfile << *reportResults<<endl;
}

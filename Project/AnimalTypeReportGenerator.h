#ifndef ANIMALTYPEREPORTGENERATOR_H
#define ANIMALTYPEREPORTGENERATOR_H

#include "ReportGenerator.h"
#include "ReportData.h"

class AnimalTypeReportGenerator : public ReportGenerator

/* This is animalTypeReportGeneratorClass which is used in report 3 calculation
    and this is inherited class of ReportGenerator.cc*/

{

    public:
    AnimalTypeReportGenerator(CompareBehaviour<int>*);   /// wrong fix it
    virtual ~AnimalTypeReportGenerator();

    virtual void compute();
    void formatData(Map<string>);
    void printReport();


    private:
        ReportData<int>* reportResults;


};

#endif
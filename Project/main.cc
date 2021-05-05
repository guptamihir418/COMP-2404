#include "DescBehaviour.h"
#include "AscBehaviour.h"
#include "AnimalTypeReportGenerator.h"
#include "YearReportGenerator.h"
#include "RegionReportGenerator.h"
#include "ReportGenerator.h"

#include "Control.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    // AscBehaviour<float> a;
    // ReportGenerator::loadRecords();

    Control c;
    // YearReportGenerator* yp = new YearReportGenerator(&a);
    c.launch();
    // AnimalTypeReportGenerator hp(&d);
    // YearReportGenerator yp(&a);
    // RegionReportGenerator rp(&d);

    // ReportGenerator::loadRecords();
    
    
    // yp->compute();
    // yp->printReport();
    
    
    
    return 0;
}
#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "AnimalTypeReportGenerator.h"
#include "YearReportGenerator.h"
#include "RegionReportGenerator.h"
#include "AscBehaviour.h"
#include "DescBehaviour.h"

#include <vector>

class Control{


/* Main working of the program*/

    public:
        Control();
        ~Control();
        void launch();
    
    private:

        View v;
        vector<ReportGenerator*> reports;

};

#endif
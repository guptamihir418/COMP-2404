p: main.o Record.o ReportGenerator.o RegionReportGenerator.o YearReportGenerator.o AnimalTypeReportGenerator.o Control.o View.o
	g++ -o p main.o Record.o ReportGenerator.o RegionReportGenerator.o YearReportGenerator.o AnimalTypeReportGenerator.o Control.o View.o

main.o: main.cc
	g++ -c main.cc

Record.o: Record.cc Record.h Map.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Map.h ReportData.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h
	g++ -c ReportGenerator.cc

RegionReportGenerator.o: RegionReportGenerator.cc RegionReportGenerator.h Map.h ReportData.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h
	g++ -c RegionReportGenerator.cc

YearReportGenerator.o: YearReportGenerator.cc YearReportGenerator.h Map.h ReportData.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h
	g++ -c YearReportGenerator.cc

AnimalTypeReportGenerator.o: AnimalTypeReportGenerator.cc AnimalTypeReportGenerator.h Map.h ReportData.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h
	g++ -c AnimalTypeReportGenerator.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o p Report1.txt	Report2.txt Report3.txt








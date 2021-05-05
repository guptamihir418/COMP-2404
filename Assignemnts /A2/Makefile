A2:	main.o Date.o Call.o Time.o Subscriber.o View.o Array.o Telco.o Control.o
	g++ -o A2 main.o Date.o Call.o Time.o Subscriber.o View.o Array.o Telco.o Control.o

main.o:	main.cc Date.h Call.h Array.h Subscriber.h Telco.h Time.h View.h Control.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Call.o:	Call.cc Call.h
	g++ -c Call.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

Subscriber.o:	Subscriber.cc Subscriber.h
	g++ -c Subscriber.cc

View.o:	View.cc View.h
	g++ -c View.cc

Array.o:	Array.cc Array.h
	g++ -c Array.cc

Telco.o:	Telco.cc Telco.h
	g++ -c Telco.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

clean:
	rm -f *.o A2

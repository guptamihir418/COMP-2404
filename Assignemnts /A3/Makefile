A3: main.o Identifiable.o Criteria.o CriteriaArray.o Animal.o Client.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o View.o Control.o Shelter.o
	g++ -o A3 main.o Identifiable.o Criteria.o CriteriaArray.o Animal.o Client.o Match.o MatchList.o MatchListByScore.o MatchListByClient.o View.o Control.o Shelter.o
main.o:	main.cc defs.h
	g++ -c main.cc

CriteriaArray.o:	CriteriaArray.cc CriteriaArray.h
	g++ -c CriteriaArray.cc

Animal.o:	Animal.cc Animal.h defs.h
	g++ -c Animal.cc

Criteria.o:	Criteria.cc Criteria.h
	g++ -c Criteria.cc

Identifiable.o:	Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc

Client.o:	Client.cc Client.h
	g++ -c Client.cc

MatchListByScore.o:	MatchListByScore.cc MatchListByScore.h
	g++ -c MatchListByScore.cc

MatchListByClient.o:	MatchListByClient.cc MatchListByClient.h
	g++ -c MatchListByClient.cc

Match.o:	Match.cc Match.h
	g++ -c Match.cc

MatchList.o:	MatchList.cc MatchList.h
	g++ -c MatchList.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc	View.h
	g++ -c View.cc

Shelter.o:	Shelter.cc Shelter.h
	g++ -c Shelter.cc

clean:
	rm -f *.o A3


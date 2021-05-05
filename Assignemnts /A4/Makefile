A4: main.o Date.o Guest.o Room.o RoomArray.o Hotel.o Reservation.o Recorder.o StayRecorder.o GuestRecorder.o UpgradeRecorder.o ResManager.o Control.o View.o
	g++ -o A4 main.o Date.o Guest.o Room.o RoomArray.o Hotel.o Reservation.o Recorder.o StayRecorder.o GuestRecorder.o UpgradeRecorder.o ResManager.o Control.o View.o

main.o: main.cc
	g++ -c main.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Guest.o: Guest.cc Guest.h
	g++ -c Guest.cc

Room.o: Room.cc Room.h defs.h
	g++ -c Room.cc 

RoomArray.o: RoomArray.cc RoomArray.h
	g++ -c RoomArray.cc

Hotel.o: Hotel.cc Hotel.h
	g++ -c Hotel.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Recorder.o: Recorder.cc Recorder.h
	g++ -c Recorder.cc

StayRecorder.o: StayRecorder.cc StayRecorder.h Recorder.h
	g++ -c StayRecorder.cc

GuestRecorder.o: GuestRecorder.cc GuestRecorder.h Recorder.h
	g++ -c GuestRecorder.cc

UpgradeRecorder.o: UpgradeRecorder.cc UpgradeRecorder.h Recorder.h
	g++ -c UpgradeRecorder.cc

ResManager.o: ResManager.cc ResManager.h
	g++ -c ResManager.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o A4


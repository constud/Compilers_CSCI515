# Usage:     ./dealer seed num_moves | short_con
all: dealer short_con

dealer: dealer.cpp
	g++ -o dealer dealer.cpp

short_con: threecardmonte.o time_threecardmonte.o
	g++ -o short_con threecardmonte.o time_threecardmonte.o
	
mac_short_con: mac_threecardmonte.o time_threecardmonte.o
	g++ -o mac_short_con mac_threecardmonte.o time_threecardmonte.o

linux_short_con_better: linux_threecardmonte_better.o time_threecardmonte.o
	g++ -o linux_short_con_better linux_threecardmonte_better.o time_threecardmonte.o



linux_short_con: linux_threecardmonte.o time_threecardmonte.o
	g++ -o linux_short_con linux_threecardmonte.o time_threecardmonte.o

threecardmonte.o: threecardmonte.cpp 
	g++ -c threecardmonte.cpp
	
time_threecardmonte.o: time_threecardmonte.cpp
	g++ -c time_threecardmonte.cpp

clean:
	rm -f short_con dealer threecardmonte.o time_threecardmonte.o dealer.o

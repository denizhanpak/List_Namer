List_Namertest: List_Namer.o List_Namertest.o
		g++ List_Namertest.o List_Namer.o -o List_Namer

List_Namer.o: List_Namer.cpp List_Namer.h
		g++ -c List_Namer.cpp

List_Namertest.o: List_Namertest.cpp List_Namer.h
		g++ -c List_Namertest.cpp

clean:
	rm List_Namertest List_Namertest.o List_Namer.o

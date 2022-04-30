all: zadatak6

zadatak6: zadatak6.cpp
	g++ -fopenmp -Wall zadatak6.cpp -o zadatak6
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o zadatak6

run:
	./zadatak6 4 8

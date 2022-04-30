all: zadatak5

zadatak5: zadatak5.cpp
	g++ -fopenmp -Wall zadatak5.cpp -o zadatak5
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o zadatak5

run:
	./zadatak5 4

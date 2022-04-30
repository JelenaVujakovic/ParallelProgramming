all: zadatak3

zadatak3: zadatak3.cpp
	mpic++ zadatak3.cpp -o zadatak3
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o zadatak3

run:
	mpirun -np 4 ./zadatak3

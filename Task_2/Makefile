all: zadatak2

zadatak2: zadatak2.cpp
	mpic++ zadatak2.cpp -o zadatak2
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o zadatak2

run:
	mpirun -np 4 ./zadatak2 14

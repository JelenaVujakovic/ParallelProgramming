all: zadatak1

zadatak1: zadatak1.cpp
	mpic++ zadatak1.cpp -o zadatak1
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o zadatak1

run:
	mpirun -np 4 ./zadatak1

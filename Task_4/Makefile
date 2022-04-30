all: zadatak4

zadatak4: zadatak4.cpp
	mpic++ zadatak4.cpp -o zadatak4
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o zadatak4

run:
	mpirun -np 4 ./zadatak4 input_vector.txt input_matrix.txt

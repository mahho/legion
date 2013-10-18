CC=g++
all: clean encoder decoder 

encoder:
	$(CC) encoder.cpp -o encoder -L.. -Wl,-rpath,.. -lleg

decoder: 
	$(CC) decoder.cpp -o decoder -L.. -Wl,-rpath,.. -lleg
    
clean:
	rm -f encoder decoder
    
    
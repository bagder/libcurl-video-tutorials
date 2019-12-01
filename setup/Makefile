CC = `curl-config --cc`
LIBS = `curl-config --libs`

mycurlapp: mycurlapp.o
	$(CC) -g -o $@ $< $(LIBS)

mycurlapp.o: mycurlapp.c
	$(CC) -g -c $<

clean:
	rm -f mycurlapp.o mycurlapp

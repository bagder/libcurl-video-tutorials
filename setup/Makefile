CC = `curl-config --cc`
LIBS = `curl-config --libs`

sample: sample.o
	$(CC) -g -o $@ $< $(LIBS)

sample.o: sample.c
	$(CC) $(CFLAGS) -g -c $<

clean:
	rm -f sample.o sample

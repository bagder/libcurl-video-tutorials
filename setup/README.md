[table of contents](../) [next: global](../global/)

# Video

[Youtube: libcurl video tutorial: setup](https://youtu.be/DVR8N9ob_ZY)

# setup a makefile that builds our code

Using Linux and gcc, we create a [Makefile](Makefile) and a first C program
embryo called [mycurlapp.c](mycurlapp.c).

When created, we can invoke `make` to build our program `mycurlapp` and we can
invoke it from the command line.

We can reuse this Makefile in several future episodes easily as we will keep
naming our source code `mycurlapp.c`.

## curl-config

The Makefile uses the `curl-config` tool, which typically gets installed with
curl. It is used to extract information about the curl build.

## Makefile

This is not really a make school but here's how the basic stuff in the file
works:

    CC = `curl-config --cc`

This sets the `CC` variable to hold the contents of what `curl-config --cc`
outputs. That's the name of the compiler that was used to build libcurl. Most
commonly this is plain `gcc`. We could possibly make it `CC = gcc` too.

    LIBS = `curl-config --libs`

This sets the `LIBS` variable to hold the contens of what `curl-config --libs`
outputs. That's a list of linker options necessary to link with libcurl on
this machine. Most commonly, this is `-lcurl`. We could also probably get away
with simply doing `LIBS = -lcurl`.

    mycurlapp: mycurlapp.o

This is the first rule of the makefile and thus the "default" one that will be
checked for a plain `make` invoke.

The *output* called `mycurlapp` depends on the files on the right side of the
colon. There's only one file there: `mycurlapp.o`. If the `.o` file is newer than
`mycurlapp`, then the following command will be executed:

    $(CC) -g -o $@ $< $(LIBS)

The CC variable (that is the compiler) is used and a command line is created
with a few options like `-g` and `-o`. `$@` is an automatic variable that
holds the name from the left side of the colon in the line above (`mycurlapp`),
`$<` holds the names on the ride side of the colon in the line above
(`mycurlapp.o`) and `$LIBS` is often just `-lcurl`.

In a typical machine, the command line that runs is thus something like:
`gcc -g -o mycurlapp mycurlapp.o -lcurl`.

    mycurlapp.o: mycurlapp.c

The object file depends on the C file. If the object file is missing or if the
C file is newer than the object file, run the following command:

    $(CC) -g -c $<

Again, `$<` holds the names on the ride side of the colon in the line above,
which one is `mycurlapp.c` which makes this run something like: `cc -g -c
mycurlapp.c`. The `-c` flag to gcc makes it produce the object file from the C
file.

    clean:
        rm -f mycurlapp.o mycurlapp

Here's a special target that lets us do `make clean` and then this command
line is run. Handy when we want to wipe previous build results and start over,
by force.

## mycurlapp.c

The point in this episode is only that the code uses libcurl functions so we
need to make sure the build succeeds. We don't care very much what exactly the
code does. Move on to [simplest](../simples/) for that.

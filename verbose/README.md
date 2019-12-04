[prev: receive data](../receive-data/) [table of contents](../) next: other protocols

# Video

[Youtube: libcurl video tutorial: verbose]()

# Set `CURLOPT_VERBOSE` to get more knowledge

In this episode we explore what happens when a transfer returns an error and
how you as a libcurl user can go ahead to get more information and details
about it.

The first step there is to set the
[CURLOPT_VERBOSE](https://curl.haxx.se/libcurl/c/CURLOPT_VERBOSE.html) option
which will "insider information" about what's going on.

Other options to set to help out include
[CURLOPT_ERRORBUFFER](https://curl.haxx.se/libcurl/c/CURLOPT_ERRORBUFFER.html)
and or in some cases just properly investigating the response headers by
setting [CURLOPT_HEADER](https://curl.haxx.se/libcurl/c/CURLOPT_HEADER.html).


## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

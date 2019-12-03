[prev: simplest](../simplest/) [table of contents](../) next: CURLOPT_VERBOSE

# Video

[Youtube: libcurl video tutorial: receive data](https://youtu.be/nbTaHEocCuo)

# Use a write callback

(This example code is inspired by the
[getinmemory.c](https://curl.haxx.se/libcurl/c/getinmemory.html) example.)

By default libcurl sends received data to stdout, which is rarely what a user
wants to do. Instead, applications typically sets up a "write callback" with
the
[CURLOPT_WRITEFUNCTION](https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html)
option to
[curl_easy_setopt()](https://curl.haxx.se/libcurl/c/curl_easy_setopt.html) -
and that gets called for every little peace of data that libcurl downloads.

The write callback gets a custom pointer passed to it and in this example we
create a struct (`struct memory`) that we declare in the main function and is
called `chunk` there which we pass a pointer to into the write callback. The
pointer is passed on via the
[CURLOPT_WRITEDATA](https://curl.haxx.se/libcurl/c/CURLOPT_WRITEDATA.html)
option.

In the `writecallback` function, the logic will use `realloc()` to dynamically
expand our receive buffer as more data is delivered, and the new data is
appended to the end of that buffer every time it gets invoked.

In the end, if no error occured, the main function will output a short message
to stdout saying how many bytes it actually ended up receiving.

## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

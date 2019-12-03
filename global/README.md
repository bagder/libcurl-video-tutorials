[prev: setup](../setup/) [table of contents](../) [next: simplest](../simplest/)

# Video

[Youtube: libcurl video tutorial: global](https://youtu.be/X3bq2uf0OEU)

# global init and cleanup

Before any libcurl functions are invoked, you should call
[curl_global_init()](https://curl.haxx.se/libcurl/c/curl_global_init.html) and
once all libcurl usage is done, call the corresponding
[curl_global_cleanup()](https://curl.haxx.se/libcurl/c/curl_global_cleanup.html).

The `mycurlapp.c` example here shows it get done with the `CURL_GLOBAL_ALL`
argument, which inits as much as possible.

## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

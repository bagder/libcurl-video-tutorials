[prev: head](../head/) [table of contents](../) next: other protocols

# Video


# More protocols

When we set the URL to transfer with the
[CURLOPT_URL](https://curl.haxx.se/libcurl/c/CURLOPT_URL.html) option, we can
ask for a URL using any of the protocols, URL schemes, that libcurl supports.

To try this out, we make the code accept a URL as a command line argument and
we try passing in a few different schemes. `FILE`, `FTP`, plain `HTTP` etc.

A different URL scheme doesn't change the libcurl program. It works the same
way independently of what scheme the URL is using.

## Limit what protocols to accept

Thanks to
[CURLOPT_PROTOCOLS](https://curl.haxx.se/libcurl/c/CURLOPT_PROTOCOLS.html), an
application can tell libcurl exactly what protocols to accept in a given URL
so even if the application accepts a URL as an argument, it can still restrict
libcurl without having to parse the URL itself.

(URL parsing is also possible with libcurl, but is the subject of a separate
episode.)

## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

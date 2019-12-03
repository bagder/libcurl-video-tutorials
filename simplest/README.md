[prev: setup](../setup/) [table of contents](../) [next: write callback](../write-callback/)

# Video

[Youtube: libcurl video tutorial: simplest](https://youtu.be/Uha3JGPRIQs)

# simplest possible HTTPS client code

We go through the basics of the libcurl API and concepts and create [the
simplest possible HTTP client code](mycurlapp.c) we can.

[mycurlapp.c](mycurlapp.c) first declares a `CURL *` handle and then calls
[curl_easy_init()](https://curl.haxx.se/libcurl/c/curl_easy_init.html) to
create one.

If the handle gets created successfullly, the function calls
[curl_easy_setopt()](https://curl.haxx.se/libcurl/c/curl_easy_setopt.html) for
that handle, sets the second argument to
[CURLOPT_URL](https://curl.haxx.se/libcurl/c/CURLOPT_URL.html) and the exact
URL to transfer in the third argument. `https://example.com` to be exact.

Once the URL has been set for the handle, the example performs the transfer by
calling
[curl_easy_perform()](https://curl.haxx.se/libcurl/c/curl_easy_perform.html)
and passing in the handle as argument. The perform function returns an error
code in a `CURLcode` type that the function recevies in the variable named
`res`.

If `res` isn't `CURLE_OK` the transfer failed somehow and the program outputs
an eror message and produces a text version from the error code by calling
[curl_easy_strerror()](https://curl.haxx.se/libcurl/c/curl_easy_strerror.html)
with the error code as argument.

Finally, it cleans up the handle again by calling
[curl_easy_cleanup()](https://curl.haxx.se/libcurl/c/curl_easy_cleanup.html)
and passin in the handle as argument.

Ultimately, the function returns a zero.

## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

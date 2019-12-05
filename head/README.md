[prev: verbose](../verbose/) [table of contents](../) [next: more protocols](../more-protocols/)

# Video


# HEAD requests

A HTTP request starts with a "method", and code we've written so far in this
series (for example the [simplest](../simplest/) and [receive
data](../receive-data/) episodes) have only used `GET` which is the method
used for retriving data.

Another well used and useful HTTP method is `HEAD`. `HEAD` is similar to `GET`
in many regards and the server should send back identical response headers as
to a `GET` for the same resources, but a `HEAD` never gets any data
back. There's no response body to a `HEAD` request, which is also a reason why
the libcurl for this is called `CURLOPT_NOBODY`!

You tell libcurl you want a `HEAD` request by setting the
[CURLOPT_NOBODY](https://curl.haxx.se/libcurl/c/CURLOPT_NOBODY.html) option to
[curl_easy_setopt()](https://curl.haxx.se/libcurl/c/curl_easy_setopt.html).

(The `CURLOPT_NOBODY` option incidentally also works fine for other protocols
than `HTTP` when you want to get the headers or meta-data only but avoid
transferring a response body.)


## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

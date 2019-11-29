# simplest possible HTTPS client code

We're going through the initial basics of the libcurl API and concepts and
create [the simplest possible HTTP client code](sample.c) we can.

 - [curl_easy_init](https://curl.haxx.se/libcurl/c/curl_easy_init.html)
 - [curl_easy_setopt](https://curl.haxx.se/libcurl/c/curl_easy_setopt.html)
 - [CURLOPT_URL](https://curl.haxx.se/libcurl/c/CURLOPT_URL.html)
 - [curl_easy_perform](https://curl.haxx.se/libcurl/c/curl_easy_perform.html)
 - [curl_easy_strerror](https://curl.haxx.se/libcurl/c/curl_easy_strerror.html)
 - [curl_easy_cleanup](https://curl.haxx.se/libcurl/c/curl_easy_cleanup.html)

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

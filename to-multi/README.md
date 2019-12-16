[prev: setup](../setup/) [table of contents](../) [next: receive data](../receive-data/)

# Video

TBD

# Convert simple easy-using program to multi API

We start off with the code from the [../simplest](simplest) episode: a very
simple and basic libcurl application doing nothing but a very basic HTTPS
transfer.

The easy API is blocking and does a full transfer in one go before it returns.

The multi API is non-blocking, can do numerous of transfers in parallel.

We still create `CURL *` handles with
[curl_easy_init()](https://curl.haxx.se/libcurl/c/curl_easy_init.html) that
represent the specific transfer we want to do and we still set options for
that transfer with
[curl_easy_setopt()](https://curl.haxx.se/libcurl/c/curl_easy_setopt.html).

The big difference is in how we drive that particular transfer. With the multi
interface, we first create a "multi handle" with
[curl_multi_init()](https://curl.haxx.se/libcurl/c/curl_multi_init.html). This
handle can be used to drive a number of concurrent transfers and you can also
set specific options that controls how the multi transfer will be performed.

With a "multi handle" created, you continue and add "easy handles" to it. The
easy handles then being the transfers you want to have done by the multi
transfer. You can add and remove easy handles to and from the multi handle at
any point as long as the multi handle exists.

In our simple example app here, we create a multi handle and just add a single
easy handle to it for the one transfer we want to do.

When we have a transfer added to the multi handle, we call
[curl_multi_perform()](https://curl.haxx.se/libcurl/c/curl_multi_perform.html)
that will do a little bit of "transfer" until it would block and then return
back control to our program. A full transfer will typically require that we
invoke this function many times until the transfer is or the transfer**s** are
completed.

[curl_multi_perform()](https://curl.haxx.se/libcurl/c/curl_multi_perform.html)
stores the number of "still running" transfers in the integer we pass to it in
its second argument. In this example we use that counter as a signal of when
to stop the loop. When `still_running` reaches zero, the loop has nothing more
to do.

While `still_running` is non-zero however, we call
[curl_multi_poll()](https://curl.haxx.se/libcurl/c/curl_multi_poll.html) to
wait for network traffic or an internal timeout before we continue.

When the loop ends and the transfer is complete, we:
- remove the easy handle again from the multi handle
- close the easy handle
- close the multi handle
- cleanup the global context

## setup

Using the Makefile from the [setup](../setup/) episode, we build the program
and test it.

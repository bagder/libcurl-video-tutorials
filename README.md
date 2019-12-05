# libcurl video tutorials

A video tutorials series on how to write Internet applications using libcurl
with [Daniel Stenberg](https://daniel.haxx.se/), founder and lead developer of
the curl project.

Each episode has a title and focused purpose. The source code used and
discussed in each episode is made available here as well as extra links and
useful materials.

All code is written using C. A reasonably modern libcurl version is assumed.

Episode are 10-15 minutes long and only occasionally longer.

## Episodes

1. [setup](setup/) &#128249; a makefile that builds our code (using Linux and gcc)

2. [global](global/) &#128249; init and cleanup

1. [simplest](simplest/) &#128249; possible HTTPS client code

2. [receive data](receive-data/) &#128249; by using a write callback

3. [verbose](verbose/) &#128249; enable CURLOPT_VERBOSE to get more info

3. [head](head/) do HTTP HEAD and something about HTTP methods

3. [more protocols](more-protocols/) make the client download HTTP and FTP too (and limit protocols)

2. certificate verification for HTTPS clients

6. HTTP POST

7. HTTP PUT - with read callback

8. Modifying the HTTP request headers

8. debug callback

8. Retrieving the HTTP response code after a successful transfer

8. multi-part formpost

9. use cookies and login to a site with POST

10. different HTTP versions

11. parse URLs with libcurl

12. do two transfers in parallel with the multi API

13. do many parallel transfers and add new ones before all the existing are done

## Concept

Each episode should be short and focused on the topic only.

Episodes will be named, not numbered, so that we can insert new ones in
between older ones if we think that suits the narrative.

## Request episodes!

If you have additional ideas or thoughts of more topics and angles to cover, please [file an issue](https://github.com/bagder/libcurl-video-tutorials/issues) and explain!

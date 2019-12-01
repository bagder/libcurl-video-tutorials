# libcurl video tutorials

This is a planned series of video tutorials on how to write Internet
applications using libcurl. With [Daniel Stenberg](https://danie.haxx.se/),
founder of lead developer of the curl project.

Each episode has a title and planned goal and purpose. The source code used
and discussed in each episode is made available here as well as extra links
and useful materials.

All code will be written using C. A reasonably modern libcurl version is
assumed.

Ideally, each episode will be no longer than 10-15 minutes.

## Episodes

1. [setup](setup/) a makefile that builds our code (using Linux and gcc)

2. [global](global/) init and cleanup

1. [simplest](simplest/) possible HTTPS client code

2. add write callback

3. make the client download HTTP and FTP too

2. certificate verification details for HTTPS clients

4. limit what protocols to accept

6. HTTP POST example

7. HTTP PUT example - with read callback

8. Modifying the HTTP request headers

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

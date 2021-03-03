/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURLM *multi;
  CURL *curl;
  CURLcode res;
  int still_running = 1;

  curl_global_init(CURL_GLOBAL_ALL);

  multi = curl_multi_init();
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

  curl_multi_add_handle(multi, curl);

  while(still_running) {
    CURLMcode mc; /* curl_multi_poll() return code */
    int numfds;

    /* we start some action by calling perform right away */
    mc = curl_multi_perform(multi, &still_running);

    if(still_running)
      /* wait for activity, timeout or "nothing" */
      mc = curl_multi_poll(multi, NULL, 0, 1000, &numfds);

    if(mc != CURLM_OK) {
      fprintf(stderr, "curl_multi_poll() failed, code %d.\n", mc);
      break;
    }
  }

  curl_multi_remove_handle(multi, curl);
  curl_easy_cleanup(curl);
  curl_multi_cleanup(multi);
  curl_global_cleanup();
  return 0;
}

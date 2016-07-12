Use this in your project!

For exmaple, if your project gets this HTTP GET request:

  GET /index.html HTTP/1.1
  
then you will need to send back the index.html file in this directory! To
do this you need to send the HTTP Response Header back which will need
to have lines similar to:

  HTTP/1.1 200 OK
  Server: 60334Project Server
  Connection: close
  Content-Type: text/html
  
  [index.html content goes here]
  
It is very important that the first line, "Connection: close", and 
"Content-Type: MIME_TYPE" are present in the output.

Required MIME types:
  .html files: text/html
  .css files: text/css
  .jpg files: image/jpeg
  .334html files: text/html

HTTP GET requests with url decoding must be supported.
HTTP POST requests (from a form, text and password fields) must be supported.

.334html are files that replace provided GET / POST name parameters in the file. The
parameters are denoted with a prefixed '$'. Use regex_replace() to find and replace
such.


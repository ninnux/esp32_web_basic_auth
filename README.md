# esp32 component for web basic auth implementation

## how to

- add #include "esp32_web_basic_auth.h" on your web app

- use base64 shell commmand to code <user>:<password> 
- add base64 string on menuconfig component field "BASIC AUTH WEB user and password"

- protect your resource inside the handler

### example
```
if(!esp32_web_basic_auth(req)){
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, "<h1>Hello Secure World!</h1>", -1); 
}else{
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, "<h1>Ciaone!!</h1>", -1); 

}  
```


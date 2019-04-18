#include <esp_https_server.h>

#define WWW_USER_PASS_BASE64 CONFIG_WWW_USER_PASS_BASE64 

int esp32_web_basic_auth(httpd_req_t *req);

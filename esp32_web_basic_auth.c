
#include "esp32_web_basic_auth.h"

#include <esp_log.h>
static const char *TAG="APP";

int esp32_web_basic_auth(httpd_req_t *req){

    char*  buf;
    size_t buf_len;
    char* check;

    buf_len = httpd_req_get_hdr_value_len(req, "Authorization") + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
	check=malloc(sizeof(WWW_USER_PASS_BASE64)+6);
        if (httpd_req_get_hdr_value_str(req, "Authorization", buf, buf_len) == ESP_OK) {
            sprintf(check,"Basic %s",WWW_USER_PASS_BASE64); 
 	    if(!strncmp(buf,check,strlen(check))){
                ESP_LOGI(TAG, "%s", "OK");
    	    	httpd_resp_set_status(req, "200 Ok");
		return 0;
	    }else{
                ESP_LOGI(TAG, "%s", "NO");
       		httpd_resp_set_status(req, "403 Forbidden");
	    }	
        }
        free(buf);
        free(check);
    }else{
       httpd_resp_set_hdr(req, "WWW-Authenticate", "Basic realm=pippo");
       ESP_LOGI(TAG, "WWW-Authoicate:%s","culo");
       httpd_resp_set_status(req, "401 Unauthorized");
       ESP_LOGI(TAG, "401:%s","culo");
    }
    return 1;
}

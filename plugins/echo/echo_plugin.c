#include "../../uwsgi.h"

extern struct uwsgi_server uwsgi;


int uwsgi_echo_request(struct wsgi_request *wsgi_req) {

	wsgi_req->status = 200;
	wsgi_req->response_size = write(wsgi_req->poll.fd, wsgi_req->buffer, wsgi_req->uh.pktsize);
	
	return 0;
}

struct uwsgi_plugin echo_plugin = {

	.name = "echo",
	.modifier1 = 101,
	
	.request = uwsgi_echo_request,
};

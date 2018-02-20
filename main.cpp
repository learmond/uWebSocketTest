#include <uWS/uWS.h>
#include <iostream>
#include <string>

using namespace std;

typedef uWS::WebSocket<uWS::SERVER> uWSvr;

int main() {
    uWS::Hub hub;

    hub.onConnection([](uWSvr* ws, uWS::HttpRequest req) {
        cout << "Client connected" << endl;
    });

    hub.onDisconnection([](uWSvr*, int code, char* msg, size_t len) {
        cout << "Client disconnect: " << code << endl << string(msg,len) << endl;
    });

    hub.onMessage([](uWSvr* ws, char* msg, size_t len, uWS::OpCode opCode) {
        switch( opCode ) {
            case uWS::TEXT:
                cout << "<==== " << string(msg, len) << endl;
                ws->send(msg, len, opCode);
            break;
            default:
                cout << "Msg: " << opCode << "  " << msg << endl;
        }
    });

    if( hub.listen(4115)) {
        cout << "Listening on: 4115" << endl;
        hub.run();
    }
}
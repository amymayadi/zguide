//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
//
#include <zmq.hpp>
#include <string>
#include <iostream>

int main (int argc, char *argv[])
{
    bool bMulThread = false;
    int nThreadNum = 0;
    if(argc==2) {
        bMulThread = true;
        nThreadNum = atoi(argv[1]);
    }
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to hello world server..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (8); //(6);
        if(bMulThread)
        {
            std::string strThreadNum = argv[1];
            std::string str = strThreadNum + ":Hello";
            std::cout << "str:" << str <<std::endl;
            memcpy ((void *) request.data (), str.c_str(), 7); //"Hello", 5);
            std::string tmp = (char *)request.data ();
            std::cout << "reguest:" << tmp << std::endl;
            std::cout << "Thread " << strThreadNum << " Sending Hello " << request_nbr << "..." << std::endl;
        }else{
            memcpy ((void *) request.data (), "Hello", 5);
            std::cout << "Sending Hello " << request_nbr << "..." << std::endl;
        }
        socket.send (request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }
    return 0;
}

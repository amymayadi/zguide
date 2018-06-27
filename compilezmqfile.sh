#g++ -g -Wall -fPIC -I/home/mayadi/zmq/include -L/home/mayadi/zmq/lib -lzmq $1 -o $2
g++ -g -Wall -fPIC -I/usr/include -L/usr/lib64 -lzmq $1 -o $2

#g++ -g -Wall -fPIC -I/home/mayadi/zmq/include -L/home/mayadi/zmq/lib -lzmq $1 -o $2
g++ -g -Wall -fPIC -I/usr/include -I/home/mayadi/cppzmq-master/ -L/usr/lib64 -lzmq $1 -o $2

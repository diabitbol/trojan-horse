#include <iostream>
#include <string>
#include <SFML/Network.hpp>
// #include "opencv2/core.hpp"
// #include "opencv2/highgui.hpp"
// #include <ostringstream>
// #include <istringstream>
using namespace std;
using namespace sf;
// using namespace cv;

int main()
{
    Packet packet;
    TcpSocket socket, recevoir;
    TcpListener listener;
    socket.connect("127.0.0.1", 10002);
    listener.listen(10001);
    // VideoCapture cap;
    // Mat img;
    string a;
    while (true)
    {
        if (listener.accept(recevoir) == Socket::Done)
        {
            // ostringstream b;
            size_t received = 0;
            recevoir.receive(packet);
            packet >> a;
            if (a=="stop")break;
            // if (a=="cam")
            // {
            //     for(; ;)
            //     {
            //         cap.open(0);
            //         if (!cap.opened())
            //         {
            //             packet << false;
            //         }
            //         else
            //         {
            //             cap >> img;
            //             b << img;
            //             packet << b.str();    
            //         }
            //         socket.send(packet);
            //     }
            //     cap.release();
            else
            {    
                a += " >> ~/Documents/retour";
                cout << a << endl;
                system(a.c_str());
                
            }
            packet.clear();            
        }
    }
    listener.close();
    recevoir.disconnect();
    socket.disconnect();
    return 0;
}
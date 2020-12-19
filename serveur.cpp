#include <iostream>
#include <SFML/Network.hpp>
#include <vector>
// #include "opencv2/core.hpp"
// #include "opencv2/highgui.hpp"
using namespace std;
using namespace sf;
// using namespace cv;

int main()
{
    vector<IpAddress> ip;
    TcpListener listener;
    Packet packet;
    TcpSocket socket, recevoir;
    string str; 
    // Mat img;
    listener.listen(10002);
    if (listener.accept(recevoir) == Socket::Done)
    {  
        cout << "new client connected : "<< recevoir.getRemoteAddress() << "local : " << socket.getLocalPort() << " remote : " << socket.getRemoteAddress() << endl;
        ip.push_back(recevoir.getRemoteAddress());
        string a;
        char c;
        while (true)
        {
            cout << "entrez une commande : ";
            while (cin.get(c))
            {
                if (c != '\n')a+=c;
                else break;
            }
            packet << a;
            socket.connect(recevoir.getRemoteAddress(), 10001);
            socket.send(packet);
            if (a=="stop")break;
            // if (a == "cam")
            // {
            //     for (;;)
            //     {
            //         recevoir.receive(packet);
            //         packet >> str;
            //         str >> img;
            //         imshow("webcam", img);
            //     }
            // }
            else
            {
                packet.clear();
                a.clear();
            }
        }
    }
    socket.disconnect();
    return 0;
}
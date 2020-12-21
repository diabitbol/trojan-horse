net = require('net');
readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})
server = net.createServer((socket)=>
{
    console.log("connexion avec un client ! ");
    socket.write("connexion réussie");

    socket.on("data", (data)=>
    {
        console.log("C>", data.toString());
        readline.question('S>', msgS => {
            socket.write(msgS);
            console.log(msgS)});    
    });
});
server.listen(8080, ()=>{console.log("à l'écoute !");});

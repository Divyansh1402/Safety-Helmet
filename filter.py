import socket
import subprocess

host = '192.168.128.168'
#host = socket.gethostname()
port1 = 6000

server_socket = socket.socket()
server_socket.bind((host,port1))
server_socket.listen(0)
conn, address = server_socket.accept()
for i in range(4):
    p = conn.recv(1024)
    print(p)
    port = 5000

    message = " 71 240 1 l l"
    count = 28;
    dat = str(count)+message
    client_socket = socket.socket()
    client_socket.connect((host,port))
    client_socket.send(dat.encode())
server_socket.close()

import socket
serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(('192.168.225.129', 80))
serv.listen(5)
print('start listening')
while True:
    conn,addr = serv.accept()
    print(conn,addr)
    print('acceptdone')
    conn.sendall(b'1')
    conn.close()
    print ('client disconnected')

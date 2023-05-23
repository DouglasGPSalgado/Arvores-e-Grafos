import socket
import threading

def handle_client(client_socket):
    while True:
        message = client_socket.recvfrom(2048).decode()
        if message.strip() == 'LOGOUT':
            break
        print(f'Mensagem recebida: {message}')
    client_socket.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('10.110.4.26', 3000))
server.listen(5)

while True:
    client_socket, addr = server.accept()
    print(f'Conexão estabelecida com: {addr}')
    client_handler = threading.Thread(target=handle_client, args=(client_socket,))
    client_handler.start()

# Para executar e testar a aplicação, siga os seguintes passos:
# Salve o código em um arquivo com extensão .py, por exemplo server.py.
# Abra um terminal ou prompt de comando e navegue até o diretório onde o arquivo server.py está salvo.
# Execute o arquivo server.py digitando o comando python server.py.
# O servidor estará agora em modo de escuta aguardando conexões de clientes.
# Abra outro terminal ou prompt de comando e execute o seguinte comando para se conectar ao servidor: telnet 10.110.4.26 3000. Substitua o endereço IP pelo endereço IP do servidor, se necessário.
# Digite algumas mensagens no terminal do cliente e pressione Enter para enviá-las ao servidor.
# Para encerrar a conexão, digite a mensagem LOGOUT e pressione Enter.
# O servidor imprimirá as mensagens recebidas do cliente no terminal onde está sendo executado.
import socket
import threading

# Função que lida com as mensagens recebidas do cliente
def handle_client(client_socket):
    while True:
        # Recebe a mensagem do cliente
        message = client_socket.recvfrom(2048).decode()
        # Verifica se o cliente enviou a mensagem de logout
        if message.strip() == 'LOGOUT':
            break
        # Imprime a mensagem recebida
        print(f'Mensagem recebida: {message}')
    # Fecha a conexão com o cliente
    client_socket.close()

# Cria um objeto de socket TCP/IP
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Vincula o socket a um endereço IP e porta específicos
server.bind(('10.110.4.26', 3000))
# Coloca o socket em modo de escuta para aguardar conexões de clientes
server.listen(5)

# Loop infinito para aguardar conexões de clientes
while True:
    # Aceita uma conexão de cliente e retorna um novo objeto de socket e o endereço do cliente
    client_socket, addr = server.accept()
    # Imprime o endereço do cliente que se conectou
    print(f'Conexão estabelecida com: {addr}')
    # Cria uma nova thread para lidar com as mensagens do cliente
    client_handler = threading.Thread(target=handle_client, args=(client_socket,))
    client_handler.start()
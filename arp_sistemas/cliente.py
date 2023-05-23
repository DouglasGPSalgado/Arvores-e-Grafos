# Para executar e testar a aplicação, siga os seguintes passos:
# Salve o código em um arquivo com extensão .py, por exemplo client.py.
# Abra um terminal ou prompt de comando e nave até o diretório onde o arquivo client.py está salvo.
# Execute o arquivo client.py digitando o comando python client.py.
# O cliente estará agora em modo de espera aguardando a entrada do usuário.
# Digite uma mensagem e pressione Enter para enviá-la ao servidor.
# O servidor processará a mensagem e enviará uma resposta de volta ao cliente.
# O cliente imprimirá a resposta do servidor no terminal onde está sendo executado.
# Repita os passos 5 a 7 para enviar mais mensagens ao servidor.

import socket

# Cria um objeto de socket UDP
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

if __name__ == "__main__":
    print("Cliente iniciado")
    while True:
        # Lê a mensagem a ser enviada do usuário
        mensagem_envio = input("Digite a Mensagem: ")
        # Envia a mensagem para o servidor especificando o endereço IP e porta
        client.sendto(mensagem_envio.encode(), ("10.110.4.26", 3000))
        # Recebe a resposta do servidor e o endereço IP do servidor
        mensagem_bytes, endereco_ip_servidor = client.recvfrom(2048)
        # Imprime a resposta do servidor
        print(mensagem_bytes.decode())

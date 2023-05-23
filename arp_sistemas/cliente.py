import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM, socket.SOCK_DGRAM)

if __name__ == "__main__":
    print("Servidor iniciado")
    while True:
        mensagem_envio = input("Digite a Mensagem: ")
        client.sendto(mensagem_envio.encode(), ("10.110.4.26", 3000))
        mensagem_bytes, endereco_ip_servidor = client.recvfrom(2048)
        print(mensagem_bytes.decode())
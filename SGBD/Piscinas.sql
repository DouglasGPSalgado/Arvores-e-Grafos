-- Curso de Engenharia de Software - UniEVANGÉLICA 
-- Disciplina de Sisetmas Gerenciadores de Banco de Dados
-- Dev: Douglas Gabriel Pereira Salgado
-- Data: 27/03/2023

-- Cria um banco de dados
CREATE DATABASE empresa_piscinas;

-- Usa um banco de dados
USE empresa_piscinas;

-- A tabela Cliente armazena informações sobre os clientes, incluindo seu nome, sobrenome, telefone, email e endereço.

CREATE TABLE Cliente ( 
  id_cliente INT NOT NULL AUTO_INCREMENT, 
  nome VARCHAR(50) NOT NULL, 
  sobrenome VARCHAR(50) NOT NULL, 
  telefone VARCHAR(15) NOT NULL, 
  email VARCHAR(50) NOT NULL, 
  endereco VARCHAR(100) NOT NULL, 
  PRIMARY KEY (id_cliente) 
); 

-- A tabela Funcionário armazena informações sobre os funcionários, incluindo seu nome, sobrenome, telefone, email, cargo e salário.

CREATE TABLE Funcionario ( 
  id_funcionario INT NOT NULL AUTO_INCREMENT, 
  nome VARCHAR(50) NOT NULL, 
  sobrenome VARCHAR(50) NOT NULL, 
  telefone VARCHAR(15) NOT NULL, 
  email VARCHAR(50) NOT NULL, 
  cargo VARCHAR(50) NOT NULL, 
  salario DECIMAL(10,2) NOT NULL, 
  PRIMARY KEY (id_funcionario) 
); 

-- A tabela Fornecedor armazena informações sobre os fornecedores, incluindo seu nome, telefone, email e endereço.

CREATE TABLE Fornecedor ( 
  id_fornecedor INT NOT NULL AUTO_INCREMENT, 
  nome VARCHAR(50) NOT NULL, 
  telefone VARCHAR(20) NOT NULL, 
  email VARCHAR(50) NOT NULL, 
  endereco VARCHAR(100) NOT NULL, 
  PRIMARY KEY (id_fornecedor) 
); 

-- A tabela Produto armazena informações sobre os produtos vendidos pela empresa, incluindo seu nome, descrição, quantidade em estoque e preço.

CREATE TABLE Produto ( 
  id_produto INT NOT NULL AUTO_INCREMENT, 
  nome VARCHAR(50) NOT NULL, 
  descricao VARCHAR(100) NOT NULL, 
  quantidade INT NOT NULL, 
  preco DECIMAL(10,2) NOT NULL, 
  PRIMARY KEY (id_produto) 
); 

-- A tabela Venda armazena informações sobre as vendas realizadas, incluindo o ID do cliente, a data da venda e o total da venda.

CREATE TABLE Venda ( 
  id_venda INT NOT NULL AUTO_INCREMENT, 
  id_cliente INT NOT NULL, 
  data_venda DATE NOT NULL, 
  total DECIMAL(10,2) NOT NULL, 
  PRIMARY KEY (id_venda), 
  FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente) 
); 

-- A tabela Item_Venda armazena informações sobre os itens vendidos em cada venda, incluindo o ID da venda, o ID do produto, a quantidade vendida e o subtotal.

CREATE TABLE Item_Venda ( 
  id_item_venda INT NOT NULL AUTO_INCREMENT, 
  id_venda INT NOT NULL, 
  id_produto INT NOT NULL, 
  quantidade INT NOT NULL, 
  subtotal DECIMAL(10,2) NOT NULL, 
  PRIMARY KEY (id_item_venda), 
  FOREIGN KEY (id_venda) REFERENCES Venda(id_venda), 
  FOREIGN KEY (id_produto) REFERENCES Produto(id_produto) 
); 

-- A tabela Serviço armazena informações sobre os serviços oferecidos pela empresa, incluindo o nome, a descrição e o preço.

CREATE TABLE Servico ( 
  id_servico INT NOT NULL AUTO_INCREMENT, 
  nome VARCHAR(50) NOT NULL, 
  descricao VARCHAR(100) NOT NULL, 
  preco DECIMAL(10,2) NOT NULL, 
  PRIMARY KEY (id_servico) 
); 

-- A tabela Agendamento armazena informações sobre os agendamentos de serviços feitos pelos clientes, incluindo o ID do cliente, o ID do funcionário, o ID do serviço, a data e a hora do agendamento e o status do agendamento.


CREATE TABLE Agendamento ( 
    id_agendamento INT NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    id_cliente INT NOT NULL, 
    id_funcionario INT NOT NULL, 
    id_servico INT NOT NULL, 
    data_agendamento DATE NOT NULL, 
    hora_agendamento TIME NOT NULL, 
    status ENUM('agendado', 'cancelado', 'realizado') NOT NULL, 
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente), 
    FOREIGN KEY (id_funcionario) REFERENCES Funcionario(id_funcionario), 
    FOREIGN KEY (id_servico) REFERENCES Servico(id_servico) 
);

-- As chaves primárias e estrangeiras são definidas para garantir a integridade referencial e a consistência dos dados. Com essa estrutura de banco de dados, a empresa pode gerenciar seus clientes, funcionários, fornecedores, produtos, vendas, agendamentos e serviços de forma eficiente e confiável.

-- O código inclui um comando INSERT INTO que adiciona alguns dados à tabela "Cliente"
INSERT INTO Cliente (id_cliente, nome, sobrenome, telefone, email, endereco) VALUES
(1, 'Josué', 'Costa', '629645-7834', 'josue.costa@gmail.com', 'Rua 876'),
(2, 'Lucas', 'Lima', '629123-7845', 'lucas.lima@gmail.com', 'Rua 543'),
(3, 'João', 'Armandes', '6292378-5483', 'joao.armandes@gmail.com', 'Rua 31'),
(4, 'Miguel', 'Castro', '6299565-1609', 'miguel.castro@gmail.com', 'Rua 45');

-- É uma consulta SQL que seleciona dados de uma tabela de agendamentos ("Agendamento") juntamente com informações de outras três tabelas: "Cliente", "Funcionário" e "Serviço". O objetivo da consulta é obter informações sobre os agendamentos que ainda estão "agendados" (ou seja, ainda não foram realizados).
SELECT c.nome AS nome_cliente, f.nome AS nome_funcionario, s.nome AS nome_servico, a.data_agendamento, a.hora_agendamento
FROM Agendamento AS a
-- A consulta utiliza as cláusulas "JOIN" para combinar dados de várias tabelas. A cláusula "ON" é utilizada para especificar as condições de junção, ou seja, as colunas que relacionam as tabelas.
JOIN Cliente AS c ON a.id_cliente = c.id_cliente
JOIN Funcionario AS f ON a.id_funcionario = f.id_funcionario
JOIN Servico AS s ON a.id_servico = s.id_servico
-- A cláusula "WHERE" é utilizada para filtrar apenas os registros que têm o status "agendado".
WHERE a.status = 'agendado';

-- Consulta utilizando INNER JOIN
SELECT c.nome, v.data_venda, v.total, p.descricao, iv.quantidade
FROM Cliente c
INNER JOIN Venda v ON c.id_cliente = v.id_cliente
INNER JOIN Item_Venda iv ON v.id_venda = iv.id_venda
INNER JOIN Produto p ON iv.id_produto = p.id_produto;

-- Consulta utilizando LEFT JOIN
SELECT c.nome, a.data_agendamento, a.status, s.nome
FROM Cliente c
LEFT JOIN Agendamento a ON c.id_cliente = a.id_cliente
LEFT JOIN Servico s ON a.id_servico = s.id_servico;

-- Consulta utilizando INNER JOIN
SELECT c.nome, f.nome, a.data_agendamento, a.hora_agendamento
FROM Cliente c
INNER JOIN Agendamento a ON c.id_cliente = a.id_cliente
INNER JOIN Funcionario f ON a.id_funcionario = f.id_funcionario
WHERE a.status = 'agendado';
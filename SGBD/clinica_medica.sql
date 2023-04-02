CREATE DATABASE clinica_medica;

USE clinica_medica;

-- Tabela Consultórios
CREATE TABLE Consultorios (
    idConsultorio INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    localizacao VARCHAR(100) NOT NULL
);

-- Tabela Profissionais
CREATE TABLE Profissionais (
    idProfissional INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    especialidade VARCHAR(50) NOT NULL,
    registroCRM VARCHAR(10) NOT NULL
);

-- Tabela Pacientes
CREATE TABLE Pacientes (
    idPaciente INT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    dataNascimento DATE NOT NULL,
    numeroConvenio VARCHAR(20) NOT NULL
);

-- Tabela Agendamentos
CREATE TABLE Agendamentos (
    idAgendamento INT PRIMARY KEY,
    dataHora DATETIME NOT NULL,
    idPaciente INT NOT NULL,
    idProfissional INT NOT NULL,
    idConsultorio INT NOT NULL,
    FOREIGN KEY (idPaciente) REFERENCES Pacientes(idPaciente),
    FOREIGN KEY (idProfissional) REFERENCES Profissionais(idProfissional),
    FOREIGN KEY (idConsultorio) REFERENCES Consultorios(idConsultorio)
);
INSERT INTO Consultorios (idConsultorio, nome, localizacao)
VALUES (1, 'doug', 'anapolis'); 

INSERT INTO Profissionais (idProfissional, nome, especialidade, registroCRM)
VALUES (2, 'douglas', 'doido', '12312431'); 

INSERT INTO Pacientes (idPaciente, nome, dataNascimento, numeroConvenio)
VALUES (3, 'douglas', '2023-04-01', '12312'); 

-- Inserir um novo agendamento de consulta
INSERT INTO Agendamentos (dataHora, idPaciente, idProfissional, idConsultorio)
VALUES ('2023-04-01 10:30:00', 1, 2, 3);

-- Atualizar os dados de um agendamento existente
UPDATE Agendamentos
SET dataHora = '2023-04-01 11:00:00', idProfissional = 4
WHERE idAgendamento = 1;

-- Excluir um agendamento de consulta
DELETE FROM Agendamentos
WHERE idAgendamento = 1;

-- Listar todos os consultórios disponíveis na clínica
SELECT * FROM Consultorios;

-- Listar todos os profissionais da clínica e suas respectivas especialidades
SELECT nome, especialidade FROM Profissionais;

-- Listar todos os pacientes da clínica e suas respectivas datas de nascimento
SELECT nome, dataNascimento FROM Pacientes;

-- Listar todas as consultas agendadas para um determinado dia
SELECT dataHora, p.nome as paciente, pr.nome as profissional, c.nome as consultorio
FROM Agendamentos a
JOIN Pacientes p ON a.idPaciente = p.idPaciente
JOIN Profissionais pr ON a.idProfissional = pr.idProfissional
JOIN Consultorios c ON a.idConsultorio = c.idConsultorio
WHERE DATE(dataHora) = '2023-04-01';

-- Listar todas as consultas agendadas para um determinado profissional
SELECT dataHora, p.nome as paciente, c.nome as consultorio
FROM Agendamentos a
JOIN Pacientes p ON a.idPaciente = p.idPaciente
JOIN Consultorios c ON a.idConsultorio = c.idConsultorio
WHERE a.idProfissional = 2;

-- Listar todas as consultas agendadas para um determinado paciente
SELECT dataHora, pr.nome as profissional, c.nome as consultorio
FROM Agendamentos a
JOIN Profissionais pr ON a.idProfissional = pr.idProfissional
JOIN Consultorios c ON a.idConsultorio = c.idConsultorio
WHERE a.idpaciente = 2;

-- Operadores de comparação
SELECT * FROM Consultorios WHERE idConsultorio > 5;

-- Combinando diferentes operadores lógicos
SELECT dataHora, p.nome as paciente, c.nome as consultorio
FROM Agendamentos a
JOIN Pacientes p ON a.idPaciente = p.idPaciente
JOIN Consultorios c ON a.idConsultorio = c.idConsultorio
WHERE a.idProfissional = 2 AND dataHora > NOW();

-- Operadores de intervalo
SELECT dataHora, pr.nome as profissional, c.nome as consultorio
FROM Agendamentos a
JOIN Profissionais pr ON a.idProfissional = pr.idProfissional
JOIN Consultorios c ON a.idConsultorio = c.idConsultorio
WHERE a.idpaciente = 2 AND dataHora BETWEEN '2023-03-01' AND '2023-04-01';

-- Operadores de padrão
SELECT * FROM Pacientes WHERE nome LIKE 'A%';

-- Operações de conjuntos
SELECT nome, dataNascimento FROM Pacientes
UNION
SELECT nome, especialidade FROM Profissionais;

-- Operadores de agregação
SELECT COUNT(*) FROM Agendamentos WHERE idProfissional = 2;

-- JOINS
SELECT dataHora, p.nome as paciente, pr.nome as profissional
FROM Agendamentos a
JOIN Pacientes p ON a.idPaciente = p.idPaciente
JOIN Profissionais pr ON a.idProfissional = pr.idProfissional;INSERT INTO Agendamentos (idAgendamento, dataHora, idPaciente, idProfissional, idConsultorio) VALUES (1, '2023-04-01 10:30:00', 1, 2, 3)

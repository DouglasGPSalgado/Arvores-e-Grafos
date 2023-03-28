//  Curso de Engenharia de Software - UniEVANGÉLICA 
//  Disciplina de Sisetmas Gerenciadores de Banco de Dados
//  Dev: Douglas Gabriel Pereira Salgado
//  Data: 27/03/2023

import React, { useState } from "react";
import "./App.css";

function App() {
  const [board, setBoard] = useState(Array(9).fill(null));
  const [player, setPlayer] = useState("X");
  const [winner, setWinner] = useState(null);

  const handleClick = (index) => {
    if (winner || board[index]) return;
    const newBoard = [...board];
    newBoard[index] = player;
    setBoard(newBoard);
    setPlayer(player === "X" ? "O" : "X");
    checkWinner(newBoard);
  };

  const checkWinner = (board) => {
    const possibleLines = [
      [0, 1, 2],
      [3, 4, 5],
      [6, 7, 8],
      [0, 3, 6],
      [1, 4, 7],
      [2, 5, 8],
      [0, 4, 8],
      [2, 4, 6],
    ];
    for (let i = 0; i < possibleLines.length; i++) {
      const [a, b, c] = possibleLines[i];
      if (board[a] && board[a] === board[b] && board[a] === board[c]) {
        setWinner(player);
        return;
      }
    }
    if (board.every((cell) => cell !== null)) {
      setWinner("Draw");
    }
  };

  const renderCell = (index) => {
    return (
      <div className="cell" onClick={() => handleClick(index)}>
        {board[index]}
      </div>
    );
  };

  const renderBoard = () => {
    return (
      <div className="board">
        <div className="row">
          {renderCell(0)}
          {renderCell(1)}
          {renderCell(2)}
        </div>
        <div className="row">
          {renderCell(3)}
          {renderCell(4)}
          {renderCell(5)}
        </div>
        <div className="row">
          {renderCell(6)}
          {renderCell(7)}
          {renderCell(8)}
        </div>
      </div>
    );
  };

  const renderStatus = () => {
    if (winner) {
      return `${winner} wins!`;
    } else {
      return `Player ${player}'s turn`;
    }
  };

  const resetGame = () => {
    setBoard(Array(9).fill(null));
    setPlayer("X");
    setWinner(null);
  };

  return (
    <div className="container">
      <h1>Tic Tac Toe</h1>
      {renderBoard()}
      <div className="status">{renderStatus()}</div>
      {winner && (
        <button className="play-again" onClick={resetGame}>
          Play again
        </button>
      )}
    </div>
  );
}

export default App;

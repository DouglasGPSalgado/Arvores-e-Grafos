const cards = [
  { id: 1, img: "./assets/card1.png" },
  { id: 2, img: "./assets/card2.jpg" },
  { id: 3, img: "./assets/card3.jpg" },
  { id: 4, img: "./assets/card4.jpg" },
  { id: 5, img: "./assets/card5.jpg" },
  { id: 6, img: "./assets/card6.jpg" },
  // Adicione aqui as outras cartas
];

let shuffledCards = shuffle(cards.concat(cards));

const board = document.querySelector(".board");
shuffledCards.forEach((card) => {
  const div = document.createElement("div");
  div.classList.add("card");
  div.dataset.card = card.id;
  const front = document.createElement("div");
  front.classList.add("front");
  div.style.backgroundImage = `url(${card.img})`;
  div.style.backgroundSize = "cover";
  div.style.backgroundRepeat = "no-repeat";
  div.style.backgroundPosition = "center";
  board.appendChild(div);
  board.appendChild(front);
});

let flippedCards = [];
let matchedCards = [];

board.addEventListener("click", (event) => {
  const clickedCard = event.target.closest(".card");

  if (
    !clickedCard ||
    clickedCard.classList.contains("flipped") ||
    flippedCards.length === 2
  ) {
    return;
  }

  clickedCard.classList.add("flipped");
  flippedCards.push(clickedCard);

  if (flippedCards.length === 2) {
    const firstCard = flippedCards[0];
    const secondCard = flippedCards[1];

    if (firstCard.dataset.card === secondCard.dataset.card) {
      matchedCards.push(firstCard, secondCard);
      flippedCards = [];

      if (matchedCards.length === shuffledCards.length) {
        endGame();
      }
    } else {
      setTimeout(() => {
        firstCard.classList.remove("flipped");
        secondCard.classList.remove("flipped");
        flippedCards = [];
      }, 1000);
    }
  }
});

function shuffle(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

let timeLeft = 60;
let timerId;

function startTimer() {
  const timerElement = document.querySelector(".timer");
  timerElement.textContent = timeLeft;

  timerId = setInterval(() => {
    timeLeft--;
    timerElement.textContent = timeLeft;

    if (timeLeft === 0) {
      endGame();
    }
  }, 1000);
}

function endGame() {
  clearInterval(timerId);

  const board = document.querySelector(".board");
  board.classList.add("hidden");

  const resultsScreen = document.querySelector(".results");
  resultsScreen.classList.remove("hidden");

  const resultsTitle = resultsScreen.querySelector("h2");
  resultsTitle.textContent =
    matchedCards.length === shuffledCards.length
      ? "Você ganhou!"
      : "Você perdeu!";

  const resetButton = resultsScreen.querySelector("button");
  resetButton.addEventListener("click", () => {
    board.classList.remove("hidden");
    resultsScreen.classList.add("hidden");
    timeLeft = 60;
    startTimer();
    resetGame();
  });
}

function resetGame() {
  const board = document.querySelector(".board");
  board.innerHTML = "";

  shuffledCards = shuffle(cards.concat(cards));
  shuffledCards.forEach((card) => {
    const div = document.createElement("div");
    div.classList.add("card");
    div.dataset.card = card.id;
    div.style.backgroundImage = `url(${card.img})`;
    board.appendChild(div);
  });

  flippedCards = [];
  matchedCards = [];
}

startTimer();

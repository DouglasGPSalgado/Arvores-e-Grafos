const piscinasLista = document.getElementById("piscinas-lista");
const clearBtn = document.getElementById("clear-btn");

// Adiciona o evento de clique em cada link "Apagar"
piscinasLista.addEventListener("click", (event) => {
  if (event.target.tagName === "A") {
    event.preventDefault();
    event.target.parentNode.remove();
  }
});

// Adiciona o evento de clique no botão "Limpar Lista"
clearBtn.addEventListener("click", () => {
  piscinasLista.innerHTML = "";
});

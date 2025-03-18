<!DOCTYPE html>
<html lang="pt">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Batalha Naval Simples</title>
    <style>
        table {
            border-collapse: collapse;
            margin: 20px;
        }
        td {
            width: 50px;
            height: 50px;
            text-align: center;
            border: 1px solid black;
            cursor: pointer;
        }
        td.hit {
            background-color: red;
        }
        td.miss {
            background-color: lightblue;
        }
    </style>
</head>
<body>
    <h1>Batalha Naval - Jogo Simples</h1>
    <table id="board"></table>
    <p id="message"></p>

    <script>
        const boardSize = 5; // Tamanho do tabuleiro (5x5)
        const shipRow = 2;   // Posição do navio (linha)
        const shipCol = 2;   // Posição do navio (coluna)

        // Função para criar o tabuleiro
        function createBoard() {
            const table = document.getElementById("board");
            for (let row = 0; row < boardSize; row++) {
                const tr = document.createElement("tr");
                for (let col = 0; col < boardSize; col++) {
                    const td = document.createElement("td");
                    td.setAttribute("data-row", row);
                    td.setAttribute("data-col", col);
                    td.addEventListener("click", handleClick);
                    tr.appendChild(td);
                }
                table.appendChild(tr);
            }
        }

        // Função para tratar o clique do usuário
        function handleClick(event) {
            const row = event.target.getAttribute("data-row");
            const col = event.target.getAttribute("data-col");

            // Verifica se acertou o navio
            if (row == shipRow && col == shipCol) {
                event.target.classList.add("hit");
                document.getElementById("message").textContent = "Você acertou o navio!";
            } else {
                event.target.classList.add("miss");
                document.getElementById("message").textContent = "Você errou!";
            }
        }

        // Inicializa o tabuleiro ao carregar a página
        createBoard();
    </script>
</body>
</html>

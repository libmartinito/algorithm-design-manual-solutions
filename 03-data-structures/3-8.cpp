// goal: make a data structure that does the following:
//
// input: sequence of tic-tac-toe moves with the following format
//   <0,1,2 0,1,2 0,1,2>
//
//   0: row
//   1: column
//   2: type - 'O' or 'X'
//
//   each move is sepaated from other moves through spaces
//   each identifier (0 1 2) is separated through commas

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string line, std::string delimiter) {
  std::vector<std::string> elements{};
  size_t delimiter_pos{line.find(delimiter)};

  while (delimiter_pos != std::string::npos) {
    elements.push_back(line.substr(0, delimiter_pos));
    line = line.substr(delimiter_pos + 1);
    delimiter_pos = line.find(delimiter);
  }

  if (line != "") {
    elements.push_back(line);
  }

  return elements;
}

struct TicTacToe {
  std::vector<std::vector<std::string>> board;
  std::string winner{"none"};

  TicTacToe() { initializeBoard(); }

  void initializeBoard() {
    std::vector<std::string> row{};

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        row.push_back(".");
      }

      board.push_back(row);
      row = {};
    }

    return;
  }

  void processMoves(std::string line) {
    std::vector<std::string> moves = split(line, " ");

    for (std::string move : moves) {
      std::vector<std::string> move_info = split(move, ",");

      int row = std::stoi(move_info[0]);
      int col = std::stoi(move_info[1]);
      std::string type = move_info[2];

      board[row][col] = type;
    }

    updateWinner();
  }

  void reset() {
    winner = "none";

    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[0].size(); j++) {
        board[i][j] = ".";
      }
    }

    return;
  }

  void updateWinner() {
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
          board[i][0] != ".") {
        winner = board[i][0];
        return;
      }
    }

    for (int i = 0; i < 3; i++) {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
          board[0][i] != ".") {
        winner = board[0][i];
        return;
      }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != ".") {
      winner = board[0][0];
      return;
    }

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] &&
        board[2][0] != ".") {
      winner = board[2][0];
      return;
    }
  }
};

int main() {
  TicTacToe *ticTacToe = new TicTacToe();

  ticTacToe->processMoves("0,0,O 0,1,O 0,2,X");

  if (ticTacToe->winner == "none") {
    std::cout << "works if no winner!\n";
  } else {
    std::cout << "error if no winner.\n";
  }

  ticTacToe->reset();
  ticTacToe->processMoves("0,0,O 0,1,O 0,2,O");

  if (ticTacToe->winner == "O") {
    std::cout << "works if winner on row!\n";
  } else {
    std::cout << "error if winner on row.\n";
  }

  ticTacToe->reset();
  ticTacToe->processMoves("0,0,X 1,0,X 2,0,X");

  if (ticTacToe->winner == "X") {
    std::cout << "works if winner on col!\n";
  } else {
    std::cout << "error if winner on col.\n";
  }

  ticTacToe->reset();
  ticTacToe->processMoves("0,0,O 1,1,O 2,2,O");

  if (ticTacToe->winner == "O") {
    std::cout << "works if winner on diagonal!\n";
  } else {
    std::cout << "error if winner on diagonal.\n";
  }

  ticTacToe->reset();
  ticTacToe->processMoves("2,2,X 1,1,X 0,0,X");

  if (ticTacToe->winner == "X") {
    std::cout << "works if winner on diagonal!\n";
  } else {
    std::cout << "error if winner on diagonal.\n";
  }
}

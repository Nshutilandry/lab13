#include "arcade.h"

#include <iostream>
#include <string>

#include "input.h"

Arcade::Arcade() : m_games{}, m_count{0} {}

Arcade::~Arcade() {
  for (int i = 0; i < m_count; ++i) {
    delete m_games[i];
  }
}

void Arcade::add(Game *game) {
  if (m_count == max_games) {
    delete game;
    return;
  }
  m_games[m_count] = game;
  ++m_count;
}

void Arcade::run() {
  std::string line;
  while (true) {
    std::cout << "\n=== ARCADE ===\n";
    for (int i = 0; i < m_count; ++i) {
      std::cout << i + 1 << ". " << m_games[i]->title() << "\n";
    }
    std::cout << "0. Quit\n";
    if (!prompt_line("Choose: ", line)) {
      std::cout << "Goodbye.\n";
      return;
    }

    int choice{0};
    if (!parse_int(line, choice) || choice < 0 || choice > m_count) {
      std::cout << "Please enter 0-" << m_count << ".\n";
    } else if (choice == 0) {
      std::cout << "Goodbye.\n";
      return;
    } else {
      Game *game{m_games[choice - 1]};
      game->play();
      std::cout << game->title() << " score: " << game->last_score() << "\n";
    }
  }
}

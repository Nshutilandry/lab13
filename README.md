# Arcade: Week 13 starter (S13)

A text-game arcade in C++20. The four games derive from the abstract `Game`
base class and are played through an owning `Arcade` that stores `Game *`
pointers. The Dungeon also owns room monsters through `Monster *` pointers and
dispatches combat actions virtually.

## What is already here

| Part | Files | Notes |
| --- | --- | --- |
| Game hierarchy | `game.*`, `hangman_game.*`, `dungeon_game.*`, `blackjack_game.*`, `minesweeper_game.*` | Abstract base with virtual `play()` |
| The games | `hangman.*`, `dungeon.*`, `blackjack.*`, `minesweeper.*` and their helper classes | The `play_*` functions |
| **Arcade** | `include/arcade.h`, `src/arcade.cpp` | Owns games and runs the polymorphic menu. |
| **Monster** | `include/monster.h`, `src/monster.cpp`, `goblin.*`, `troll.*` | Abstract base and two concrete monsters. |
| Combat | `src/dungeon.cpp`, `room.*` | Rooms own monsters; combat uses the Monster interface. |
| Tests | `tests/` | `test_arcade.cpp` and `test_monster.cpp` build automatically once the files they need exist |
| Notes to fill in | `POLYMORPHISM_NOTES.md`, `GDB_LOG.md` | |

## File names

`Goblin` (3 damage, 8 health) and `Troll` (6 damage, 20 health) each have a
default constructor. All implementation files are listed in `arcade_lib` in
`CMakeLists.txt`.

## Build and run

```
cmake -S . -B build
cmake --build build
./build/arcade
cd build && ctest --output-on-failure
```

AddressSanitizer, in a separate folder:

```
cmake -S . -B build-asan -DENABLE_ASAN=ON
cmake --build build-asan
./build-asan/arcade
```

## Rules

- No warnings under `-Wall -Wextra`.
- Allowed headers: `<iostream>`, `<iomanip>`, `<string>`, `<fstream>`, `<stdexcept>`, `<random>`. No standard containers, no `<algorithm>`, no `using namespace std;`.
- Naming: `underscore_separated` functions and variables, `Capitalized` types, private data members start with `m_`, enumerators are lowercase, no ALL_CAPS constants.
- Conventional Commits, composed in the editor (not `-m`).

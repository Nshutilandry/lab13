# Polymorphism notes

## 1. The non-virtual destructor

I could not run the requested AddressSanitizer experiment in this workspace,
so I cannot report its actual output. Deleting a derived game through a
`Game *` with a non-virtual destructor is undefined behavior: the base
destructor runs, but the derived destructor does not, which skips derived
cleanup.

## 2. Game is abstract

`Game g;` no longer compiles because `Game::play()` is pure virtual. A class
with a pure virtual function is abstract and cannot be instantiated directly.

## 3. override

`override` asks the compiler to verify that this method really overrides a
virtual method in the base class. For example, writing `void paly() override;`
instead of `void play() override;` is caught as an error rather than silently
creating a different method.

## 4. Last week versus this week

Last week, `Game *g = &hangman; g->play();` printed `Game::play called`:
non-virtual `play()` used **static dispatch**, selected from the pointer's
static type `Game *`. Now it runs `Hangman::play()` through **dynamic
dispatch**, selected from the object's runtime type.

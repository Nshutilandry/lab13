# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

Backtrace inside `Hangman::Hangman` (paste it):

Backtrace inside `Game::Game` (paste it):

Where `finish` returned to:

Order of destructor breakpoints when the program ended:

Construction order and destruction order, as read from the backtraces:

### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:

## Week 13 (Lab 13)

Each partner writes their own section. Put your name here: **[your name]**

### A Game pointer with a virtual play()

Commands used:

```
set print object on
print *g
info vtbl *g
step
```

Paste your actual `print *g` and `info vtbl *g` output here. With dynamic
object printing enabled, GDB should identify the object as `Hangman`; the
virtual function table should include its `play()` implementation. The exact
format and other entries depend on the compiler and debug information.

What changed from Week 12? The pointer's declared type remains `Game *`, but
GDB can show the dynamic `Hangman` object. A virtual call through `g` uses
dynamic dispatch.

Which functions are in the table? Record the names shown by your `info vtbl`
output; at minimum it should include the virtual destructor and `play()`.

Where `step` into `g->play()` landed, and how that compares with Week 12:
It should enter `Hangman::play()` rather than the base placeholder that ran
last week. Replace this expected description with what your debugger showed.

### A Monster pointer

Commands used:

```
set print object on
print *monster
ptype monster
info vtbl *monster
```

Paste actual output for a Goblin and a Troll. `print *monster` can show the
dynamic derived object; `ptype monster` reports the expression's static type,
`Monster *`. The vtables should differ in their `attack_damage()` and
`describe()` implementations. `step` into `monster->attack_damage()` should
land in `Goblin::attack_damage()` for the Goblin and `Troll::attack_damage()`
for the Troll.

GDB is not available in the workspace used to prepare this file, so the
compiler-specific transcripts and personal observations above must be
captured by each partner when running the debugger; no output is fabricated
here.

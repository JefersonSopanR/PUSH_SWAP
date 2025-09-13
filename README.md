# PUSH_SWAP

Push_swap is a sorting algorithm project designed for the 42 school curriculum. The goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves possible. The project consists of two main programs:

- `push_swap`: Takes a list of integers as arguments and outputs the sequence of operations to sort them.
- `checker`: (bonus) Verifies if a given sequence of operations correctly sorts the stack.

## Features
- Custom implementation of standard C library functions (see `libft/`).
- Efficient sorting algorithms for small and large sets of numbers.
- Input validation and error handling (duplicates, non-integer values, etc).
- Bonus: Checker program for validating operation sequences.

## Usage

### Compilation
Use the provided `Makefile` to compile the project:

```bash
make
```
For the bonus checker:
```bash
make bonus
```

### Running push_swap
```bash
./push_swap [list of integers]
```
Example:
```bash
./push_swap 3 2 1
```

### Running checker (bonus)
```bash
./checker [list of integers]
```
Then input the operations to check, e.g.:
```
sa
pb
ra
...etc
```

## Project Structure
- `src/` : Main source files for push_swap
- `src_bonus/` : Source files for checker (bonus)
- `inc/` : Header files
- `libft/` : Custom C library functions

## Allowed Operations
- `sa`, `sb`, `ss` : Swap top two elements of stack A/B/both
- `pa`, `pb` : Push top element to stack A/B
- `ra`, `rb`, `rr` : Rotate stack A/B/both upwards
- `rra`, `rrb`, `rrr` : Reverse rotate stack A/B/both downwards

## Example
Input:
```
./push_swap 2 1 3
```
Output:
```
sa
```

## Author
Jeferson Sopan R

## License
This project is for educational purposes at 42 School.

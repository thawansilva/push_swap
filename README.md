# Push swap

A program that sorts a stack of integers using a limited set of operations.

## Description

Push_swap is a sorting algorithm project that uses two stacks (A and B) and a set of operations to sort integers in ascending order. The program calculates and displays the smallest list of instructions to sort the input numbers.

## Getting Started

### Prerequisites

- GCC/Clang compiler
- GNU Make
- Linux/MAC environment (for checker program)

### Compilation

To compile the push_swap program:

```sh
make
```

This will create the executable `push_swap`.

### Testing

To run the test suite:

```sh
cd tests
make
```

This will:
1. Compile the project
2. Build and run the test suite
3. Show test results

## Usage

```sh
./push_swap [numbers]
```

Example:
```sh
./push_swap 2 1 3 6 5 8
```

To check if the solution is correct using the checker:
```sh
./push_swap [numbers] | ./checker_linux [numbers]
```

## Operations

- `sa` : swap elements at the top of stack A
- `sb` : swap elements at the top of stack B 
- `ss` : sa and sb at the same time
- `pa` : push top element from stack B to stack A
- `pb` : push top element from stack A to stack B
- `ra` : rotate stack A up by one
- `rb` : rotate stack B up by one
- `rr` : ra and rb at the same time
- `rra` : rotate stack A down by one
- `rrb` : rotate stack B down by one
- `rrr` : rra and rrb at the same time

## Cleaning Up

To remove generated files:

```sh
make clean    # Remove object files
make fclean   # Remove object files, obj directory and executable
make re       # Rebuild the project
```

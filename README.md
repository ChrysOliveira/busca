# Line Filter Program in C

This program reads a specified file and prints each line containing a given word. It’s a simple utility useful for text processing tasks where only relevant lines matching a specific word need to be extracted.

## How It Works

The program opens a file in read-only mode and processes it line by line. It checks if each line contains the specified word, and if it does, that line is printed to the standard output. If the file cannot be opened or there is an error during reading, the program will display an error message.

## Requirements

- C compiler (e.g., GCC)
- Linux or UNIX-like environment (for the `open` system call and other POSIX functions)
- Make utility

## Project Structure

The project uses the following folder structure:
- `include/` - Directory for header files.
- `src/` - Directory for source files.
- `obj/` - Directory for compiled object files.
- `bin/` - Directory for the final binary output.

## Makefile

The project includes a `Makefile` to manage compilation and execution:

- **`make`**: Compiles the program and places the output in `bin/main`.
- **`make clean`**: Removes all object files and temporary files from the project directories.
- **`make run`**: Runs the program using a default file `temporary.txt` and a search word `magia`.

## Usage

### Compilation

Compile the program using `make`:
```bash
make
```

### Running the Program
You can run the program by specifying a file and a word:
```bash
./bin/main <file> <word>
```
 - `<file>`: The path to the file you want to search.
 - `<word>`: The word you want to search for within each line of the file.

Alternatively, to run it with default values, use:
```bash
make run
```

## Example
Suppose you have a file **example.txt** with the following contents:
```plaintext
Hello world
This is a test
Another line with test
No matching word here
```
If you run:
```bash
./bin/main example.txt test
```
The output will be:
```plaintext
This is a test
Another line with test
```
Only the lines containing the word "test" will be printed.

### Error Handling
 - If the specified file cannot be opened, the program will print an error message and exit.
 - If the program encounters any issues while reading the file, it will also print an error message and exit.

### Notes
 - The program uses a buffer to read the file in chunks, making it efficient for large files.
 - Ensure you have read permissions for the specified file to avoid permission-related errors.


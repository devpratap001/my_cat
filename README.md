# Linux Cat Command Clone

---

A simple C program to simulate 'cat' linux command behaviour, with various flags support and I/O redirection features.

<!-- about and features -->

---

## Features

It supports stdin input, if no files are passed, flags to manipulate output like; `-n` to print line numbers, `-b` to number  non-blank lines, `-e` to show line ends with a '$' sign and `-s` to skip multiple empty lines in file.   
It also supports IO redirection to read and write to a file instead of `STDIN` or `STDOUT`.

### Flags and Supported Operators

| Flag/Operator | Description       | Use Case                                                      |
|:--------------|:------------------|:--------------------------------------------------------------|
| -n            | NUMBER            | Show line no. before every line                               |
| -b            | NUMBER NON-BLANK  | number non-blank lines in output                              |
| -e            | SHOW ENDS         | Show line ends with a '$'                                     |
| -s            | SQUEEZE BLANK     | Skip multiple empty lines                                     |
| --help        | MANUAL            | print the help man page                                       |
| [             | REDIRECT STDIN    | redirect stdin to take input from file instead of stdin       |
| ]             | REDIRECT STDOUT   | redirect stdout to print output into a file instead of stdout |

---

## Project Structure

```
/MY_CAT
    |-- /build/
    |       |-- /dependencies/
    |       |-- /objects/
    |       |-- my_cat
    |
    |-- /include/
    |       |-- concat.h
    |       |-- io_redidrect.h
    |       |-- parse_token.h
    |
    |-- /src/
    |       |-- concat.c            //file parse logic
    |       |-- io_redirect.c       //redirect STDIN/STDOUT
    |       |-- my_cat.c            //main
    |       |-- parse_token.c       //parse CLI tokens
    |
    |-- .gitignore
    |-- Makefile
    |-- README
```

<!-- installation and build -->

---

## Installation and Usage

Clone the repository using following command and build the executable binaries.

``` bash
git clone git@github.com:devpratap001/my_cat.git
cd my_cat
make all
```

In order to run the project, use my_cat binary file from `/build/my_cat`.

``` bash
./build/my_cat              //take input from stdin
./build/my_cat --help       //to see a list of possible flags

./build/my_cat [OPTIONS]... [FILENAME]...

./build/my_cat [FILENAME]... ] [OUTPUT_FILE]    // redirect output to external file instead of stdout
```

### Using Redirection Operators

``` bash
./build/my_cat [ test.txt           // take input from test.txt instead of stdin
./build/my_cat  test.txt ] out.txt  // print content of test.txt into out.txt
```

<!-- contact and support -->

---

## Contacts

If you have any questions or suggestions, feel free to reach out:

* Github: [devpratap001](https://github.com/devpratap001/)
* Email: [devps1125@gmail.com](mailto:devps1125@gamil.com)

---
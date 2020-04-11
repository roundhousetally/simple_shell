# simple_shell
Unix command line interpreter for Holberton School.
<br>
## Getting Started
-------
### Clone the simple_shell repository to your local directory.
````
$ git clone https://github.com/roundhousetally/simple_shell.git
````
### Compile using gcc 4.8.4

`gcc -Wall -Werror -Wextra -pedantic *.c -o pieshell`

## How to launch after compilation

`./pieshell`

### Modes

This shell can be ran in interactive and non-interactive modes.
You can run this shell in non-interactive mode by piping commancs into the shell
executable.

#### Non-Interactive Mode Example

````
 ls -al | ./pieshell
````
### Built-In Commands

| Built-n | Use |
|--|--|
|`env`| prints the current environment |
|`exit`| exits the shell|

### Authors
----
[Lance Burklin](https://github.com/lancewburklin)

[Tahlia Roper](https://github.com/roundhousetally/)

<p align="center">

  <img src="sol.jpg" width="400\"/>

<br>


<h1><p align="center">Sol Shell- A simple shell Project</h1></p></font>





# GSH
Sol Shell also known as the shell is a simple command line prompt that takes the most basics of commands that are present in the bash shell and runs them. This shell was built as a project for ALX software engineering project.

`the shell` works like the bash and other basic shells.

The shell can compile using `gcc -Wall -Werror -Wextra -pedantic *.c -o shell`.

## Example of how to launch the shell after compiling:
`./shell`

* Output: prompt to terminal: `$ `

## Syntax
The shell works by using commands given by the user input. The shell commands take in the following syntax: `command name {arguments}`. The shell executes a command after it is written by user using the command followed by the arguments.


For more information on cat, you can use the `man` command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are `exit` and `env`. You can also use `help` command to know which builtins are provided by the shell. The `help` command works similarly to the manual where it provides further detail or information on given builtin.

### Compilation
All files will be compiled with the following: `$ gcc -Wall -Werror -Wextra -pedantic *.c`


### Builtins
There are two builtins programmed into the shell. Below is a description and use for each builtin.

* `env` - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a    way to access those values through the shell.

* `exit` - If you wish to exit out of the shell the user can use the builtin `exit`.

* `cd` - To change directory.


### Exiting commands and the shell
To exit out of a command or process the user can use `ctrl c`. `Control c` stops a process and causes it to abort.
The user can also utilize the command `ctrl D` which will just exit. When the command `ctrl D` is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

## Files
* `README.md` : Current file, contains information about this project
* `main.h` : Header file, contains all prototypes for funcitons used, as well as libriaries
* `hsh.c`: Main file that uses most functions and executes them within this file
* `_getenv.c` : Contains the code for `_printf`
* `_getline.c`: File for getting prompt and user input
* `which.c`: File containing the specific functions for conversion specifiers
* `builtins.c`: identifying and executing the builtins function
* `execute.c`: File that forks and creates child processee and excute the commands
* `free.c`: File with free malloc functions
* `prompt.c`: File with actual prompt line $
* `parse.c`: File that creates function to tokenize an array of strings
* `strings.c`: helper functions

### Comments

### Authors
* Solomon ferede Ezez - https://github.com/solomon1227

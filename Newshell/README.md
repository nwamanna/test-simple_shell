![Logo](https://pbs.twimg.com/media/C93xIaaUwAAAM99?format=jpg&name=small)

 # ze_sh - a simple shell

##### ZE_SH  Shell is a simple command line shell for OS X and Linux. ze_sh  includes most basic features present in the bash shell. This shell was built as a project for Holberton School.

#### Quick Start and Installation

------

ZE_SH  works like any other shell, like bash or zsh.

ZE_SH  builds successfully with a GCC 4.8.8 compiler or later. ZE_SH  can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o ZE_SH _shell`.

To start up ZE_SH  Shell, simply type
```
./ze_sh
```
in the terminal.

#### Syntax Overview

------

Like other shells, ze_sh  is used by given it commands. Every ze_sh  command follows the same general syntax: `command name {arguments}`. The command is executed by writing the name of the command followed by any arguments.

```
echo Hello ze_sh 
```

Above will run the `echo` command, which will write its arguments `Hello ze_sh ` to  the standard output.

For more information on echo, you can use the `man` command. The `man` command displays a manual page of a given command, system call, libraries, and important files.

```
man echo
```

The hsh shell also provides various builtins, commands built into the hsh shell itself. For more information on specific builtins, you can use the `help` command, which provides a similar manual for the specific builtin.


#### Commands

------

Any program in your computer can be used as a command in ze_sh  by typing the filename, provided the program is located in any of the directories in the [PATH - link include]. Otherwise, a full path to the program is required.

```
/Desktop/Holberton/_echo Hello Holberton
```

##### Command Seperation

Commands and any arguments are seperated by a ` ' '` . Commands are read and executed from left to right and end with a newline (i.e Return Key).

```
echo Hello Holberton
```
##### Switches & Flags

Switches and flags arguments of commands are also supported by ze_sh . Most switches start with a hypen, `-`  For example, when a user inputs:

```
ls -l
```

The `ls` commands lists all directories and files in the current working directory. However, including the flag `-l` , will list all files and directories in long format.

##### List of useful commands

`cat` - concatenate and print files to standout output

`cp` - copy files to another file

`grep` - searches a file for a specified pattern

`less` - allows backward moveement in the file as well as foward movement

`ls` - lists all files and directories of current working directory

`mv` - moves one file into another file

`pwd` - prints out the current working directory

#### Builtins

------

There are several builtins programmed into the ze_sh . Below is a description and use for each builtin.

##### env

To print out a list of all the environmental variables, the builtin `env` can be used. Each environmental variable and its value is printed out with a syntax of `key=value`. Each variable is separated by a new line.
```
env
```
##### exit

To exit out of the shell, the user may use the `exit` builtin.

```
exit
```

#### Exiting commands and ze_sh 

------

To exit out of a process or command, `ctrl c` is used. Control-C interrupts a process and causes it to abort.

To exit out of the ze_sh  shell, the user can do one of the following, `ctrl D` or `exit `. When exiting with `ctrl D`, an exit status of 0 is given.
# Simple Shell Project for Atlas School

## Description

A simple UNIX command interpreter built as part of the Holberton School curriculum. This shell can execute simple commands in an environment similar to `/bin/sh`.

---

## Table of Contents

1. [Learning Objectives](#learning-objectives)
2. [Features](#features)
3. [Compilation and Setup](#compilation-and-setup)
4. [Tasks](#tasks-summary)
5. [Usage](#usage)
6. [Examples](#examples)
7. [Betty Linter and Style Guide](#betty-linter-and-style-guide)
8. [Man Page](#man-page-setup)
9. [Testing for Memory Leaks](#testing-for-memory-leaks)
10. [Authors](#authors)

---

## Learning Objectives

<details>

  <summary>Learning Objectives</summary>
  
### Who designed and implemented the original Unix operating system?

- **Ken Thompson** and **Dennis Ritchie** developed Unix in the late 1960s at Bell Labs.

### Who wrote the first version of the UNIX shell?

- The first UNIX shell, called the **Thompson shell**, was written by **Ken Thompson** in 1971.

### Who invented the B programming language (the direct predecessor to the C programming language)?

- **Ken Thompson** created the B programming language, which was later improved by **Dennis Ritchie** into the C programming language.

### Who is Ken Thompson?

- **Ken Thompson** is a computer scientist known for co-creating Unix, the B programming language, and contributing to the design of regular expressions and the C language.

### How does a shell work?

- A shell is a command-line interpreter that reads user commands, interprets them, and then executes them. It can run internal shell commands (like `cd`) or launch external programs using system calls.

### What is a pid and a ppid?

- **PID**: Process ID – a unique identifier for a running process.
- **PPID**: Parent Process ID – the PID of the process that started the current process.

### How to manipulate the environment of the current process?

- You can manipulate the environment using functions like `setenv()` to set a variable, `unsetenv()` to remove a variable, or directly modify the `environ` global variable.

### What is the difference between a function and a system call?

- A **function** is a block of code that performs a specific task within a program.
- A **system call** is a request made by a program to the kernel (operating system) to perform low-level operations, like creating processes or accessing hardware.

### How to create processes?

- Use the **`fork()`** system call to create a new process. The parent process receives the PID of the child process, while the child gets 0 as the return value.

### What are the three prototypes of main?

- `int main(void)`
- `int main(int argc, char *argv[])`
- `int main(int argc, char *argv[], char *envp[])`

### How does the shell use the PATH to find the programs?

- The shell uses the **`PATH`** environment variable, which contains a list of directories. When a command is entered, the shell searches each directory in `PATH` for an executable file matching the command name.

### How to execute another program with the execve system call?

- Use the **`execve()`** system call to replace the current process with a new one, executing a specified program. This function takes the path to the executable, arguments, and the environment variables.

### How to suspend the execution of a process until one of its children terminates?

- Use the **`wait()`** or **`waitpid()`** system call to pause the parent process until one of its child processes has finished execution.

### What is EOF / “end-of-file”?

- **EOF (End of File)** is a special condition that indicates no more data can be read from a file or input stream. In the shell, it's triggered when the user presses **Ctrl+D** or when reading input from a file reaches its end.
  
</details>

## Features

- **Simple command execution**: Execute basic commands such as `ls`, `pwd`, etc.
- **Error handling**: Handles invalid commands and prints error messages.
- **Built-in commands**:
  - `exit`: Exits the shell.
  - `env`: Prints the current environment variables.
- **Environment**: The shell uses the `PATH` to find and execute commands.
- **EOF handling**: Detects `Ctrl+D` and exits the shell gracefully.

---

## Compilation and Setup

To get started with the Simple Shell, follow the steps below.

### Dependencies

Make sure you have the following installed:

- **GCC Compiler**: You can install it via:

```bash
sudo apt-get install build-essential
```

- Valgrind(for memory checking)

``` bash
sudo apt-get install valgrind
```

## Compilation

All files will be compiled with the following:

``` bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 
```

<details>
  <summary>Options Explained</summary>

- **`-Wall`**: Enables all compiler warning messages, helping to identify potential issues in your code.
  
- **`-Werror`**: Treats all warnings as errors, preventing the code from compiling if any warnings are present. This ensures you address all warnings.
  
- **`-Wextra`**: Enables additional warning messages that are not covered by `-Wall`, providing more insight into potential issues.
  
- **`-pedantic`**: Enforces strict adherence to the C standard, disallowing any compiler-specific extensions or non-standard code.
  
- **`-std=gnu89`**: Specifies the use of the GNU89 C standard (C89 with GNU extensions), which is the standard used for this project.

</details>

## Tasks Summary

Here’s a high-level overview of the tasks involved in this project:

1. **Initial Setup**:
   - Write a README, man page, and an AUTHORS file listing contributors.
   
2. **Code Quality**:
   - Ensure the code passes the Betty linter checks for style and standards.

3. **Simple Shell Functionality**:
   - Create a basic UNIX command line interpreter that:
     - Displays a prompt, waits for user input, and handles command execution.
     - Supports simple commands without semicolons, pipes, or redirections.
     - Handles command errors and gracefully handles `Ctrl+D` (EOF).
   
4. **Extended Shell Features**:
   - Implement handling of command-line arguments.
   - Manage the `PATH` to locate executables and ensure `fork()` is only called if the command exists.
   
5. **Built-In Commands**:
   - Implement `exit` to terminate the shell.
   - Implement `env` to print the current environment variables.

---

## Detailed Tasks

### 1. Initial Setup

- **README**: Write a comprehensive README explaining how the shell works, how to compile it, and how to run it.
- **man Page**: Write a man page for the shell that provides documentation on how to use it.
- **AUTHORS**: Create an AUTHORS file at the root of the repository that lists all individuals who have contributed to the project.

### 2. Code Quality

- **Betty Compliance**: Ensure the code is well-formatted and passes all Betty style checks. Betty is the linter used to ensure coding standards are followed in the Holberton curriculum.

### 3. Simple Shell Functionality

- **Prompt and Command Handling**:
  - Your shell should display a prompt and wait for the user to enter a command.
  - After executing the command, the shell should display the prompt again.
  
- **Command Execution**:
  - Only simple commands should be supported — no semicolons, pipes, or advanced features.
  - Commands will consist of a single word (the command name).
  
- **Error Handling**:
  - If an executable cannot be found, print an error message and redisplay the prompt.
  - Handle `Ctrl+D` (EOF) gracefully to exit the shell.

### 4. Extended Shell Features

- **Arguments**:
  - Add support for handling command-line arguments (e.g., `ls -l`).

- **PATH Handling**:
  - Your shell should use the `PATH` environment variable to locate executables.
  - Ensure that `fork()` is not called if the command does not exist.

### 5. Built-In Commands

- **exit**:
  - Implement the `exit` built-in command to exit the shell.
  - The `exit` command should not accept any arguments.
  
- **env**:
  - Implement the `env` built-in command to print the current environment variables.

---

## Usage

After compilation, you can run the shell using the following command:

``` bash
./hsh
```

Once the shell is running, you'll see a prompt (($)), where you can type commands.

### Built-in Commands:

exit: Exits the shell.
Usage: Type exit and press Enter to close the shell.

env: Prints the environment variables.
Usage: Type env and press Enter to see all environment variables.

### Example Commands:

- Running ls:

``` bash
($) ls
```

Output: Lists the files and directories in the current folder.

- Using pwd to print the working directory:

```bash
($) pwd
```

Output: Displays the full path of the current directory.

- Help in the shell:

``` bash
($) help
```

Output: Displays help during the shell instance.

- Exiting the shell:

``` bash
($) exit
```

## Examples

### Example 1: Basic Commands

``` bash

$ ./hsh
($) ls
AUTHORS  README.md  aux_functions.c  builtins.c  hsh  shell.h
($) pwd
/workspaces/holbertonschool-simple_shell
($) env
SHELL=/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
...
($) exit
$
```

### Example 2: Handling Invalid Commands

``` bash

$ ./hsh
($) invalidcommand
./hsh: 1: invalidcommand: not found
($) exit
$
```

---

## Betty Linter and Style Guide

The project must adhere to the Betty coding style, a linter used at Holberton School for code formatting.

### Running Betty
To install and run Betty:

Install Betty (if not already installed):

Clone the Betty repository:

``` bash
git clone https://github.com/holbertonschool/Betty.git
```

Navigate to the Betty directory:
``` bash
cd Betty
```

Install the linter:

```bash
./install.sh
```

Run Betty on Your Code: After installation, you can run Betty on your .c files:

``` bash
betty *.c
```

This will check your code style and ensure it follows the required conventions.

## Man Page Setup

The hsh command includes a custom man page to provide usage instructions.

Install the Man Page: To install the man page, copy hsh.1 to the correct man page directory:

```bash
sudo mkdir -p /usr/local/man/man1
sudo cp hsh.1 /usr/local/man/man1/
```

Access the Man Page: Once installed, you can access the manual using:

```bash
sudo mandb
man hsh
```

This will display the manual for the hsh shell.

## Testing for Memory Leaks

To ensure that there are no memory leaks, use Valgrind for testing:

```bash
valgrind --leak-check=full ./hsh
```

Valgrind will report any memory leaks during execution.

## Authors

Eve Baker

Crystal Carrillo

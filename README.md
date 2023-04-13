# Simple Shell Project for Holberton School
### Made by Eve Baker and Crystal Carrillo

#### Description: Write a simple UNIX command interpreter.
##### Learning Objectives of this project:  

Who designed and implemented the original Unix operatingsystem?  
Who wrote the first version of the UNIX shell?  
Who invented the B programming language (the directpredecessor to the C programming language)?  
Who is Ken Thompson?  
How does a shell work?  
What is a pid and a ppid?  
How to manipulate the environment of the current process?  
What is the difference between a function and a system call?  
How to create processes.  
What are the three prototypes of main?  
How does the shell use the PATH to find the programs?  
How to execute another program with the execve system call.  
How to suspend the execution of a process until oneof its children terminates.  
What is EOF / “end-of-file”?  







## Output:
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the nameof the program must be equivalent to your argv[0]

## Compilation:
All files will be compiled with the following:
```$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```


## Tasks:
0. README, man, AUTHORS  
	*Write a README.  
	*Write a man for your shell.  
	*You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker.  

1. Betty would be proud.  
Write a beautiful code that passes the Betty checks.  
Repo:GitHub repository: holbertonschool-simple_shell  

2. Simple shell 0.1  
Write a UNIX command line interpreter.  

``` Usage: simple_shell ```

Your Shell should:  

	*Display a prompt and wait for the user to type a command.   A command line always ends with a new line.  
	*The prompt is displayed again each time a command has been executed.  
	*The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.  
	*The command lines are made only of one word. No arguments will be passed to programs.  
	*If an executable cannot be found, print an error message and display the prompt again.  
	*Handle errors.  
	*You have to handle the “end of file” condition (Ctrl+D).  

3. Simple shell 0.2.  
Simple shell 0.1 +  
	*Handle command lines with arguments. 

4. Simple shell 0.3.  
Simple shell 0.2 +  

	*Handle the PATH  
	*fork must not be called if the command doesn’t exist  

5. Simple shell 0.4  
Simple shell 0.3 +  

	*Implement the exit built-in, that exits the shell  
	*Usage: exit  
	*You don’t have to handle any argument to the built-in exit.  

6. Simple shell 1.0.  
Simple shell 0.4 +  

	*Implement the env built-in, that prints the current environment  












## Examples:

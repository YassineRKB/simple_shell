#### -> Project Requirments: 
	A thompsone shell,  that can be run both in interactive mode and non interiactive mode. 

### -> DataFlow Diagram:
![alt text](https://github.com/YassineRKB/simple_shell/blob/prototypev2/images/graph.png)
#### -> Project RoadMap:
	> Implement Interactive Mode: print '$ ' on each terminal line. 
	> Read 1024 buffer of input at time and spit back whole input.
	> Add "EOL" or 'CTRL+D' Command detection.
	> Read $PATH env var and spit back Each path with ':' as delimeter.
	> Read terminal Command and check command against paths in $PATH.
	> Handle errors if command does not exist.
	> Implement History Buffer to record all insrted commands.
	> Implement built-in Commands.
	> Implement support for local commands.
	> Implement support for reading commands from a file
	> Finish Establishing non-Interiactive mode.

### -> Compile with:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### -> Project Folder Format:
	README.md AUTHORS *.c ./hsh


### TO-DO:
+ [x] make own getline();
+ [x] make own getenv();
+ [x] make own getpath();
+ [x] make own isvalid();
+ [x] make own atoi();
+ [ ] make own strtok();
+ [x] make own strcmp();
+ [ ] make own strncmp();
+ [x] make own strcpy();
+ [x] make own strdup();
+ [x] make own realloc();
+ [x] make own memcpy();
+ [x] make own strlen();
+ [ ] make own printf();
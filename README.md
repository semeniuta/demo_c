# demo_c

Collection of short C demos:

 * `growarr.c`: grow array on heap using `realloc` function call
 * `playstrtok.c`: split a string using `strtok`
 * `readstrings.c`: read strings from stdin using `scanf` 
 * `scopenread.c`: demo of `open`, `read`, `close` system calls and the associated error handling functionality
 * `udsock_srv.c`: UNIX domain sockets demo (still in progress)
 * `playgl.c`: read lines from stdin or a file using `getline`

The demos are buildable using `make`. The enclosed `Makefile` generates an execuble from every `.c` source file. 

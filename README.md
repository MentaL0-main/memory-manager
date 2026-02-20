# Memory manager

![screenshot](screenshots/screenshot.png)
![screenshot](screenshots/screenshot2.png)

## Description
Memory manager is a small utility that allows you to manage memory at a basic level. Allocate and deallocate

## Commands
You can type 'help' to get list of all commands:

```bash
Welcome to memory manager!
You can type 'help' to get list of commands.
~# help
list of commands:
 memory - show count of use memory (bytes).
 exit - exit from program, also you can press Ctrl+C.
 allocate - allocate 200MB.
 free - free all allocate memory.
 overflow - this command start infinity loop of allocating memory!
 clear - clear console output.
 help - show this message.
~# 
```

## Quick start
1) Clone and go to repository
```bash
git clone https://github.com/mental0-main/memory-manager.git
cd memory-manager
```

2) Compile with gcc/clang
```bash
gcc -o memory-manager main.c
```

3) Finally - Execute and use
```bash
./memory-manager
```

## License
Lincense - MIT.

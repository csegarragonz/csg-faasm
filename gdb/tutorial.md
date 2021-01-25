# GDB Cheat Sheet

## Getting started

+ Compile with debugging symbol table (use the `-g` flag):
```
clang++-10 -g *.cpp -o <out>
```

+ Start GDB:
```
gdb <binary>
```

+ Run with arguments:
```
r
r <args>
r < <file>
```

+ To load a file from within gdb:
```
file <program_name>
```

+ Quit GDB:
```
q
```

## Stepping through the code

+ Print source code:
```
l # Print 10 lines of code
l <N> # print N lines of code
l <function_name> # print source code of a function
```

+ Stepping through the code:
```
next (n) # run until next line of code
step (s) # run next line of code and step into functions
finish (f) # finishes execution of the current function and stops, step out
```

## Breakpoints and Watchpoints

+ Breakpoints:
```
break (file.cpp:)45 # breakpoint at a specific line number
break (file.cpp:)45 if <condition> # conditional breakpoint
break myfunction # breakpoint at a specific function
info break # prints the available breakpoints
clear <line_num> # remove a specific breakpoint
```

+ Watchpoints:
```
watch x == 3 # pauses the program when a condition changes
watch x # pause when the variable changes
```

+ Resume execution and delete breakpoints:
```
continue # resume execution
delete N # deletes N breakpoints
```

## Printing values

+ Print the value of a variable:
```
print <var> # prints the value of a variable
print/x <var> # prints the value in hexadecimal
```

+ When printing pointer values, we may use the standard pointer
operators: `*`, `.`, `->`.

## Backtrace and changing frames

+ Print the current stack:
```
bt

c() # newest
b()
a()
main() # oldest
```

+ Moving around frames:
```
up/down # move to the next frame to examine local variables.
```

# Analyzing core dumps

+ Load the core dump:
```
gdb <binary> <core>
bt # get the backtrace
frame <number> # inspect given frame
list # see code around function
info locals # see local variables
print <name_variable> # to see its value
```

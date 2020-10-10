# Wiki of errors

## Can't link with some header file
+ Usually happens after recompiling `wasi-libc`
+ Example:
```bash
fatal error: 'faasm/faasm.h' file not found
#include "faasm/faasm.h"
```
+ Solution: recompile the toolchain libraries.
```bash
cd <faasm>
source workon.sh
inv libs.toolchain
```

## Errors with the Fortran compiler
+
+ Example:
```bash
The Fortran compiler
"/usr/bin/f95"
is not able to compile a simple test program.
...
/usr/bin/ld: ungrecognized option '--stack-first'
error: ld returned 1 exit status
```
+  Solution: 


## Cross-Compilation: symbol not defined (syscall)
+ Usually the symbol is not defined in `wasi-libc`
+ Either we include it - then see [this doc](./extending_libc.md) - or we 
discard it.

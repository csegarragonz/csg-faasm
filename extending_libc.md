### Steps to get rid of compiler error around popen:
+ Change stdio.h in wasi-lib to include popen definition with `if defined(__faasm)...`
+ Copy your modified stdio.h into place in /usr/local/faasm/llvm-sysroot/include
+ Add `popen`  to the list of acceptable missing symbols at `faasm/faasm-toolchain/sysroot_extras/libc.imports`
+ Copy your modified libc.imports  to /usr/local/faasm/llvm-sysroot/lib/wasm32-wasi/
+ This will leave an undefined symbol in the output wasm for popen, then to finally link and run (you can do this later):
  + Add a popen stub to process.cpp (see link above)
+ Note that instead of copy-pasting headers and .imports files around, you can also rebuild libc:
```bash
# Remember to be in the right wasi-libc branch!
cd third-party/faasm-toolchain
make clean-libc
make
```

### References
+ https://lld.llvm.org/WebAssembly.html
+ https://github.com/apache/incubator-mxnet/compare/master...faasm:faasm
+ https://github.com/faasm/wasi-libc (edited) 
+ https://github.com/faasm/wasi-libc/blob/faasm/libc-top-half/musl/include/stdio.h#L160 (edited) 
+ https://github.com/faasm/wasi-libc/blob/faasm/libc-top-half/musl/include/stdio.h#L146 (edited) 
+ https://github.com/faasm/faasm/blob/master/src/wavm/process.cpp (edited) 

### Further tips for tracking:
+ **Alwas work from the `faasm` repo as root!!!!!**
+ Create a branch called `lammps` in `faasm`, `faasm-toolchain` and `wasi-libc`
+ Create a draft PR from each of those
+ Add all those draft PRs to the project board
+ Then look at https://github.com/pulls

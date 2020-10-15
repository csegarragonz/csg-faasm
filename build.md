+ Reset to a working state from Github
```bash
rm -r build
inv toolchain.download-toolchain
inv toolchain.download-sysroot

inv dev.cmake
inv dev.cc simple_runner
inv dev.cc codegen_func

inv compile demo hello
inv codegen demo hello

inv run demo hello
```

+ Build the toolchain
```bash
inv dev.cc codegen_shared_obj
inv libs.toolchain
```

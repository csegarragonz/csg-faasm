## Run a custom script with a helper binary:
+ Install it in some relative path to the build dir (e.g. `../install`).
+ Copy the compiled binary to `wasm/<user>/<funcion>/function.wasm` (e.g. `wasm/lammps/test/function.wasm`)
+ Run the code generation and the actual function:
```bash
inv codegen <user> <function> # inv codegen lammps test
inv run <user> <function> # inv run lammps test
```

## Use a custom data file as input
+ Upload the data file to the upload server
```bash
# Run an upload server
inv dev.cc upload
inv dev.r upload

# Upload the file 
inv state.shared-file <path-to-file> <relative-path-within-faasm>
```

+ The file gets uploaded to
```
/usr/local/faasm/shared_store/<relative path>
```

+ When loaded by a function it gets cached on the function host at
```
/usr/local/faasm/shared/<relative path>
```

+ Note that, when running locally the function host and the upload host are the same


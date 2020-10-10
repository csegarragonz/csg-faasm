+ Reset submodule dependencies
```bash
rm -r third-party/*
git submodule sync
git submodule update --init
```

+ Update tags
```bash
cd <FAASM_HOME>
ctags -R .
```

+ Code formatting:
  + We use clang-format-10 for C++ code. From within vim run: `<Leader>c` or `:ClangFormat`.
  + We use black for python code. From within vim run: `Black`


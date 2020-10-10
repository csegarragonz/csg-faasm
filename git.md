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

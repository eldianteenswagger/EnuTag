HOW TO START:
```bash
cmake .. (copies .mac files in /build)
make -jN
./main
```

./main can be initialised with macro:
```bash
./main MACRONAME.mac
```
this will start the executable using the referenced macro.
Default macro is vis.mac, which starts an OPENGL GUI.

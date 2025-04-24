HOW TO START:
```console
cmake .. (copies .mac files in /build)
make -jN
./main
```

./main can be initialised with macro:
```console
./main MACRONAME.mac
```
this will start the executable using the referenced macro.
Default macro is vis.mac, which starts an OPENGL GUI.

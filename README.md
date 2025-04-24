##Starting program

HOW TO START:
```console
cmake ..
make -jN
./main
```

When cmake is run all .mac files are copied from /Macros to /Build. If marcos are changed, cmake .. must be rerun.

./main can be initialised with macro:
```console
./main MACRONAME.mac
```
this will start the executable using the referenced macro.
Default macro is vis.mac, which starts an OPENGL GUI.
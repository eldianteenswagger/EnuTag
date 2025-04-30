# Starting program

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

> [!NOTE]
> The program can handle multithread but requires A LOT of RAM memory for # of cores > 6.

# Macros

| vis.mac | Default macro for visualisation. Uses `OPENGL`. |
| test.mac | Changes `PrimaryGenerator` to shoot 8.5 GeV pions from just after target. |
| run.mac | Used to run big particle batches. Does not start visualization. |


# Starting program

HOW TO START:
```console
cmake ..
make -jN
./main
```

When cmake is run all `.mac` files are copied from /macros to /muild. If macros are changed, `cmake ..` must be rerun.

./main can be initialised with macro:
```console
./main MACRONAME.mac
```
this will start the executable using the referenced macro.

> [!NOTE]
> The program can handle multithread but requires A LOT of RAM memory if the number of used cores is set above around 6.

# Macros

| Macro | Description |
| --- | --- |
| vis.mac | Default macro for visualisation. Uses `OPENGL`. |
| test.mac | Changes `PrimaryGenerator` to shoot 8.5 GeV pions from just after target. |
| run.mac | Used to run big particle batches. Does not start visualization. |

# Custom commands

`\ENUTAG\` contains some custom commands to be used during visualisation:

- \ENUTAG\testMode <bool>: enable/disable test mode (8.5 GeV pions).


# TO DO 

- Macros are not working from bash line.
- Add ROOTMessenger.
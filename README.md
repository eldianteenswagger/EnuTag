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

# ROOT files

ROOT ouput files are stored in the /ROOT macro.
/ROOT also contains `hist.C`. This is a macro that can be used to access the particle energy spectrum seen by a detector.
Currently the detector name must be set by hand.<br />
USVD, DSVD1 and DVSD2 are considered __virtual__ detectors, and thus **dE** is not computed.

## ROOT file structure

NomeDetector<br />
╠ E<br />
╠ x<br />
╠ y<br />
╠ z<br />
╠ px<br />
╠ py<br />
╠ pz<br />
╠ t<br />
╠ PDG<br />
╚ dE (only for real detectors, 1 to 5)

# TO DO 

- run.mac starts a void OPENGL. To address.
- Add ROOTMessenger.
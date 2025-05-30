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

# Macros

| Macro | Description |
| --- | --- |
| vis.mac | Default macro for visualisation. Uses `OPENGL`. |
| graphics.mac | Handles proper visualisation of blocks in `OPENGL`. Called by `vis.mac`, `test.mac`, `shielding.mac` and `soil.mac` |
| test.mac | Changes `PrimaryGenerator` to shoot 8.5 GeV pions from just after target. Uses `OPENGL`. |
| run.mac | Used to run big particle batches. Does not start visualization. |
| shieldings.mac | Shows shieldings and concrete. Uses `OPENGL`. |
| soil.mac | Shows soil blocks. Uses `OPENGL`. |

# Custom commands

`\ENUTAG\` contains some custom commands to be used during visualisation:

- \ENUTAG\testMode <bool>: enable/disable test mode (8.5 GeV pions).
- \ENUTAG\outName <string>: define output file name (e.g. outFile.root).

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

neutrinos contains origin coordinates of neutrino tracks

# TO DO 

- add hists to hist_salad.C
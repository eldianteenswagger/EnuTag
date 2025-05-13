import os
n_jobs = 10
n_threads = 10
n_particles = 5000
macro_dir = "macros/"
out_dir = "/sps/gdrnu/lzappacosta01/jobsOut"
sh_dir = "sh/"

if(os.path.isdir(macro_dir)==False):
    os.mkdir(macro_dir)
if(os.path.isdir(sh_dir)==False):
    os.mkdir(sh_dir)

for i in range(n_jobs):
    macrofile = open(macro_dir+"/run"+str(i)+".mac","w")
    print("/run/numberOfThreads "+str(n_threads), file=macrofile)
    print("/run/initialize", file=macrofile)
    print("/ENUTAG/testMode false", file=macrofile)
    print("/ENUTAG/outName "+out_dir+"runOut"+str(i)+".root", file=macrofile)
    print("/run/initialize", file=macrofile)
    print("/run/beamOn "+str(n_particles), file=macrofile)
    macrofile.close()

    shfile = open(sh_dir+"/test"+str(i)+".sh","w")
    print("#!/bin/bash", file=shfile)
    print("#SBATCH --ntasks=1", file=shfile)
    print("#SBATCH --account=gdrnu", file=shfile)
    print("#SBATCH --partition=htc", file=shfile)
    print("#SBATCH --licenses=sps", file=shfile)
    print("#SBATCH --time=4:00:00", file=shfile)
    print("#SBATCH --job-name=ENUTAGt"+str(i), file=shfile)
    print("#SBATCH --output=/sps/gdrnu/lzappacosta01/LOG/logtest"+str(i)+".out", file=shfile)
    print("#SBATCH --error=/sps/gdrnu/lzappacosta01/LOG/logtest"+str(i)+".err", file=shfile)
    print(" ", file=shfile)
    print("module unload Analysis/root", file=shfile)
    print("module unload Modelisation/geant4", file=shfile)
    print("module add Analysis/root/6.26.14", file=shfile)
    print("module load Modelisation/geant4/11.3.0", file=shfile)
    print("pwd", file=shfile)
    print("cp /sps/gdrnu/lzappacosta01/EnuTag/build/main .", file=shfile)
    print("cp /sps/gdrnu/lzappacosta01/EnuTag/sbatch/macros/run"+str(i)+".mac .", file=shfile)
    print("main run"+str(i)+".mac", file=shfile)
    shfile.close()
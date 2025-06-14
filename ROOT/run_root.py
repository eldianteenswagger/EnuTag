import os

shfile = open("startRoot.sh","w")
print("#!/bin/bash", file=shfile)
print("#SBATCH --ntasks=1", file=shfile)
print("#SBATCH --account=gdrnu", file=shfile)
print("#SBATCH --partition=htc", file=shfile)
print("#SBATCH --licenses=sps", file=shfile)
print("#SBATCH --time=48:00:00", file=shfile)
print("#SBATCH --mem=12G", file=shfile)
print("#SBATCH --job-name=RootGigi", file=shfile)
print("#SBATCH --output=/sps/gdrnu/lzappacosta01/LOG/logtestROOT.out", file=shfile)
print("#SBATCH --error=/sps/gdrnu/lzappacosta01/LOG/logtestROOT.err", file=shfile)
print(" ", file=shfile)
print("module unload Analysis/root", file=shfile)
print("module add Analysis/root/6.26.14", file=shfile)
print("pwd", file=shfile)
print("cp /sps/gdrnu/lzappacosta01/EnuTag/jobsOut/hists.C .", file=shfile)
for j in range(5000):
    print("cp /sps/gdrnu/lzappacosta01/EnuTag/jobsOut/runOut"+str(j)+".root .", file=shfile)
print("root hists.C", file=shfile)
shfile.close()

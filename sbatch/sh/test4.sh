#!/bin/bash
#SBATCH --ntasks=1
#SBATCH --account=gdrnu
#SBATCH --partition=htc
#SBATCH --licenses=sps
#SBATCH --time=4:00:00
#SBATCH --job-name=ENUTAGt4
#SBATCH --output=/sps/gdrnu/lzappacosta01/LOG/logtest4.out
#SBATCH --error=/sps/gdrnu/lzappacosta01/LOG/logtest4.err
 
module unload Analysis/root
module unload Modelisation/geant4
module add Analysis/root/6.26.14
module load Modelisation/geant4/11.3.0
pwd
cp /sps/gdrnu/lzappacosta01/EnuTag/build/main .
cp /sps/gdrnu/lzappacosta01/EnuTag/sbatch/macros/run4.mac .
main run4.mac

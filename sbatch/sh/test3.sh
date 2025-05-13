#!/bin/bash
#SBATCH --ntasks=1
#SBATCH --account=gdrnu
#SBATCH --partition=htc
#SBATCH --licenses=sps
#SBATCH --time=1:00:00
#SBATCH --job-name=ENUTAGt3
#SBATCH --output=/sps/gdrnu/fpupilli/tesi_Luigi/LOG/logtest.out
#SBATCH --error=/sps/gdrnu/fpupilli/tesi_Luigi/LOG/logtest.err 

module unload Analysis/root
module unload Modelisation/geant4
module add Analysis/root/6.26.14
module load Modelisation/geant4/11.3.0
pwd
cp /sps/gdrnu/fpupilli/tesi_Luigi/EnuTag/build/main .
cp /sps/gdrnu/fpupilli/tesi_Luigi/EnuTag/build/run3.mac .
main run3.mac

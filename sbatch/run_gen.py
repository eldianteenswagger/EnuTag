import os
n_jobs = 4
n_threads = 10
n_particles = 1000
macro_dir = "macros/"
out_dir = "../ROOT/"
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



    #!/bin/bash                                                                                                                                                                             
#SBATCH --ntasks=1                                                                                                                                                                      
#SBATCH --account=gdrnu                                                                                                                                                                 
#SBATCH --partition=htc                                                                                                                                                                 
#SBATCH --licenses=sps                                                                                                                                                                  
#SBATCH --time=2:00:00                                                                                                                                                                  
#SBATCH --job-name=ENUTAGt                                                                                                                                                              
#SBATCH --output=/sps/gdrnu/fpupilli/tesi_Luigi/LOG/logtest.out                                                                                                                         
#SBATCH --error=/sps/gdrnu/fpupilli/tesi_Luigi/LOG/logtest.err                                                                                                                          
#SBATCH --mem=12G                                                                                                                                                                       


module unload Analysis/root
module unload Modelisation/geant4
module add Analysis/root/6.26.14
module load Modelisation/geant4/11.3.0

pwd

cp /sps/gdrnu/fpupilli/tesi_Luigi/EnuTag/build/main .
cp /sps/gdrnu/fpupilli/tesi_Luigi/EnuTag/build/run.mac .

main run.mac
import os
n_jobs = 4
n_threads = 10
n_particles = 1000
sh_dir = "sh/"
out_dir = "../ROOT/"

if(os.path.isdir(sh_dir)==False):
    os.mkdir(sh_dir)

for i in range(n_jobs):
    f = open(sh_dir+"/run"+str(i)+".sh","w")
    print("/run/numberOfThreads "+str(n_threads), file=f)
    print("/run/initialize", file=f)
    print("/ENUTAG/testMode false", file=f)
    print("/ENUTAG/outName "+out_dir+"runOut"+str(i)+".root", file=f)
    print("/run/initialize", file=f)
    print("/run/beamOn "+str(n_particles), file=f)
    f.close()

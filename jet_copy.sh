bazel clean
echo " ---------- JETSON -------------"
sshpass -p "nvidia" scp -r * nvidia@tegra-ubuntu.local:/home/nvidia/VMOS

sshpass -p "nvidia" ssh nvidia@tegra-ubuntu.local 'cd /home/nvidia/VMOS && bazel build //victorycar:main && ls'

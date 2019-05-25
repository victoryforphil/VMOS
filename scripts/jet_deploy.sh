echo " ----------- Building using TX2 Config. -----------"
bazel build --config=tx2 //victorycar:all
echo " ----------- Clearing deployment directory on Jetson -----------"
sshpass -p "nvidia" ssh nvidia@tegra-ubuntu.local 'rm -r /home/nvidia/VMOS && mkdir /home/nvidia/VMOS/'
echo "----------- Deploying Build Results -----------"
sshpass -p "nvidia" scp -r bazel-bin/victorycar/* nvidia@tegra-ubuntu.local:/home/nvidia/VMOS/
echo "----------- Built and Deployed! -----------"
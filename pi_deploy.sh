echo " ----------- Building using TX2 Config. -----------"
bazel build --config=tx2 //testbed:all
echo " ----------- Clearing deployment directory on Jetson -----------"
sshpass -p "raspberry" ssh pi@pi.local 'rm -r /home/pi/VMOS && mkdir /home/pi/VMOS/'
echo "----------- Deploying Build Results -----------"
sshpass -p "raspberry" scp -r bazel-bin/testbed/* pi@pi.local:/home/pi/VMOS/
echo "----------- Built and Deployed! -----------"
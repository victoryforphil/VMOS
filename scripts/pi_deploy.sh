echo " ----------- Building using TX2 Config. -----------"
bazel build --config=tx2 //testbed:all
echo " ----------- Clearing deployment directory on Jetson -----------"
sshpass -p "raspberry" ssh ubuntu@10.0.0.30 'rm -r /home/ubuntu/VMOS && mkdir /home/ubuntu/VMOS/'
echo "----------- Deploying Build Results -----------"
sshpass -p "raspberry" scp -r bazel-bin/testbed/* ubuntu@10.0.0.30:/home/ubuntu/VMOS/
echo "----------- Built and Deployed! -----------"
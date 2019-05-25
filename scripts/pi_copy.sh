echo "----------- Deploying Build Results -----------"
bazel clean
sshpass -p "raspberry" scp -r * pi@pi.local:/home/pi/VMOS/
echo "----------- Built and Deployed! -----------"
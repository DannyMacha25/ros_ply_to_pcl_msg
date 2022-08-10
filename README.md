# PLY TO PCL MSG
This is just a node that turns a ply file
into a pcl msg and uploads it to a topic with 
ROS. 

To use it just clone the directory and change the
path of the file inside the params file. There is 
also a param for topic.

Just launch the node with `roslaunch pcl_stuff pcl_launch.launch`
and it will continously publish the pointcloud until
you stop the node.
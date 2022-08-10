
#include <pcl-1.8/pcl/io/ply_io.h>
#include <pcl-1.8/pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl-1.8/pcl/point_types.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud.h>



int main(int argc, char* argv[]){
    string topic;
    string path;

    ros::init (argc,argv,"e");
    ros::NodeHandle nh;

    nh.getParam("topic",topic,"/output");
    nh.getParam("path",path,"/home");

    pcl::PointCloud<pcl::PointXYZ>::Ptr pc(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPLYFile(path,*pc);

    
    ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("/output",10);

    sensor_msgs::PointCloud2 msg;
    pcl::toROSMsg(*pc,msg);

    msg.header.frame_id = "/base_link";

    ros::Rate loop(10);

    while (ros::ok()){
        pub.publish(msg);
        loop.sleep();
        ros::spinOnce();
        
    }
    return 0;
}


#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

std::string turtle_name;



void poseCallback(){
  static tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(0, 0, 0.0) );
  transform.setRotation( tf::Quaternion(0, 0, 0) );
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/odom_combined", "/base_footprint"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_pub_broadcaster");

  ros::NodeHandle node;
  //ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &poseCallback);
  ros::Rate rt(10);
  while (ros::ok()) {
    rt.sleep();
    poseCallback();
    ros::spinOnce();
  }

  //  ros::spin();
  return 0;
};


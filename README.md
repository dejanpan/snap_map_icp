SnapMapICP (re-)initializes localisation with amcl on the fly. It creates a pointcloud from the map and matches incoming laser scans to it using pcl point-to-point icp. After matching, the match quality is assessed by counting inliers - projected scan points that are within a defined distance to a map obstacle point after icp. When the inlier percentage is higher than the defined threshold and additionally, the assumed robot pose differs more than some threshold from the robot pose currently assumed by amcl, a new initial pose with a fixed covariance is sent to amcl. Additionally, SnapMapICP will only send a new initial pose every so many seconds. The behaviour can be controlled by setting parameters, all apart from the frame names are read out all the time and can thus be changed on-the-fly.

Apart from spamming rosout, the node creates a information topic /SnapMapICP that shows a human-readable summary of the current state per incoming laser scan.

Important parameters:

SnapMapICP/age_threshold, float, describes how old laser scans can be before they get sorted out by SnapMapICP. SnapMapICP/angle_upper_threshold, float, maximum icp transform angle that will still be considered a sane match published as an initial pose. SnapMapICP/update_age_threshold, float, seconds, how long before another, new initial pose will be sent after one was sent

SnapMapICP/icp_inlier_dist, float, meters distance a point can have to its nearest neighbor in map to be still considered as inlier SnapMapICP/icp_inlier_threshold, float, 1 = 100%, percentage of scan points that must match withing icp_inlier_dist so that the match is considered good and a initial pose can be sent

SnapMapICP/icp_num_iter, number of iterations in ICP

SnapMapICP/pose_covariance_trans, translational pose covariance the initial pose gets sent with

SnapMapICP/angle_threshold, float, minimum angle change that will trigger a re-initialisation of amcl SnapMapICP/dist_threshold, float, meters, minimum position change that will trigger a re-initialisation of amcl

SnapMapICP/odom_frame, string, usually "/odom_combined" SnapMapICP/base_laser_frame, string, usually "/base_laser_link"

[image1]: images/rmse.jpg 

# Extended Kalman Filter

In this project a kalman filter is utilized to estimate the state of a moving object of interest with noisy lidar and radar measurements. Files which were modified to accomplish the project are src/FusionEKF.cpp, src/FusionEKF.h, kalman_filter.cpp, kalman_filter.h, tools.cpp, and tools.h. The provided simulated lidar and radar measurements are detecting a bicycle that travels around a vehicle. The purpose is to track the bicycle's position and velocity.

INPUT: values provided by the simulator to the c++ program

["sensor_measurement"] => the measurement that the simulator observed (either lidar or radar)


OUTPUT: values provided by the c++ program to the simulator

["estimate_x"] <= kalman filter estimated position x
["estimate_y"] <= kalman filter estimated position y
["rmse_x"]
["rmse_y"]
["rmse_vx"]
["rmse_vy"]

RMSE values are computed using the provided ground truth (true position and speed of the bycicle).

### Building Instructions

1. Make a build directory: `mkdir build && cd build`
2. Compile: `cmake .. && make` 
3. Run it: `./ExtendedKF `

### Performance

Lidar measurements are red circles, radar measurements are blue circles with an arrow pointing in the direction of the observed angle, and estimation markers are green triangles. The image below shows what the simulator looks like when a c++ script is using its Kalman filter to track the object. The simulator provides the script the measured data (either lidar or radar), and the script feeds back the measured estimation marker, and RMSE values from its Kalman filter.

![alt text][image1]   

# Extended Kalman Filter Project

In this project you will utilize a kalman filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. Passing the project requires obtaining RMSE values that are lower that the tolerance outlined in the project rubric. 

The goals / steps of this project are the following:

* Step 1: Initializing kalman filter matrices and vectors 
* Step 2: Predicting state vector (px, py, vx, vy) and state covariance matrix 
* Step 3: Updating predicted states based on sensor measurements
* Step 4: Calculating rmse

Goals:
* Utilizing kalman filter to estimate the state of a moving object with lidar and radar mesaurments
* Achieving low RMSE values  

### Build & Run Instruction
This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

This repository includes two files that can be used to set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. For windows you can use either Docker, VMware, or even [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) to install uWebSocketIO. 

Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./ExtendedKF `

### Report

#### Data 1

* Using both Radar & Laser Measurment:

RMSE Total:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.0975829</td>
    <td>0.0865559</td>
    <td>0.</td>
    <td>0.448438</td>
  </tr>
</table>

RMSE Laser Only:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.126304</td>
    <td>0.0976934</td>
    <td>0.60724</td>
    <td>0.457049</td>
  </tr>
</table>

RMSE Radar Only:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.185953</td>
    <td>0.283136</td>
    <td>0.456911</td>
    <td>0.696011</td>
  </tr>
</table>

<table style="width:100%">
  <tr>
    <td>RMSE Total</td>
    <td>RMSE Laser only</td>
    <td>RMSE Radar only</td>
  </tr>
  <tr>
    <td><img src="./data1/rmse_total.png" width="350" height="200"/></td>
    <td><img src="./data1/rmse_laser.png" width="350" height="200"/></td>
    <td><img src="./data1/rmse_radar.png" width="350" height="200"/></td>
  </tr>
  <tr>
<table>

<table style="width:100%">
  <tr>
    <td>Simulator Total</td>
    <td>Simulator Laser only</td>
    <td>Simulator Radar only</td>
  </tr>
  <tr>
    <td><img src="./data1/sim_total.png" width="350" height="200"/></td>
    <td><img src="./data1/sim_laser.png" width="350" height="200"/></td>
    <td><img src="./data1/sim_radar.png" width="350" height="200"/></td>
  </tr>
  <tr>
<table>

According to the plots and avg RMSE values, considering both sensor information obviously generates more accurate results. However on dataset-1 LASER tends to be more precise than RADAR for (px & py) and less acurate for (vx,vy), while on dataset-2 LASER acheives a better RMSE than RADAR overall. 
It's also worth mentioning that eliminating 1 sensor results in missing almost half of the data from simulator. (total number of data ~440, laser-only:~220 , radar-only:~220)

#### Data 2

* Using both Radar & Laser Measurment:

AVG RMSE:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.069098066</td>
    <td>0.088632142</td>
    <td>0.697019243</td>
    <td>0.661271259</td>
  </tr>
</table>

AVG Laser Only:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.091197524</td>
    <td>0.097981478</td>
    <td>0.791264839</td>
    <td>0.472911087</td>
  </tr>
</table>

AVG Radar Only:
<table style="width:100%">
  <tr>
    <td>px </td>
    <td>py </td>
    <td>vx </td>
    <td>vy </td>
  </tr>
  <tr>
    <td>0.223615637</td>
    <td>0.235410359</td>
    <td>0.910446286</td>
    <td>1.006735722</td>
  </tr>
</table>

<table style="width:100%">
  <tr>
    <td>RMSE Total</td>
    <td>RMSE Laser only</td>
    <td>RMSE Radar only</td>
  </tr>
  <tr>
    <td><img src="./data1/rmse_total.png" width="350" height="200"/></td>
    <td><img src="./data1/rmse_laser.png" width="350" height="200"/></td>
    <td><img src="./data1/rmse_radar.png" width="350" height="200"/></td>
  </tr>
  <tr>
<table>

<table style="width:100%">
  <tr>
    <td>Simulator Total</td>
    <td>Simulator Laser only</td>
    <td>Simulator Radar only</td>
  </tr>
  <tr>
    <td><img src="./data1/sim_total.png" width="350" height="200"/></td>
    <td><img src="./data1/sim_laser.png" width="350" height="200"/></td>
    <td><img src="./data1/sim_radar.png" width="350" height="200"/></td>
  </tr>
  <tr>
<table>

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Generating Additional Data

This is optional!

If you'd like to generate your own radar and lidar data, see the
[utilities repo](https://github.com/udacity/CarND-Mercedes-SF-Utilities) for
Matlab scripts that can generate additional data.

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project resources page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/382ebfd6-1d55-4487-84a5-b6a5a4ba1e47)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! We'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Regardless of the IDE used, every submitted project must
still be compilable with cmake and make.

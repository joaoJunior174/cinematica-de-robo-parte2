/*
 * Copyright 1996-2020 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Description:   Starts with a predefined behaviors and then
 *                read the user keyboard inputs to actuate the
 *                robot
 */

#include <webots/keyboard.h>
#include <webots/robot.h>

#include <arm.h>
#include <base.h>
#include <gripper.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIME_STEP 64

int main(int argc, char **argv) {
  wb_robot_init();
  
  WbDeviceTag wheel1,wheel2,wheel3,wheel4;
  wheel1 = wb_robot_get_device("wheel1");
  wheel2 = wb_robot_get_device("wheel2");
  wheel3 = wb_robot_get_device("wheel3");
  wheel4 = wb_robot_get_device("wheel4");
  
  wb_motor_set_velocity(wheel1,0.7);
  wb_motor_set_velocity(wheel2,0.7);
  wb_motor_set_velocity(wheel3,0.7);
  wb_motor_set_velocity(wheel4,0.7);
  
  wb_robot_cleanup();

  return 0;
}

#include <webots/robot.h>
#include <webots/motor.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TIME_STEP 64

struct posRobo{

  double w1,w2,w3,w4;//velocidades angular
  int segs;//tempo que demora para fazer determinado percurso
  
};

int main(int argc, char **argv) {
  wb_robot_init();
  
  WbDeviceTag wheel1,wheel2,wheel3,wheel4;
  wheel1 = wb_robot_get_device("wheel1");
  wheel2 = wb_robot_get_device("wheel2");
  wheel3 = wb_robot_get_device("wheel3");
  wheel4 = wb_robot_get_device("wheel4");
  
  wb_motor_set_position(wheel1,INFINITY);
  wb_motor_set_position(wheel2,INFINITY);
  wb_motor_set_position(wheel3,INFINITY);
  wb_motor_set_position(wheel4,INFINITY);
  

  struct posRobo p[8];
  int ind=0;
  p[0].w1=2;p[0].w2=2;p[0].w3=2;p[0].w4=2;p[0].segs=210;//frente
  p[1].w1=0;p[1].w2=2;p[1].w3=2;p[1].w4=0;p[1].segs=440;//diagonal
  p[2].w1=-2;p[2].w2=2;p[2].w3=2;p[2].w4=-2;p[2].segs=220;//lado
  p[3].w1=-2;p[3].w2=0;p[3].w3=0;p[3].w4=-2;p[3].segs=440;//diagonal
  p[4].w1=-2;p[4].w2=-2;p[4].w3=-2;p[4].w4=-2;p[4].segs=210;//re
  p[5].w1=0;p[5].w2=-2;p[5].w3=-2;p[5].w4=0;p[5].segs=440;//diagonal
  p[6].w1=2;p[6].w2=-2;p[6].w3=-2;p[6].w4=2;p[6].segs=220;//lado
  p[7].w1=2;p[7].w2=0;p[7].w3=0;p[7].w4=2;p[7].segs=440;//diagonal

  int cont=0;//esse  cara conta o tempo para ir de um vértice a outro
  while(wb_robot_step(TIME_STEP)!= -1){

      wb_motor_set_velocity(wheel1,p[ind].w1);
      wb_motor_set_velocity(wheel2,p[ind].w2);
      wb_motor_set_velocity(wheel3,p[ind].w3);
      wb_motor_set_velocity(wheel4,p[ind].w4);
     cont++;
      if(p[ind].segs==cont) {
        cont=0;
        ind++;
       }
  }
  wb_robot_cleanup();

  return 0;
}

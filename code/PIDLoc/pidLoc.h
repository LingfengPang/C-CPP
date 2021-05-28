#ifndef PIDLOC_H
#define PIDLOC_H
struct PidLoc
{
    /* data */
    float target_val; //目标值
    float actual_val; //实际值
    float err; //定义偏差值
    float err_last; //定义上一个偏差值
    float Kp,Ki,Kd; //定义比例、积分、微分系数
    float integral; //定义积分值
};
typedef struct PidLoc pidLoc;
void PID_param_init(pidLoc* pid);//pid参数初始化
float PID_realize(float temp_val);//pid算法实现
#endif
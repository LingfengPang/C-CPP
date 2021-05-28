#ifndef PIDLOC_H
#define PIDLOC_H
struct PidAdd
{
    /* data */
    float target_val; //目标值
    float actual_val; //实际值
    float err; //定义当前偏差值
    float err_next; //定义下一个偏差值
    float err_last; //定义最后一个偏差值
    float Kp, Ki, Kd; //定义比例、积分、微分系数
};
typedef struct PidAdd pidadd;
void PID_param_init(pidadd* pid);//pid参数初始化
float PID_realize(float temp_val);//pid算法实现
#endif
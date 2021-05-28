#include <iostream>
#include "pidAdd.h"
struct PidAdd pid;
void PID_param_init(pidadd* pid){
    pid->target_val=0.0;
    pid->actual_val=0.0;
    pid->err=0.0;
    pid->err_last=0.0;
    pid->err_next = 0.0;
    pid->Kp = 0.21;
    pid->Ki = 0.8;
    pid->Kd = 0.01;
}

float PID_realize(float temp_val){
    /* 计算目标值与实际值的误差 */
    pid.err=pid.target_val-temp_val;
    /*PID 算法实现 */
    float increment_val = pid.Kp*(pid.err - pid.err_next) + pid.Ki*pid.err+pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);
    /* 累加 */
    pid.actual_val += increment_val;
    /* 传递误差 */
    pid.err_last = pid.err_next;
    pid.err_next = pid.err;
    /* 返回当前实际值 */
    return pid.actual_val;
}
int main(){
    PID_param_init(&pid);
    pid.target_val = 200;
    while(1){
        static int num=0;
        static int run_i=0;
        float val=PID_realize(pid.actual_val);
        std::cout << val << std::endl;
        if(val >= 199)
            break;
        }
    system("pause");   
    return 0;
}
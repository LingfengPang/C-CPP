#include <iostream>
#include "pidLoc.h"
pidLoc pid;
void PID_param_init(pidLoc* pid){
    pid->target_val=0.0;
    pid->actual_val=0.0;
    pid->err=0.0;
    pid->err_last=0.0;
    pid->integral=0.0;
    pid->Kp = 0.31;
    pid->Ki = 0.1;
    pid->Kd = 0.0;
}

float PID_realize(float temp_val){
    /* 计算目标值与实际值的误差 */
    pid.err=pid.target_val-temp_val;
    /* 误差累积 */
    pid.integral+=pid.err;
    /*PID 算法实现 */
    pid.actual_val=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);
    /* 误差传递 */
    pid.err_last=pid.err;
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
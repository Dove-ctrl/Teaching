#pragma once

class PID{
private:
    double P , I , D;
    double kp , ki , kd;
    double target , error_tol;
    double I_Max , D_Tol;
    double output;
    bool arrived;
    bool feed_forward_gain_activate;
    int arrived_times;
    int current_times;
    double feed_forward_gain;

public:
    PID(){
        P = 0;
        I = 0;
        D = 0;
        kp = 0;
        ki = 0;
        kd = 0;
        target = 0;
        error_tol = 0;
        I_Max = 0;
        D_Tol = 0;
        output = 0;
        arrived = false;
        arrived_times = 0;
        current_times = 0;
        feed_forward_gain = 0;
        feed_forward_gain_activate = false;
    };
    
    void reset(){
        output = 0;
        arrived = false;
        current_times = 0;
        I = 0;
    };
    
    void set_coefficient(double _kp , double _ki , double _kd){
        kp = _kp;
        ki = _ki;
        kd = _kd;
    }
    
    void set_feed_forward(double _ff){feed_forward_gain = _ff;}
    void set_arrived_times(double _arrived_times){arrived_times = _arrived_times;}
    void set_error_tol(double _error_tol){error_tol = _error_tol;}
    void set_target(double _target){target = _target;}
    void set_feed_forward_gain_activate(bool _bff){feed_forward_gain_activate = _bff;}
    bool is_arrived(){return arrived;}
    double get_output(){return output;}
    double get_target(){return target;}
    void set_I_Max(double _I_Max){I_Max = _I_Max;};
    void set_D_Tol(double _D_Tol){D_Tol = _D_Tol;};
    
    void update(double input){
        double error = 0.0;
        double pre_error = 0.0;

        error = target - input;
    
        if( error <= error_tol && -error <= error_tol ){
            if( current_times == arrived_times ){
                arrived = true;
            }
            current_times++;
        }
        
        P = error;
    
        I += error;
        if(I >= I_Max){
            I = I_Max;
        }
    
        D = error - pre_error;
        if(D < D_Tol && -D < D_Tol){
            D = 0;
        }
    
        pre_error = error;
    
        double ff_output = feed_forward_gain * error * feed_forward_gain_activate;
        
        output = ff_output + (P * kp) + (I * ki) + (D * kd);
    }
};
#include "pid_controller.hpp"

using namespace VMOS;

PIDController::PIDController(){
    _settings = {
        0.5,
        0,
        0,
        0,
        0.1
    };

    _setpoint = 0;
}

PIDController::PIDController(PIDSettings settings){
    _settings = settings;
    _setpoint = 0;
}

PIDSettings PIDController::getSettings(){
    return _settings;
}

void PIDController::setSettings(PIDSettings settings){
    _settings = settings;
}

void PIDController::setSetpoint(double setpoint){
    _setpoint = setpoint;
}




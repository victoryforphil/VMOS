#ifndef _PID_CONTROLLER_H
#define _PID_CONTROLLER_H

/*
----------------------------------
VMOS/Core - PID Controller (pid_controller.hpp - _PID_CONTROLLER_H)
Alex Carter @ 6:40PM 5/21/2019
----------------------------------
A Generic Class representring a simple PIDF controller for using throughout robotic applications.
It defines a simple PID Settings struct to store P,I,D,F values. In addition it provides a class
to run a standalone PIDF controller, with manual control over update rate (TICK) and when to get the result.

All multi-threading and event managment should be done outside this class.
*/


namespace VMOS
{   
    
    struct PIDSettings
    {
        double kP = 0.5;
        double kI = 0;
        double kD = 0;
        double kF = 0;
        double tolerance = 0.1;
    };
    
    class PIDController{
        private:        
            PIDSettings _settings; // Current PID settings
            double      _setpoint; // Current setpoint
            bool        _atTarget;

        public:
            /// Class Constructors
            PIDController();                     // Create a new PID Controller using default PID Settings
            PIDController(PIDSettings settings); // Create a new PID Controller using defined PID Settings
            
            // Data Managment
            PIDSettings getSettings();                      // Get current PID Settings
            void        setSettings(PIDSettings settings);  // Update PID Settings
            
            // Controller Functions
            void   setSetpoint(double setpoint);      // Set the current target for the sensor value
            double getResult();        // Get the result of the last cycle 
            void   tick(double input); // Run a cycle of the PID Controller using a sensor input
    };
} // VMOS

#endif
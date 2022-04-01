#pragma once
#include <ctre/Phoenix.h>
#include "constants.h"
#include <rev/CANSparkMax.h>
#include <frc/drive/DifferentialDrive.h>


using namespace motors;
using namespace drive;

class Drive {
private:
    rev::CANSparkMax m_leadRight{kRightLeadDriveMotorID, rev::CANSparkMax::MotorType::kBrushed};
    rev::CANSparkMax m_followRight{kRightFollowDriveMotorID, rev::CANSparkMax::MotorType::kBrushed};
    rev::CANSparkMax m_leadLeft{kLeftLeadDriveMotorID, rev::CANSparkMax::MotorType::kBrushed};
    rev::CANSparkMax m_followLeft{kLeftFollowDriveMotorID, rev::CANSparkMax::MotorType::kBrushed};

public:

    double currentLeftPower;  //left drive power for acceleration curve
    double currentRightPower; //right drive power for acceleration curve

    //frc::DifferentialDrive m_drive{m_leadLeft, m_leadRight};

    void RobotInit(){
    m_leadLeft.RestoreFactoryDefaults();
    m_leadLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_leadLeft.SetSmartCurrentLimit(kCurrentLimit);
    m_leadLeft.SetInverted(kLeftInverted);
    m_followLeft.RestoreFactoryDefaults();
    m_followLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_followLeft.SetSmartCurrentLimit(kCurrentLimit);
    m_followLeft.Follow(m_leadLeft, true);

    m_leadRight.RestoreFactoryDefaults();
    m_leadRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_leadRight.SetSmartCurrentLimit(kCurrentLimit);
    m_leadRight.SetInverted(kRightInverted);
    m_followRight.RestoreFactoryDefaults();
    m_followRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_followRight.SetSmartCurrentLimit(kCurrentLimit);
    m_followRight.Follow(m_leadLeft, true);
    }

    void arrowDriveAccel(double goSpeed, double turnSpeed, double reduction) {
        goSpeed = goSpeed * goSpeed * goSpeed; //cubic curve added to make it easier to move at lower speeds
        double sign = 1;
        if(goSpeed < 0) {
            sign = -1;
        }
        double leftPower = goSpeed;
        double rightPower = goSpeed;
        if(turnSpeed * sign > 0) {
          leftPower -= sign * (2 * kSpinRate) * std::abs(turnSpeed);
        }
        else {
          rightPower -= sign * (2 * kSpinRate) * std::abs(turnSpeed);
        }
        leftPower *= std::abs(goSpeed);
        rightPower *= std::abs(goSpeed);
        leftPower += (1 - std::abs(goSpeed)) * (goSpeed * (1 - kSpinRate) - turnSpeed * kSpinRate);
        rightPower += (1 - std::abs(goSpeed)) * (goSpeed * (1 -kSpinRate) + turnSpeed * kSpinRate);
        if(std::abs(currentLeftPower - leftPower) < kAccelRate) {
            currentLeftPower = leftPower;//set current power to algorithm power to increase precision, prevent oscillation
        }
        else {
          currentLeftPower += kAccelRate * compareDoubles(currentLeftPower, leftPower);//add or remove a constant amount of speed each cycle till we reach correct speed
        }
        if(std::abs(currentRightPower - rightPower) < kAccelRate) {
            currentRightPower = rightPower;
        }
        else {
          currentRightPower += kAccelRate * compareDoubles(currentRightPower, rightPower);
        }
        m_leadLeft.Set(currentLeftPower * reduction);
        //std::cout << currentLeftPower << std::endl;
        m_leadRight.Set(currentRightPower * reduction);
        //std::cout << currentRightPower << std::endl;
    }

    int compareDoubles(double a, double b) { 
        if(a - b == 0) return 0;
        else return (std::signbit(a - b)) ? (1.0) : (-1.0);
    }
};

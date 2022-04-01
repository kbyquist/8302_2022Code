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
    frc::DifferentialDrive m_drive{m_leadLeft, m_leadRight};

    void RobotInit(){
    m_leadLeft.RestoreFactoryDefaults();
    m_leadLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_leadLeft.SetInverted(kLeftInverted);
    m_followLeft.RestoreFactoryDefaults();
    m_followLeft.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_followLeft.SetSmartCurrentLimit(kCurrentLimit);
    m_followLeft.SetInverted(kLeftInverted);
    m_followLeft.Follow(m_leadLeft);
    //m_leadLeft.SetOpenLoopRampRate(.4);

    m_leadRight.RestoreFactoryDefaults();
    m_leadRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_leadRight.SetSmartCurrentLimit(kCurrentLimit);
    m_leadRight.SetInverted(kRightInverted);
    m_followRight.RestoreFactoryDefaults();
    m_followRight.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    m_followRight.SetSmartCurrentLimit(kCurrentLimit);
    m_followRight.SetInverted(kRightInverted);
    m_followRight.Follow(m_leadRight);
    //m_leadRight.SetOpenLoopRampRate(.4);
    }

};

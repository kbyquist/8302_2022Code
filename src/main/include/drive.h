#pragma once
#include <ctre/Phoenix.h>
#include "constants.h"


using namespace motors;

class Drive {
private:
    VictorSPX m_leadRight{kRightLeadDriveMotorID};
    VictorSPX m_followRight{kRightFollowDriveMotorID};
    VictorSPX m_leadLeft{kLeftLeadDriveMotorID};
    VictorSPX m_followLeft{kLeftFollowDriveMotorID};

public:

    void RobotInit(){
        m_followRight.Follow(m_leadRight, FollowerType::FollowerType_PercentOutput);
        m_followRight.SetNeutralMode(NeutralMode::Coast);
        m_followLeft.Follow(m_leadLeft, FollowerType::FollowerType_PercentOutput);
        m_followLeft.SetNeutralMode(NeutralMode::Coast);
        m_followRight.SetInverted(false);
        m_followLeft.SetInverted(true);

    }

    void tankdrive(double left, double right){
        m_leadRight.Set(ControlMode::PercentOutput, right);
        m_leadLeft.Set(ControlMode::PercentOutput, left);
    }
};

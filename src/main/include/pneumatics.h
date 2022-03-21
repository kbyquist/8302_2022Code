#pragma once
#include "constants.h"
#include <frc/DoubleSolenoid.h>

using namespace pneumatics;

class Pneumatics {
    private:

    frc::DoubleSolenoid p_CargoDoor{kPCMID, frc::PneumaticsModuleType::CTREPCM, kDoorInID, kDoorOutID};
    frc::DoubleSolenoid p_Stabilizer{kPCMID, frc::PneumaticsModuleType::CTREPCM, kStabilizerInID, kStabilizerOutID};

    public:

    void RobotInit() {
        CargoDoorUp();
        StabilizerRetract();
    }
    
    void CargoDoorDown() {
        p_CargoDoor.Set(kDoorDown);
    }

    void CargoDoorUp() {
        p_CargoDoor.Set(kDoorUp);
    }

    void StabilizerDeploy() {
        p_Stabilizer.Set(kStabilize);
    }

    void StabilizerRetract() {
        p_Stabilizer.Set(kRetractStabilize);
    }

};

#include "MoveComponent.h"

class InputComponent: public MoveComponent {
    public:
        InputComponent(class Actor* owner);
        void ProcessInput(const uint8_t* keyState) override;

        void SetForwardKey(int key) { mForwardKey = key; }
        void SetBackKey(int key) { mBackKey = key; }
        void SetClockwiseKey(int key) { mClockwiseKey = key; }
        void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }
        void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
        void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }

        float GetMaxForwardSpeed() { return mMaxForwardSpeed; }

    private:
        float mMaxForwardSpeed;
        float mMaxAngularSpeed;
        int mForwardKey;
        int mBackKey;
        int mClockwiseKey;
        int mCounterClockwiseKey;
};

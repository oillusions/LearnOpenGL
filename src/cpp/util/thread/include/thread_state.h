#pragma once

enum ThreadState {
    ThreadState_Ready = 0,
    ThreadState_Working,
    ThreadState_Waiting,
    ThreadState_End
};
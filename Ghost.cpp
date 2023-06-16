#include "Ghost.h"



Ghost::Ghost(int x, int y, int size) : MovingEntity()
{
    houseMode = new HouseModeState(this);
    currentState = houseMode;
    chaseMode = new ChaseModeState(this);
    scatterMode = new ScatterModeState(this);
    frightenedMode = new FrightenedModeState(this);
    eatenMode = new EatenModeState(this);
    isChasing = true;
}

Ghost::~Ghost()
{
    delete currentState;
    delete houseMode;
    delete chaseMode;
    delete scatterMode;
    delete frightenedMode;
    delete eatenMode;
    isChasing = true;
}

void HouseModeState::outsideHouse()  {
    bool ischasing = ghost->is_Chasing();
    if (ischasing == 0)
        ghost->setState(ghost->getScatterMode());
    else
        ghost->setState(ghost->getChaseMode());
}

void ChaseModeState::superPacGumEaten() {
    ghost->setState(ghost->getFrightenedMode());
}

void ChaseModeState::timerModeOver() {
    ghost->setState(ghost->getScatterMode());
}

void ScatterModeState::superPacGumEaten() {
    ghost->setState(ghost->getFrightenedMode());
}

void ScatterModeState::timerModeOver() {
    ghost->setState(ghost->getChaseMode());
}

void FrightenedModeState::timerFrightenedMode() {
    bool ischasing = ghost->is_Chasing();
    if (ischasing == 0)
        ghost->setState(ghost->getScatterMode());
    else
        ghost->setState(ghost->getChaseMode());
}

void FrightenedModeState::eaten() {
    ghost->setState(ghost->getEatenMode());
}

void EatenModeState::insideHouse()  {
ghost->setState(ghost->getHouseMode());
}
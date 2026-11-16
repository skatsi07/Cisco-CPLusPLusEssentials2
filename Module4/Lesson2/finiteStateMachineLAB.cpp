#include <iostream>
#include <stdexcept>

using namespace std;

class StateMachine {
public:
    enum State {
        Start = 1,
        State1,
        State2,
        State3,
        State4,
        Stop
    };

    StateMachine();
    void transition(int input);
    void printState();
    StateMachine& operator<<(int input);
    void printHistory();

private:
    State currentState;
    int statesCount = 0;
    int history[100];
};

StateMachine::StateMachine() {
    currentState = Start;
    history[statesCount] = currentState;
    statesCount++;
}

void StateMachine::transition(int input) {
    if (input < 0) {
        throw runtime_error("Invalid input");
    }

    if (currentState == Stop) {
        return;
    }

    if (input < 5) {
        currentState = Start;
        history[statesCount] = currentState;
        statesCount++;
    } else {
        currentState = State(currentState + 1);
        history[statesCount] = currentState;
        statesCount++;
    }
}

StateMachine& StateMachine::operator<<(int input) {
    transition(input);
    return *this;
}

void StateMachine::printState() {
    cout << currentState << endl;
}

void StateMachine::printHistory() {
    cout << "History: " << endl;
    for (int i = 0; i < statesCount; i++) {
        cout << history[i] << " ";
    }
    cout << endl;
}

int main() {
    StateMachine fsm;
    fsm.printState();

    fsm << 3;
    fsm.printState();

    fsm << 6;
    fsm.printState();

    fsm << 6;
    fsm.printState();

    fsm << 4;
    fsm.printState();

    fsm.printHistory();

    return 0;
}
//
//  StateMachine.h
//  DoodleDrop2DX
//
//  Created by 林光海 on 13-11-23.
//
//

#ifndef DoodleDrop2DX_StateMachine_h
#define DoodleDrop2DX_StateMachine_h

#include <iostream>
#include <cassert>
#include <string>
#include "State.h"
using namespace std;

template<class entity_type>
class StateMachine
{
public:
    StateMachine(entity_type *owner):_owner(owner),
                                    _currentState(NULL),
                                    _previousState(NULL),
                                    _globalState(NULL)
    {}
    
    void SetCurrentState(State<entity_type>* state)
    {
        _currentState = state;
    }
    
    void SetGlobalState(State<entity_type>* state)
    {
        _globalState = state;
    }
    
    void SetPreviousState(State<entity_type>* state)
    {
        _previousState = state;
    }
    
    void Update() const
    {
        if(_globalState) _globalState->Execute(_owner);
        if(_currentState) _currentState->Execute(_owner);
    }
    
    bool HandleMessage(const Telegram& msg) const
    {
        if(_currentState && _currentState->OnMessage(_owner, msg))
        {
            return true;
        }
        
        if(_globalState && _globalState->OnMessage(_owner, msg))
        {
            return true;
        }
        
        return false;
    }

    
    void ChangeState(State<entity_type>* pNewState)
    {
        assert(pNewState && "<StateMachine::ChangeState>: trying to change to NULL state");
        _previousState = _currentState;
        _currentState->Exit(_owner);
        _currentState = pNewState;
        _currentState->Enter(_owner);
    }
    
    void RevertToPreviousState()
    {
        ChangeState(_previousState);
    }
    
    bool isInState(const State<entity_type>& st) const
    {
        return typeid(*_currentState) == typeid(st);
    }
    
    State<entity_type>* CurrentState() const
    {
        return _currentState;
    }
    
    State<entity_type>* GlobalState() const
    {
        return _globalState;
    }
    
    State<entity_type>* PreviousState() const
    {
        return _previousState;
    }
    
protected:
    entity_type *_owner;
    
    State<entity_type>* _currentState;
    
    State<entity_type>* _previousState;
    
    State<entity_type>* _globalState;
};


#endif

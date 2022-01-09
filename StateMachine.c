#include <statemachine.h>




void StateMachine_Init( StateMachine_t* mFsm,  StateMachineConfig_t* mConfig, uint8_t mInitState)
{
	mFsm->Config = mConfig;
	mFsm->Actual.CurrentState = mInitState;
	mFsm->Actual.ResultCode = 0;
	mFsm->Actual.InitState = mInitState;
	mFsm->Run = &StateMachine_Run;
}

void StateMachine_Run( StateMachine_t* mFsm )
{	
	switch ( mFsm->Actual.CurrentStatePoint )
	{
		case ENTRY:
		if( mFsm->Config[mFsm->Actual.CurrentState].EntryFunction != NULL )
			{
				mFsm->Config[mFsm->Actual.CurrentState].EntryFunction( NULL );
				mFsm->Actual.CurrentStatePoint = RUN;
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = RUN;
			}
		break;
		
		case RUN:
			if( mFsm->Config[mFsm->Actual.CurrentState].RunFunction != NULL )
			{
				mFsm->Actual.ResultCode = mFsm->Config[mFsm->Actual.CurrentState].RunFunction( NULL );
				
				if( mFsm->Actual.CurrentState != mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState )
				{
					mFsm->Actual.CurrentStatePoint = EXIT;
				}
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = EXIT;
			}
		break;
		
		case EXIT:
			if( mFsm->Config[mFsm->Actual.CurrentState].ExitFunction != NULL )
			{
				mFsm->Config[mFsm->Actual.CurrentState].ExitFunction( NULL );
				
				mFsm->Actual.CurrentStatePoint = ENTRY;
				mFsm->Actual.CurrentState = mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState;
				
				mFsm->Actual.ResultCode = 0;
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = ENTRY;
				
				if( mFsm->Config[mFsm->Actual.CurrentState].RunFunction == NULL )
				{
					mFsm->Actual.CurrentState = mFsm->Actual.InitState; // Si hemos llegado aqui desde la funcion run null
					mFsm->Actual.ResultCode = 0;
				}
				else
				{
					mFsm->Actual.CurrentState = mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState;
					mFsm->Actual.ResultCode = 0;
				}
			}
		break;
	}
}

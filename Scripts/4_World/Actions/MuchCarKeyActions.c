#ifdef MuchCarKey
modded class ActionPickLockOnCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetObject());
		if(!carScript) carScript = CarScript.Cast(action_data.m_Target.GetParent());
        if(!carScript) return;
        if (!carScript.m_IsCKLocked && !carScript.m_HasCKAssigned) {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "has successful picked");
        } else {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "has failed to pick");
        }
    }
}

modded class ActionLockCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "locked");
    }
}

modded class ActionUnlockCar: ActionLockUnlockCar {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "unlocked");
    }
}
#endif
#ifdef TRADER
modded class ActionUnlockVehicle: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "unlocked");
    }
}

modded class ActionUnlockVehicleInside: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "unlocked from inside");
    }
}
modded class ActionLockVehicle: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "locked");
    }
}

modded class ActionLockVehicleInside: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "locked from inside");
    }
}
#endif
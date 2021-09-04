#ifdef CARCOVER
modded class ActionAddCarCover: ActionCoverUncoverCar {
    override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_MainItem) return;
		CarScript CarObject = CarScript.Cast(action_data.m_Target.GetObject());
		if (!CarObject) CarObject = CarScript.Cast(action_data.m_Target.GetParent());
		EntityAI CarEntity;
		Class.CastTo(CarEntity, CarObject);
        if (!CarEntity) return;
        SendToCFTools(action_data.m_Player, "hands", CarEntity.GetType(), "added a car cover to");
    }
}

modded class ActionRemoveCarCover : ActionCoverUncoverCar {
    override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);
        
		if (!action_data.m_Player || !action_data.m_Target) return;
        CarCoverBase CarCovered;
        EntityAI CarEntity = EntityAI.Cast(action_data.m_Target.GetObject());
		Class.CastTo(CarCovered, CarEntity);
        SendToCFTools(action_data.m_Player, "hands", CarCovered.GetCarClass(), "removed a car cover from");
    }
}
#endif
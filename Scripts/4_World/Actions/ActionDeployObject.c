/**
 * This is here because adding ActionDeployObject to
 * monitored aactions doesn't seem to work
 */

modded class ActionDeployObject: ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_MainItem) return;
        SendToCFTools(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "delpoyed");
    }
}

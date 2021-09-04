/**
 * This is here because adding ActionPin to
 * monitored aactions doesn't seem to work
 */

modded class ActionPin: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);

        SendToCFTools(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "pinned");
	}
}

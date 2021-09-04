#ifdef CodeLock
modded class ActionAttachCodeLockToFence: ActionSingleUseBase {
    override void OnExecuteServer(ActionData action_data) {
        super.OnExecuteServer(action_data);

        if (!action_data.m_Player || !action_data.m_MainItem) return;
        SendToCFTools(action_data.m_Player, "fence", action_data.m_MainItem.GetType(), "attached");
    }
}

modded class ActionAttachCodeLockToTent: ActionSingleUseBase {
    override void OnExecuteServer(ActionData action_data) {
        super.OnExecuteServer(action_data);

        if (!action_data.m_Player || !action_data.m_MainItem) return;
        SendToCFTools(action_data.m_Player, "tent", action_data.m_MainItem.GetType(), "attached");
    }
}

modded class ActionDestroyCodeLockOnFence: ActionContinuousBase {
    override void OnFinishProgressServer(ActionData action_data) {
        if (!action_data.m_Player || !action_data.m_MainItem || !action_data.m_Target) return;
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        CodeLock codelock = fence.GetCodeLock();
        if (!codelock) {
            super.OnFinishProgressServer(action_data);
            return;
        }
        float CodeLockHealthStart = codelock.GetHealth();

        super.OnFinishProgressServer(action_data);

        float CodeLockHealth = codelock.GetHealth();
        float CodeLockHealthDiff = CodeLockHealthStart - CodeLockHealth;
        if (CodeLockHealth > 0) {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), fence.GetType() + " (" + CodeLockHealth + "/" + codelock.GetMaxHealth() + ")", "did " + CodeLockHealthDiff + " damage to");
        } else {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), fence.GetType(), "destroyed");
        }
    }
}

modded class ActionDestroyCodeLockOnTent: ActionContinuousBase {
    override void OnFinishProgressServer(ActionData action_data) {
        if (!action_data.m_Player || !action_data.m_MainItem || !action_data.m_Target) return;
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        CodeLock codelock = tent.GetCodeLock();
        if (!codelock) {
            super.OnFinishProgressServer(action_data);
            return;
        }
        float CodeLockHealthStart = codelock.GetHealth();

        super.OnFinishProgressServer(action_data);
        
        float CodeLockHealth = codelock.GetHealth();
        float CodeLockHealthDiff = CodeLockHealthStart - CodeLockHealth;
        if (CodeLockHealth > 0) {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), tent.GetType() + " (" + CodeLockHealth + "/" + codelock.GetMaxHealth() + ")", "did " + CodeLockHealthDiff + " damage to");
        } else {
            SendToCFTools(action_data.m_Player, action_data.m_MainItem.GetType(), tent.GetType(), "destroyed");
        }
    }
}
#endif
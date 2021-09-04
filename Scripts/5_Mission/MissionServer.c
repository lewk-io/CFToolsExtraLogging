modded class MissionServer {
    override void OnInit() {
		super.OnInit();

        if (GetGameLabs().IsServer()) {
            // Log locking doors with lockpick
            GetGameLabs().AddMonitoredAction("ActionLockDoors");
            // Log unlocking doors with lockpick
            GetGameLabs().AddMonitoredAction("ActionUnlockDoors");
        }
    }

#ifdef TRADER
    override void OnUpdate(float timeslice) {
        /**
         * OnUpdate() is ugly but it's how Dr's Trader works
         */
        super.OnUpdate(timeslice);

		m_Trader_StatUpdateTime += timeslice;
		if (m_Trader_StatUpdateTime >= m_Trader_StatUpdateTimeMax) {
			m_Trader_StatUpdateTime = 0;

			for (int j = 0; j < m_Players.Count(); j++) {
                PlayerBase player = PlayerBase.Cast(m_Players.Get(j));
				
				if (!player) continue;

                bool isInSafezone = false;

                for (int k = 0; k < m_Trader_TraderPositions.Count(); k++) {
					if (vector.Distance(player.GetPosition(), m_Trader_TraderPositions.Get(k)) <= m_Trader_TraderSafezones.Get(k)) isInSafezone = true;
				}

				if (player.m_Trader_IsInSafezone == false && isInSafezone == true) {
                    SendToCFTools(player, "", "", "entered a safezone (god mode enabled)");
                }

                if (player.m_Trader_IsInSafezone == true && isInSafezone == false && player.m_Trader_IsInSafezoneTimeout == 29) {
                    SendToCFTools(player, "", "", "leaving a safezone (god mode enabled)");
                }

                if (player.m_Trader_IsInSafezone == true && isInSafezone == false && player.m_Trader_IsInSafezoneTimeout == 1) {
                    SendToCFTools(player, "", "", "left a safezone (god mode disabled)");
                }

                if (isInSafezone && player.m_Trader_IsInSafezoneTimeout < m_Trader_SafezoneTimeout) {
                    SendToCFTools(player, "", "", "re-entered a safezone (god mode enabled)");
                }
            }
        }
    }
#endif

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);

        SendToCFTools(player, "", "", "has connected");
	}

	override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed) {
        SendToCFTools(player, "", "", "is disconnecting");

        super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
    }

	override void InvokeOnDisconnect(PlayerBase player) {
        SendToCFTools(player, "", "", "has disconnected");

		super.InvokeOnDisconnect(player);
	}
}
static void SendToCFTools(PlayerBase player, string item, string target, string action) {
    if (GetGameLabs().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        action = action + " ";
        ref _Payload_ItemInteract payload = new _Payload_ItemInteract(logObjectPlayer, item, target, action);
        GetGameLabs().GetApi().ItemInteract(new _Callback(), payload);
    }
}
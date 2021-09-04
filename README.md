# CFTools Extra Logging
A server side mod to enable some extra logging in CFTools.
Currently all additional logs use CFTools' interaction api, this means all extra logs will appear as "base building".

## Logged functions:

### Vanilla
Action | Function | Description
-|-|-
'has connected' | `MissionServer InvokeOnConnect()` | Logs when a player has finished connecting. CFTools' default log will be when a player initiates joining (so they're in the loading screen). This log fires when the player has finished loading.
'is disconnecting' | `MissionServer OnClientDisconnectedEvent()` | Logs when a player starts disconnecting (if they press escape > exit). If the player presses ALT+F4, then this message will appear followed by a 'left' message.
'has disconnected' | `MissionServer InvokeOnDisconnect()` | Logs when a player has waited through the log out time and disconected. If a player presses alt+f4 after they have started disconnecting, you will not see this log. Note: This log will be when the player has disconnected from the server, CFTools's default "left" message will occur when their character has been despawned.
'ActionDeployObject' | `ActionDeployObject OnFinishProgressServer()` |Logs whenever the `ActionDeployObject` function is used (ie. Expansion Satchels).
'ActionPin' | `ActionPin OnStartServer()` | Logs whenever the `ActionPin` function is used (ie: a grenade is pinned).
'ActionUnpin' | `ActionUnpin OnStartServer()` | Logs whenever the `ActionUnpin` function is used (ie. a grenade is unpinned).
'ActionLockDoors' | `GetGameLabs().AddMonitoredAction("ActionLockDoors");` | Logs whenever the `ActionLockDoors` function is used (ie. locking a door with a lockpick).
'ActionUnlockDoors' | `GetGameLabs().AddMonitoredAction("ActionUnlockDoors");` | Logs whenever the `ActionUnlockDoors` function is used (ie. unlocking a door with a lockpick).

### CarCover
Action | Function | Description
-|-|-
'ActionAddCarCover' | `ActionAddCarCover OnFinishProgressServer()` | Logs when a player covers a vehicle.
'ActionRemoveCarCover' | `ActionRemoveCarCover OnFinishProgressServer()` | Logs when a player uncovers a vehicle.+

### CodeLock
Action | Function | Description
-|-|-
'ActionAttachCodeLockToFence' | `ActionAttachCodeLockToFence` | Logs when a player attaches a codelock to a fence.
'ActionAttachCodeLockToTent' | `ActionAttachCodeLockToTent` | Logs when a player attaches a codelock to a tent.
'ActionDestroyCodeLockOnFence' | `ActionDestroyCodeLockOnFence` | Logs when a player damages a codelock on a fence.
'ActionDestroyCodeLockOnTent' | `ActionDestroyCodeLockOnTent` | Logs when a player damages a codelock on a tent.

### Dr_J0nes's Trader
Action | Function | Description
-|-|-
'entered a safezone' | `MissionServer OnUpdate()` | Logs when a player enters a safezone (and godmode is enabled).
'leaving a safezone' | `MissionServer OnUpdate()` | Logs when a player has gone outside of the safezone but is still in 'cooldown'.
're-entered a safezone' | `MissionServer OnUpdate()` | Logs when a player has gone outside of the safezone but is still in 'cooldown' and then goes back into the safezone.
'left a safezone' | `MissionServer OnUpdate()` | Logs when a player has left a safezone and is out of cooldown (when godmode is disabled).
'[vehicle] unlocked' | `ActionUnlockVehicle` | Logs when a vehicle is unlocked.
'[vehicle] unlocked from inside' | `ActionUnlockVehicleInside` | Logs when a vehicle is unlocked from inside.
'[vehicle] locked' | `ActionLockVehicle` | Logs when a vehicle is locked.
'[vehicle] locked from inside' | `ActionLockVehicleInside` | Logs when a vehicle is locked from inside.

### MuchCarKey
Action | Function | Description
-|-|-
'successfully picked' | `ActionPickLockOnCar` | Logs when a player successfully picks the lock on a vehicle.
'failed to pick' | `ActionPickLockOnCar` | Logs when a player fails to pick the lock on a vehicle.
'unlocked' | `ActionUnlockCar` | Logs when a player unlocks a vehicle.
'locked' | `ActionLockCar` | Logs when a player locks a vehicle.


## Terms
> Repacking is allowed but be warned; you will not get any updates without coming here to find them.
> (Repacking is allowed so that you can remove anything you don't need).
> You may use this on your monetized server.

https://github.com/lewk-io/CFToolsExtraLogging
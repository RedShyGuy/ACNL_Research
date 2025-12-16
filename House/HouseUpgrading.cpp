void SetTentState(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 0;
		town->PlayerHouse[playerIndex].exterior2.HouseStyle = 0;
		town->PlayerHouse[playerIndex].exterior2.HouseDoorShape = 0;
		town->PlayerHouse[playerIndex].exterior2.HouseBrick = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseRoof = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseDoor = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseFence = 0;
		town->PlayerHouse[playerIndex].exterior2.HousePavement = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseMailBox = 0xB;

		town->PlayerHouse[playerIndex].exterior1.HouseSize = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseStyle = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseDoorShape = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseBrick = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseRoof = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseDoor = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseFence = 0;
		town->PlayerHouse[playerIndex].exterior1.HousePavement = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseMailBox = 0xB;
	}

void BuildHouse(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//paying tent payment
		player->PlayerFlags.TomNookToldYouFirstPayment = 1;
		player->PlayerFlags.TomNookDownFirstPayment = 1;

		town->PlayerHouse[playerIndex].exterior2.HouseSize = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseBrick = 0;
		town->PlayerHouse[playerIndex].exterior2.HouseRoof = 0; //Red Roof = 0x00 || Blue Roof = 0x20 ||Yellow Roof = 0x21 ||Green Roof = 0x22
		town->PlayerHouse[playerIndex].exterior2.HouseDoor = 0;
		town->PlayerHouse[playerIndex].exterior2.HouseFence = 1;
		town->PlayerHouse[playerIndex].exterior2.HouseMailBox = 0;

		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 1;
	//Next day -> House was built | Needs testing, try not on the first day
		player->PlayerFlags.Unknown95 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].MiddleRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 0;

		town->PlayerHouse[playerIndex].exterior1.HouseSize = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseBrick = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseRoof = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseDoor = 0;
		town->PlayerHouse[playerIndex].exterior1.HouseFence = 1;
		town->PlayerHouse[playerIndex].exterior1.HouseMailBox = 0;
	//Gets set when you talk to tom nook after your house was built
		player->PlayerFlags.HouseUpgradeFinished = 0;
		player->PlayerFlags.Unknown95 = 0;
		
		player->PlayerFlags.Unknown140 = 1;
		player->PlayerFlags.Unknown149 = 1;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
		player->PlayerFlags.Unknown43 = 1;
		player->PlayerFlags.Unknown156 = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;
	}

void UpgradeHouseFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 2;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;
		player->PlayerFlags.Unknown149 = 0;
		player->PlayerFlags.Unknown150 = 1;
		player->PlayerFlags.Unknown157 = 1;

		town->PlayerHouse[playerIndex].exterior1.HouseSize = 2;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you enter Tom Nooks after your house was upgraded
		player->PlayerFlags.LyleIntroduction = 1;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;
	}

	void UpgradeHouseSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 3;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;
	
		town->PlayerHouse[playerIndex].exterior1.HouseSize = 3;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].MiddleRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;	
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildSecondRoom(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 4;
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].exterior1.HouseSize = 4;
		town->PlayerHouse[playerIndex].SecondRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
		player->PlayerFlags.Unknown305 = 1;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeSecondRoomFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].SecondRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeSecondRoomSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown242 = 1;
		player->PlayerFlags.Unknown246 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].SecondRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].SecondRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildBasementRoom(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown242 = 0;
		player->PlayerFlags.Unknown243 = 1;
		player->PlayerFlags.Unknown246 = 0;
		player->PlayerFlags.Unknown247 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BasementRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeBasementRoomFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown242 = 1;
		player->PlayerFlags.Unknown246 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BasementRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeBasementRoomSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown242 = 0;
		player->PlayerFlags.Unknown243 = 0;
		player->PlayerFlags.Unknown244 = 1;
		player->PlayerFlags.Unknown246 = 0;
		player->PlayerFlags.Unknown247 = 0;
		player->PlayerFlags.Unknown248 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BasementRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].BasementRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildRightRoom(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 5;
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown242 = 0;
		player->PlayerFlags.Unknown243 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;
		
		town->PlayerHouse[playerIndex].exterior1.HouseSize = 5;
		town->PlayerHouse[playerIndex].RightRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeRightRoomFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].RightRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeRightRoomSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].RightRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].RightRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildLeftRoom(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].exterior2.HouseSize = 7;
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown92 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].exterior1.HouseSize = 7;
		town->PlayerHouse[playerIndex].LeftRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeLeftRoomFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].LeftRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeLeftRoomSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].LeftRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].LeftRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildBackRoom(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BackRoom.flags.RoomSize = 2;
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeBackRoomFirst(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BackRoom.flags.RoomSize = 3;
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void UpgradeBackRoomSecond(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to expand
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.HouseUpgradeFinished = 1;

		town->PlayerHouse[playerIndex].BackRoom.flags.RoomSize = 4;
		town->PlayerHouse[playerIndex].BackRoom.flags.IsRoomUpgrading = 0;
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;
		player->PlayerFlags.Unknown117 = 1; //probably finished all debts
	//Talking to tom nook to let him know you payed your loan
		player->PlayerFlags.HouseLoanRepayed = 0;	
	}

	void BuildSecretStorage(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Tell Tom Nook you want to build secret storage
		player->PlayerFlags.Unknown319 = 1;
	//Next day -> Upgrade was made
		player->PlayerFlags.Unknown118 = 1;
		player->PlayerFlags.Unknown188 = 1;
		player->PlayerFlags.HouseUpgradeFinished = 1;
		player->PlayerFlags.UnlockedSecretStorage = 1;
	}

void AfterEverything(ACNL_Player* player, ACNL_TownData* town, int playerIndex) {
	//Unknown
		player->PlayerFlags.Unknown258 = 1;	
	//Gets set when you talk to tom nook after your house was upgraded
		player->PlayerFlags.HouseUpgradeFinished = 0;
	//Meet Lottie
		player->PlayerFlags.Unknown382 = 1;
	//finished house editor tutorial
		player->PlayerFlags.UnlockedHouseEditor = 1;

	//after repaying loan in post office
		player->PlayerFlags.HouseLoanRepayed = 1;

	//Talking to tom nook to let him know you payed your loan	
		player->PlayerFlags.HouseLoanRepayed = 0;
		player->PlayerFlags.Unknown382 = 0;
	}

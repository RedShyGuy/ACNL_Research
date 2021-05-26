#include <iostream>

uint16_t InitArr[102] = {
	0x0000, 0x0001, 0x0001, 0x0014, 0x0001, 0x2710, 0x0014, 0x0001, 0x0001, 
	0x0001, 0x0005, 0xC350, 0x0001, 0x0003, 0x0014, 0x0014, 0x000A, 0x0001, 
	0x0001, 0x0003, 0x0001, 0x0001, 0x0001, 0x0003, 0x0003, 0x000A, 0x0001, 
	0x0001, 0x0001, 0x0003, 0x0003, 0x0008, 0x0001, 0x0001, 0x1388, 0x0001, 
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0005, 
	0x0001, 0x0001, 0x0001, 0x1388, 0x0064, 0x0001, 0x0005, 0x0001, 0x0001, 
	0x0001, 0x0001, 0x0096, 0x0001, 0x01F4, 0x0001, 0x0005, 0x000A, 0x0001, 
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0003, 0x0001, 0x0001, 
	0x0001, 0x0001, 0x0005
};

/**
* \brief Gives the goal value for a Initiative
* \param Initiative The Initiative you want
* \return The goal value for the Initiative
*/
uint16_t GetInitiativesValue(int Initiative) {
	return InitArr[Initiative]; //0 is not valid
}

/**
* \brief Gives the current initiatives ID for the day
* \param InitiativeSaveOffset The Offset where the Initiative data starts
* \param InitPos The position of the Initiative (0 = 1st Init.)
* \param weekDay The current weekday (1 = Monday)
* \return The current initiatives ID
*/
uint8_t GetCurrentInitiatives(uint32_t InitiativeSaveOffset, int InitPos, int weekDay) {
	switch(InitPos) {
		default: return 0;
		case 0: return *(uint8_t *)(InitiativeSaveOffset + 0x11 + weekDay); //Daily
		case 1: return *(uint8_t *)(InitiativeSaveOffset + 0xA + weekDay); //Daily
		case 2: return *(uint8_t *)(InitiativeSaveOffset + 8); //Weekly
		case 3: return *(uint8_t *)(InitiativeSaveOffset + 9); //Weekly
	}
}

/**
* \brief If a Initiative is finished
* \param InitiativeSaveOffset The Offset where the Initiative data starts
* \param Initiative The Initiative ID
* \return True if finished | False if not finished
*/
bool InitiativeFinished(uint32_t InitiativeSaveOffset, int Initiative) {
	uint16_t iVar1 = GetInitiativesValue(Initiative);
	return iVar1 <= *(uint16_t *)(InitiativeSaveOffset + Initiative * 4 + 0x1C);
}

/**
* \brief Gets the save offset for the Initiative
* \param InitiativeSaveOffset The Offset where the Initiative data starts
* \param Initiative The Initiative ID
* \return the Initiative save offset
*/
uint32_t GetInitiativeOffset(uint32_t InitiativeSaveOffset, int Initiative) {
	return (InitiativeSaveOffset + Initiative * 4 + 0x1C);
}

/**
* \brief Lets you toggle the completion of a Initiative
* \param pPos The player you want to use (0 = Player 1)
* \param InitPos The position of the Initiative (0 = 1st Initiative in List)
* \param weekDay The current weekday (1 = Monday)
* \param finish Set true if you want to complete the Initiative, false to uncomplete it
*/
void ToggleInitiative(int pPos, int InitPos, int weekDay, bool finish) {
	uint32_t InitiativeSaveOffset = 0xA0 + (pPos * 0xA480) + 0x8AE0; //PlayerSaveOffset + 0x8AE0

	uint8_t currInit = GetCurrentInitiatives(InitiativeSaveOffset, InitPos, weekDay);

	if(!((currInit != 0) && (currInit < 0x66))) //0 is invalid Initiative | 0x65 is highest Initiative 
		return;

	if(InitiativeFinished(InitiativeSaveOffset, currInit) && !finish) {
		*(uint16_t *)GetInitiativeOffset(InitiativeSaveOffset, currInit) = 0; //Clear completion of Initiative
		return;
	}
	else if(!InitiativeFinished(InitiativeSaveOffset, currInit) && finish) {
		*(uint16_t *)GetInitiativeOffset(InitiativeSaveOffset, currInit) = GetInitiativesValue(currInit); //Complete Initiative
		return;
	}
} 
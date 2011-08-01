#ifndef __CPLAYER_POOL_H__
#define __CPLAYER_POOL_H__


class CPlayerPool
{
#pragma pack( 1 )
public:

	BOOL		isCreated[ MAX_PLAYERS ];							// + 0x0000 - 0000
	CPlayer*	player[ MAX_PLAYERS ];								// + 0x07D0	- 2000
	char		nickNames[ MAX_PLAYERS ][ MAX_PLAYER_NAME+1 ];		// + 0x0FA0 - 4000
	BOOL		isPlayerAdmin[ MAX_PLAYERS ];						// + 0x4074 - 16500
	uint32_t	playersVirtualWorlds[MAX_PLAYERS];					// + 0x4844 - 18500
	BOOL		bIsNPC[ MAX_PLAYERS ];								// + 0x5014	- 20500			// Ouais je sais IsPlayerNPC c'est un peu contradictoire comme nom, mais si vous avez mieux ... gardez le pour vous :p
	uint32_t	playersCount;										// + 0x57E4	- 22500
//	uint8_t		unk[0x8];											// + 0x57E8 - 22504
	uint32_t	unknown57E8;										// + 0x57E8 - 22504
	uint32_t	unkonwn57EC;										// + 0x57EC - 22508
	uint32_t	playersScore[ MAX_PLAYERS ];						// + 0x57F0 - 22512
	uint32_t	playersMoney[ MAX_PLAYERS ];						// + 0x5FC0 - 24512
	uint32_t	drunkLevel[ MAX_PLAYERS ];							// + 0x6790 - 26512
	char		playersSerial[ MAX_PLAYERS ][ 0x64 ];				// + 0x6F60 - 28512



	void setScore( _PlayerID playerID, uint32_t value );
	uint32_t getScore( _PlayerID playerID );

	float GetDistanceBetweenPlayers( _PlayerID player_one, _PlayerID player_two );

	int New( _PlayerID playerID, const char* nickname, char* serial, uint32_t isNPC = 0 );
	int Delete( _PlayerID playerID, uint8_t reason );


	int HidePlayerForPlayer( _PlayerID playerID, _PlayerID forPlayerID );
	int	ShowPlayerForPlayer( _PlayerID forPlayerID, _PlayerID playerID  );

	bool isNPC( _PlayerID playerID );

	uint32_t getPlayerMoney( _PlayerID playerID );
	void setPlayerMoney( _PlayerID playerID, uint32_t amount );
	void givePlayerMoney( _PlayerID playerID, uint32_t amount );
	void resetPlayerMoney( _PlayerID playerID );

	void setPlayerNick( _PlayerID playerID, char* nickname );
	char* getPlayerNick( _PlayerID playerID );
	bool isNicknameUsed( char* nick );

	bool GetSlotState( _PlayerID playerID );
	CPlayer* GetPlayer( _PlayerID playerID );

	CPlayerPool( );
	~CPlayerPool( );
private:

};

#endif
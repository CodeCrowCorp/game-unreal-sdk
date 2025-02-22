#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnkrDelegates.h"
#include "WearableNFTExample.generated.h"

/// UWearableNFTExample provide various functions to mint character, mint items, get balance and changeHat etc.
UCLASS(Blueprintable, BlueprintType)
class ANKRSDK_API UWearableNFTExample : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	FHttpModule* http;
	FString deviceId;
	FString session;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString activeAccount;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) int chainId;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString GameItemContractAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString GameItemABI;
			 
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString GameCharacterContractAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString GameCharacterABI;
			  
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString TransactionGasLimit;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString BlueHatAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString RedHatAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString WhiteHatAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString BlueShoesAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString RedShoesAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString WhiteShoesAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString BlueGlassesAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString RedGlassesAddress;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString WhiteGlassesAddress;

	void Init(FString _deviceId, FString _session);
	void SetAccount(FString _account, int _chainId);

	/// MintItems function is used to mint a batch of items to the user and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "ticket".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// @attention YOUR_ITEM_ADDRESS(s) and YOUR_ITEM_QUANTITY(s) represent each other respectively.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0xD0eF33b38D8525728902D90b20d6e2F303B8dc2C", "abi_hash":"YOUR_ABI_HASH", "method":"mintBatch", "args":["TO_WALLET_ADDRESS", ["YOUR_ITEM_ADDRESS", "YOUR_ITEM_ADDRESS", "YOUR_ITEM_ADDRESS", "YOUR_ITEM_ADDRESS", "YOUR_ITEM_ADDRESS", "YOUR_ITEM_ADDRESS"], [YOUR_ITEM_QUANTITY, YOUR_ITEM_QUANTITY, YOUR_ITEM_QUANTITY, YOUR_ITEM_QUANTITY, YOUR_ITEM_QUANTITY, YOUR_ITEM_QUANTITY], \"0x\"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void MintItems(FString abi_hash, FString to, FAnkrCallCompleteDynamicDelegate Result);

	/// MintCharacter function is used to mint a character to the user and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "ticket".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param to The address of the user to which the character should be minted.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0x7081F409F750EACD27867c988b4B3771d935Fe16", "abi_hash":"YOUR_ABI_HASH", "method":"safeMint", "args:["TO_WALLET_ADDRESS"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void MintCharacter(FString abi_hash, FString to, FAnkrCallCompleteDynamicDelegate Result);

	/// GameItemSetApproval function is used to set an approval to mint items for the user and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "ticket".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param callOperator The address of the contract that will operate the items.
	/// @param approved Whether the approval is granted or not.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0xD0eF33b38D8525728902D90b20d6e2F303B8dc2C", "abi_hash":"YOUR_ABI_HASH", "method":"setApprovalForAll", "args:["0xD0eF33b38D8525728902D90b20d6e2F303B8dc2C", true]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GameItemSetApproval(FString abi_hash, FString callOperator, bool approved, FAnkrCallCompleteDynamicDelegate Result);

	/// GetCharacterBalance function is used to get the token balance that user holds.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "data".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param address The address of the user to check the balance against.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0x7081F409F750EACD27867c988b4B3771d935Fe16", "abi_hash":"YOUR_ABI_HASH", "method":"balanceOf", "args":["WALLET_ADDRESS"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetCharacterBalance(FString abi_hash, FString address, FAnkrCallCompleteDynamicDelegate Result);

	/// GetCharacterTokenId function is used to get the id of the token at the specified index.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "ticket".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param tokenBalance The token balance obtained by GetCharacterBalance(FString, FString, FAnkrCallCompleteDynamicDelegate);
	/// @param owner The address of the owner of the token.
	/// @param index The index of the token.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0x7081F409F750EACD27867c988b4B3771d935Fe16", "abi_hash":"YOUR_ABI_HASH", "method":"tokenOfOwnerByIndex", "args":["WALLET_ADDRESS", "INDEX"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetCharacterTokenId(FString abi_hash, int tokenBalance, FString owner, FString index, FAnkrCallCompleteDynamicDelegate Result);

	/// ChangeHat function is used to change the hat of the character and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "ticket".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param characterId The character id obtained by GetCharacterTokenId(FString, int, FString, FString, FAnkrCallCompleteDynamicDelegate);
	/// @param hasHat Whether the character already has the hat or not.
	/// @param hatAddress The address of the hat to change hat to.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0x7081F409F750EACD27867c988b4B3771d935Fe16", "abi_hash":"YOUR_ABI_HASH", "method":"changeHat", "args":["TOKEN_ID", "HAT_ADDRESS"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void ChangeHat(FString abi_hash, int characterId, bool hasHat, FString hatAddress, FAnkrCallCompleteDynamicDelegate Result);

	/// GetHat function is used to get the current hat of the character and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires a parameter described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a  device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.
	/// string data will be received in json response for a "data".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param characterId The character id obtained by GetCharacterTokenId(FString, int, FString, FString, FAnkrCallCompleteDynamicDelegate);
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0x7081F409F750EACD27867c988b4B3771d935Fe16", "abi_hash":"YOUR_ABI_HASH", "method":"getHat", "args":["TOKEN_ID"]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetHat(FString abi_hash, int characterId, FAnkrCallCompleteDynamicDelegate Result);
	
	/// GetTicketResult function is used to get the result of the ticket generated by MintItems(FString, FString, FAnkrCallCompleteDynamicDelegate), MintCharacter(FString, FString, FAnkrCallCompleteDynamicDelegate),
	/// GameItemSetApproval(FString, FString, bool, FAnkrCallCompleteDynamicDelegate) or ChangeHat(FString, int, bool, FString, FAnkrCallCompleteDynamicDelegate)
	///
	/// The function requires a parameter described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a data and txHash. The format is describied in the note section below.
	/// string data will be received in json response for a "data".
	///
	/// @param ticketId The ticket generated by UpdateNFT(FString, FItemInfoStructure, FAnkrCallCompleteDynamicDelegate);
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"ticket":"YOUR_TICKET"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetTicketResult(FString ticketId, FAnkrCallCompleteDynamicDelegate Result);

	/// GetItemsBalance function is used to get the balance of items in batch.
	///
	/// The function requires a parameter described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a ticket. The format is describied in the note section below.
	/// string data will be received in json response for a "data".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param address The address of the user to check the balance of items against.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"0xD0eF33b38D8525728902D90b20d6e2F303B8dc2C", "abi_hash":"YOUR_ABI_HASH", "method":"balanceOfBatch", "args:[ ["activeAccount", " + activeAccount", "activeAccount", "activeAccount", "activeAccount", "activeAccount", "activeAccount", "activeAccount", "activeAccount"], ["BlueHatAddress", "RedHatAddress ", "WhiteHatAddress ", "BlueShoesAddress", "RedShoesAddress", "WhiteShoesAddress", "BlueGlassesAddress", "RedGlassesAddress", "WhiteGlassesAddress"]]}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetItemsBalance(FString abi_hash, FString address, FAnkrCallCompleteDynamicDelegate Result);

	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	int GetItemValueFromBalances(FString data, int index);

	/// GetTokenURI function is used to get token uri of an NFT.
	///
	/// The function requires a parameter described below and returns nothing.
	/// Inside the function, A POST request is sent to the Ankr. The request needs a json body containing a ticket. The format is describied in the note section below.
	/// string data will be received in json response for a "data".
	///
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param tokenId The id the token hold by the user.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetTokenURI(FString abi_hash, int tokenId, FAnkrCallCompleteDynamicDelegate Result);
};
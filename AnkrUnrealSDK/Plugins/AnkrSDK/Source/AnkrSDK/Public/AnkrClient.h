#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UpdateNFTExample.h"
#include "WearableNFTExample.h"
#include "AnkrDelegates.h"
#include "AdvertisementManager.h"
#include "RequestBodyStructure.h"
#include "AnkrClient.generated.h"

#define DOXYGEN_SHOULD_SKIP_THIS

/// AnkrClient provides various functions that are used to connect wallet and interact with the blockchain.
UCLASS(Blueprintable, BlueprintType)
class ANKRSDK_API UAnkrClient : public UObject
{

	GENERATED_UCLASS_BODY()

public:
//#ifndef DOXYGEN_SHOULD_SKIP_THIS
	FHttpModule* http;
	bool isDevelopment;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString deviceId;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString session;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString walletConnectDeeplink;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) bool needLogin;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) TArray<FString> accounts;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) FString activeAccount;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) int chainId;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) UUpdateNFTExample* updateNFTExample;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) UWearableNFTExample* wearableNFTExample;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) UAdvertisementManager* advertisementManager;
//#endif 

	/// Ping function is used to check if the Ankr API responds properly.
	///
	/// The function requires a parameter described below and returns nothing.
	/// Inside the function, A GET request is sent to the Ankr API.
	/// string data will be received in json response with "pong".
	///
	/// @param Result A callback delegate that will be triggered once a response is received with a data.
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void Ping(const FAnkrCallCompleteDynamicDelegate& Result);

	/// ConnectWallet function is used to connect the wallet such as metamask etc.
	///
	/// The function requires a parameter described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device id and the format is describied in the body section below.\n
	/// string data will be received in json response for "login", "session" and "uri".\n
	/// "uri" will be used to launch metamask to confirm the user to connect to the wallet. Once connected you can call GetWalletInfo(const FAnkrCallCompleteDynamicDelegate&) to get the wallet address.
	///
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	///
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void ConnectWallet(const FAnkrCallCompleteDynamicDelegate& Result);

	/// GetWalletInfo function is used to get the wallet address and chain id.
	///
	/// The function requires a parameter described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device id and the format is describied in the body section below.\n
	/// string data will be received in json response for "accounts" and "chainId".
	///
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	///
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetWalletInfo(const FAnkrCallCompleteDynamicDelegate& Result);

	/// GetActiveAccount function is used to get the connected wallet address.
	///
	/// The function doesn't require a parameter and returns a string.\n
	/// Inside the function, the activeAccount is returned.
	///
	/// @returns Returns the connected wallet address.
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	FString GetActiveAccount();

	/// SendABI function is used to get the hash of the abi string.
	///
	/// The function requires a parameter described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing an abi string and the format is describied in the body section below.\n
	/// string data will be received in json response for "abi".
	///
	/// @param abi An ABI string of a contract.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	///
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"abi":"YOUR_ABI"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void SendABI(FString abi, const FAnkrCallCompleteDynamicDelegate& Result);


	/// SendTransaction function is used to send a transaction and requires the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the body section below.\n
	/// string data will be received in json response for a "ticket".
	///
	/// @param contract The address of the contract to which you want to interact.
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param method The method that is to be called in the contract.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"YOUR_CONTRACT_ADDRESS", "abi_hash":"YOUR_ABI_HASH", "method":"YOUR_METHOD", "args:"YOUR_ARGS"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void SendTransaction(FString contract, FString abi_hash, FString method, FString args, const FAnkrCallCompleteDynamicDelegate& Result);

	/// GetTicketResult function is used to get the result of the ticket generated by SendTransaction(FString, FString, FString, FString, const FAnkrCallCompleteDynamicDelegate&).
	///
	/// The function requires a parameter described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a ticket. The format is describied in the body section below.\n
	/// string data will be received in json response for a "data".
	///
	/// @param ticketId The ticket generated by SendTransaction(FString, FString, FString, FString, const FAnkrCallCompleteDynamicDelegate&);
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"ticket":"YOUR_TICKET"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetTicketResult(FString ticketId, const FAnkrCallCompleteDynamicDelegate& Result);

	/// CallMethod function is used to get a data from blockchain and doesn't require the user confirmation through wallet such as metamask.
	///
	/// The function requires parameters described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, contract_address, abi_hash, method and args. The format is describied in the note section below.\n
	/// string data will be received in json response for a "data".
	///
	/// @param contract The address of the contract to which you want to interact.
	/// @param abi_hash The hash of the abi string of the contract.
	/// @param method The method that is to be called in the contract.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "contract_address":"YOUR_CONTRACT_ADDRESS", "abi_hash":"YOUR_ABI_HASH", "method":"YOUR_METHOD", "args:"YOUR_ARGS"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void CallMethod(FString contract, FString abi, FString method, FString args, const FAnkrCallCompleteDynamicDelegate& Result);

	/// SignMessage function is used to sign a message and requires the user confirmation to sign through wallet such as metamask..
	///
	/// The function requires parameters described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id and message. The format is describied in the note section below.\n
	/// string data will be received in json response for a "data".
	///
	/// @param device_id The address of the contract to which you want to interact.
	/// @param message The string message to be signed
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "message":"YOUR_MESSAGE"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void SignMessage(FString message, const FAnkrCallCompleteDynamicDelegate& Result);

	/// GetSignature function is used to get the signature signed by the SignMessage(FString, const FAnkrCallCompleteDynamicDelegate&) function.
	///
	/// The function requires a parameter described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a ticket. The format is describied in the note section below.\n
	/// string data will be received in json response for a "signature".
	///
	/// @param ticket The ticket received in the SignMessage(FString, const FAnkrCallCompleteDynamicDelegate&) function.
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"ticket":"YOUR_TICKET"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void GetSignature(FString ticket, const FAnkrCallCompleteDynamicDelegate& Result);

	/// VerifyMessage function is used to verify the message that was signed.
	///
	/// The function requires parameters described below and returns nothing.\n
	/// Inside the function, A POST request is sent to the Ankr API. The request needs a json body containing a device_id, message and signature. The format is describied in the note section below.\n
	/// string data will be received in json response for an "address".
	///
	/// @param device_id The address of the contract to which you want to interact.
	/// @param message The string message to be signed
	/// @param signature The signature received by GetSignature(FString, const FAnkrCallCompleteDynamicDelegate&);
	/// @param Result A callback delegate that will be triggered once a response is received with data.
	/// @attention The "message" should be the one that was used in SignMessage(FString, const FAnkrCallCompleteDynamicDelegate&).
	/// @attention The "signature" should be the one that was obtained in GetSignature(FString, const FAnkrCallCompleteDynamicDelegate&).
	/// 
	/// ### Body
	/// ~~~~~~~~~~~~~~~~~~~~~~~.cpp
	/// {"device_id":"YOUR_DEVICE_ID", "message":"YOUR_MESSAGE", "signature":"YOUR_SIGNATURE"}
	/// ~~~~~~~~~~~~~~~~~~~~~~~
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
    void VerifyMessage(FString message, FString signature, const FAnkrCallCompleteDynamicDelegate& Result);

	/// GetLastRequest function gets the name of last function that was called for the Ankr API. 
	///
	/// The function doesn't require a parameter and returns a string.\n
	/// Inside the function, the name of the last function that was called for the Ankr API is returned.
	///
	/// @returns The name of the last function that was called for Ankr API.
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	FString GetLastRequest();

	/*! SetLastRequest function sets the name of last function that is called for the Ankr API. 
	 *
	 * The function requires a parameter described below and returns nothing.\n
	 * Inside the function, the name of the last function that is called for the Ankr API is set.
	 *
	 * @param _lastRequest The name of the function that is called for the Ankr API.*/
	UFUNCTION(BlueprintCallable, Category = "ANKR SDK")
	void SetLastRequest(FString _lastRequest);
};
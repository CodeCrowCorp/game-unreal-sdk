#include "WearableNFTExample.h"
#include "UpdateNFTExample.h"
#include "ItemInfo.h"
#include "RequestBodyStructure.h"

UWearableNFTExample::UWearableNFTExample(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameItemContractAddress		 = "0xD0eF33b38D8525728902D90b20d6e2F303B8dc2C";
	//GameItemContractAddress		 = "0x26aFc7805Aa279fB0E806c2bc1e2bF37A70F995d";
	GameItemABI					 = "[{\"inputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"bool\",\"name\":\"approved\",\"type\":\"bool\"}],\"name\":\"ApprovalForAll\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"previousAdminRole\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"newAdminRole\",\"type\":\"bytes32\"}],\"name\":\"RoleAdminChanged\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"sender\",\"type\":\"address\"}],\"name\":\"RoleGranted\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"sender\",\"type\":\"address\"}],\"name\":\"RoleRevoked\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256[]\",\"name\":\"ids\",\"type\":\"uint256[]\"},{\"indexed\":false,\"internalType\":\"uint256[]\",\"name\":\"values\",\"type\":\"uint256[]\"}],\"name\":\"TransferBatch\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"value\",\"type\":\"uint256\"}],\"name\":\"TransferSingle\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"string\",\"name\":\"value\",\"type\":\"string\"},{\"indexed\":true,\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"}],\"name\":\"URI\",\"type\":\"event\"},{\"inputs\":[],\"name\":\"DEFAULT_ADMIN_ROLE\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"MINTER_ROLE\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"URI_SETTER_ROLE\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"}],\"name\":\"balanceOf\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address[]\",\"name\":\"accounts\",\"type\":\"address[]\"},{\"internalType\":\"uint256[]\",\"name\":\"ids\",\"type\":\"uint256[]\"}],\"name\":\"balanceOfBatch\",\"outputs\":[{\"internalType\":\"uint256[]\",\"name\":\"\",\"type\":\"uint256[]\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"value\",\"type\":\"uint256\"}],\"name\":\"burn\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"internalType\":\"uint256[]\",\"name\":\"ids\",\"type\":\"uint256[]\"},{\"internalType\":\"uint256[]\",\"name\":\"values\",\"type\":\"uint256[]\"}],\"name\":\"burnBatch\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"}],\"name\":\"exists\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"}],\"name\":\"getRoleAdmin\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"grantRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"hasRole\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"}],\"name\":\"isApprovedForAll\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"data\",\"type\":\"bytes\"}],\"name\":\"mint\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256[]\",\"name\":\"ids\",\"type\":\"uint256[]\"},{\"internalType\":\"uint256[]\",\"name\":\"amounts\",\"type\":\"uint256[]\"},{\"internalType\":\"bytes\",\"name\":\"data\",\"type\":\"bytes\"}],\"name\":\"mintBatch\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"renounceRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"revokeRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256[]\",\"name\":\"ids\",\"type\":\"uint256[]\"},{\"internalType\":\"uint256[]\",\"name\":\"amounts\",\"type\":\"uint256[]\"},{\"internalType\":\"bytes\",\"name\":\"data\",\"type\":\"bytes\"}],\"name\":\"safeBatchTransferFrom\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"amount\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"data\",\"type\":\"bytes\"}],\"name\":\"safeTransferFrom\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"internalType\":\"bool\",\"name\":\"approved\",\"type\":\"bool\"}],\"name\":\"setApprovalForAll\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"string\",\"name\":\"newuri\",\"type\":\"string\"}],\"name\":\"setURI\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes4\",\"name\":\"interfaceId\",\"type\":\"bytes4\"}],\"name\":\"supportsInterface\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"id\",\"type\":\"uint256\"}],\"name\":\"totalSupply\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"name\":\"uri\",\"outputs\":[{\"internalType\":\"string\",\"name\":\"\",\"type\":\"string\"}],\"stateMutability\":\"view\",\"type\":\"function\"}]";

	GameCharacterContractAddress = "0x7081F409F750EACD27867c988b4B3771d935Fe16";
	//GameCharacterContractAddress = "0x2ff8d8a0e5d8e3cf34aa490abfd8f365e1f77f0d";
	//GameCharacterContractAddress = "0x10555B832DE7bAD8459d6de1D8E8F5ad990709A0";
	GameCharacterABI			 = "[{\"inputs\":[{\"internalType\":\"address\",\"name\":\"gameItemContractAddress\",\"type\":\"address\"}],\"stateMutability\":\"nonpayable\",\"type\":\"constructor\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"approved\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"Approval\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"indexed\":false,\"internalType\":\"bool\",\"name\":\"approved\",\"type\":\"bool\"}],\"name\":\"ApprovalForAll\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"oldGlassesId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"newGlassesId\",\"type\":\"uint256\"}],\"name\":\"GlassesChanged\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"oldHatId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"newHatId\",\"type\":\"uint256\"}],\"name\":\"HatChanged\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"previousAdminRole\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"newAdminRole\",\"type\":\"bytes32\"}],\"name\":\"RoleAdminChanged\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"sender\",\"type\":\"address\"}],\"name\":\"RoleGranted\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"sender\",\"type\":\"address\"}],\"name\":\"RoleRevoked\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"oldShoesId\",\"type\":\"uint256\"},{\"indexed\":false,\"internalType\":\"uint256\",\"name\":\"newShoesId\",\"type\":\"uint256\"}],\"name\":\"ShoesChanged\",\"type\":\"event\"},{\"anonymous\":false,\"inputs\":[{\"indexed\":true,\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"indexed\":true,\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"Transfer\",\"type\":\"event\"},{\"inputs\":[],\"name\":\"DEFAULT_ADMIN_ROLE\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"MINTER_ROLE\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"approve\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"}],\"name\":\"balanceOf\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"burn\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"newGlassesId\",\"type\":\"uint256\"}],\"name\":\"changeGlasses\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"newHatId\",\"type\":\"uint256\"}],\"name\":\"changeHat\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"newShoesId\",\"type\":\"uint256\"}],\"name\":\"changeShoes\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"getApproved\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"}],\"name\":\"getGlasses\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"}],\"name\":\"getHat\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"}],\"name\":\"getRoleAdmin\",\"outputs\":[{\"internalType\":\"bytes32\",\"name\":\"\",\"type\":\"bytes32\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"characterId\",\"type\":\"uint256\"}],\"name\":\"getShoes\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"grantRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"hasRole\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"}],\"name\":\"isApprovedForAll\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"name\",\"outputs\":[{\"internalType\":\"string\",\"name\":\"\",\"type\":\"string\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"uint256[]\",\"name\":\"\",\"type\":\"uint256[]\"},{\"internalType\":\"uint256[]\",\"name\":\"\",\"type\":\"uint256[]\"},{\"internalType\":\"bytes\",\"name\":\"\",\"type\":\"bytes\"}],\"name\":\"onERC1155BatchReceived\",\"outputs\":[{\"internalType\":\"bytes4\",\"name\":\"\",\"type\":\"bytes4\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"},{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"\",\"type\":\"bytes\"}],\"name\":\"onERC1155Received\",\"outputs\":[{\"internalType\":\"bytes4\",\"name\":\"\",\"type\":\"bytes4\"}],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"ownerOf\",\"outputs\":[{\"internalType\":\"address\",\"name\":\"\",\"type\":\"address\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"renounceRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes32\",\"name\":\"role\",\"type\":\"bytes32\"},{\"internalType\":\"address\",\"name\":\"account\",\"type\":\"address\"}],\"name\":\"revokeRole\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"}],\"name\":\"safeMint\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"safeTransferFrom\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"},{\"internalType\":\"bytes\",\"name\":\"_data\",\"type\":\"bytes\"}],\"name\":\"safeTransferFrom\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"operator\",\"type\":\"address\"},{\"internalType\":\"bool\",\"name\":\"approved\",\"type\":\"bool\"}],\"name\":\"setApprovalForAll\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"bytes4\",\"name\":\"interfaceId\",\"type\":\"bytes4\"}],\"name\":\"supportsInterface\",\"outputs\":[{\"internalType\":\"bool\",\"name\":\"\",\"type\":\"bool\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"symbol\",\"outputs\":[{\"internalType\":\"string\",\"name\":\"\",\"type\":\"string\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"index\",\"type\":\"uint256\"}],\"name\":\"tokenByIndex\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"owner\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"index\",\"type\":\"uint256\"}],\"name\":\"tokenOfOwnerByIndex\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"tokenURI\",\"outputs\":[{\"internalType\":\"string\",\"name\":\"\",\"type\":\"string\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[],\"name\":\"totalSupply\",\"outputs\":[{\"internalType\":\"uint256\",\"name\":\"\",\"type\":\"uint256\"}],\"stateMutability\":\"view\",\"type\":\"function\"},{\"inputs\":[{\"internalType\":\"address\",\"name\":\"from\",\"type\":\"address\"},{\"internalType\":\"address\",\"name\":\"to\",\"type\":\"address\"},{\"internalType\":\"uint256\",\"name\":\"tokenId\",\"type\":\"uint256\"}],\"name\":\"transferFrom\",\"outputs\":[],\"stateMutability\":\"nonpayable\",\"type\":\"function\"}]";

	TransactionGasLimit			 = "1000000";
	BlueHatAddress				 = "0x00010000000000000000000000000000000000000000000000000000000001";
	RedHatAddress				 = "0x00010000000000000000000000000000000000000000000000000000000002";
	BlueShoesAddress			 = "0x00020000000000000000000000000000000000000000000000000000000001";
	WhiteShoesAddress			 = "0x00020000000000000000000000000000000000000000000000000000000003";
	RedGlassesAddress			 = "0x00030000000000000000000000000000000000000000000000000000000002";
	WhiteGlassesAddress			 = "0x00030000000000000000000000000000000000000000000000000000000003";
}

void UWearableNFTExample::Init(FString _deviceId, FString _baseUrl, FString _session)
{
	deviceId = _deviceId;
	baseUrl = _baseUrl;
	session = _session;
}

void UWearableNFTExample::SetAccount(FString _account, int _chainId)
{
	activeAccount = _account;
	chainId		  = _chainId;
}

void UWearableNFTExample::MintItems(FString abi_hash, FString to, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - MintItems - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FString ticket = JsonObject->GetStringField("ticket");
				data = ticket;

			}

			Result.ExecuteIfBound(data);
		});

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Request, abi_hash, to]()
		{
			FString mintBatchMethodName = "mintBatch";

			FString json = "[\"" + to + "\", [\"" + BlueHatAddress + "\", \"" + RedHatAddress + "\", \"" + BlueShoesAddress + "\", \"" + WhiteShoesAddress + "\", \"" + RedGlassesAddress + "\", \"" + WhiteGlassesAddress + "\"], [1, 2, 3, 4, 5, 6], \"0x\"]";
			json = json.Replace(TEXT(" "), TEXT(""));

			FString j = "[\"0x0e9e2a366f0d82502483380093867335a58025bf\", [\"0x00010000000000000000000000000000000000000000000000000000000001\", \"0x00010000000000000000000000000000000000000000000000000000000002\", \"0x00020000000000000000000000000000000000000000000000000000000001\", \"0x00020000000000000000000000000000000000000000000000000000000003\", \"0x00030000000000000000000000000000000000000000000000000000000002\", \"0x00030000000000000000000000000000000000000000000000000000000003\"],[1, 2, 3, 4, 5, 6], []]";
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - MintItems - json: %s"), *j);

			FString url = baseUrl + "send/transaction";
			Request->SetURL(url);
			Request->SetVerb("POST");
			Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
			Request->SetHeader("Content-Type", TEXT("application/json"));
			Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameItemContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + mintBatchMethodName + "\", \"args\": " + json + "}");
			Request->ProcessRequest();

#if PLATFORM_ANDROID
			FPlatformProcess::LaunchURL(session.GetCharArray().GetData(), NULL, NULL);
#endif
		});
}

void UWearableNFTExample::MintCharacter(FString abi_hash, FString to, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - MintCharacter - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FString ticket = JsonObject->GetStringField("ticket");
				data = ticket;
				
			}
			
			Result.ExecuteIfBound(data);
		});

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Request, abi_hash, to]()
		{
			FString safeMintMethodName = "safeMint";

			FString url = baseUrl + "send/transaction";
			Request->SetURL(url);
			Request->SetVerb("POST");
			Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
			Request->SetHeader("Content-Type", TEXT("application/json"));
			Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + safeMintMethodName + "\", \"args\": [\"" + to + "\"]}");
			Request->ProcessRequest();

#if PLATFORM_ANDROID
			FPlatformProcess::LaunchURL(session.GetCharArray().GetData(), NULL, NULL);
#endif
		});
}

void UWearableNFTExample::GameItemSetApproval(FString abi_hash, FString callOperator, bool approved, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GameItemSetApproval - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				bool result = JsonObject->GetBoolField("result");
				if (result)
				{
					FString ticket = JsonObject->GetStringField("ticket");
					data = ticket;
				}
			}

			Result.ExecuteIfBound(data);
		});

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Request, abi_hash, callOperator, approved]()
		{
			FString setApprovalForAllMethodName = "setApprovalForAll";

			FString url = baseUrl + "send/transaction";
			Request->SetURL(url);
			Request->SetVerb("POST");
			Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
			Request->SetHeader("Content-Type", TEXT("application/json"));
			Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + setApprovalForAllMethodName + "\", \"args\": [\"" + callOperator + "\", \"" + (approved ? "true":"false") + "\"]}");
			Request->ProcessRequest();

#if PLATFORM_ANDROID
			FPlatformProcess::LaunchURL(session.GetCharArray().GetData(), NULL, NULL);
#endif
		});
}

void UWearableNFTExample::GetCharacterBalance(FString abi_hash, FString address, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetCharacterBalance - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				data = JsonObject->GetStringField("data");
				UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetCharacterBalance - Balance: %s"), *data);
			}

			Result.ExecuteIfBound(data);
		});

	FString balanceOfMethodName = "balanceOf";

	FString url = baseUrl + "call/method";
	Request->SetURL(url);
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + balanceOfMethodName + "\", \"args\": [\"" + address + "\"]}");
	Request->ProcessRequest();
}

void UWearableNFTExample::GetBalanceERC1155(FString contract_address, FString abi_hash, FString _account, FString id, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetBalanceERC1155 - GetContentAsString: %s"), *Response->GetContentAsString());
			Result.ExecuteIfBound(Response->GetContentAsString());
		});

	FString tokenOfOwnerByIndexMethodName = "tokenOfOwnerByIndex";

	FString url = baseUrl + "call/method";
	Request->SetURL(url);
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + contract_address + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + tokenOfOwnerByIndexMethodName + "\", \"args\": [\"" + _account + "\", \"" + id + "\"]}");
	Request->ProcessRequest();
}

void UWearableNFTExample::GetCharacterTokenId(FString abi_hash, int tokenBalance, FString owner, FString index, FMirageDelegate Result)
{
	if (tokenBalance <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetCharacterTokenId - You don't own any of these tokens - tokenBalance: %d"), tokenBalance);
		return;
	}

	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetCharacterTokenId - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				data = JsonObject->GetStringField("data");
				UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetCharacterTokenId - Balance: %s"), *data);
			}

			Result.ExecuteIfBound(data);
		});

	FString tokenOfOwnerByIndexMethodName = "tokenOfOwnerByIndex";

	FString url = baseUrl + "call/method";
	Request->SetURL(url);
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + tokenOfOwnerByIndexMethodName + "\", \"args\": [\"" + owner + "\", \"" + index + "\"]}");
	Request->ProcessRequest();
}

void UWearableNFTExample::GetHasHatToken(FString abi_hash, int tokenBalance, FString tokenAddress, FString _account, FString id, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			FString data = Response->GetContentAsString();
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetHasHatToken - GetContentAsString: %s"), *data);

			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				data = JsonObject->GetStringField("data");
				UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetHasHatToken - Balance: %s"), FCString::Atoi(*data));
			}

			Result.ExecuteIfBound(data);
		});

	FString balanceOfMethodName = "balanceOf";

	FString url = baseUrl + "call/method";
	Request->SetURL(url);
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameItemContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + balanceOfMethodName + "\", \"args\": [{\"" + _account + "\", \"" + id + "\"]}");
	Request->ProcessRequest();
}

void UWearableNFTExample::ChangeHat(FString abi_hash, int characterId, bool hasHat, FString hatAddress, FMirageDelegate Result)
{
	if (!hasHat || characterId == -1)
	{
		UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - ChangeHat - CharacterID or HatID is null"));
		return;
	}

	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - ChangeHat - GetContentAsString: %s"), *Response->GetContentAsString());
			Result.ExecuteIfBound(Response->GetContentAsString());
		});

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Request, abi_hash, characterId, hasHat, hatAddress]()
		{
			FString changeHatMethodName = "changeHat";

			FString url = baseUrl + "send/transaction";
			Request->SetURL(url);
			Request->SetVerb("POST");
			Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
			Request->SetHeader("Content-Type", TEXT("application/json"));
			Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + changeHatMethodName + "\", \"args\": [\"" + FString::FromInt(characterId) + "\", \"" + BlueHatAddress + "\", \"" + TransactionGasLimit + "\"]}");
			Request->ProcessRequest();

#if PLATFORM_ANDROID
			FPlatformProcess::LaunchURL(session.GetCharArray().GetData(), NULL, NULL);
#endif
		});
}

void UWearableNFTExample::GetHat(FString abi_hash, int characterId, FMirageDelegate Result)
{
	http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			UE_LOG(LogTemp, Warning, TEXT("WearableNFTExample - GetHat - GetContentAsString: %s"), *Response->GetContentAsString());
			Result.ExecuteIfBound(Response->GetContentAsString());
		});

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Request, abi_hash, characterId]()
		{
			FString getHatMethodName = "getHat";

			FString url = baseUrl + "call/method";
			Request->SetURL(url);
			Request->SetVerb("POST");
			Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
			Request->SetHeader("Content-Type", TEXT("application/json"));
			Request->SetContentAsString("{\"device_id\": \"" + deviceId + "\", \"contract_address\": \"" + GameCharacterContractAddress + "\", \"abi_hash\": \"" + abi_hash + "\", \"method\": \"" + getHatMethodName + "\", \"args\": [{\"_characterId\":" + FString::FromInt(characterId) + "}] }");
			Request->ProcessRequest();
		});
}

void UWearableNFTExample::GetTicketResult(FString ticketId, FMirageTicketResult Result)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = http->CreateRequest();
	Request->OnProcessRequestComplete().BindLambda([Result, ticketId, this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
			UE_LOG(LogTemp, Warning, TEXT("UpdateNFTExample - GetTicketResult - GetContentAsString: %s"), *Response->GetContentAsString());
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FString data = JsonObject->GetStringField("data");
				Result.ExecuteIfBound(Response->GetContentAsString(), 1);// "Transaction Hash: " + data, 1);
			}
		});

	FString url = baseUrl + "result";
	Request->SetURL(url);
	Request->SetVerb("POST");
	Request->SetHeader(TEXT("User-Agent"), "X-MirageSDK-Agent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	Request->SetContentAsString("{\"ticket\": \"" + ticketId + "\" }");
	Request->ProcessRequest();
}
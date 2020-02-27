//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<iostream>
#include <iterator>
#include	"GateControl.hpp"

using namespace std;

//****************************************************************************************
//
//	CONSTANT DEFINITIONS
//
//****************************************************************************************

//****************************************************************************************
//
//	CLASSES, TYPEDEFS AND STRUCTURES
//
//****************************************************************************************

//****************************************************************************************
//
//	PUBLIC DATA
//
//****************************************************************************************
extern	string	gCurrentDate;

extern	string	gCurrentTime;

//****************************************************************************************
//
//	PRIVATE DATA
//
//****************************************************************************************

//****************************************************************************************
//
//	FUNCTION PROTOTYPES
//
//****************************************************************************************

//****************************************************************************************
//
//	GateControl::AccessAllowed
//
//****************************************************************************************
//iterates through map and checks for authorization returns true or false
bool	GateControl::AccessAllowed(CardNumber number)
{
	AuthorizationIterator iterator;
//used for-loop for learning, could also use iterator = authorizationMap_.find(number), less code
	for (iterator=authorizationMap_.begin(); iterator!=authorizationMap_.end(); ++iterator){
		if(iterator->first == number){ //true authorization check, numbers match
				if(iterator->second.startTime_ <= gCurrentTime && iterator->second.endTime_>=gCurrentTime){
				transactionVector_.push_back(Transaction(iterator->second.number_, iterator->second.name_, gCurrentDate, gCurrentTime, true));
				return 1; //endtime and starttime to push date and time when granted access to vector
				}
				else { //false authorization, no number match
					transactionVector_.push_back(Transaction(iterator->second.number_, iterator->second.name_, gCurrentDate, gCurrentTime, false));
					return 0;
				}
			}
		}
		//name not present and number not present in map, false return
	transactionVector_.push_back(Transaction(number,"***", gCurrentDate, gCurrentTime, false));
	return 0;
}

//****************************************************************************************
//
//	GateControl::AddAuthorization
//
//****************************************************************************************
//add authorization, returns a bool
bool	GateControl::AddAuthorization(CardNumber number, const string& name,
									  const string& startTime, const string& endTime)
{
	//************************************************************************************
	//	LOCAL DATA
//if not empty, insert into map
if(!authorizationMap_.empty()){
AuthorizationIterator	iterator;
//for-loop of .find()
	for (iterator=authorizationMap_.begin(); iterator!=authorizationMap_.end(); ++iterator){
			if(iterator->second.number_ == number) //check for duplicate
				return 0; //return false
			}
	authorizationMap_.insert(pair<CardNumber, Authorization> (number, Authorization(number, name, startTime, endTime)));
	//if no duplicates, insert into map
	return 1; //return true
}
else { //if map is empty no need to check for duplicates, just insert. faster.
	authorizationMap_.insert(pair<CardNumber, Authorization> (number, Authorization(number, name, startTime, endTime)));
		return 1;
	}
}

//****************************************************************************************
//
//	GateControl::ChangeAuthorization
//
//****************************************************************************************
//change authorization, bool return
bool	GateControl::ChangeAuthorization(CardNumber number, const string& name,
										 const string& startTime, const string& endTime)
{
	AuthorizationIterator	iterator;
	for (iterator=authorizationMap_.begin(); iterator!=authorizationMap_.end(); ++iterator){
		if(iterator->first == number){ //changes authorization details, matches number first in map
			iterator->second.name_ = name;
			iterator->second.startTime_ = startTime;
			iterator->second.endTime_ = endTime;
			return 1; //return true for success
		}
	}
	//************************************************************************************
	//	EXECUTABLE STATEMENTS
	return 0; //return false for failure if no number match
}

//****************************************************************************************
//
//	GateControl::DeleteAuthorization
//
//****************************************************************************************
//deletes authorization from map
bool	GateControl::DeleteAuthorization(CardNumber number)
{
		AuthorizationIterator	iterator;

		for (iterator=authorizationMap_.begin(); iterator!=authorizationMap_.end(); ++iterator){
			if(iterator->first == number){ // finds matching number and then deletes element from map
				authorizationMap_.erase(iterator);
				return 1; //return true for success
			}
		}
return 0; // return false, number was not in map
}

//****************************************************************************************
//
//	GateControl::GetAllAuthorizations
//
//****************************************************************************************
//transfers all the authorizations from map into vector for main check
void	GateControl::GetAllAuthorizations(AuthorizationVector& authorizationVector)
{
	//************************************************************************************
	//	LOCAL DATA

	AuthorizationIterator	iterator;

//if map empty clear vector
		if (authorizationMap_.empty()) {
				authorizationVector.clear();
				return;
			}
		else { //CLEARED BEFORE ADDING AGAIN TO REMOVE FLAG BREAKS
			authorizationVector.clear();
			for (iterator=authorizationMap_.begin(); iterator!=authorizationMap_.end(); ++iterator){
								authorizationVector.push_back(Authorization(iterator->second.number_, iterator->second.name_, iterator->second.startTime_, iterator->second.endTime_));
			 }
		}
}

//****************************************************************************************
//
//	GateControl::GetAllTransactions
//
//****************************************************************************************
//get all history of transactions and transfer to transactionVector for main
void	GateControl::GetAllTransactions(TransactionVector& transactionVector)
{
	transactionVector.clear(); //clears main vector
/*for(int i = 0; i<transactionVector_.size(); i++){
	transactionVector.push_back(Transaction(transactionVector_.at(i).number_,transactionVector_.at(i).name_,transactionVector_.at(i).date_, transactionVector_.at(i).time_, transactionVector_.at(i).accessAllowed_));
} //push all to main vector from transactionVector_
*/
transactionVector = transactionVector_; //simple clear and copy
	return;
}

//****************************************************************************************
//
//	GateControl::GetCardAuthorization
//
//****************************************************************************************
//uses find to find number and get card detials
bool	GateControl::GetCardAuthorization(CardNumber number, Authorization& authorization)
{
AuthorizationIterator iterator;
iterator = authorizationMap_.find(number);
	if(iterator == authorizationMap_.end())
		return 0;
	else {
		authorization.number_ = iterator->second.number_;
		authorization.name_ = iterator->second.name_;
		authorization.startTime_ = iterator->second.startTime_;
		authorization.endTime_ = iterator->second.endTime_;
		return 1;
	}
	return 0;
}

//****************************************************************************************
//
//	GateControl::GetCardTransactions
//
//****************************************************************************************
//gets card transactions, checks transactionVector_ == to number by iteration, pushes all details to vector
//return true or false for success
bool	GateControl::GetCardTransactions(CardNumber number,
										 TransactionVector& transactionVector)
{
	bool success = false;
	transactionVector.clear();
	for(int i = 0; i < transactionVector_.size(); i++){
		if(transactionVector_.at(i).number_ == number){
			transactionVector.push_back(Transaction(transactionVector_.at(i).number_,
																	transactionVector_.at(i).name_,
																	transactionVector_.at(i).date_,
																	transactionVector_.at(i).time_,
																	transactionVector_.at(i).accessAllowed_));
		success = true;
		}
	}
	if(success == true)
		return 1;
	else
		return 0;
}

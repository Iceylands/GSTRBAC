/* Update notes: 
1- removed using namespace std (Mustafa 5-2-19) 
2- included std:: before the string data type (Mustafa 5-2-19)
3- included the headers of STZone and Role to allow 
the assignRole to be defined (Mustafa 5-2-19)
4- included the include guard (Mustafa 5-2-19)
5- added the body to getName() funciton (Mustafa 5-2-19)
*/

/*Creates functions assignRole, activateRole, getAssignmentRoles, getActivatedRoles, getAuthorizedRoles, checkAccess
takes currentzone from STZone and relations from userRoleRelation
*/
/*Update notes: 02/08/19
1- headers were added to include activity, object and vector
2- currently having issues creating classes that output a return of type vector
3- checkAccess == function needs to be overloaded to compare the class types since they aren't general values. 
*/
// Separation done by User.h by OB and miguel, .h by OB and .cpp by Miguel.
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "STZone.h"
#include "Role.h"
#include "UserRoleAssignment.h"
#include "UserRoleActivation.h"
#include "UserRoleRelation.h"
#include "Activity.h"
#include "Object.h"
#include <vector>

//#include "UserRoleRelation.h"
//class UserRoleRelation;
class User {
public:
	User(std::string& userName, std::vector<UserRoleRelation>& userRelations, STZone& cZone);//{
		//}
			
		/*	, 
		const std::vector<UserRoleRelation> &userRelations)
		{

			name{ userName };
			relations{ userRelations };

		}
		*/
	//User(const User&) = default;
	//A(const A&) = default;
	//User& operator=(const User&) = default;
	//A& operator=(const A&) = default;


	const UserRoleAssignment& assignRole(Role& r, STZone& z);									//done 3/8

	void deassignRole(Role& r, STZone& z); 

	const UserRoleActivation& activateRole(Role& r, STZone& z); // added 02/07 and tested	
																//done 3/8
	void deactivateRole(Role& r, STZone& z); //this was missing from .cpp Rey- 9-17-19
	const std::vector<Role> getAssignedRoles(const STZone& z);  //added 02/07 and tested
	
	const std::vector<Role>& getActivatedRoles(const STZone& z); 

	const std::vector<Role>& getAuthorizedRoles(STZone& z);
		//Algorithm:
		//authorizedRoles = getAssignedRoles(z);
		// create juniorRole vector
		// loop over authorizeRole vector
			// get their junior roles at a particular zone
			// push them to juniorRole vector
		// push juniorRoles to authorizedRoles vector
		// return authorizedRole vector

		// get all assigne roles in addition of their junior role
		// at particular zone
		// push them to the authorizedRoles vector 
		
	const bool checkAccess(Object& o, Activity& a, STZone& z); 
	// You need to include the other member functions signatures here 

	std::string& getName() const; 
	void setName(std::string givenName);
	const STZone& getCurrentZone();
private:
	
	std::string& name;
	STZone& currentZone; // this represents the UserZone association
	std::vector<UserRoleRelation>&  relations; // this represents the URRUser association
	//seperation of the relations vector in an attempt to simplify code
	std::vector<UserRoleActivation> userActivatedRoles;
	std::vector<UserRoleAssignment> userAssignedRoles;

	UserRoleRelation * createUserRoleRelation(int, Role&, STZone&);
	
};

#endif // !USER_H
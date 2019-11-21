/* Update Changes:
1- start creating the driver (Mustafa 5-2-19)
2- Included the include for the class User, Role, STZone, and UserRoleAssignment (Mustafa 5-2-19)
3- Instantiated the user class (created mustafa object) (Mustafa 5-2-19)
4- tested if getName works for user (Mustafa 5-2-19)
5- created the role object  faculty  (Mustafa 5-2-19)
6- created the the STZoen object tamiu  (Mustafa 5-2-19) 
7- Tested the assignRole() member function of the user class (Mustafa 5-2-19) 
8- Added and tested SystemManager's functions and initial tracking ability (Marshal 11-18-19)
*/

#include <iostream>
#include "User.h"
#include "Role.h"
#include "STZone.h"
#include "UserRoleAssignment.h"
#include "UserRoleActivation.h"
#include "Object.h"
#include "Activity.h"
#include "Permission.h"
#include "SOD.h"
#include "Location.h"
#include "TimeInterval.h"
#include "SystemManager.h"
using namespace std;

//you should include the other headers here

int main() {
	SystemManager sManager{};

	string user1Name{ "Bob" };
	string user2Name{ "Ben" };
	string user3Name{ "Alice" };
	string user4Name{ "Rachael" };
	string user5Name{ "Clare" };
	string user6Name{ "Sam" };
	vector<STZone> include{};
	vector<STZone> rzones{};
	TimeInterval intervals{include};
	sManager.addTICount(intervals);
	string zName{ "zoning" };
	Location zoneLoc(include);
	sManager.addLocationCount(zoneLoc);
	string name{ "Mustafa" };
	vector<UserRoleRelation> testRelations{};

	vector<User> zoneUser;
	vector<Role> zoneRole;
	vector<Permission> zonePermission;
	vector<Object> zoneObject;
	vector<PermissionAssignment> zonePermAssign;
	vector<SOD> zoneSOD;
	vector<PSSOD> zonePSSOD;
	vector<RoleHierarchy> zoneRH;
	vector<STZone> locZones;
		STZone tamiu{ zName,zoneLoc, testRelations, intervals, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		sManager.addZoneCount(tamiu);
		
		Location Home(locZones);
		sManager.addLocationCount(Home);
		Location developmentOffice(locZones);
		sManager.addLocationCount(developmentOffice);
		Location testingOffice(locZones);
		sManager.addLocationCount(testingOffice);
		Location directorOffice(locZones);
		sManager.addLocationCount(directorOffice);
		Location departmentBuilding(locZones);
		sManager.addLocationCount(departmentBuilding); //latest line added for SystemManager test
		string zName0{ "Department Building" };
		string zName1{ "Home" };
		string zName2{ "Develmopment Office" };
		string zName3{ "Testing Office" };
		string zName4{ "Director Office" };
		TimeInterval i1(locZones);
		TimeInterval i2(locZones);
		STZone z0{ zName0,departmentBuilding, testRelations, i1, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		STZone z1{ zName1,Home, testRelations, i2, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		STZone z2{ zName2,developmentOffice, testRelations, i1, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		STZone z3{ zName3,testingOffice, testRelations, i1, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		STZone z4{ zName4,directorOffice, testRelations, i1, zoneUser, zoneRole, zonePermission, zoneObject, zonePermAssign, zoneSOD, zonePSSOD, zoneRH };
		User Bob{ user1Name,testRelations,z0 };

		User Ben{ user2Name, testRelations, z1 };
		User Alice{ user3Name,testRelations,z3 };
		User Rachael{ user4Name, testRelations, z4 };
		User Clare{ user5Name,testRelations,z0};
		User Sam{ user6Name, testRelations, z3};


		string rName0("Software Engineer");
		string rName1("Software Programmer");
		string rName2("Test Engineer");
		string rName3("Programmer Supervisor");
		string rName4("Test Supervisor");
		string rName5("Project Lead");
		//rzones.push_back(z0);
		//rzones.push_back(z2);
		vector<PermissionAssignment*> rolePermission;
		Role SE(rName0, testRelations, rzones, zoneRH, zoneRH, zoneSOD,rolePermission);
		SE.enableZone(z0);
		SE.enableZone(z2);
		Role SP(rName1, testRelations, rzones, zoneRH, zoneRH, zoneSOD,rolePermission);
		SP.enableZone(z1);
		SP.enableZone(z2);

		
		vector<STZone> zones{ SP.getEnabledZone() };
		for (STZone& zone : zones)
		{
			cout << zone.getName() << endl;
		}
		
		Role TE(rName2, testRelations, rzones, zoneRH, zoneRH, zoneSOD,rolePermission);
		Role PS(rName3, testRelations, rzones, zoneRH, zoneRH, zoneSOD, rolePermission);
		Role TS(rName4, testRelations, rzones, zoneRH, zoneRH, zoneSOD, rolePermission);
		Role PL(rName5, testRelations, rzones, zoneRH, zoneRH, zoneSOD, rolePermission);

		//assign Bob to SP
		UserRoleAssignment uraObj= Bob.assignRole(SP, z1);
		cout << "the User of the uraObject is " << uraObj.getUser()->getName() << endl;//testing all values connected to assignRole
		cout << "The role of the uraObject is " << uraObj.getRole().getName() << endl;
		cout << "The zone of the uraObject is " << uraObj.getZone().getName() << endl;
		UserRoleActivation urActObj = Bob.activateRole(SP, z1);
		cout << "The Role of the urActObj is " << urActObj.getRole().getName() << endl;//testing values of the activateRole
		cout << "The Zone of the urActObj is " << urActObj.getZone().getName() << endl;
		cout << "The User of the urActObj is " << urActObj.getUser()->getName() << endl;
		Bob.assignRole(SE, z1);
		//Bob.deassignRole(SE, z1);
		TE.addAHJuniorRole(PS, z1);
		TE.addIHJuniorRole(PL, z3);
		TE.enableZone(z1);
		TE.enableZone(z3);
		PS.enableZone(z2);
		TS.enableZone(z3);
		PL.enableZone(z4);

		//Enableing z1 of TS for testing only 
		TS.enableZone(z1);
		vector<STZone> zones4{ TS.getEnabledZone() };
		cout << "\n\n ===== TS zones after enabling:\n";
		for (STZone& zone : zones4)
		{
			cout << zone.getName() << endl;
		}

		TS.disableZone(z3);

		vector<STZone> zones5{ TS.getEnabledZone() };
		cout << "\n\n ===== TS zones after enabling:\n";
		for (STZone& zone : zones5)
		{
			cout << zone.getName() << endl;
		}

		//creating objects. 
		vector<STZone> objZones;
		vector<Permission> objPermission;
		Object obj1 ("Project Files",objZones, objPermission);
		Object obj2 ("Test Files",objZones, objPermission);
		Object obj3 ("Programmer Logs",objZones, objPermission);
		Object obj4 ("Test Logs",objZones, objPermission);
		Object obj5 ("Programer Supervisor Report",objZones, objPermission);
		Object obj6 ("TestSupervisorsReports",objZones, objPermission);
		obj1.enableZone(z1);
		obj1.enableZone(z2);
		obj2.enableZone(z1);
		obj2.enableZone(z3);
		obj3.enableZone(z2);
		obj4.enableZone(z3);
		obj5.enableZone(z4);
		obj6.enableZone(z4);
		//checking role enabling 
		//TE.enableZone(z1);
		vector<STZone> zones2{ TE.getEnabledZone() };

		cout << "\n\n ===== TE zones after enabling:\n";
		for (STZone& zone : zones2)
		{
			cout << zone.getName() << endl;
		}
		TE.disableZone(z1);
		
		vector<STZone> zones3{ TE.getEnabledZone() };
		cout << "\n\n =====  TE zones after disabling:\n";
		for (STZone& zone : zones3)
		{
			cout << zone.getName() << endl;
		}
 
		//TE.getZoneName();

		//testing user functions
		Bob.assignRole(TE, z3);
		Bob.deassignRole(TE, z3);
		Bob.deassignRole(SE, z1);

		cout << "\n The assigned roles are \n";
		vector<Role> temp= Bob.getAssignedRoles(z1) ;
		for (Role roles : temp) {
			cout << roles.getName() << endl;
		}
		Bob.deactivateRole(SE, z1);
		Bob.getAuthorizedRoles(z1);



		
		//Bob.getAssignedRoles(z1);
//Bob.getAssignedRoles(z1);
	/*User mustafa{ name,relations, tamiu };
	Role faculty{faculty}; // to test if assignRole(r:Role,z:STZone) works correctly
	Role student{ student };
	
	Object ob{ ob };
	Activity act{ act };
	Permission yes{ yes };
	SOD duty{ duty };
	//user function testing
	mustafa.setName("Mustafa");
	cout << "Mustafa's name is : " << mustafa.getName() << endl;
	mustafa.getActivatedRoles(tamiu);
	mustafa.getAuthorizedRoles(tamiu);
	mustafa.assignRole(faculty, tamiu);
	mustafa.getAssignedRoles(tamiu);
	mustafa.checkAccess(ob, act, tamiu);
	// role function testing
	faculty.addAHJuniorRole(faculty, tamiu);
	faculty.addIHJuniorRole(faculty, tamiu);
	faculty.addSSoDRole(student, tamiu);
	faculty.addDSoDRole(faculty, tamiu);
	faculty.getSSoDRoles(tamiu);
	faculty.getDSoDRoles(tamiu);
	faculty.getJuniorRoles(tamiu);
	faculty.getAHJuniorRoles(tamiu);
	faculty.getIHJuniorRoles(tamiu);
	faculty.getPrerequisiteRoles();
	faculty.inherits(student, tamiu);
	faculty.inheritsAH(student, tamiu);
	faculty.inheritsIH(student, tamiu);
	faculty.getAllAHInheritedRoles(tamiu);
	faculty.getAllIHInheritedRoles(tamiu);
	faculty.getAssignedPermissions(tamiu);
	faculty.getAuthorizedPermissions(tamiu);//tested and functioning
	//Permission function testing
	yes.addSoDPermission(yes, tamiu);
	yes.getSoDPermission(tamiu);
	yes.getPrerequisitePermissions();//tested and compile
	//SOD function testing
	//SOD function was omitted



	//UserRoleAssignment ura1{ faculty,tamiu };
	//UserRoleActivation ura2{ faculty,tamiu };
	//ura1 = mustafa.assignRole(faculty, tamiu); // invoking the assignRole on a user object, to make sure it
	//ura2 = mustafa.activateRole(faculty, tamiu);// returns the correct type 
	
	
	//role function tests
	//faculty.addAHJuniorRole(student, tamiu);
	//use ranged based for loop to test the assigned roles
	//The function does not repeat itself but it does print once. I don't think it's seperating the role variables, attempted for(Role roles: allRoles) and for(auto:allRoles)
	std::vector<Role> roles;
	roles = mustafa.getAssignedRoles(tamiu);
	for ( auto role: roles) {
			cout << "Role name: " << role.getName() << endl;
	}
	*/
		system("pause");
		return 0;

}
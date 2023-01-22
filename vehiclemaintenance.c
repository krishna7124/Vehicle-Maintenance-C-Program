/*This is a c program which helps to know whether the vehiche needs maintenance or not
It is developed by Krishna Bhatt
Version - 1.02
Started Date - 25/12/2022
Completion Date - 31/12/2022
*/

#include <stdio.h>
#include <string.h>

#define NUM_VEHICLE_TYPES 5
#define NUM_SUBTYPES_PER_TYPE 3

const char *VEHICLE_TYPES[NUM_VEHICLE_TYPES] = {
  "Car",
  "Truck",
  "Bicycle",
  "Motorcycle",
  "Plane"
};

const char *SUBTYPE_NAMES[NUM_VEHICLE_TYPES][NUM_SUBTYPES_PER_TYPE] = {
  { "Sedan", "SUV", "Coupe" }, // Car
  { "Pickup", "Box Truck", "Dump Truck" }, // Truck
  { "Road", "Mountain", "Hybrid" }, // Bicycle
  { "Sport", "Cruiser", "Tour" }, // Motorcycle
  { "Single-Engine", "Jet", "Helicopter" } // Plane
};

const int MAINTENANCE_INTERVALS[NUM_VEHICLE_TYPES][NUM_SUBTYPES_PER_TYPE] = {
  { 16093, 24140, 12186 }, // Car
  { 32186, 48280, 64373 }, // Truck
  { 1609, 804, 402 }, // Bicycle
  { 8047, 16093, 24140 }, // Motorcycle
  { 160934, 804700, 1609340 } // Plane
};

int main() {
  char user_name[100];
  int current_kilometers;
  int last_kilometers;
  int vehicle_type;
  int subtype;

  printf("Enter your name: ");
  scanf("%s", user_name);

  printf("\nEnter the type of vehicle (0 for Car, 1 for Truck, 2 for Bicycle, 3 for Motorcycle, 4 for Plane): ");
  scanf("%d", &vehicle_type);

  if (vehicle_type < 0 || vehicle_type >= NUM_VEHICLE_TYPES) {
    printf("Invalid vehicle type.\n");
    return 1;
  }

  printf("Enter the subtype of %s (0 for %s, 1 for %s, 2 for %s): ",
    VEHICLE_TYPES[vehicle_type], SUBTYPE_NAMES[vehicle_type][0],
    SUBTYPE_NAMES[vehicle_type][1], SUBTYPE_NAMES[vehicle_type][2]);
-  scanf("%d", &subtype);

  if (subtype < 0 || subtype >= NUM_SUBTYPES_PER_TYPE) {
    printf("Invalid subtype.\n");
    return 1;
  }

  printf("\nEnter the current kilometers of the %s %s: ", SUBTYPE_NAMES[vehicle_type][subtype], VEHICLE_TYPES[vehicle_type]);
  scanf("%d", &current_kilometers);
  printf("Enter the last recorded mileage of the %s %s: ",SUBTYPE_NAMES[vehicle_type][subtype], VEHICLE_TYPES[vehicle_type]);
  scanf("%d", &last_kilometers);

  int kilometers_since_last_maintenance = current_kilometers - last_kilometers;
    if (kilometers_since_last_maintenance >= MAINTENANCE_INTERVALS[vehicle_type][subtype]) {
    printf("\nHi %s, \nIt has been %d Kilometers since your %s %s's last recorded kilometers.",
      user_name,kilometers_since_last_maintenance,SUBTYPE_NAMES[vehicle_type][subtype], VEHICLE_TYPES[vehicle_type]);
    printf("\nBased on the maintenance intervals for this type of vehicle, it is time for maintenance.");
  } else {
    printf("\nHi %s, \nIt has been %d Kilometers since your %s %s's last recorded kilometers.", user_name,kilometers_since_last_maintenance,SUBTYPE_NAMES[vehicle_type][subtype], VEHICLE_TYPES[vehicle_type]);
    printf("\nBased on the maintenance intervals for this type of vehicle, maintenance is not needed.");
  }

  printf("\n\nThankyou for using our Software \nDeveloped By Krishna Bhatt");

}

// OUTPUT:

// Enter your name: John

// Enter the type of vehicle (0 for Car, 1 for Truck, 2 for Bicycle, 3 for Motorcycle, 4 for Plane): 0
// Enter the subtype of Car (0 for Sedan, 1 for SUV, 2 for Coupe): 1

// Enter the current kilometers of the SUV Car: 120000
// Enter the last recorded mileage of the SUV Car: 100000

// Hi John,
// It has been 20000 Kilometers since your SUV Car's last recorded kilometers.
// Based on the maintenance intervals for this type of vehicle, maintenance is not needed.

// Thankyou for using our Software
// Developed By Krishna Bhatt

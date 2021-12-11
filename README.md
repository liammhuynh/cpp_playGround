# cpp_playGround

201 Hospital
The assignment problem:
You will develop a simple patient’s management system for 201 Hospital. The hospital has 3 departments: Heart
clinic, Lung clinic, and Plastic surgery. The first screen of your application will ask the user to select one of the
departments. You need to create a queue for each department that includes patients of the current
department only. Users of your software can do the following functions within each department:

• Add new patient
The “Add patient” is responsible to add a new patient entry into the queue. Each patient must have a first name,
last name, and a social security number (cannot be empty, but can be of any length for simplicity, e.g. 123 is
accepted). If the social security number is empty (return character), the operation should be canceled with
cancelation message. The maximum number of patients in any department is 100. Note that after adding a new
patient, your application should confirm the entered data of the patient on a new screen. After confirming the
entered data, the user can press any key to return to the department’s menu. You do not need to ask the user if the
entered data is correct or not. Just confirm it by re-printing it.

• Add critically ill patient (emergency cases)
The “Add critically ill patient” will add a new patient (first name, last name, social security number) at the
beginning of the current queue –passing all current patients in the queue. This means that patients entered the
queue as critically ill will have operation before other patients, even if they entered the queue after the regular
patients. Your application can add any number of patients as critically ill, but not more than 100 patients in total
within each department, both regular and critically ill patients. Note that, if you have several critically ill patients
then they have operations in the same order they entered the queue (First in, first out). Once all critically ill
patients have been taken out to operation (removed from the queue), the application continues with the regular
patients –also in a first in, first out manner. Note that after adding a new patient, your application should confirm
the entered data of the patient on a new screen. After confirming the entered data, the user can press any key to
return to the department’s menu. You do not need to ask the user if the entered data is correct or not. Just confirm
it by re-printing it.

• Take out patient for operation
This feature is responsible to move patients to the operation room (remove them from the queue). Of course, this
should be a first-come first-served operation. Note that having critically ill patients will give them higher priority
to enter the operations room (to be removed from the queue first, even if they have been added after the regular
patients). After moving a patient to the operation room, your application should print the data of the moved patient
(name and social security number) in a new screen. If no patients are left, your application should print a
notification message to the screen “No more patients.”

• Cancel patient
This feature will ask the user to input the data of a patient (first name, last name, and social security number) and
then remove that patient from the queue. If such a patient does not exist, a notification message is printed to the
screen “Patient Does Not Exist.”

• List all current patients
This feature lists all patients currently in the queue (first name, last name, social security number) including
regular and critically ill patients.

• Exit the current department
This function exists the current department, clear the screen, and print the main application menu.

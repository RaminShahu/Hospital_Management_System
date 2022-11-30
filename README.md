# Hospital_Management_System

Hospital Management System 

This management system was developed using object oriented programming principles such as abstraction,encapsulation,polymorphism and inheretence

Terminal based hospital management system using text files which allows user to register a patient into the hospital, select the doctor they want for a particular patient, enter other details such as reason for visit, if they wanted extra care , what kind of ward they would prefer etc.

The system has 6 main functionality:

1. Register Patient (RP)

2. Deregister Patient (DP)

3. Check Record of Current Patients (CRCP)

4. Check Record of Previous Patients (CRPP)

5. Search Room (SR)

6. Exit (EX)


The role of a user changes in the system for example initially a user is receptionist after they register the patient,select doctor for them and add other details.
The user starts acting as a doctor and follows it roles by prescribing medication and advising to go to specialist doctor if needed(Role will change to specialsist doctor). 
The specialist doctor has the ability to prescribe additional medication and ask patient to stay at hospital for certain number of days.(RP)
 

 All the data of the patient is stored in a text file and a user has functionality to search patient which will give user the details of the patient.(CRCP)
 

The program allows user to generate a summary of a particular ward which will show them the capacity of ward, which patients are inside the ward and type of ward.(SR)


Also, user can deregister patient which remove their information from text file. (DP)


The removed information is stored into a different text file which keeps track of previous patient in the hospital. User can also generate the previous patient’s history.(CRPP)


The Exit will shut down the program. A message will be printed and the data will still remain in the file.(EX)

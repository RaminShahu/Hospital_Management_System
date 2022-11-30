# Hospital_Management_System

Hospital Management System 

This management system was developed using object-oriented programming principles such as abstraction, encapsulation, polymorphism, and inheritance.

The program was tested using incremental testing that is why it has many mainfiles with numbers. However the orignal file is main.cpp

Terminal-based hospital management system using text files allows users to register a patient into the hospital, select the doctor they want for a particular patient, and enter other details such as the reason for visit, if they wanted extra care, what kind of ward they would prefer, etc.

The system has 6 main functionality:

1. Register Patient (RP)

2. Deregister Patient (DP)

3. Check Record of Current Patients (CRCP)

4. Check Record of Previous Patients (CRPP)

5. Search Room (SR)

6. Exit (EX)


The role of a user changes in the system when registering a patient for example initially a user is a receptionist after they register the patient, select a doctor for them, and add other details.
The user starts acting as a doctor and follows their role by prescribing medication and advising them to go to the specialist doctor if needed(The role will change to a specialist doctor). 
The specialist doctor can prescribe additional medication and ask the patient to stay at the hospital for a certain number of days. (RP)
 

All the data of the patients is stored in a text file and a user has the functionality to search patients which will give the user the details of the patient.(CRCP)
 

The program allows users to generate a summary of a particular ward which will show them the capacity of the ward, which patients are inside the ward, and type of ward.(SR)


Also, user can deregister patient which removes their information from the text file. (DP)


The removed information is stored in a different text file which keeps track of the previous patients who visited hospital. Users can also generate the previous patient’s history.(CRPP)


The Exit will shut down the program. A message will be printed and the data will remain in the file.(EX)

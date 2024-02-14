# 🏦 Payment Application
an application that enables the user to carry out simple **financial transactions**, consists of 3 main modules
# Project Description
the application enable the user to:

1- Withdraw

2- Deposit

3- Transfere 

4- see Mini Statement

5- See account details (balance, Card expiraion date, name, last transactions...)

# project flowchart

![image](https://github.com/raghadislam/ATM_machine_project/assets/112733878/5cb67134-af19-46ee-b04f-f1beae02cc0d)

# File Handling
I used it to improve the synchronization of any changes made by the user and automatically modify them in their information stored in the **databases** file, so after the application is closed all the changes is saved includig: balance, last transactions, etc...

# linked list 
I used it to improve memory consumption in the application, where one function called function reads everything in the database file and stores it in the linked list to enable the application to work on them, then before the program is closed there is another function "WriteToFile" transfers everything in the list to the database file, and finally linked list is deallocated.

# validations
the application validate all user information to make sure they exist in the database, also every input in the application has a validation function.

And with all inputs taken from users as **strings** although it was harder to deal with them but I made sure that nothing enterd by users can cause the program to crash, it's well protected.

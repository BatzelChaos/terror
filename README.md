v0.0.13 PRE_ALPHA


GOALS:

- WRITE THE BATTLE FUNCTIONS
    - RUN - INDEV/WORKING
    - ATTACK - INDEV/NONWORKING
    - INVENTORY - INDEV/WORKING
- MAKE A LEVEL-UP
- MAKE A PAUSE MENU IN MAP - INDEV
- ENABLE USERS TO GO BACK TO ALL THE WAY BACK TO THE MAIN MENU THROUGH THE PAUSE MENU - DONE
- BE ABLE TO GO UP AND DOWN IN THE INVENTORY
- BE ABLE TO USE ITEMS FROM THE INVENTORY
- PROFILE
- EQUIPPING ITEMS
- MAKE ITEMS USABLE INSIDE BATTLE INVENTORY





CHANGELOG:

- v0.0.13:
    - fixed access to inventory through battlescreen causing a loop
    - added "esc" key as an alternative to "i" as a button to close inventory
    - reworked the play() function to have a bigger role
    - fixed the character select ghost screen bug FINALLY
    - isolated character selection to it's own file to fix a bug with pause screen
    - added a template for the pause menu, right now it just softlocks the program
    - almost finished pause menu, with some fatal softlocks still needing solving

- v0.0.12:
    - made the treasure logic work correctly.
    - almost finished the inventory functions except for using items from the inventory, that is for later.
    - fixed the double collision check bug i was unaware of before now.
    - fixed removeCell function
    - other minor edits
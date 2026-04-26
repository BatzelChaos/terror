#pragma once

class CharacterSelect:public menumenu
{
    private:
        WINDOW* characterSelectScreen;
    public:
        CharacterSelect(WINDOW* tempscreen);
        int characterSelectMove();
        int characterSelect();

};
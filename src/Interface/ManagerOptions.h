<<<<<<< HEAD
#ifndef MANAGEROPTIONS_H
#define MANAGEROPTIONS_H

class ManagerOptions
{
public:
    enum class Options
    {
        RESET_BLACKLIST,
        ADD_TO_BLACKLIST,
        ADD_MANAGER,
        SET_FILE,
        EXIT
    };

    Options SelectMainOption();

private:
    void DisplayMenu();
    int GetValidOption();

};

=======
#ifndef MANAGEROPTIONS_H
#define MANAGEROPTIONS_H

class ManagerOptions
{
public:
    enum class Options
    {
        RESET_BLACKLIST,
        ADD_TO_BLACKLIST,
        ADD_MANAGER,
        SET_FILE,
        EXIT
    };

    Options SelectMainOption();

private:
    void DisplayMenu();
    int GetValidOption();

};

>>>>>>> origin/master
#endif // !MANAGEROPTIONS_H
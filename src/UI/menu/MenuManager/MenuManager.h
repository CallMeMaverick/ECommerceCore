#ifndef ECOMMERCECORE_MENUMANAGER_H
#define ECOMMERCECORE_MENUMANAGER_H

/**
 * @class MenuManager
 * @brief Manages the overall main menu for user interaction.
 *
 * This class is designed to control the operation of the main menu in an application.
 * It offers a single point of action for different user pathways by sharing a common entry
 * point, execute(). The purpose of the MenuManager is to facilitate lean and well-organized
 * primary interaction without dealing with the preliminaries of choosing how to start their
 * journey through the application's functionalities. As designed, this class cannot be instantiated,
 * using the "delete" keyword on its constructor, and serves strictly as a layout for the
 * static method that encapsulates its operations.
 *
 * The best way to leverage the MenuManager is by invoking its `execute()` static function to
 * initiate the different application services a system or a piece of more significant software
 * aims to offer, post any entry-level authorizations or bootstrapping.
 */
class MenuManager
{
public:
    /**
     * @brief Boots the navigation by controlling the display and transition through the main menu.
     *
     * This core, gateway method facilitates the ways the user, or the running machine can manage
     * various commands, strategies, and queries to key in for the type of job, program, or action
     * they are willing to work on or automate. It primarily handles the graphical part,
     * that's the compendium of menu lists or redirections to the complete main courses of the solution
     * it is a basis of.
     */
    static void execute();

    /* Prevent instantiation of the class */
    MenuManager() = delete;

    /* The destructor is defaulted, meaning no special clean-up is required */
    ~MenuManager() = default;
};


#endif //ECOMMERCECORE_MENUMANAGER_H

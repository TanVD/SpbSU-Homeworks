#pragma once
/**
  * @mainpage OutputInterface makes it easier to work with output in file and console
  */

/**
 * @brief The OutputInterface class Is the interface of outputing int arrays in file or console
 */
class OutputInterface
{
public:
    /**
     * @brief ~OutputInterface Virtual destructor
     */
    virtual ~OutputInterface() {};
    /**
     * @brief out Virtual method of outputing int arrays which makes childs of interface implement outputing
     */
    virtual void out() = 0;
};


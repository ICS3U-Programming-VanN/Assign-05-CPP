// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: December 2, 2022
// This program asks the if they want to calculate the
// area of a trapezoid or the volume of a trapezoidal prism
// The program will then display the measurement to the user and
// display all the calculations they have done.
// This program can be ran multiple times(at user's request)


#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iomanip>


// This function calculates the area of a trapezoid and returns it to main()
float CalculateAreaTrapezoid(float base1, float base2, float height) {
    float area;

    // Calculates the area
    area = (base1 + base2) / 2 * height;

    // Returns area to main
    return area;
}


// This function calculates the
// volume of a trapezoidal prism and returns it to main()
float CalculateVolumeTrapezoid(float base1, float base2,
                               float height, float width) {
    float volume;

    // Calculates the volume
    volume = (base1 + base2) / 2 * height * width;

    // Returns volume to main()
    return volume;
}


int main() {
    // Initialize Variable
    bool userRepeat = true;

    // Declared Variable
    std::string dimensionsOfTrapezoid, runAgain, unitOfMeasurement;
    std::string userBaseString1, userBaseString2, userHeightString;
    std::string userPrismWidthString;
    float userBase1, userBase2, userHeight;
    float userPrismWidth, trapezoidArea, trapezoidalPrismVolume;

    // Initialize List with possible answers
    // to repeat program (later in program)
    std::list<std::string> yesOrNoRepeat = {"y", "n"};

    // Do-while loop to run program
    // at least once before asking user to run again
    do {
        // Reset runAgain Variable if the program has been run again
        runAgain = "";

        // Reset dimensionOfTrapezoid variable to ask the user for
        // how many dimensions their trapezoid is (if the program runs again)
        dimensionsOfTrapezoid = "";

        // Displays introductory message about
        // how many dimensions their trapezoid is
        std::cout << "Is your trapezoid 2D or 3D?" << std::endl;

        // Ensures that user will enter a valid input
        // for what kind of trapezoid they will be calculating for
        while (dimensionsOfTrapezoid != "2" && dimensionsOfTrapezoid != "3") {
            // Asks user if they will be calculating for a 2D or 3D trapezoid
            std::cout << "Enter (2 for a regular trapezoid "
            << "or 3 for a trapezoidal prism): ";
            std::getline(std::cin, dimensionsOfTrapezoid);
        }

        // Checks for exceptions
        try {
            // Asks user for the measurement of the first base
            std::cout << "Enter the value for the first base: ";
            std::getline(std::cin, userBaseString1);

            // Asks user for the measurement of the second base
            std::cout << "Enter the value for the second base: ";
            std::getline(std::cin, userBaseString2);

            // Asks user for the measurement of the height
            std::cout << "Enter the value for the height: ";
            std::getline(std::cin, userHeightString);

            // Converts the first base to a float
            userBase1 = stof(userBaseString1);

            // Converts the second base to a float
            userBase2 = stof(userBaseString2);

            // Converts the height to a float
            userHeight = stof(userHeightString);

            // IF the trapezoid is 3D
            if (dimensionsOfTrapezoid == "3") {
                // Asks user for the width of the trapezoidal prism
                std::cout << "Enter the width of the trapezoidal prism: ";
                std::getline(std::cin, userPrismWidthString);

                // Converts the prism width to a float
                userPrismWidth = stof(userPrismWidthString);

                // Checks if the prism width is negative or equal to zero
                // (this shape would not exist otherwise)
                if (userPrismWidth <= 0) {
                    std::cout << "You must enter positive numbers\n"
                    << std::endl;

                    // Returns to the beginning (restarts the program)
                    continue;
                }
            }

            // Ensures that the measurements are not negative or equal to zero
            if (userBase1 <= 0 || userBase2 <= 0 || userHeight <= 0) {
                std::cout << "You must enter positive numbers!\n" << std::endl;

            // IF the user has inputted valid measurements
            } else {
                // Displays to user message about paying attention
                // to what they input for the units
                std::cout << "\nPlease pay attention when entering units!"
                << std::endl;

                // Asks user for the unit measurements
                std::cout << "Enter the unit of measurement"
                << "(ex. mm, cm, m, km): ";
                std::getline(std::cin, unitOfMeasurement);

                // IF the user selected a 2D trapezoid
                if (dimensionsOfTrapezoid == "2") {
                    // Calls function to calculate the area of the trapezoid
                    trapezoidArea = CalculateAreaTrapezoid(userBase1,
                                                userBase2, userHeight);

                    // Displays the area of the trapezoid to the user
                    std::cout << "\nThe area of your trapezoid: "
                    << std::fixed << std::setprecision(2) << trapezoidArea
                    << unitOfMeasurement << "^2" << "\n" << std::endl;

                // IF the user selected a 3D trapezoid (Trapezoidal Prism)
                } else {
                    // Calls function to calculate
                    // the volume of the trapezoidal prism
                    trapezoidalPrismVolume = CalculateVolumeTrapezoid(
                        userBase1, userBase2, userHeight, userPrismWidth);

                    // Displays the volume of the trapezoidal prism to the user
                    std::cout <<
                    "The volume of your trapezoidal prism: "
                    << std::fixed << std::setprecision(2)
                    << trapezoidalPrismVolume
                    << unitOfMeasurement<< "^3" << "\n" << std::endl;
                }
            }

            // Ensures that the user will input either 'y' or 'n'
            // for whether or not they want to run the program again
            // Checks if the user's response is in the list
            while (std::find(yesOrNoRepeat.begin(), yesOrNoRepeat.end(),
                    runAgain) == yesOrNoRepeat.end()) {
                // Asks user if they want to run the program again
                std::cout << "Do you want to run the program again? (y/n): ";
                std::getline(std::cin, runAgain);

                // Converts user's input into uppercase
                std::transform(runAgain.begin(), runAgain.end(),
                                runAgain.begin(), ::tolower);
            }

            // IF the user wants to end the program
            if (runAgain == "n") {
                // Sets looping condition to false (ending program)
                userRepeat = false;
            }

        // In the event of an exception
        } catch (std::invalid_argument) {
            // Displays to user error message
            std::cout << "You must enter positive numbers!"
            << "(Invalid Input, try again.)\n" << std::endl;
        }
    // Repeats the program until otherwise inputted by user
    } while (userRepeat == true);
}

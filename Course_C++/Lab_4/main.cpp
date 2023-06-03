#include <iostream>
#include <vector>
#include "interfaces.h"
#include "segment.h"
#include "hexagon.h"

unsigned int getTotalMemoryUsage(const std::vector<IFigure*> &shapes) {
    unsigned int total = 0;
    for (auto shape : shapes) {
        total += shape->size();
    }
    return total;
}

void sortShapesByMass(std::vector<IFigure*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](IFigure* a, IFigure* b) {
        return *a < *b;
    });
}

int main() {
    std::vector<IFigure*> shapes;
    int choice = 0;

    while (choice != 9) {
        std::cout << "\nSelect an option:\n"
                  << "1. Add a segment\n"
                  << "2. Add a hexagon\n"
                  << "3. List all shapes\n"
                  << "4. Calculate total area of all shapes\n"
                  << "5. Calculate total perimeter of all shapes\n"
                  << "6. Calculate center of mass of the whole system\n"
                  << "7. Total memory usage:\n"
                  << "8. Sorting shapes with each other by mass:\n"
                  << "9. Quit" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                auto *segment = new Segment();
                shapes.push_back(segment);
                break;
            }

            case 2: {
                auto *hexagon = new Hexagon();
                shapes.push_back(hexagon);
                break;
            }

            case 3: {
                std::cout << "List of Shapes:\n";
                for (auto shape: shapes) {
                    std::cout << " - " << shape->className() << "\n";
                }
                break;
            }

            case 4: {
                double totalArea = 0.0;
                for (auto shape: shapes) {
                    totalArea += shape->square();
                }
                std::cout << "\nThe total area of all shapes is " << totalArea << ".\n";
                break;
            }

            case 5: {
                double totalPerimeter = 0.0;
                for (auto shape: shapes) {
                    totalPerimeter += shape->perimeter();
                }
                std::cout << "\nThe total perimeter of all shapes is " << totalPerimeter << ".\n";
                break;
            }

            case 6: {
                double totalMass = 0.0;
                double xCenter = 0.0;
                double yCenter = 0.0;

                // Calculate total mass and center of mass of the whole system
                for (auto shape: shapes) {
                    double mass = shape->mass();
                    totalMass += mass;
                    xCenter += mass * shape->position().x;
                    yCenter += mass * shape->position().y;
                }

                xCenter /= totalMass;
                yCenter /= totalMass;

                std::cout << "\nThe center of mass of the whole system is (" << xCenter << ", " << yCenter << ").\n";
                break;
            }

            case 7: {
                std::cout << "Total memory usage: " << getTotalMemoryUsage(shapes) << " bytes\n";
                break;
            }

            case 8: {
                sortShapesByMass(shapes);
                std::cout << "Shapes sorted by mass:\n";
                for (auto shape: shapes) {
                    std::cout << " - " << shape->className() << " (mass = " << shape->mass() << ")\n";
                }
                break;
            }

            case 9: {
                std::cout << "Exit\n";
                break;
            }

            default: {
                std::cout << "Invalid choice\n";
                break;
            }
        }
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
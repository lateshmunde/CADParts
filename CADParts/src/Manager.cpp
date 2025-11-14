#include "Manager.h"

Manager::Manager(){}

Manager::~Manager() //free memory
{
    for (auto p : parts)
    {
        delete p;
    }
    parts.clear();

    while (!deletedParts.empty())
    {
        delete deletedParts.top();
        deletedParts.pop();
    }
}

void Manager::menu()
{
    int choice;
    do {
        std::cout << "------------- CAD parts ---------------\n"
                  << "1. Add part\n"
                  << "2. Display all parts\n"
                  << "3. Search part\n"
                  << "4. Delete part\n"
                  << "5. Undo Delete\n"
                  << "6. Show part count\n"
                  << "7. Save parts to File\n"
                  << "9. Exit\n"
                 << "-----------------------------------\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1: { addPart(); break; }
        case 2: { viewAll(); break; }
        case 3: { searchPart(); break; }
        case 4: { deletepart(); break; }
        case 5: { undoDeletes(); break; }
        case 6: { showPartsCount(); break; }
        case 7: { saveToFile(); break; }
        case 8: { std::cout << "Exiting...\n"; break; }
        default: { std::cout << "Invalid choice!\n"; break; }
        }

    } while (choice != 8);
}

void Manager::addPart()
{

    std::string ID;
    Material material;
    double diameter;
    std::cout << "Enter Unique Id for part : ";
    std::cin >> ID;
    std::cout << "Enter Material for part : ";
    std::cin >> material;
    std::cout << "Enter Diameter for part : ";
    std::cin >> diameter;

    std::cout << "1. Pipe\n"
              << "2. Valve\n"
              << "3. Elbow\n"
              << "4. Flange\n";

    int choice1;
    std::cout << "Enter your choice: ";
    std::cin >> choice1;

    switch (choice1)
    {
    case 1: 
    { 
        std::string name = "Pipe";
        double len;
        double thick;
        std::cout << "Enter Length of Pipe : ";
        std::cin >> len;
        std::cout << "Enter thickness of Pipe : ";
        std::cin >> thick;

        parts.push_back(new Pipe(name, ID, material, diameter, len ,thick));
        //parts.push_back(std::make_unique<Pipe>());
        break; 
    }
    case 2: 
    { 
        std::string name = "Valve";
        std::string typ; 
        int pressLimit;
        std::cout << "Enter Type of Valve : ";
        std::cin >> typ;
        std::cout << "Enter Pressure Limit of valve : ";
        std::cin >> pressLimit;
        parts.push_back(new Valve(name, ID, material, diameter, typ, pressLimit));
        break; 
    }
    case 3: 
    { 
        std::string name = "Elbow";
        int ang; 
        double cRadius;
        std::cout << "Enter Angle of Elbow : ";
        std::cin >> ang;
        std::cout << "Enter Corner Radius of elbow : ";
        std::cin >> cRadius;
        parts.push_back(new Elbow(name, ID, material, diameter, ang, cRadius));
        break; 
    }
    case 4: 
    { 
        std::string name = "Flange";
        double len;
        double strength;
        std::cout << "Enter Length of Flange : ";
        std::cin >> len;
        std::cout << "Enter Stength of Flange : ";
        std::cin >> strength;
        parts.push_back(new Flange(name, ID, material, diameter, len, strength));
        break;
    }
    default: 
    { 
        std::cout << "Invalid choice!\n"; 
        break; 
    }
    }
}

void Manager::viewAll() const
{
    if (parts.empty())
    {
        std::cout << "No shapes to display.\n";
    }
    else {
        for (auto p : parts)
        {
            p->display();
        }
    }
   
}

void  Manager::searchPart() const
{ 
    std::vector<std::string> Ids;
    if (parts.empty())
    {
        std::cout << "No shapes to sort.\n";
        return ;
    }
    else
    {
        for (auto p : parts)
        {
            Ids.push_back(p->getId());
        }

        std::string key;
        std::cout << "Enter ID to search : ";
        std::cin >> key;
        bool found = std::binary_search(Ids.begin(), Ids.end(),key);
        if(found)
            std::cout << "Found ";
        else
            std::cout << "Not Found ";
    }
   
}

void Manager::deletepart()
{
    if (parts.empty())
    {
        std::cout << "No shapes available to delete.\n";
        return;
    }

    int i = 0;
    std::cout << "Available Shapes: \n";
    for (auto p : parts)
    {
        std::cout << i << ":" << p->getName() << ", Id: " 
                  << p->getId() << ", Material: " 
                  << p->getMaterial() << "\n";
        i++;
    }

    int index;
    std::cout << "Enter the index of shape to delete: ";
    std::cin >> index;

    if ((0 <= index) && (index < parts.size()))
    {// Push the shape pointer to deleted stack
        deletedParts.push(parts[index]);
    }
    else
    {
        std::cout << "Invalid index!Try again.\n";
    }

    parts.erase(parts.begin() + index);
    std::cout << "Shape deleted successfully. You can undo this action.\n";
}

void Manager::undoDeletes()
{
    if (deletedParts.empty())
    {
        std::cout << "Nothing to Undo.\n";
        return;
    }

    parts.push_back(deletedParts.top());
    deletedParts.pop();
    std::cout << "Last delete undone successfully!\n";
}

void Manager::showPartsCount() const
{
    std::cout << Parts::getPartsCount();
}

void Manager::saveToFile()
{
    FileManger::saveParts(parts, "parts.txt");
    std::cout << "Shapes saved successfully to " << "shapes.txt" << "\n";
}



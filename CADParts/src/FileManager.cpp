#include "FileManger.h"



void FileManger::saveParts(const std::vector<Parts*>& parts, const std::string& fileName)
{
    std::ofstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("cannot open file: " + fileName);

    for (const auto* p : parts)
    {
        if (const auto* pipe = dynamic_cast<const Pipe*>(p))
        {
            file << "Pipe," << pipe->getId();
            pipe->getMaterial();
            pipe->getDiameter();
            pipe->getLength();
            pipe->getThickness();
        }
        else if (const auto* v = dynamic_cast<const Valve*>(p))
        {
            file << "Valve," << v->getId();
            v->getMaterial();
            v->getDiameter();
            v->getPressureLimit();
            v->getType();
        }
        else if (const auto* e = dynamic_cast<const Elbow*>(p))
        {
            file << "Valve," << pipe->getId();
            e->getMaterial();
            e->getDiameter();
            e->getAngle();
            e->getRadius();
        }
        else if (const auto* f = dynamic_cast<const Flange*>(p))
        {
            file << "Valve," << pipe->getId();
            f->getMaterial();
            f->getDiameter();
            f->getLength();
            f->getMaxStregnth();
        }   
    }
}


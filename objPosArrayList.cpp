#include "objPosArrayList.h"


objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[arrayCapacity];

    // Initialiing all elements to the default objPos oject
    for(int i=0; i<listSize; i++){
        aList[i] = objPos();

    }
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Shifting the all objPos members to the right
    if (listSize < arrayCapacity) {

        // Starting from the last member, traverse to the first one, while shifting each one to the right
        for (int i = listSize-1; i >= 0 ; i--)
        {
            aList[i+1] = aList[i]; 
        }

        // Setting the Head of snake 
        aList[0] = thisPos;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Inserting object to end of list
    if (listSize < arrayCapacity){
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if (listSize != 0 && listSize == 1){
        aList[0] = objPos(); // reset the only element
        listSize--;

    } else {
        for (int i = 0; i < listSize; i++)
        {
            aList[i] = aList[i+1];
        }
        aList[listSize-1] = objPos(); // reset the last element
        listSize--;

    }
}

void objPosArrayList::removeTail()
{
    if (listSize>1) {
        aList[listSize-1] = objPos();
        listSize--;

    } else if (listSize == 1){
        removeHead();

    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}
/**************************************************************************
 * Class Name: Space
 * Date: 12-10-2019
 * Author: Danielle DuChene
 * Description: The space class holds four pointers for top, right, bottom, 
 *    and left. It links spaces through pointers.
 * ************************************************************************/
#include "Space.hpp"

Space::Space(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :top(inTop), right(inRight), left(inLeft), bottom(inBottom), name(inName){
}
 
/******************************************************************************
* getName: Returns the name of the room.
* ****************************************************************************/
string Space::getName(){
    return name;
}
 
/******************************************************************************
* setSpacePointers: Sets the pointers of the Space object. Used after all the
*    needed Space objects have been created.
* ****************************************************************************/
void Space::setSpacePointers(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom){
    top = inTop;
    right = inRight;
    left = inLeft;
    bottom = inBottom;
}
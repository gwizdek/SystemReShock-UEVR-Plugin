#pragma once

#include "SDK/Basic.hpp"
#include "SDK/CoreUObject_classes.hpp"

// Finds an object by the full name UEVR uses, "<Class> /Package/Path.Outer.Name", without
// building a string per object.
//
// API::find_uobject converts the full name of every object to a string and compares them. For
// an object that is loaded it answers from a cache at once, but for one that is not loaded it
// walks the whole object array, about 105 ms with 176k objects. Code that checks every few
// seconds whether a class has been loaded caused a visible stutter that way. This lookup turns
// the names of the path into FNames once and compares the FName numbers of each object, its
// outers and its class. A hit is remembered by its object array index and checked again on
// the next call, so an object that was unloaded and loaded again is found anew.
class ObjectLookup final
{
public:
    // Game thread only. Returns nullptr when no live object has this full name.
    template <class T = SDK::UObject>
    static T* find(const wchar_t* full_name) {
        return reinterpret_cast<T*>(find_object(full_name));
    }

private:
    static SDK::UObject* find_object(const wchar_t* full_name);
};
